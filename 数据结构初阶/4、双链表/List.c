#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
//带头的双向循环链表

//2、创建结点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if(node)
        return NULL;
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//1、初始化哨兵位结点
//传值调用：不会改变外面的值
//void ListInit(ListNode* phead)
//{
//	phead = BuyListNode(0);
//	phead->next = phead;
//	phead->prev = phead;
//}

//方法一：
//传址调用
//void ListInit(ListNode** pphead)
//{
//	//通过外面传的地址在函数里面，改变函数外面的变量的值
//	*pphead = BuyListNode(0);
//	(*pphead)->next = *pphead;
//	(*pphead)->prev = *pphead;
//}

//方法二：
//返回哨兵位结点的地址
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//3、尾插 -不需要改变传过来的哨兵位指针，即不需要传二级指针
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);//链表为空，即开辟哨兵结点开辟空间失败。一般不会失败，即一定哨兵位结点地址不为空，也不需要断言
	//找尾
	ListNode* tail = phead->prev;
	//插入新结点
	ListNode* newnode = BuyListNode(x);
	//链接：phead->prev和newnode链接、newnode-next和phead链接、tail-next和newnode链接
	//newnode->prev和tail链接
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

	//注意：也不需要像不带头单链表一样，考虑没有结点的情况
}
////14、尾插
//void ListPushBack(ListNode* phead, LTDataType x)
//{
//	//尾插：在pos为phead的前面插入x
//	ListInsert(phead, x);
//}

//4、打印：从第一个结点（非哨兵位）开始，找到哨兵位结点停止打印
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//5、头插 - 在head结点后插入
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	//方法一
	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
	//注意判断没有结点是否满足

	//方法二：
	/*//顺序不能颠倒
	ListNode* newnode = BuyListNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
	*/
}
////13、头插 - 在head结点后插入
//void ListPushFront(ListNode* phead, LTDataType x)
//{
//	//头插：在pos为phead->next的前面插入x
//	ListInsert(phead->next, x);
//}

//6、头删 - 在head结点后删除
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//判断链表为空时，继续删除的断言
	//方法一：
	/*//注意链接顺序
	ListNode* first = phead->next;
	phead->next = first->next;
	first->next->prev = phead;
	free(first);
	*/

	//方法二：
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
	first = NULL;//无需此行
	//注意判断没有结点是否满足
}
////11、头删 - 在head结点后删除
//void ListPopFront(ListNode* phead)
//{
//	ListErase(phead->next);
//}

//7、尾删
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//判断链表为空时，继续删除的断言
	//方法一：
	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
	tail = NULL;//可以不置空，因为tail为局部变量，出了局部范围自动释放

	//方法二：
	/*//注意链接顺序
	ListNode* tail = phead->prev;
	phead->prev = tail->prev;
	tail->prev->next = phead;
	free(tail);
	*/
	//注意：没有结点是否满足
}
////12、尾删
//void ListPopBack(ListNode* phead)
//{
//	ListErase(phead->prev);
//}

//8、查找 - 返回找到的数对应结点的地址，也能修改
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	//走到这里没有找到
	return NULL;
}

//变量风格：
//pos_prev	  posPrev
//函数、类型、项目名、源文件名风格：
//list_print  ListPrint

//9、在pos的前面插入x
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	//链接：posPrev、newnode、pos
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;

	//方法二：
	/*//注意链接顺序
	pos->prev->next = newnode;
	newnode->prev = pos->prev;
	newnode->next = pos;
	pos->prev = newnode;
	*/
	//注意：pos在第一个结点，相当于尾插
	//注意：pos在最后一个结点，相当于头插
}

//10、删除pos位置的值
void ListErase(ListNode* pos)
{
	assert(pos);
	//方法一：
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;

	//方法二：
	/*//注意链接顺序
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	*/
	//注意：pos在最后一个结点，相当于尾删
    //注意：pos在第一个结点，相当于头删
}

//12、空间销毁 - 销毁创建的链表
//释放结点后，里面的值为随机值，找不到下一个结点，有两种方法删除：
//1、保存下一个，释放当前结点
//2、保存当前结点，再往下走，再释放当前结点
//void ListDestory(ListNode* phead)
//{
//	assert(phead);
	/*
	//第二种方法：
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//来到这里，1、如果链表不使用，则删除head，2、如果链表继续使用，则不删除head
	//2、如果链表继续使用，则不删除head
	phead->next = phead;
	phead->prev = phead;

	//1、如果链表不使用，则删除head
	free(phead);
	phead = NULL;//本身phead需要置空，通过调试发现函数里面置空了，但是函数外面没有作用，因为head和phead它们是两个独立的空间
	*/

    /*
    //第三种方法：
    //1、如果链表不使用，则删除head
	ListClear(phead);//此行代码相当于以上所有代码
	free(phead);//释放空间，让其回归内存，即变量的地址仍不变，但是地址的值为随机值，空间还给了操作系统
	phead = NULL;//本身phead需要置空，通过调试发现函数里面置空了，但是函数外面没有作用，因为head和phead它们是两个独立的空间
    */
//	//解决方法：
//	//1、在外面主函数最末尾补一行phead = NULL;(不建议)
//	//2、二级指针：即传址调用，函数里面想要改变函数外面的值。传值调用：函数里面不改变函数外面的值。
//  	//3、使用返回值，外面用同一个变量接收返回值
//}

//第四种方法：传二级指针
void ListDestory(ListNode** pphead)
{
    //1、如果链表不使用，则删除head
	assert(*pphead);
	ListClear(*pphead);//此行代码相当于以上所有代码
	free(*pphead);//释放空间，让其回归内存，即变量的地址仍不变，但是地址的值为随机值，空间还给了操作系统
	//2、二级指针
	*pphead = NULL;
}

//11、清理数据 - 清理所有的数据节点，保留head头结点，可以继续使用 - 例如：购物车业务
void ListClear(ListNode* phead)
{
	assert(phead);
	//第二种方法：
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//来到这里，1、如果链表不使用，则删除head，2、如果链表继续使用，则不删除head
	//2、释放掉所有数据结点，让头结点head保持带头双向循环链表结构
	phead->next = phead;
	phead->prev = phead;
}

//注意：代码的复用，面试可能要求极短时间内写完，此时代码复用很重要
//对于查找接口，最优算法是：1、平衡搜索数（AVL树，红黑树）2、哈希表 3、B树，B+树系列
//对于其他接口，都是最优的算法
