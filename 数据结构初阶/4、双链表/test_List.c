#define _CRT_SECURE_NO_WARNINGS 1
//带头 双向 循环 链表
#include "List.h"
void TestList1()
{
    //方法一：
	/*ListNode* head = NULL;
	ListInit(&head);*/

	//方法二：
	ListNode* head = NULL;
	head = ListInit();

    //方法三：直接在外面初始化
	/*ListNode* head = NULL;
	head->next = head;
	head->prev = head;*/

	ListPushBack(head, 1);
	ListPushBack(head, 2);//传入的是ListNode*类型，形参接受也用ListNode*
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPrint(head);

	ListPopBack(head);
	ListPopBack(head);
	ListPopBack(head);
	ListPrint(head);

	ListPushFront(head, -1);
	ListPushFront(head, -2);
	ListPushFront(head, -3);
	ListPrint(head);

	ListPopFront(head);
	ListPopFront(head);
	ListPrint(head);

	//销毁空间
	ListDestory(&head);
}
void TestList2()
{
	ListNode* head = NULL;
	head = ListInit();
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPrint(head);

    //查找，并修改
	ListNode* pos = ListFind(head, 3);
	if(pos)
    {
        pos->data *= 10;
    }
    ListPrint(head);

    //在pos的前面插入30
    ListInsert(pos, 30);
	ListPrint(head);

	//删除4
	pos = ListFind(head, 4);
	ListErase(pos);
	ListPrint(head);

	//将1改为10
	pos = ListFind(head, 1);
	pos->data = 10;
	ListPrint(head);

	//销毁空间
	//ListDestory(head);
	ListDestory(&head);

}
/** \brief
 int main()
{
	//TestList1();
	TestList2();
	return 0;
}
 */

