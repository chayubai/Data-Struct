#define _CRT_SECURE_NO_WARNINGS 1
//相交链表
//编写一个程序，找到两个单链表相交的起始结点。
//如：
//A链表：     a1-> a2->
//                      c1->c2->c3
//B链表：b1-> b2-> b3->
//在结点c1开始相交
//单链表不存在交叉，但存在相交
//当相交时，返回结点所在的值，不相交时返回null
//在返回结果后，两个链表仍须保持原有的结构
//可假定整个链表结构中没有循环
//程序尽量满足O(n)时间复杂度，且仅用O(1)内存

//输入：4->1->8
//				->4->5
//   5->0->1->8
//intersectVal = 8,listA = [4,1,8,4,5],listB = [5,0,1,8,4,5]
//skipA = 2,skipB = 3
//输出：Reference of the node with value = 8

//输入：2->6->4
//1->5
//intersectVal = 0,listA = [2,6,4],listB = [1,5]
//skipA = 2,skipB = 3
//输出：null

//1、用A链表的每一个结点的地址和B链表中的所有节点的地址比较，如果存在地址相同，则相交，第一个相交的结点
//时间复杂度为O(M*N)

//2、尾节点相同就是相交，否则就不相交，并求相交结点
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //1、判断是否相交
    //定义两个变量存放头结点，防止迭代时头结点的值改变
    struct ListNode* tailA = headA;
    struct ListNode* tailB = headB;
    //2、计算两个链表的长度
    int lenA = 1;
    int lenB = 1;
    while (tailA->next != NULL)
	{
		lenA++;
		tailA = tailA->next;
	}
	while (tailB->next != NULL)
	{
		lenB++;
		tailB = tailB->next;
	}
	if(tailA != tailB)
    {
        return NULL;
    }
    //3、计算两链表长度的差值
	int subValue = abs(lenA - lenB);
	//4、判断两个链表的长度关系：分三种情况，lenA>lenB,lenA<lenB,lenA=lenB
	//假设默认lenA>lenB
	struct ListNode* longList = headA;
	struct ListNode* shortList = headB;
	//矫正
	if (lenB > lenA)
	{
		longList = headB;
		shortList = headA;
	}
	//5、长的链表的指针先走subValue步
	while (subValue)
	{
		longList = longList->next;
		subValue--;
	}
	//6、两个指针同时走
	while (longList != shortList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}
    return longList;
}
//3、求交点：长的链表先走(长度差)步，在同时走，第一个地址相同的就是交点
//计算A和B两个链表的长度，假设分别为lA、lB(A比B短)，差值为k
//两个指针headA、headB，分别指向两个链表的头，让他们同时走，headA（短）每次走一步，headB（长）每次走k步
//或者让headB（长）先走k步，再同时走
//当他们的地址相同时，即为交点的结点的地址

/*
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	//1、计算两个链表的长度
	//定义两个变量存放头结点，防止迭代时头结点的值改变
	struct ListNode* curA = headA;
	int lA = 0;
	while (curA != NULL)
	{
		lA++;
		curA = curA->next;
	}
	struct ListNode* curB = headB;
	int lB = 0;
	while (curB != NULL)
	{
		lB++;
		curB = curB->next;
	}
	//2、判断两个链表的长度关系：分三种情况，lA>lB,lA<lB,lA=lB
	//假设默认lA>lB
	struct ListNode* longList = headA;
	struct ListNode* shortList = headB;
	if (lB > lA)
	{
		longList = headB;
		shortList = headA;
	}
	//3、计算两链表长度的差值
	int subValue = abs(lA - lB);
	//4、长的链表的指针先走subValue步
	while (subValue)
	{
		longList = longList->next;
		subValue--;
	}
	//5、两个指针同时走
	while (longList)//有一个链表走到尾
	{
		if (longList == shortList)
		{
			return longList;
		}
		longList = longList->next;
		shortList = shortList->next;
	}

	//来到这里，说明走到尾了也没有找到相交
	return NULL;
}

int main()
{
	//链表A
	struct ListNode* n1 = malloc(sizeof(struct ListNode));
	n1->val = 4;
	struct ListNode* n2 = malloc(sizeof(struct ListNode));
	n2->val = 1;

	//链表B
	struct ListNode* m1 = malloc(sizeof(struct ListNode));
	m1->val = 5;
	struct ListNode* m2 = malloc(sizeof(struct ListNode));
	m2->val = 0;
	struct ListNode* m3 = malloc(sizeof(struct ListNode));
	m3->val = 1;

	struct ListNode* N3 = malloc(sizeof(struct ListNode));
	N3->val = 8;
	struct ListNode* N4 = malloc(sizeof(struct ListNode));
	N4->val = 4;
	struct ListNode* N5 = malloc(sizeof(struct ListNode));
	N5->val = 5;
	//链表A
	n1->next = n2;
	n2->next = N3;
	N3->next = N4;
	N4->next = N5;
	N5->next = NULL;
	//链表B
	m1->next = m2;
	m2->next = m3;
	m3->next = N3;
	N3->next = N4;
	N4->next = N5;
	N5->next = NULL;
	struct ListNode* node = getIntersectionNode(n1, m1);
	printf("Reference of the node with value = %d\n",node->val);
	return 0;
}
 */
