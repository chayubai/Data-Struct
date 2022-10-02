#define _CRT_SECURE_NO_WARNINGS 1
//移除链表元素
//删除链表中等于给定值val的所有结点。
//输入：1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6,val = 6
//输出：1 -> 2 - >3 -> 4 -> 5

//方法1、先写一个查找该数据的指针的接口函数，找到一个该数的指针，将其返回后，并删除，继续从头遍历找，直到全部删除
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};
/*
struct ListNode* SListFind(struct ListNode* head, int val)
{
    struct ListNode* cur = head;
    while (cur)
    {
        if (cur->val == val)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
void SListErase(struct ListNode** pphead, struct ListNode* pos)
{
    if (pos == *pphead)
    {
        //头删
        *pphead = pos->next;
        free(pos);
    }
    else
    {
        struct ListNode* prev = *pphead;
        while (prev->next != pos)//当pos第一个结点时，prev从第一个结点开始遍历直到NULL都没有找到prev->next等于pos
        {//因此pos第一个结点时，另行考虑，即头删
            prev = prev->next;
        }
        //先链接
        prev->next = pos->next;
        //再free
        free(pos);
        pos = NULL;//可以不需要此行代码
        //注意：不能先释放掉pos指向的空间，否则找不到pos->next指向的空间
    }
}
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* val_node = SListFind(head, val);

    while (val_node)
    {
        //保存下一个结点
        struct ListNode* next = val_node->next;
        //删除val所在的结点
        SListErase(&head, val_node);
        val_node = SListFind(next, val);
    }
    return head;//返回链表的头结点的指针
}
 */

//方法2、找到val所在的结点，先用prev保存前一个结点，再val结点释放掉
//     head
//prev cur
//NULL  6 -> 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6

//     head
//prev cur
//      1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6

//     prev cur
// 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6

//     prev cur
// 1 -> 2 -> 3 -> 4 -> 5 -> 6
//cur定位数字，找到后删除，再链接
//注意头结点为6是，链接prev->next = cur->next;时，prev为空，解引用程序会崩。
//此时将后一个结点作为新的头结点，释放旧的头结点的空间，让cur重新为头结点
//如果cur = head->next;则cur指向的是第三个节点，第二个结点没有比较

struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* prev = NULL;//这里赋值不能赋值为head
	struct ListNode* cur = head;
	//判断是否为空链表
	if (head == NULL)
		return head;
	//循环迭代
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			//如果删除的是头结点时，则让下一个节点成为新的头结点
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;//cur重新指向新的头结点
				//如果cur = head->next;则cur指向的是第三个节点，第二个结点没有比较
			}
			else
			{
				//除头删以外的删除
				prev->next = cur->next;//前一个结点链接下一个结点
				free(cur);//释放空间，cur为野指针，必须让cur继续往后走
				cur = prev->next;//删除结点后，让cur指向下一个结点
			}
		}
		else
		{
			//迭代，两行代码的顺序不能反
			prev = cur;
			cur = cur->next;
		}
	}
	return head;//返回链表的头结点的指针
}
//在链表中，如何测试函数的正确性 - 手动创建链表
/** \brief
 int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->val = 6;
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n2->val = 6;
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n3->val = 1;
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n4->val = 6;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    struct ListNode* newphead = removeElements(n1, 6);//通过调试确定是否正确
    while (newphead != NULL)
    {
        printf("%d -> ", newphead->val);
        newphead = newphead->next;
    }
    printf("NULL\n");
    return 0;
}
 */


