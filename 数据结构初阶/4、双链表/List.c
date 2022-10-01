#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
//��ͷ��˫��ѭ������

//2���������
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if(node)
        return NULL;
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//1����ʼ���ڱ�λ���
//��ֵ���ã�����ı������ֵ
//void ListInit(ListNode* phead)
//{
//	phead = BuyListNode(0);
//	phead->next = phead;
//	phead->prev = phead;
//}

//����һ��
//��ַ����
//void ListInit(ListNode** pphead)
//{
//	//ͨ�����洫�ĵ�ַ�ں������棬�ı亯������ı�����ֵ
//	*pphead = BuyListNode(0);
//	(*pphead)->next = *pphead;
//	(*pphead)->prev = *pphead;
//}

//��������
//�����ڱ�λ���ĵ�ַ
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//3��β�� -����Ҫ�ı䴫�������ڱ�λָ�룬������Ҫ������ָ��
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);//����Ϊ�գ��������ڱ���㿪�ٿռ�ʧ�ܡ�һ�㲻��ʧ�ܣ���һ���ڱ�λ����ַ��Ϊ�գ�Ҳ����Ҫ����
	//��β
	ListNode* tail = phead->prev;
	//�����½��
	ListNode* newnode = BuyListNode(x);
	//���ӣ�phead->prev��newnode���ӡ�newnode-next��phead���ӡ�tail-next��newnode����
	//newnode->prev��tail����
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

	//ע�⣺Ҳ����Ҫ�񲻴�ͷ������һ��������û�н������
}
////14��β��
//void ListPushBack(ListNode* phead, LTDataType x)
//{
//	//β�壺��posΪphead��ǰ�����x
//	ListInsert(phead, x);
//}

//4����ӡ���ӵ�һ����㣨���ڱ�λ����ʼ���ҵ��ڱ�λ���ֹͣ��ӡ
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//5��ͷ�� - ��head�������
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	//����һ
	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
	//ע���ж�û�н���Ƿ�����

	//��������
	/*//˳���ܵߵ�
	ListNode* newnode = BuyListNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
	*/
}
////13��ͷ�� - ��head�������
//void ListPushFront(ListNode* phead, LTDataType x)
//{
//	//ͷ�壺��posΪphead->next��ǰ�����x
//	ListInsert(phead->next, x);
//}

//6��ͷɾ - ��head����ɾ��
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//�ж�����Ϊ��ʱ������ɾ���Ķ���
	//����һ��
	/*//ע������˳��
	ListNode* first = phead->next;
	phead->next = first->next;
	first->next->prev = phead;
	free(first);
	*/

	//��������
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
	first = NULL;//�������
	//ע���ж�û�н���Ƿ�����
}
////11��ͷɾ - ��head����ɾ��
//void ListPopFront(ListNode* phead)
//{
//	ListErase(phead->next);
//}

//7��βɾ
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//�ж�����Ϊ��ʱ������ɾ���Ķ���
	//����һ��
	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
	tail = NULL;//���Բ��ÿգ���ΪtailΪ�ֲ����������˾ֲ���Χ�Զ��ͷ�

	//��������
	/*//ע������˳��
	ListNode* tail = phead->prev;
	phead->prev = tail->prev;
	tail->prev->next = phead;
	free(tail);
	*/
	//ע�⣺û�н���Ƿ�����
}
////12��βɾ
//void ListPopBack(ListNode* phead)
//{
//	ListErase(phead->prev);
//}

//8������ - �����ҵ�������Ӧ���ĵ�ַ��Ҳ���޸�
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	//�ߵ�����û���ҵ�
	return NULL;
}

//�������
//pos_prev	  posPrev
//���������͡���Ŀ����Դ�ļ������
//list_print  ListPrint

//9����pos��ǰ�����x
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	//���ӣ�posPrev��newnode��pos
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;

	//��������
	/*//ע������˳��
	pos->prev->next = newnode;
	newnode->prev = pos->prev;
	newnode->next = pos;
	pos->prev = newnode;
	*/
	//ע�⣺pos�ڵ�һ����㣬�൱��β��
	//ע�⣺pos�����һ����㣬�൱��ͷ��
}

//10��ɾ��posλ�õ�ֵ
void ListErase(ListNode* pos)
{
	assert(pos);
	//����һ��
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;

	//��������
	/*//ע������˳��
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	*/
	//ע�⣺pos�����һ����㣬�൱��βɾ
    //ע�⣺pos�ڵ�һ����㣬�൱��ͷɾ
}

//12���ռ����� - ���ٴ���������
//�ͷŽ��������ֵΪ���ֵ���Ҳ�����һ����㣬�����ַ���ɾ����
//1��������һ�����ͷŵ�ǰ���
//2�����浱ǰ��㣬�������ߣ����ͷŵ�ǰ���
//void ListDestory(ListNode* phead)
//{
//	assert(phead);
	/*
	//�ڶ��ַ�����
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//�������1���������ʹ�ã���ɾ��head��2������������ʹ�ã���ɾ��head
	//2������������ʹ�ã���ɾ��head
	phead->next = phead;
	phead->prev = phead;

	//1���������ʹ�ã���ɾ��head
	free(phead);
	phead = NULL;//����phead��Ҫ�ÿգ�ͨ�����Է��ֺ��������ÿ��ˣ����Ǻ�������û�����ã���Ϊhead��phead���������������Ŀռ�
	*/

    /*
    //�����ַ�����
    //1���������ʹ�ã���ɾ��head
	ListClear(phead);//���д����൱���������д���
	free(phead);//�ͷſռ䣬����ع��ڴ棬�������ĵ�ַ�Բ��䣬���ǵ�ַ��ֵΪ���ֵ���ռ仹���˲���ϵͳ
	phead = NULL;//����phead��Ҫ�ÿգ�ͨ�����Է��ֺ��������ÿ��ˣ����Ǻ�������û�����ã���Ϊhead��phead���������������Ŀռ�
    */
//	//���������
//	//1����������������ĩβ��һ��phead = NULL;(������)
//	//2������ָ�룺����ַ���ã�����������Ҫ�ı亯�������ֵ����ֵ���ã��������治�ı亯�������ֵ��
//  	//3��ʹ�÷���ֵ��������ͬһ���������շ���ֵ
//}

//�����ַ�����������ָ��
void ListDestory(ListNode** pphead)
{
    //1���������ʹ�ã���ɾ��head
	assert(*pphead);
	ListClear(*pphead);//���д����൱���������д���
	free(*pphead);//�ͷſռ䣬����ع��ڴ棬�������ĵ�ַ�Բ��䣬���ǵ�ַ��ֵΪ���ֵ���ռ仹���˲���ϵͳ
	//2������ָ��
	*pphead = NULL;
}

//11���������� - �������е����ݽڵ㣬����headͷ��㣬���Լ���ʹ�� - ���磺���ﳵҵ��
void ListClear(ListNode* phead)
{
	assert(phead);
	//�ڶ��ַ�����
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//�������1���������ʹ�ã���ɾ��head��2������������ʹ�ã���ɾ��head
	//2���ͷŵ��������ݽ�㣬��ͷ���head���ִ�ͷ˫��ѭ������ṹ
	phead->next = phead;
	phead->prev = phead;
}

//ע�⣺����ĸ��ã����Կ���Ҫ�󼫶�ʱ����д�꣬��ʱ���븴�ú���Ҫ
//���ڲ��ҽӿڣ������㷨�ǣ�1��ƽ����������AVL�����������2����ϣ�� 3��B����B+��ϵ��
//���������ӿڣ��������ŵ��㷨
