#define _CRT_SECURE_NO_WARNINGS 1
//对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A,请返回一个int值，代表其是否为回文结构，保证链表长度小于等于900
//输入：1->2->2->1
//输出：true

//方法1：开一个900的数组，遍历链表将数据放入数组中，判断左边下标和右边下标对于的元素是否相等

//方法2：查找中间结点，对相同部分的后半段进行逆置，再遍历前半段和后半段比较，判断是否相同
//					      prev
//                             slow           fast
//偶数个结点时：1 -> 2 -> 3 -> 3 -> 2 -> 1 -> NULL
//从slow中间结点前面断掉，否则会指向3所在的结点
//A链表：1->2->3->NULL
//slow链表：1->2->3->NULL   以slow为结点开始逆置
//				     prev
//                        slow      fast
//奇数个结点时：1 -> 2 -> 3 -> 2 -> 1 -> NULL
//从slow中间结点前面断掉，否则会指向3所在的结点
//A链表：1->2->NULL
//slow链表：1->2->3->NULL   以slow为结点开始逆置
//prev保存slow前一个结点，方便断掉
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
//链表逆置 - 反转链表
struct ListNode* reverseList(struct ListNode* head)
{

	struct ListNode* newhead = NULL;
	struct ListNode* cur = head;
	struct ListNode* next = NULL;

	//判断空链表，或则只有一个结点的链表，这里可以不需要判断，cur为NULL，不进入循环
 	if (head == NULL || head->next == NULL)
		return head;
	//迭代
	while (cur != NULL)
	{
		next = cur->next;
		//头插
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}
/*
int chkPalindrome(struct ListNode* A)
{
	struct ListNode* fast = A;
	struct ListNode* slow = A;
	struct ListNode* prev = NULL;//用于断掉中间结点的联系

	//第一步：找到中间结点（偶数个节点时，中间结点为第二个结点）
	while (fast && fast->next)
	{
		prev = slow;//slow走之前，保存它的地址
		slow = slow->next;
		fast = fast->next->next;
	}
	//断掉中间结点的联系，即slow前一个置为NULL
	prev->next = NULL;

	//第二步：以slow为结点的链表逆置
	//reverseList(slow);//这里虽然逆置了，但是是值传递得到的结果没有发生变化
	//3 -> 2 -> 1		逆置后1->2->3
	slow = reverseList(slow);//需要接收它的新头结点的地址

	//第三步：分解的两个链表的比较
	while(A)//A链表为空结束
	{
		if (A->val != slow->val)
		{
			return 0;
		}
		else
		{
			A = A->next;
			slow = slow->next;
		}
	}
	return 1;
}
 */

//优化：不断开链接
//					      prev
//                             slow           fast
//偶数个结点时：1 -> 2 -> 3 -> 3 -> 2 -> 1 -> NULL
//从slow中间结点前面断掉，否则会指向3所在的结点
//1->2->3->
//1->2->3->NULL   以slow为结点开始逆置
//A链表：1->2->3->3->NULL  slow链表：1->2->3->NULL
//				     prev
//                        slow      fast
//奇数个结点时：1 -> 2 -> 3 -> 2 -> 1 -> NULL
//从slow中间结点前面断掉，否则会指向3所在的结点
//1->2->
//1->2->3->NULL   以slow为结点开始逆置
//A链表：1->2->3->NULL     slow链表：1->2->3->NULL

int chkPalindrome(struct ListNode* A)
{
	struct ListNode* fast = A;
	struct ListNode* slow = A;
	//第一步：找到中间结点
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	//第二步：以slow为结点的链表逆置
	slow = reverseList(slow);

	//第三步：分解的两个链表的比较
	while(A && slow)//A或slow链表有一个为空，结束
	{
		if (A->val != slow->val)
		{
			return 0;
		}
		else
		{
			A = A->next;
			slow = slow->next;
		}
	}
	return 1;
}

/*
int main()
{
	struct ListNode* n1 = malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode* n2 = malloc(sizeof(struct ListNode));
	n2->val = 2;
	struct ListNode* n3 = malloc(sizeof(struct ListNode));
	n3->val = 3;
	struct ListNode* n4 = malloc(sizeof(struct ListNode));
	n4->val = 3;
	struct ListNode* n5 = malloc(sizeof(struct ListNode));
	n5->val = 2;
	struct ListNode* n6 = malloc(sizeof(struct ListNode));
	n6->val = 1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;

	int result = chkPalindrome(n1);
	if (result)
		printf("该链表是回文结构\n");
    else
		printf("该链表不是回文结构\n");
	return 0;
}
 */
