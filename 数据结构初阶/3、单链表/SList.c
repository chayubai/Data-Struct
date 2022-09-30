#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
//不带头 单向 非循环 链表

//1、遍历打印链表
void SListPrint(SListNode* phead)
{
    //assert(phead);//这里不能加断言，否则空链表不能打印
	SListNode* cur = phead;
	while (cur != NULL)//cur等于空，表示头地址没有链表，循环结束
	{
		printf("%d-> ", cur->data);
		//改变指针，指向下一个结点
		cur = cur->next;
	}
	printf("NULL\n");
}

//3、开辟结点
SListNode* BuySListNode(SLDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	//判断开辟空间是否成功
	if (newNode == NULL)
	{
		printf("申请结点失败\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

//传值调用:
//尾插：找NULL，找到后，赋值一个malloc(sezof(slnode))地址
//void SListPushBack(SListNode* phead, SLDataType x)
//{//将地址作为值传递，phead改变，但不会影响pList
//	if (phead == NULL)//空链表，一上来就解引用操作，会导致问题
//	{
//		//当为空链表时，创建一个空间，链接上去
//		SListNode* phead = BuySListNode(x);
//	}
//	else
//	{
//		SListNode* tail = BuySListNode(x);
//		//链接
//		//tail = newNode;
//	}
//
//}

//传址调用
//2、尾插：找NULL，找到后，赋值一个malloc(sezof(slnode))地址
void SListPushBack(SListNode** pphead, SLDataType x)
{//pphead是&pList，*pphead就是pList

    assert(pphead);//pphead = &pList一定不可能为空，这里加断言主要是防止测试传错了
	//开辟结点
	SListNode* newNode = BuySListNode(x);//这里创建空间，方便后面找尾链接

	if (*pphead == NULL)//如果没有判断是否为空链表，会导致解引用NULL，出错
	{
		//当为空链表时，创建一个空间，链接上去
		*pphead = newNode;
	}
	else//链表不为空
	{
		SListNode* tail = *pphead;//此之后的*pphead不再是NULL，而是第一个结点的地址

		//找到了尾,找到NULL
		//while (tail != NULL)//找到了,则tail为NULL，循环结束
		//{
		//	tail = tail->next;
		//}
		//链接
		//tail->next = newNode;//如果为空链表，链接新结点到尾，这里找到了NULL，对NULL解引用操作，出错了

		//找到尾节点的指针，如果为空链表，一上来就将新结点链接到尾，解引用操作tail->next != NULL会导致问题
		while (tail->next != NULL)//找到了，则tail->next为NULL
		{
			tail = tail->next;
		}
		//链接
		tail->next = newNode;//这里是将newNode赋给NULL，而不是上面的解引用NULL再赋值
	    //注意：tail是结点的地址，tail->next是下一个结点的地址，也是上一个结点的数据
	}
}
//  NULL     0x1
//*pphead     1 NULL
//  0x1
//
//
//   0x1     0x1     0x3     0x6
//*pphead     1 0x3   2 0x6   3 NULL

//6、尾删：保存前一个结点的指针，将本节点指向的空间释放掉，再将前一个结点的next置为NULL
//直接释放尾节点，导致前一个结点的next为野指针
void SListPopBack(SListNode** pphead)
{
	//1、没有结点
	//2、一个结点
	//3、一个以上的结点
	if (*pphead == NULL)//没有结点
	{
		return;
	}
	else if ((*pphead)->next == NULL)//一个结点，即下一个结点为NULL
	{
		free(*pphead);//释放*pphead指向的开辟的空间
		*pphead = NULL;//空链表
	}
	else//一个以上结点
	{
	    //方法一：
		//   0x1     0x1     0x3     0x6
		//*pphead     1 0x3   2 0x6   3 NULL

		//找到尾，再将前一个地址域指向NULL
		//使用双指针，防止tail的值被覆盖
		SListNode* prev = NULL;//tail移动前将地址给prev保存
		SListNode* tail = *pphead;
		while (tail->next != NULL)//注意：如果为空链表，不判断，直接tail->next空指针解引用出问题
		{//空链表另行考虑
			prev = tail;//保存tail的前一个结点的地址
			tail = tail->next;
		}
		free(tail);
		tail = NULL;//可以不写，局部变量出了作用域被销毁了
		prev->next = NULL;//如果为一个结点时，prev->next空指针解引用错误，因此一个结点时另行考虑

		//while (tail != NULL)
		//{
		//	prev = tail;//保存tail的前一个结点的地址
		//	tail = tail->next;
		//}
		//free(prev);
		//tail = NULL;//可以不写，局部变量出了作用域被销毁了
		//prev = NULL;
		//这种方式，prev指向最后一个结点，但是没有将前一个结点的地址域的值置NULL

		/*
		//方法二：
		SListNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail = NULL;
		*/
	}
}

//4、头插
void SListPushFront(SListNode** pphead, SLDataType x)
{
	// *pphead    0x1     0x1     0x3     0x6
	//  4 0x1  *pphead     1 0x3   2 0x6   3 NULL
	SListNode* newNode = BuySListNode(x);
	newNode->next = *pphead;

	//将新的结点作为头结点
	*pphead = newNode;
}

//5、头删
void SListPopFront(SListNode** pphead)
{
	//1、没有结点
	//2、一个结点 + 3、一个以上的结点
	if (*pphead == NULL)//没有结点
	{
		return;
	}
	else
	{
	    /*
	    //方法一：
		//不能先释放空间，否则，下一个结点的地址就不知道了
		//保存下一个结点的地址，再释放掉上一个结点的空间
		SListNode* next = (*pphead)->next;//如果没有判断，这里会空指针解引用

		//以下两步位置不能颠倒
		free(*pphead);//释放空间
		//将下一个结点作为新的头结点
		*pphead = next;//空链表
        */

        //方法二：
		SListNode* tmp = *pphead;

		//以下两步位置不能颠倒
		*pphead = (*pphead)->next;
		free(tmp);
	}
}

//7、单链表查找：可在此基础上，作为改数据的功能
SListNode* SListFind(SListNode* phead, SLDataType x)
{
	//查找到的数据的地址返回
	SListNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	//没找到
	return NULL;
}

//8、在pos的前面插入x
void SListInsertBefore(SListNode** pphead, SListNode* pos, SLDataType x)
{
    //尽量多用断言
    assert(pphead);
    assert(pos);
	if(pos == *pphead)
	{
		SListPushFront(pphead, x);//注意：这里传入的参数是pphead，即&pList
		/*
		//或者
		SListNode* newNode = BuySListNode(x);
		newNode-next = *pphead;
		*pphead = newNode;
		*/
	}
	else
	{
	    //找前一个结点有以下两种方法：
	    //方法一：
	    SListNode* newNode = BuySListNode(x);
	    SListNode* prev = NULL;
		SListNode* cur = *pphead;
		while(cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
        prev->next = newNode;//当pos为第一个结点时，prev->next空指针解引用错误,因此另行考虑，即头插
		newNode->next = cur;//此时cur == pos

        /*//方法二：
        SListNode* newNode = BuySListNode(x);
		SListNode* prev = *pphead;
		while(prev->next != pos)//当pos第一个结点时，prev从第一个结点开始遍历直到NULL都没有找到prev->next等于pos
		{//因此pos第一个结点时，另行考虑，即头插
			prev = prev->next;
		}
        prev->next = newNode
		newNode >next = pos;
        */
	}
}

//9、删除pos指针位置的值：找到前一个，再将该结点的next指向pos的next的结点后，free掉pos的指针指向的空间
void SListErase(SListNode** pphead, SListNode* pos)
{
	if(pos == *pphead)
	{
		SListPopFront(pphead);//注意：这里传入的参数是pphead，即&pList

		/*
		//或者
        *pphead = pos->next;
        free(pos);
		*/
	}
	else
	{
		SListNode* prev = *pphead;
		while(prev->next != pos)//当pos第一个结点时，prev从第一个结点开始遍历直到NULL都没有找到prev->next等于pos
		{//因此pos第一个结点时，另行考虑，即头删
			prev = prev->next;
		}
		//先链接
		prev->next = pos->next;
		//再free
		free(pos);
		pos = NULL;//可以不需要此行代码
		//注意：不能先释放掉pos指向的空间，否则找不到pos->next指向的空间
	}
}

//在pos位置之后插入x
//分析思考为什么不在pos位置之前插入？ - 需要找到前一个结点，此时就需要传入&pList
void SListInsertAfter(SListNode* pos, SLDataType x)
{	//					         newNode
	//                            0x9
	//                    pos      9 0x3
	// *pphead    0x1     0x1             0x3     0x6
	//  4 0x1  *pphead     1 0x9           2 0x6   3 NULL
	assert(pos);
	//开辟结点
	SListNode* newNode = BuySListNode(x);

	//注意赋值顺序，否则导致野指针，或者可以先保存pos的下一个结点，再链接
	newNode->next = pos->next;

	pos->next = newNode;
}

//删除pos位置之后的值
//分析思考为什么删除pos位置之前值？ - 需要直到前一个结点，此时就需要传入&pList
void SListEraseAfter(SListNode* pos)
{
	//                    pos
	// *pphead    0x1     0x1             0x3     0x6
	//  4 0x1  *pphead     1 0x9           2 0x6   3 NULL

	// *pphead    0x1     0x1                0x6
	//  4 0x1  *pphead     1 0x6              3 NULL

	assert(pos);

	if (pos->next)
	{
		//注意赋值顺序
		SListNode* next = pos->next;//保存要删除的结点的地址，防止野指针
		SListNode* nextNext = next->next;
		pos->next = nextNext;

		//直接合并为一行pos->next = next->next;
		free(next);
		next = NULL;//可以不需要这一行代码
	}
}

//释放链表：倒序释放每一个结点或者释放前一个结点之前保存下一个结点的地址
void SListDestory(SListNode** pphead)
{
    asser(pphead);
    SListNode* cur = *pphead;
    while(cur)
    {
        SListNode* next = cur->next;
        free(cur);
        cur = next;
    }
    *pphead = NULL;
}
