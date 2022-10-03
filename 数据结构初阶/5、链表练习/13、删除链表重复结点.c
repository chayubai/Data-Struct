#define _CRT_SECURE_NO_WARNINGS 1
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如：链表1->2->3->3->4->4->5处理后为1->2->5

//定义一前cur一后next指针，用于判断指针的内容是否相等
//用一个prev指针保存cur的前一个结点的地址，用于链接next
//cur和next不相同，三个指针往后移动，如果cur和next相同，则只移动next，cur和next仍相同继续只移动next，
//直到不相同，free掉重复的结点
//     pHead
//prev
//     cur  next
//     1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5 -> NULL

//pHead
//     prev
//          cur  next
//1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5 -> NULL

//     prev
//          cur       next
//1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5 -> NULL

//     prev cur
//          next
//1 -> 2 -> 4 -> 4 -> 5 -> NULL

//     prev
//          cur  next
//1 -> 2 -> 4 -> 4 -> 5 -> NULL

//     prev
//          cur       next
//1 -> 2 -> 4 -> 4 -> 5 -> NULL

//     prev cur
//          next
//1 -> 2 -> 5 -> NULL

//     prev
//          cur  next
//1 -> 2 -> 5 -> NULL

//特殊用例1：重复头结点
//prev
//    cur            next
//    1 -> 1 -> 1 -> 3 -> 4 -> 5 -> NULL
//当cur和next相等的时候，prev = NULL,prev->next指向next时，即空指针解引用，发生错误
//此时删除结点，更新新的头结点，即pHead = next
//     pHead
//prev cur
//     next
//     3 -> 4 -> 5 -> NULL

//     pHead
//prev
//               cur  next
//     3 -> 4 -> 5 -> NULL

//特殊用例2：重复尾节点
//prev
//    cur  next
//    1 -> 2 -> 3 -> 3 -> 4 -> 5 -> 5 -> 5 -> NULL
//    prev
//         cur  next
//    1 -> 2 -> 3 -> 3 -> 4 -> 5 -> 5 -> 5 -> NULL
//         prev
//              cur  next
//    1 -> 2 -> 3 -> 3 -> 4 -> 5 -> 5 -> 5 -> NULL
//         prev
//              cur       next
//    1 -> 2 -> 3 -> 3 -> 4 -> 5 -> 5 -> 5 -> NULL
//         prev
//              cur  next
//    1 -> 2 -> 4 -> 5 -> 5 -> 5 -> NULL
//              prev
//                   cur  next
//    1 -> 2 -> 4 -> 5 -> 5 -> 5 -> NULL
//              prev
//                   cur       next
//    1 -> 2 -> 4 -> 5 -> 5 -> 5 -> NULL
//              prev
//                   cur            next
//    1 -> 2 -> 4 -> 5 -> 5 -> 5 -> NULL

//此时删除结点，prev = NULL
//              prev
//                   cur   next
//    1 -> 2 -> 4 -> NULL
//cur和next继续迭代，此时next->next空指针解引用错误
//因此，当cur和next相等，则next往后走一步，直到不相等或者next->next为NULL，则删除重复结点

//常规情况：1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5 -> NULL
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
/*
struct ListNode* deleteDuplication(struct ListNode* pHead)
{
	//当为空链表或者只要一个结点的链表时，直接返回
	if (pHead == NULL || pHead->next == NULL)
		return pHead;

	struct ListNode* prev = NULL;//保存cur前一个结点方便链接next
	struct ListNode* cur = pHead;
	struct ListNode* next = pHead->next;//cur和next比较

	while (next != NULL)
	{
		//cur和next不相同，三个指针往后移动
		if (cur->val != next->val)
		{
			prev = cur;
			cur = next;
			next = next->next;
        }
		else//如果cur和next相同，则只移动next，cur和next仍相同继续只移动next，
		{

			while (cur->val == next->val)//cur和next仍相同继续只移动next
			{//由于迭代前提是next不为空，这里不需要cur->val == next->val && next !=NULL
				next = next->next;
			}
			//走到这里，cur和next不相同，链接prev和next，删除结点。即free掉重复的结点
            prev->next = next;
			//释放，即迭代释放
			while (cur != next)
			{
				//free(cur)//如果直接释放cur，会找不到下一个需要释放的结点
				//保存当前结点，往后走，再释放当前结点
				struct ListNode* del = cur;//del将cur先保存起来
				cur = cur->next;
				free(del);

				//或者保存下一个结点，再释放掉前一个结点，再cur往后走
				//del = cur->next;
				//free(cur);
				//cur = del;
			}
			//cur、next迭代，cur在释放结点时cur = next, next往后走
			next = next->next;//等价于next = cur->next;
		}
	}
	return pHead;
}
 */

//特殊用例1：1 -> 1 -> 1 -> 3 -> 4 -> NULL分析过程，并修改代码
/*
struct ListNode* deleteDuplication(struct ListNode* pHead)
{
	//当为空链表或者只要一个结点的链表时，直接返回
	if (pHead == NULL || pHead->next == NULL)
		return pHead;

	struct ListNode* prev = NULL;
	struct ListNode* cur = pHead;
	struct ListNode* next = pHead->next;

	while (next != NULL)
	{
		//cur和next不相同，三个指针往后移动
		if (cur->val != next->val)
		{
			prev = cur;
			cur = next;
			next = next->next;
		}
		else//如果cur和next相同，则只移动next，cur和next仍相同继续只移动next，
		{
            while (cur->val == next->val)//cur和next仍相同继续只移动next
			{//由于迭代前提是next不为空，这里不需要cur->val == next->val && next !=NULL
				next = next->next;
			}
			//走到这里，cur和next不相同，链接prev和next，删除结点。即free掉重复的结点
			//特殊用例：头重复，删除重复结点，更新头
			if (prev != NULL)
				prev->next = next;
			else
				pHead = next;//更新头结点

			//释放，即迭代释放
			while (cur != next)
			{
				//free(cur)//如果直接释放cur，会找不到下一个需要释放的结点
      			//保存当前结点，往后走，再释放当前结点
				struct ListNode* del = cur;//将cur先保存起来
				cur = cur->next;
				free(del);
			}
			//迭代，next往后走
			next = next->next;
		}
	}
	return pHead;
}
 */

