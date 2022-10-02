#define _CRT_SECURE_NO_WARNINGS 1
//合并两个有序链表
//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有结点组成的。
//输入：1 -> 2 -> 4,1 -> 3 - > 4 - > 5
//输出：1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5

//方法一：将二个链表拼接到第一个链表上，再对链表排序
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* mergeTwoLists(struct ListNode* L1, struct ListNode* L2)
{
    //链表传参时，判断是否为NULL，否则解引用NULL，程序会崩
	if (L1 == NULL)
		return L2;//L1为空，L2不一定为空，为空或不为空也是返回L2
	if (L2 == NULL)
		return L1;//L2为空，L1不一定为空，为空或不为空也是返回L1

    //将L2链接到L1上
    struct ListNode* cur = L2;
    while(cur->next)
    {
        cur = cur->next;
    }
    cur->next = L1;

    //链表排序
    //...
    //不清楚
}

//方法二：取L1上的结点，在L2上合适的位置插入

//方法三：从头开始，取两个链表小的结点，尾插到新链表中
//1、无哨兵位的头结点
//先取两个链表中，第一个节点小的结点作为头结点head，再迭代取数值小的结点先尾插，数值大的结点后尾插
//对于单链表的尾插，是先找到尾，再插入新的结点，取一个结点找一次尾，时间复杂度为O(N^2)，效率很低，此时需要一个尾结点变量tail
//因此，这里使用tail保存尾节点，不需要找尾，方便直接链接到tail上
//
// L1                 L2
// 1 -> 2 -> 4        1 -> 3 - > 4 - > 5
// head
// NULL
// tail

// L1                 L2
// 1 -> 2 -> 4        1 -> 3 - > 4 - > 5
//head = 1(L1)
// 1
//tail
// L1                 L2
// 2 -> 4             1 -> 3 - > 4 - > 5

// L1                 L2
// 2 -> 4             1 -> 3 - > 4 - > 5
//head
// L1   L2
// 1 -> 1
//tail
// L1   L2
// 1 -> 1
//      tail
// L1                 L2
// 2 -> 4			  3 - > 4 - > 5

// L1                 L2
// 2 -> 4			  3 - > 4 - > 5
//head
//           L1
// 1 -> 1 -> 2
//     tail
//           L1
// 1 -> 1 -> 2
//           tail
// L1              L2
// 4			   3 -> 4 - > 5

// L1              L2
// 4			   3 -> 4 - > 5
//head
//                L2
// 1 -> 1 -> 2 -> 3
//          tail
//                L2
// 1 -> 1 -> 2 -> 3
//                tail
// L1              L2
// 4			   4 - > 5

// L1              L2
// 4			   4 - > 5
//head
//                     L1
// 1 -> 1 -> 2 -> 3 -> 4
//               tail
//                     L1
// 1 -> 1 -> 2 -> 3 -> 4
//                     tail
//当有一个链表为NULL循环结束

//                          L2
// 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5
//                    tail
//tail方便找到尾，并尾插
/*
struct ListNode* mergeTwoLists(struct ListNode* L1, struct ListNode* L2)
{
	//链表传参时，判断是否为NULL，否则解引用NULL，程序会崩
	if (L1 == NULL)
		return L2;//L1为空，L2不一定为空，为空或不为空也是返回L2
	if (L2 == NULL)
		return L1;//L2为空，L1不一定为空，为空或不为空也是返回L1

	struct ListNode* head = NULL,*tail = NULL;//head用于返回，tail方便找到尾，并尾插

    while(L1!=NULL && L2 !=NULL)
    {
        if(L1->val<L2->val)
        {
            //判断头结点
            if(tail == NULL)
            {
                head = tail = L1;
                //L1 = L1->next;
            }
            else
            {
                //取小的尾插
                tail->next = L1;
                tail = tail->next;
                //L1 = L1->next;
            }
            //将两个L1 = L1->next;放到这里
            L1 = L1->next;
        }
        else
        {
            //判断头结点
            if(tail == NULL)
            {
                head = tail = L2;
                //L2 = L2->next;
            }
            else
            {
                //取小的尾插
                tail->next = L2;
                tail = tail->next;
                //L2 = L2->next;
            }
            //将两个L2 = L2->next;放到这里
            L2 = L2->next;
        }
    }
    //如果一个链表走完了，另一个链表不为空，直接将不为空的链表链接到尾上
    if(L1 != NULL)
        tail->next = L1;
    if(L2 != NULL)
        tail->next = L2;

	return head;
}
*/

