#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
//��ͷ��˫��ѭ������

//2���������
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if(node == NULL)
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
/*
void ListInit(ListNode** pphead)
{
	//ͨ�����洫�ĵ�ַ�ں������棬�ı亯������ı�����ֵ
	*pphead = (ListNode*)malloc(sizeof(ListNode));//����һ���ڱ�λͷ�ڵ�
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}
*/

//��������
//�����ڱ�λ���ĵ�ַ
ListNode* ListInit()
{
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));//����һ���ڱ�λͷ�ڵ�
	if (phead == NULL)
		return NULL;
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//3��β�� -��Ϊ����Ҫ�ı䴫�������ڱ�λָ�룬�ʲ���Ҫ������ָ��
//�ı�����ڱ�λ�ṹ����������ݣ�����ֱ��ʹ���ڱ�λָ���޸ġ�
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);//����Ϊ�գ����ڱ���㿪�ٿռ�ʧ�ܡ�һ�㲻��ʧ�ܣ���һ���ڱ�λ����ַ��Ϊ�գ�Ҳ����Ҫ����
	//��β
	ListNode* tail = phead->prev;
	//�����½��
	ListNode* newnode = BuyListNode(x);
	//���ӣ�phead��tail��newnode
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
	//ע�⣺(ֻ��һ���ڱ�λ���)û�н���Ƿ�����
	//ע�⣺Ҳ����Ҫ�񲻴�ͷ������һ��������û�н������
}
/*
//14��β��
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	//β�壺��posΪphead��ǰ�����x
	ListInsert(phead, x);
}
*/

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

//5��ͷ�� - ��head������룬�����ڱ�λ��һ�����ĵ�ַ��
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);//assert(���ʽ);���ʽΪ�棬��ʲô�����ɡ����ʽΪ�٣��򱨴�
	//����һ
	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;

	//��������
	/*
	//˳���ܵߵ�
	ListNode* newnode = BuyListNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
	*/
	//ע�⣺(ֻ��һ���ڱ�λ���)û�н���Ƿ�����
}
/*
//13��ͷ�� - ��head�������
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	//ͷ�壺��posΪphead->next��ǰ�����x
	ListInsert(phead->next, x);
}
*/

//6��ͷɾ - ��head����ɾ���������һ��������һ�����ĵ�ַ��
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//�ж�����Ϊ��ʱ������ɾ���Ķ���
	//����һ��
	/*
	ListNode* first = phead->next;
	phead->next = first->next;
	first->next->prev = phead;
	//ע���ͷ�λ��
	free(first);
	*/

	//��������
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
	first = NULL;//�������
	//ע�⣺(ֻ��һ���ڱ�λ���)û�н���Ƿ�����
}
/*
//11��ͷɾ - ��head����ɾ��
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//�ж�����Ϊ��ʱ������ɾ���Ķ���
	ListErase(phead->next);
}
*/

//7��βɾ -����Ҫɾ����ǰһ�����ĵ�ַ��
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//�ж�����ֻ���ڱ�λ���(Ϊ��)ʱ������ɾ���Ķ���
	//����һ��
	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
	tail = NULL;//���Բ��ÿգ���ΪtailΪ�ֲ����������˾ֲ���Χ�Զ��ͷ�

	//��������
	/*
	ListNode* tail = phead->prev;
	phead->prev = tail->prev;
	tail->prev->next = phead;
	//ע���ͷ�λ��
	free(tail);
	*/
	//ע�⣺(ֻ��һ���ڱ�λ���)û�н���Ƿ�����
}
/*
//12��βɾ
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//�ж�����ֻ���ڱ�λ���(Ϊ��)ʱ������ɾ���Ķ��ԡ�����assert(phead->prev != phead);
	ListErase(phead->prev);
}
*/

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

//9����pos��ǰ�����x������pos��ǰһ�����ĵ�ַ��
void ListInsert(ListNode* pos, LTDataType x)//ע�⣺����Ҫ������
{
	assert(pos);
	//�����Ҫ�ڿ�������룬��Ҫ���pheadָ�롣
	ListNode* posPrev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	//���ӣ�posPrev��newnode��pos
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;

	//��������
	/*
	//ע������˳��
	pos->prev->next = newnode;
	newnode->prev = pos->prev;
	newnode->next = pos;
	pos->prev = newnode;
	*/
	//ע�⣺pos���ڱ�λ��㣬�൱��β��
	//ע�⣺pos�ڵ�һ����㣬�൱��ͷ��

	//ע�⣺(ֻ��һ���ڱ�λ���)û�н���Ƿ�����
	//��Ϊphead->prev==phead;phead->next==phead;����ͷ��(phead->next)��β��(phead)�Ľ�㶼��Ϊ�գ���������Ҫ��assert(pos);
}