//特殊用例2：1 -> 2 -> 3 -> 3 -> 4 -> 5 -> 5 -> 5 -> NULL分析代码修改程序
struct ListNode* deleteDuplication(struct ListNode* pHead)
{
	//当为空链表或者只要一个结点的链表时，直接返回
	if (pHead == NULL || pHead->next == NULL)
		return pHead;

	struct ListNode* prev = NULL;
	struct ListNode* cur = pHead;
	struct ListNode* next = pHead->next;

	while (next != NULL)
	{
		//cur和next不相同，三个指针往后移动
		if (cur->val != next->val)
		{
			prev = cur;
			cur = next;
			next = next->next;
		}
		else//如果cur和next相同，则只移动next，cur和next仍相同继续只移动next，
		{
			while (next != NULL && cur->val == next->val)//cur和next仍相同继续只移动next
			{//如果最后比较完了也没有找到不等于的结点，即next走到NULL，则结束比较
                //注意：cur->val == next->val && next != NULL不能这样，否则程序会崩，因为执行顺序的问题
				next = next->next;
            }
			//来到这里，1、可能next为空，2、也可能cur和next不相同

			//cur和next不相同或者next走到空，链接prev和next，删除结点。即free掉重复的结点
			//特殊用例：头重复，删除重复结点，更新头
			if (prev != NULL)
				prev->next = next;//这里可以处理next为空的情况，即prev不为空，next为空，删除重复的尾，prev链接到NULL
			else
				pHead = next;//更新头结点

            //判断next为空，释放重复的尾节点，是否会出问题
			//释放，即迭代释放
			while (cur != next)
			{
				//free(cur)//如果直接释放cur，会找不到下一个需要释放的结点
				//保存当前结点，往后走，再释放当前结点
				struct ListNode* del = cur;//将cur先保存起来
				cur = cur->next;
				free(del);
			}

			//迭代，next往后走，有问题，因此需要做一个判断
			//next = next->next;//如果直接使用这一行代码，当尾重复时，next已经走向了NULL，导致解引用空指针，发生错误

			//特殊用例：尾重复，删除重复结点，置为NULL
			if (next != NULL)
				next = next->next;
			else
				prev->next = NULL;//这里可以不做处理，因为prev链接next时，指向了NULL
		}
	}
	return pHead;
}

//特殊用例3：1 -> 1 -> 1 -> 3 -> 3 -> 5 -> 5 -> 5 -> NULL分析代码修改程序
struct ListNode* deleteDuplication(struct ListNode* pHead)
{
	//当为空链表或者只要一个结点的链表时，直接返回
	if (pHead == NULL || pHead->next == NULL)
		return pHead;

	struct ListNode* prev = NULL;
	struct ListNode* cur = pHead;
	struct ListNode* next = pHead->next;

	while (next != NULL)
	{
		//cur和next不相同，三个指针往后移动
		if (cur->val != next->val)
		{
			prev = cur;
			cur = next;
			next = next->next;
		}
		else//如果cur和next相同，则只移动next，cur和next仍相同继续只移动next，
		{
			while (next != NULL && cur->val == next->val)//cur和next仍相同继续只移动next
			{//如果最后比较完了也没有找到不等于的结点，即next走到NULL，则结束比较
                //注意：cur->val == next->val && next != NULL不能这样，否则程序会崩，因为执行顺序的问题
				next = next->next;
            }
			//来到这里，1、可能next为空，2、也可能cur和next不相同

			//cur和next不相同或者next走到空，链接prev和next，删除结点。即free掉重复的结点
			//特殊用例：头重复，删除重复结点，更新头
			if (prev != NULL)
				prev->next = next;//这里可以处理next为空的情况，即prev不为空，next为空，删除重复的尾，prev链接到NULL
			else
				pHead = next;//更新头结点

            //判断next为空，释放重复的尾节点，是否会出问题
			//释放，即迭代释放
			while (cur != next)
			{
				//free(cur)//如果直接释放cur，会找不到下一个需要释放的结点
				//保存当前结点，往后走，再释放当前结点
				struct ListNode* del = cur;//将cur先保存起来
				cur = cur->next;
				free(del);
			}

			//迭代，next往后走，有问题，因此需要做一个判断
			//next = next->next;//如果直接使用这一行代码，当尾重复时，next已经走向了NULL，导致解引用空指针，发生错误

			//特殊用例：尾重复，删除重复结点，置为NULL
			/*
			if (next != NULL)
				next = next->next;
			else
				prev->next = NULL;//这里可以不做处理，因为当prev为NULL时，导致空指针解引用
			*/
			if (next != NULL)
				next = next->next;
			else if(prev != NULL)
				prev->next = NULL;
		}
	}
	return pHead;
}
//总结：先想出常规思路写代码，再通过特殊用例，修改常规思路的代码
int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val = 1;
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val = 1;
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val = 3;
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n5->val = 3;
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n6->val = 5;
	struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n7->val = 5;
	struct ListNode* n8 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n8->val = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = NULL;
	struct ListNode* pHead = deleteDuplication(n1);
	while (pHead)
	{
		printf("%d -> ", pHead->val);
		pHead = pHead->next;
	}
	printf("NULL");
	return 0;
}