//优化1：
/*
 struct ListNode* mergeTwoLists(struct ListNode* L1, struct ListNode* L2)
{
	//链表传参时，判断是否为NULL，否则解引用NULL，程序会崩
	if (L1 == NULL)
		return L2;//L1为空，L2不一定为空，为空或不为空也是返回L2
	if (L2 == NULL)
		return L1;//L2为空，L1不一定为空，为空或不为空也是返回L1

	struct ListNode* head = NULL,*tail = NULL;//head用于返回，tail方便找到尾，并尾插
	//确定头结点
	if (L1->val < L2->val)
	{
		head = tail = L1;
		L1 = L1->next;
	}
	else
	{
		head = tail = L2;
		L2 = L2->next;
	}
    //尾插链接
	//确定头结点的时候，把它拿下来后，就应该往下走一次，再循环迭代取小的尾插

	//取小的尾插，其中一个为空就结束循环，都不会空则继续
	//判断条件，想的是结束的条件，写的是继续的条件
	while (L1 != NULL && L2 != NULL)//while (L1 && L2)
	{
		if (L1->val < L2->val)
		{
			tail->next = L1;
			L1 = L1->next;
		}
		else
		{
			tail->next = L2;
			L2 = L2->next;
		}
		tail = tail->next;//相当于分别在L1 = L1->next;和L2 = L2->next;前面插入tail = L1和tail = L2
	}
	if (L1 != NULL)
		tail->next = L1;
	else
		tail->next = L2;
	return head;
}
*/

//优化2：带哨兵位的头结点，此时无需判断头结点，直接取小的结点尾插
//注意返回头结点时，返回的是哨兵位下一个结点
/*
struct ListNode* mergeTwoLists(struct ListNode* L1, struct ListNode* L2)
{
	//链表传参时，判断是否为NULL，否则解引用NULL，程序会崩
	if (L1 == NULL)
		return L2;
    if (L2 == NULL)
		return L1;

	struct ListNode* head = NULL, * tail = NULL;
	// 哨兵位结点，直接在哨兵位结点后面尾插，不需要确定头结点
	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));//哨兵位的头结点

	//尾插链接
	while (L1 != NULL && L2 != NULL)//while (L1 && L2)
	{
		if (L1->val < L2->val)
		{
			tail->next = L1;
			L1 = L1->next;
		}
		else
		{
			tail->next = L2;
			L2 = L2->next;
		}
		tail = tail->next;
	}
	if (L1 != NULL)
		tail->next = L1;
	else
		tail->next = L2;

	struct ListNode* realHead = head->next;
	free(head);

	return realHead;//返回真正的头结点
}

int main()
{
	//L1
	struct ListNode* m1 = malloc(sizeof(struct ListNode));
	m1->val = 1;
	struct ListNode* m2 = malloc(sizeof(struct ListNode));
	m2->val = 2;
	struct ListNode* m3 = malloc(sizeof(struct ListNode));
	m3->val = 4;
	m1->next = m2;
	m2->next = m3;
	m3->next = NULL;
	//L2
	struct ListNode* n1 = malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode* n2 = malloc(sizeof(struct ListNode));
	n2->val = 3;
	struct ListNode* n3 = malloc(sizeof(struct ListNode));
	n3->val = 4;
	struct ListNode* n4 = malloc(sizeof(struct ListNode));
	n4->val = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	struct ListNode* pHead = mergeTwoLists(m1 ,n1);
	while (pHead != NULL)
	{
		printf("%d -> ", pHead->val);
		pHead = pHead->next;
	}
	printf("NULL\n");
	return 0;
}
 */
