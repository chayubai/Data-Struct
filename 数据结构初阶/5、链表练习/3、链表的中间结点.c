#define _CRT_SECURE_NO_WARNINGS 1
//链表的中间结点
//给定一个头结点为head的非空单链表，返回链表的中间结点的值。
//如果有两个中间结点，则返回第二个中间结点的值。
//输入：[1,2,3,4,5]
//输出：此链表中间结点的值：3

//方法1、遍历链表，计算总的结点个数，除以2，打印中间结点的数
//时间复杂度为：O(N)
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* cur = head;
    int count = 0;
	while(cur)
    {
        count++;
        cur = cur->next;
    }
    struct ListNode* middlenode = head;
    //1 2 3 4 5 count=5
    //1 2 3 4 5 6 count=6
    for(int i = 0;i < count/2;i++)
    {
        middlenode = middlenode->next;
    }
	return middlenode;//中间结点的指针
}

//方法2、只遍历链表一次。快慢指针
//两个指针分别指向第一个结点，一个指针为快指针，一个指针为慢指针
//慢指针一次走一步，快指针一次走两步，
//奇数个结点时：当快指针走到尾时，慢指针走到中间处(fast->next == NULL)
//偶数个结点时：当快指针走到NULL时，慢指针走到第二个中间结点处(fast == NULL)

/*
struct ListNode* middleNode(struct ListNode* head)
{
	//注意每次变量赋初值时，一定要确保变量是否为空，
	//一前一后两个指针的赋值，例如：head为空，struct ListNode* fast = head->next;就崩了

	struct ListNode* slow = head;
	struct ListNode* fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		//当偶数个结点时，fast/slow为空，循环结束
		//当奇数个结点时，fast->next为空，循环结束
		//即fast != NULL && fast->next != NULL均不为空，循环继续
	}
	return slow;//中间结点的指针
}

int main()
{
	struct ListNode* n1 = malloc(sizeof(struct ListNode));
	n1->val = 6;
	struct ListNode* n2 = malloc(sizeof(struct ListNode));
	n2->val = 3;
	struct ListNode* n3 = malloc(sizeof(struct ListNode));
	n3->val = 2;
	struct ListNode* n4 = malloc(sizeof(struct ListNode));
	n4->val = 4;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	struct ListNode* middlepNode = middleNode(n1);//通过调试确定是否正确
	printf("%d\n", middlepNode->val);
	return 0;
}
 */
