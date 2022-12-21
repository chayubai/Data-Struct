#define _CRT_SECURE_NO_WARNINGS 1
//环形链表 - 判断链表中是否有环
//给定一个链表，判断链表中是否有环。
//如果链表中有某个结点，可以通过连续跟踪next指针再次到达，则链表中存在环。
//为了表示给定链表中的环，我们使用整数pos来表示链表尾连接到链表中的位置
//（索引从0开始）。如果pos是-1，则在该链表中没有环。
//注意：pos不作为参数进行传递，仅仅是为了标识链表的实际情况，
//如果链表中存在环，则返回true，否则返回false。
//  1-> 2-> 3-> 4-> 5
//<-3			    ->6
//	 <- 9<- 8<- 7<-

//  1-> 2-> 3-> 4-> 5
//        <-3	    ->6
//	         <- 7<-

//两个指针指向同一个头结点，一个指针为slow，每次走一步，一个指针为fast，每次走两步。
//快指针先进入环，当快指针在环中走完N圈后，慢指针刚进入环，快指针开始追赶进入环的慢指针。
//当快指针的地址等于慢指针的地址时，即他们相遇了，说明链表为环形链表
//如果不带环，fast就会走到空。如果带环，fast就会在环里面追上slow。
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
/*
int hasCycle(struct ListNode* head)
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast != NULL && fast->next != NULL)//循环条件：可能不为环，此时奇数个结点fast为空结束，偶数个结点fast->next为空结束
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
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
	n5->next = n3;

	int result = hasCycle(n1);
	if (result)
		printf("环形链表\n");
	else
		printf("非环形链表\n");
	return 0;
}
 */

//面试官：请证明快指针是如何追上慢指针的？
//如果慢指针一次走1步，快指针一次走3步呢?4步呢?n步?

//注意：当进环后，都是fast追慢指针。

//1、第一种情况：慢指针走1步，快指针走2步(这种情况慢指针只可能最多走一圈)
//假设慢指针进入环以后，fast和slow之间的距离为X
//当他们同时每走一次，他们之间的距离缩小1，即X+1-2=X-1
//当他们一直走下去，X-1、X-2、X-3...当X = 0时，二者一定会相遇。

//2、第二种情况：慢指针走一步，快指针走3步
//假设慢指针进入环以后，fast和slow之间的距离为X(这种情况慢指针可能走多圈，可能相遇)
//当他们同时每走一次，他们之间的距离缩小2，即X+1-3=X-2
//当他们一直走下去，X-2、X-4、X-6...
//此时如果x为偶数(2的倍数)时，就会相遇。如果X为奇数(不是2的倍数)时，当X = -1时，二者就错开了。
//下一次追赶，二者相差C-1，C为环的长度。如果C-1是奇数，那么之后永远追不上。如果是偶数，就可以追上。
//也就是，N=C-1时，每次缩小2，如果极端情况下(死循环)每次差距都是奇数，就会一直错过，导致死循环。

//3、第三种情况：慢指针走一步，快指针走4步
//假设慢指针进入环以后，fast和slow之间的距离为X(这种情况慢指针可能最多走一圈，可能相遇)
//当他们同时每走一次，他们之间的距离缩小3，即X+1-4=X-3
//当他们一直走下去，X-3、X-6、X-9...
//此时如果x为(3的倍数)时，就会相遇。如果X为(不是3的倍数)时，当X = -2时，二者就错开了。
//下一次追赶，二者相差C-1或C-2，C为环的长度。如果C-1或C-2不是3的倍数，那么之后永远追不上。如果是3的倍数，可以相遇。
//也就是，N=C-1或C-2时，每次缩小2，如果极端情况下(死循环)每次差距都不是3的倍数，就会一直错过，导致死循环。

//因此：当慢指针一次走一步，快指针一次走N步，类似的道理。

//那么如何求入口点呢？返回入口点的指针。详见作业10.

//画图，走读代码，写博客。