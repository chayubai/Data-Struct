#define _CRT_SECURE_NO_WARNINGS 1
//环形链表 - 求环形链表的入口点
//给定一个链表，返回链表开始入环的第一个结点，如果链表无环，则返回NULL
//为了表示给定链表中的环，我们使用整数pos来表示链表尾连接到链表中的位置（索引从0开始）
//如果pos是-1，则在该链表中没有环。
//注意：pos仅仅是用于识别环的情况，并不会作为参数传递到函数中。
//说明：不允许修改给定的链表。
//进阶：你是否可以使用O(1)空间解决此题？
//3->2->0->4
//	 <-	    ->
//       <-
//输入：head = [3,2,0,-4],pos = 1
//输出：返回索引为1的链表结点

//1、将相遇点断开，转换成相交链表问题，求两个链表相交点

//2、慢指针进入环以后，慢指针在一圈内，快指针一定会追上慢指针
//假设头结点到循环结点距离为L，环的周长为C，入口节点到相遇节点的距离为X
//则，此时，慢指针走了：L+X
//则，此时，快指针走了：L+X+n*C（n圈）,当L越大，快指针在环内转的圈越多
//由于快指针的速度是慢指针的两倍，同步走，则路程关系也为两倍
//(L+X)*2 = L+X+n*C，即L = n*C-X = (n-1)*C + C-X  相当于L = C-X
//即：一个指针head从头结点开始走了L，另一个指针meet从相遇点开始走了C-X后相遇，即在入口点相遇
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
/*
struct ListNode* detectCycle(struct ListNode* head)
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		//找到相遇点
		if (slow == fast)
		{
			//找交点：一个从头结点走，一个从相遇点走
            		struct ListNode* meet = fast;
            		while (head != meet)
            		{
                			head = head->next;
                			meet = meet->next;
            		}
            		return meet;//返回相交结点的地址
        		}
	}
    //来到这里不相交
	return NULL;
}
 */

struct ListNode* detectCycle(struct ListNode* head)
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	//找到相遇点
	while (fast != NULL && fast->next != NULL)
	{
		/*if (slow == fast)
		{
			break;
		}*/
		slow = slow->next;
		fast = fast->next->next;
		//判断不能放在上面，否则都等于head，直接跳出了循环
		if (slow == fast)
		{
			break;
		}
	}
	//来到这里，两种情况：1、相交，2、不相交

    //2、如果不相交，返回NULL
	if (fast == NULL || fast->next == NULL)
	{
		return NULL;
	}

	//1、相交，则找相交的入口点：一个从头结点走，一个从相遇点走
	struct ListNode* meet = fast;
	while (head != meet)
	{
		head = head->next;
		meet = meet->next;
	}
	return meet;//返回相交结点的地址
}

/** \brief
 int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 3;
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val = 2;
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val = 0;
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val = 4;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n2;

	struct ListNode* result = detectCycle(n1);
	printf("%d\n", result->val);
	return 0;
}
 */

