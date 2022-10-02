#define _CRT_SECURE_NO_WARNINGS 1
//反转一个单链表
//输入：1 -> 2 -> 3 -> 4 -> 5 -> NULL
//输出：5 -> 4 -> 3 -> 2 -> 1 -> NULL
//你可以用迭代或者递归的反转链表。你能否用两种方法解决这道题？

//方法一、反转迭代 - 反指针法
// n1    n2   n3
//NULL   1 -> 2 -> 3 -> 4 -> 5 -> NULL
// n1    n2   n3
//NULL <-1    2 -> 3 -> 4 -> 5 -> NULL
//由于将n2->next指向n1后，找不到n2的下一个结点，就无法反转下一个结点的指针，因此需要用n3保存下一个结点的指针
//原本1指向2，2指向3，n1和n2用来反转，
//此时1指向NULL，即n1 = NULL，2指向1。即n2->next = n1，然后n1、n2、n3同时往后走
//n2->next指向n1，需要提前将n2-next的地址保存到n3，即head->next,否则下次迭代，找不到后面的数据

//反转过程
//	n1<- n2   n3
//NULL <-1    2 -> 3 -> 4 -> 5 -> NULL
//		 n1   n2   n3
//NULL <-1 <- 2    3 -> 4 -> 5 -> NULL
//		      n1   n2   n3
//NULL <-1 <- 2 <- 3    4 -> 5 -> NULL
//		           n1   n2   n3
//NULL <-1 <- 2 <- 3 <- 4    5 -> NULL
//		                n1   n2   n3
//NULL <-1 <- 2 <- 3 <- 4 <- 5    NULL
//		                     n1   n2   n3
//NULL <-1 <- 2 <- 3 <- 4 <- 5    NULL
//NULL <-1 <- 2 <- 3 <- 4 <- 5
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};
/*
//初始条件、迭代过程、结束条件
struct ListNode* reverseList(struct ListNode* head)
{
	//判断空链表
	if (head == NULL)//当链表只有一个结点，循环进入一次
		return head;
	//当链表为空，直接n2->next，空指针解引用错误
	struct ListNode* n1 = NULL,*n2 = head,*n3 = n2->next;

	while (n2)//n2为空结束
	{
		//反转  n2指向n1
		n2->next = n1;

		//迭代 - n1、n2、n3都往后走
		n1 = n2;
		n2 = n3;
		if(n3)//当n3为空，不再迭代，否则n3为空，n3->next解引用错误
			n3 = n3->next;
	}

	return n1;
}
*/

//方法二、头插法
//注意：不是开辟一个结点，然后头插一个，因为返回的头结点是原链表的结点
//创建新的空链表，将原链表的几个结点依次头插到最新的头结点上
//   cur  next
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
//   cur  next
//   1    2 -> 3 -> 4 -> 5 -> NULL
//   cur
//   1 -> NULL
//思路：取cur头插到以newhead为头的新链表上。
//由于cur链接到新的链表的头结点上，找不到下一个结点，就无法头插下一个结点，因此需要用next保存下一个结点
//next保存下一个结点的地址，防止cur的内容保存的下个结点的地址发生变化，而找不到下一个结点
//即cur作为新的头结点时，cur->next的地址发生了变化，此时想要把原链表新的头结点头插就找不到原链表的头结点

//保存后一个结点，再将cur插入到头上，再更新新的头结点newhead，再cur、next都往后走
//   cur  next
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
//   cur  next
//   1    2 -> 3 -> 4 -> 5 -> NULL
// newhead
//   cur  newhead    cur = next
//   1 -> NULL

//        cur  next
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
//        cur  next
//        2    3 -> 4 -> 5 -> NULL
//   cur  newhead
//    2 -> 1 -> NULL

//             cur  next
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
//             cur  next
//             3    4 -> 5 -> NULL
//   cur  newhead
//    3 -> 2 -> 1 -> NULL

//                  cur  next
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
//                  cur  next
//                  4    5 -> NULL
//   cur  newhead
//    4 -> 3 -> 2 -> 1 -> NULL

//                       cur  next
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
//                       cur  next
//                       5    NULL
//   cur  newhead
//    5 -> 4 -> 3 -> 2 -> 1 -> NULL
//                            cur  next
//                            NULL
//cur = NULL时，则循环停止

#if 0
struct ListNode* reverseList(struct ListNode* head)
{
    //开辟新连链表的头结点
	struct ListNode* newhead = NULL;

	struct ListNode* cur = head;

	//判断空链表，这里可以不需要判断，cur为NULL，不进入循环
 	//if (head == NULL)
	//	return head;

	while (cur != NULL)
	{
	    //迭代过程：

	    //保存下一个结点
		struct ListNode* next = cur->next;
		//头插
		cur->next = newhead;

        //更新新链表的头结点
		newhead = cur;
        //cur、next都往后走
		cur = next;
    }
	return newhead;
}

//遍历打印链表
void SListPrint(struct ListNode* phead)
{
	struct ListNode* cur = phead;
	while (cur != NULL)//cur等于空，表示头地址没有链表，循环结束
	{
		printf("%d-> ", cur->val);
		//改变指针，指向下一个结点
		cur = cur->next;
	}
	printf("NULL\n");
}


int main()
{
    /** //这种测试是错误的，因为指针未初始化，解引用非法访问
    struct ListNode* n1 ,*n2,*n3,*n4,*n5;
	n1->next = n2;
	n1->val = 1;

	n2->next = n3;
	n2->val = 2;

	n3->next = n4;
	n3->val = 3;

	n4->next = n5;
	n4->val = 4;

	n5->next = NULL;
	n5->val = 5;
     */

    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val = 2;
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val = 3;
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val = 4;
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n5->val = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	SListPrint(n1);

	struct ListNode* newphead = reverseList(n1);
	SListPrint(newphead);
	return 0;
}
#endif