//10��ɾ��posλ�õ�ֵ������posǰһ���ͺ�һ�����ĵ�ַ��
void ListErase(ListNode* pos)
{//���ܶԿ�����ɾ����Ҳ���ǲ���ɾ���ڱ�λ��㡣
	assert(pos);
	//����һ��
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;

	//��������
	/*
	//ע������˳��
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	*/
	//ע�⣺pos���ڱ�λ��ǰһ����㣬�൱��βɾ
    //ע�⣺pos�ڵ�һ����㣬�൱��ͷɾ

	//ע�⣺(ֻ��һ���ڱ�λ���)û�н���Ƿ�����
	//��Ϊphead->prev==phead;phead->next==phead;����ͷɾ(phead->next)��βɾ(phead->prev)�Ľ�㶼��Ϊ�գ���������Ҫ��assert(pos);
	//��������ɾ����
}

//12���ռ����� - ���ٴ���������
//�ͷŽ��������ֵΪ���ֵ���Ҳ�����һ����㣺
//�ȱ��浱ǰ������һ����㣬�ͷŵ�ǰ��㣬�ٵ�����
/*
void ListDestory(ListNode* phead)
{
	assert(phead);
	//��һ�ַ�����
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;//����
	}
	//�������1���������ʹ�ã���ɾ��head��2������������ʹ�ã���ɾ��head
	//��������������ʹ�ã���ɾ��head
	phead->next = phead;
	phead->prev = phead;

	//�����������ʹ�ã���ɾ��head
	free(phead);
	phead = NULL;//����phead��Ҫ�ÿգ�ͨ�����Է��ֺ��������ÿ��ˣ����Ǻ�������û�����ã���Ϊhead��phead���������������Ŀռ�
    
    //�ڶ��ַ�����
    //1���������ʹ�ã���ɾ��head
	ListClear(phead);
	free(phead);//�ͷſռ䣬����ع��ڴ棬�������ĵ�ַ�Բ��䣬���ǵ�ַ��ֵΪ���ֵ���ռ仹���˲���ϵͳ
	phead = NULL;//����phead��Ҫ�ÿգ�ͨ�����Է��ֺ��������ÿ��ˣ����Ǻ�������û�����ã���Ϊhead��phead���������������Ŀռ�
    
	//���������
	//1����������������ĩβ��һ��phead = NULL;(������)
	//2������ָ�룺����ַ���ã�����������Ҫ�ı亯�������ֵ����ֵ���ã��������治�ı亯�������ֵ��
	//3��ʹ�÷���ֵ��������ͬһ���������շ���ֵ
}
*/

//�����ַ�����������ָ��
void ListDestory(ListNode** pphead)
{
    //1���������ʹ�ã���ɾ��head
	assert(*pphead);
	ListClear(*pphead);
	free(*pphead);//�ͷſռ䣬����ع��ڴ棬�������ĵ�ַ�Բ��䣬���ǵ�ַ��ֵΪ���ֵ���ռ仹���˲���ϵͳ
	//2������ָ��
	*pphead = NULL;
}

//11���������� - �������е����ݽڵ㣬����headͷ��㣬���Լ���ʹ�� - ���磺���ﳵҵ��
void ListClear(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//�������1���������ʹ�ã���ɾ��head��2������������ʹ�ã���ɾ��head
	//�ͷŵ��������ݽ�㣬��ͷ���head���ִ�ͷ˫��ѭ������ṹ
	phead->next = phead;
	phead->prev = phead;
}

//ע�⣺����ĸ��ã����Կ���Ҫ�󼫶�ʱ����д�꣬��ʱ���븴�ú���Ҫ
//���ڲ��ҽӿڣ������㷨�ǣ�1��ƽ����������AVL�����������2����ϣ�� 3��B����B+��ϵ��
//���������ӿڣ��������ŵ��㷨