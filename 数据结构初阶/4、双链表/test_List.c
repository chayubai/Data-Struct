#define _CRT_SECURE_NO_WARNINGS 1
//��ͷ ˫�� ѭ�� ����
#include "List.h"
void TestList1()
{
    //����һ��
	/*ListNode* head = NULL;
	ListInit(&head);*/

	//��������
	ListNode* head = NULL;
	head = ListInit();

    //��������ֱ���������ʼ��
	/*ListNode* head = NULL;
	head->next = head;
	head->prev = head;*/

	ListPushBack(head, 1);
	ListPushBack(head, 2);//�������ListNode*���ͣ��βν���Ҳ��ListNode*
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

	//���ٿռ�
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

    //���ң����޸�
	ListNode* pos = ListFind(head, 3);
	if(pos)
    {
        pos->data *= 10;
    }
    ListPrint(head);

    //��pos��ǰ�����30
    ListInsert(pos, 30);
	ListPrint(head);

	//ɾ��4
	pos = ListFind(head, 4);
	ListErase(pos);
	ListPrint(head);

	//��1��Ϊ10
	pos = ListFind(head, 1);
	pos->data = 10;
	ListPrint(head);

	//���ٿռ�
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

