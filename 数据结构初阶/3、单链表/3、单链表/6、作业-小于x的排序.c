#define _CRT_SECURE_NO_WARNINGS 1
//现有一链表的头指针ListNode* pHead，给一定值x，
//编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据的顺序，
//返回重新排列后的链表的头指针
//输入：4 -> 2 -> 5 -> 3 -> 6 -> 9 -> 0    x = 4
//输出：2 -> 3 -> 0 -> 4 -> 5 -> 6 -> 9
//输入：1 -> 9 -> 3 -> 5 -> 6 -> 7   x = 4
//输出：1 -> 3 -> 9 -> 5 -> 6 -> 7

//如果不考虑相对顺序，依次取结点，小于x值头插，大于x值尾插，
//使用newhead和newtail保存头和尾，不需要找头和找尾，方便头插或者尾插。

//使用两个链表(两个哨兵位的结点)，第一个链表为lessHead，用来尾插链接小于x的结点
//第二个链表为greaterHead，用来尾插链接大于或等于x的结点
//最后将两个链表链接起来
//cur
//1 -> 9 -> 3 -> 5 -> 6 -> 7 -> NULL  x = 4
//将每个结点拿下来放在对应条件下的尾上
//             lessTail
//lessHead->1->3
//                      greaterTail
//greaterHead->9->5->6->7
//lessHead->1->3->greaterHead->9->5->6->7
//准备两个链表的哨兵位结点，lessTail和greaterTail方便不需要找尾，直接尾插，类似与合并链表问题

#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
/*
struct ListNode* partition(struct ListNode* pHead, int x)
{
	struct ListNode* lessHead, *lessTail;
	struct ListNode* greaterHead, *greaterTail;
	//开辟两个哨兵位的头结点，不需要考虑是否为空
	lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));

	//初始化，否则如果没有比x小的值，greaterHead->next，就是随机值。两个链表链接时，最后结点会链接随机值
	lessHead->next = greaterHead->next = NULL;

	//遍历原链表
	struct ListNode* cur = pHead;
	//迭代取下结点链接到对应的尾
	while (cur != NULL)
	{
		if (cur->val < x)
		{
			//尾插
			lessTail->next = cur;
			//尾指针往后走
			lessTail = lessTail->next;
		}
		else
		{
            //尾插
			greaterTail->next = cur;
			//尾指针往后走
			greaterTail = greaterTail->next;
		}
		//迭代条件
		cur = cur->next;
	}
	//两个链表链接
	lessTail->next = greaterHead->next;//注意：不是链接greaterHead，而是greaterHead->next
	//销毁两个哨兵位
	struct ListNode* list = lessHead->next;
	free(lessHead);
	free(greaterTail);
	return list;//如果直接返回lessHead->next则lessHead没有释放
}
 */

//以上代码错误的原因：特殊用例会导致死循环，如倒数第二个结点和最后一个结点前大后小
//分析：
//                         cur
//1 -> 9 -> 3 -> 5 -> 6 -> 7 -> 2 -> NULL  x = 4
//                  lessTail
//lessHead->1->3 -> 2 -> NULL
//                      greaterTail
//greaterHead->9->5->6->7->2
//此时greaterTail->next指向2的结点
//当lessTail->next = greaterTail->next两个链表进行链接时，构成了环
//lessHead->1->3->2->greaterHead->9->5->6->7->2->...
//故两个链表链接结束后，将greaterTail->next置空

struct ListNode* partition(struct ListNode* pHead, int x)
{
	struct ListNode* lessHead, * lessTail;
	struct ListNode* greaterHead, * greaterTail;
	//开辟两个哨兵位的头结点，不需要考虑是否为空
	lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));

	//初始化，否则如果没有比x小的值，则该节点的next就是随机值
	lessHead->next = greaterHead->next = NULL;

	//遍历原链表
	struct ListNode* cur = pHead;
	//迭代取下结点链接到对应的尾
	while (cur != NULL)
	{
		if (cur->val < x)
		{
			//尾插
			lessTail->next = cur;
			//尾指针往后走
			lessTail = lessTail->next;
		}
		else
		{
			greaterTail->next = cur;
			greaterTail = greaterTail->next;
		}
		cur = cur->next;
	}
	//两个链表链接
	lessTail->next = greaterHead->next;
	greaterTail->next = NULL;//greaterTail->next置空，防止形成环

	//销毁两个使用权
	struct ListNode* list = lessHead->next;
	free(lessHead);
	free(greaterHead);

	return list;//如果直接返回lessHead->next则lessHead没有释放
}

/*
int main()
{
	struct ListNode* n1 = malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode* n2 = malloc(sizeof(struct ListNode));
	n2->val = 9;
	struct ListNode* n3 = malloc(sizeof(struct ListNode));
	n3->val = 3;
	struct ListNode* n4 = malloc(sizeof(struct ListNode));
	n4->val = 5;
	struct ListNode* n5 = malloc(sizeof(struct ListNode));
	n5->val = 6;
	struct ListNode* n6 = malloc(sizeof(struct ListNode));
	n6->val = 7;
	struct ListNode* n7 = malloc(sizeof(struct ListNode));
	n7->val = 2;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = NULL;

	struct ListNode* pHead = partition(n1,4);
	while (pHead != NULL)
	{
		printf("%d -> ", pHead->val);
		pHead = pHead->next;
	}
	printf("NULL\n");
	return 0;
}
 */

//画图，走读代码，写博客。