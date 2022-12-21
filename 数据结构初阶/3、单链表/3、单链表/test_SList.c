#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void TestSList1()
{
	//���ͷָ��,��һ�����Ϊ������
	SListNode* pList = NULL;//NULL = 0x00000000

	//SListPushBack(pList, 1);//��ֵ���ã�������NULL������pList�ڵ�����û�иı�

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);//��֮���&pList���ٵ���NULL
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrint(pList);

	SListPushFront(&pList, 0);
	SListPushFront(&pList, -1);
	SListPushFront(&pList, -2);
	SListPushFront(&pList, -3);
	SListPrint(pList);

	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrint(pList);
}

void TestSList2()
{
	SListNode* pList = NULL;

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	SListNode* cur = SListFind(pList, 3);
	//��Ϊ��ָ�룬���ҵ���
	if (cur)
	{
		cur->data = 30;//�޸ĵ�ǰposָ�봦��ֵ
	}
	SListPrint(pList);
}

void TestSList3()
{
	SListNode* pList = NULL;

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	//�ҵ��ˣ����ظ�ֵ��ָ��
	SListNode* pos = SListFind(pList, 3);
	//��Ϊ��ָ�룬���ҵ���
	if (pos)
	{
		SListInsertBefore(&pList,pos,30);
	}
	SListPrint(pList);

	pos = SListFind(pList, 3);
	//��Ϊ��ָ�룬���ҵ���
	if (pos)
	{
		SListErase(&pList,pos);
	}
	SListPrint(pList);
}

void TestSList4()
{
	SListNode* pList = NULL;

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	//�ҵ��ˣ����ظ�ֵ��ָ��
	SListNode* pos = SListFind(pList, 4);
	if(pos)
        		SListInsertAfter(pos, 9);//������Ϊ4�Ľ����������9
	SListPrint(pList);

	//�ҵ��ˣ����ظ�ֵ��ָ��
	pos = SListFind(pList, 3);
	if(pos)
        SListEraseAfter(pos);//ɾ������Ϊ3�Ľ��������
	SListPrint(pList);

}

void TestSList5()
{
	SListNode* pList = NULL;

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 2);
	SListPrint(pList);

	//�ҵ��ˣ����ظ�ֵ��ָ��
	SListNode* pos = SListFind(pList, 2);
	int count = 1;
	while(pos)
   	 {
       	pos->data = 10;//�޸�
       	printf("��%d��pos���:%p: %d\n",count++,pos,pos->data);
        pos = SListFind(pos->next,2);
   	 }
	SListPrint(pList);
}
/*
int main()
{
	//TestSList1();
	//TestSList2();
	//TestSList3();
    //TestSList4();
   	TestSList5();
	return 0;
}
*/
