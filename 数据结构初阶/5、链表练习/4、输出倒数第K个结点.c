#define _CRT_SECURE_NO_WARNINGS 1
//输入一个链表，输出该链表中倒数第k个结点。
//输入：[1,2,3,4,5] k = 2
//输出：4

//方法1、假设链表长度为n，遍历一次链表，计算出链表的长度，再遍历一遍到n-k
//或者先逆序链表，再遍历一遍到k
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
/*
struct ListNode* FindKthToTail(struct ListNode* pListHead,int k)
{
    struct ListNode* cur = pListHead;
    int count = 0;
	while(cur)
    {
        count++;
        cur = cur->next;
    }
    struct ListNode* pk = pListHead;
    //1 2 3 4 5 count=5  k = 2
    //1 2 3 4 5 6 count=6 k = 2
    for(int i = 0;i < count-k;i++)
    {
        pk = pk->next;
    }
    return pk;//中间结点的指针
}
 */

//方法2、只遍历链表一次。双指针 - fast先走k步，slow和fast再一起走，fast为空时，slow就是倒数第k个
//两个指针，一前一后，前一个和后一个相差k，迭代后当后一个为NULL循环结束，
//此时前一个即为倒数第k个结点的地址
//注意：当相差k-1时，结束条件是fast->next为空，slow就是倒数第k个

struct ListNode* FindKthToTail(struct ListNode* pListHead,int k)
{
    //注意：k要大于0，不能等于0

	//注意每次变量赋初值时，一定要确保变量是否为空，
	//第二行改为：struct ListNode* fast = pListHead->next;就崩了
	struct ListNode* fast = pListHead;
	struct ListNode* slow = pListHead;

    /*
    //fast先走k步
	while (k)//注意k大小不能大于链表的长度，fast提前走到了NULL
	{
		k--;
      //Leetcode或者牛客网在线OJ,当报错了。分模块逐个分析后，发现这里没有if就会有问题
	  //当链表长度小于k 或者链表为空时，如果没有判断fast是否为空，就会导致解引用NULL
		if (fast != NULL)
			fast = fast->next;
		else
			return NULL;//k大于链表的长度，或者链表为空
	}
     */

    //fast先走k步 的等价写法
	while (k--)//k--是k步，--k是k-1步
	{
		if (fast)
			fast = fast->next;
		else
			return NULL;
	}
	while (fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
/*
int main()
{
	struct ListNode* n1 = malloc(sizeof(struct ListNode));
	n1->val = 6;
	struct ListNode* n2 = malloc(sizeof(struct ListNode));
	n2->val = 1;
	struct ListNode* n3 = malloc(sizeof(struct ListNode));
	n3->val = 9;
	struct ListNode* n4 = malloc(sizeof(struct ListNode));
	n4->val = 7;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	struct ListNode* pK = FindKthToTail(n1 ,2);//通过调试确定是否正确
	printf("%d\n", pK->val);
	return 0;
	//当所有方法都发现无法确定代码哪里有问题，可以将代码分块，一个一个的测试代码是否能通过
	//从而缩小错误的范围
}
 */
