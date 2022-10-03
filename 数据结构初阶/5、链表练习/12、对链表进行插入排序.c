#define _CRT_SECURE_NO_WARNINGS 1
//对链表进行插入排序
//插入排序算法：
//1、插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表
//2、每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入
//3、重复直到所有输入数据插入完为止。
//假设第一个元素为有序，从第二个元素开始，依次取出元素插入，如果比前面的元素小，移动元素，直到找到比它大的元素，插入其后 - 数组的插入排序

//1、遍历剩余的结点，依次取出数值小的结点，头插或者尾插到链表中

//3、交换结点的值？

//2、取头结点作为一个结点的新的链表，从剩余的节点中不断取值插入到新的链表中，
//如何选择最合适的位置插入？每次插入一个数时，都需要从前往后遍历新数组，直到找到一个合适的地方插入(头插、尾插、中间插入)
//head
//3 -> 1 -> 4 -> 2 -> NULL

//            sortHead       cur  next
//            3 -> NULL      1 -> 4 -> 2 -> NULL
//sortprev   sortcur

//            sortHead             cur  next
//            1 -> 3 -> NULL       4 -> 2 -> NULL
//             sortprev sortcur

//            sortHead                 cur  next
//            1 -> 3 -> 4 -> NULL      2 -> NULL
//      sortprev   sortcur

//            sortHead                      cur
//            1 -> 2 -> 3 -> 4 -> NULL      NULL
//      sortprev   sortcur
//注意：每次尾插需要将结点的next置空，否则会构成环
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* insertionSortList(struct ListNode* head)
{
	//当为空链表或者只有一个结点的链表时，直接返回
	if (head == NULL || head->next == NULL)
		return head;
	//取原链表头结点作为一个新的链表头结点，
	struct ListNode* sortHead = head;

	//cur是需要取下的剩余链表当前的结点，
	struct ListNode* cur = head->next;

	sortHead->next = NULL;//这一行不能放在struct ListNode* sortHead = head;后面，否则cur为NULL，无法取下一个结点

	//取结点插入
	while (cur)//当cur为NULL，则结点取完了
	{
		struct ListNode* next = cur->next;//next保存下一个结点，防止找不到下一个需要取下的结点

		//把cur插入到sortHead链表中，并保持有序
		if (cur->val <= sortHead->val)//即头插
		{
			cur->next = sortHead;
			sortHead = cur;//变成新的头
		}
		else//中间插入或者尾插
		{
            //sortprev、sortcur指针用于遍历新链表，
			//sortcur用于和cur的比较
            //sortprev用于保存前一个结点，防止链接cur的时候，无法链接
			struct ListNode* sortprev = sortHead;//struct ListNode* sortcur = sortHead;这里赋值，cur不可能插入在sortcur的前面
			struct ListNode* sortcur = sortprev->next;

			//遍历sortcur和cur比较，找到合适的地方插入
			while (sortcur)
			{
				if (cur->val <= sortcur->val)//中间插入 - 插入在sortcur前面
				{
					sortprev->next = cur;
					cur->next = sortcur;
					break;
                }
				else
				{
					//新链表的sortprev、sortcur迭代
					sortprev = sortcur;
					sortcur = sortcur->next;
				}
			}
			//来到这里可能是break，也可能是sortcur为NULL循环结束
			//尾插
			if (sortcur == NULL)
			{
				sortprev->next = cur;
				cur->next = NULL;//需要置空，否则会形成环
			}
		}
		//原链表的迭代，取下一个结点插入
		cur = next;
    }
	return sortHead;
}
/*
int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 3;
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val = 1;
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val = 4;
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val = 2;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	struct ListNode* sortHead = insertionSortList(n1);
	while (sortHead)
	{
		printf("%d -> ", sortHead->val);
		sortHead = sortHead->next;
	}
	printf("NULL");
	return 0;
}
 */

