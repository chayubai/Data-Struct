
#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);

	//β��1��2��3��4�ĸ�����
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	//�����������Լ���������ݣ����Խ����� - ����
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	//��ӡ - ���ܴ�ӡ��������Ӱ��ֵ�Ĵ�С�����Ǵ��ṹ���˷ѿռ�
	SeqListPrint(&s);

	//βɾ
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	//��ӡ
	SeqListPrint(&s);
}
void TestSeqList2()
{
    SeqList s;
	SeqListInit(&s);
    //β��1��2��3��4�ĸ�����
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
    //��ӡ
	SeqListPrint(&s);

	//ͷ��-1��-2��-3�������ݣ����Խ����� - ����
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	//��ӡ
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	//��ӡ
	SeqListPrint(&s);

}

void TestSeqList3()
{
    SeqList s;
	SeqListInit(&s);
    //β��1��2��3��4�ĸ�����
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
    //��ӡ
	SeqListPrint(&s);

	//���±�Ϊ3��λ�ò���1
	SeqListInsert(&s, 3, 1);
	//��ӡ
	SeqListPrint(&s);
	//�ڵ�����λ�ú���ɾ��һ������
	SeqListErase(&s, 3);
    //��ӡ
	SeqListPrint(&s);

	//����5��Ȼ��ɾ��5
	int pos = SeqListFind(&s, 5);
	if (pos != -1)
	{
		SeqListErase(&s, pos);
	}
	//��ӡ
	SeqListPrint(&s);

	SeqListDestory(&s);
}
int main()
{
	//TestSeqList1();
	//TestSeqList2();
	TestSeqList3();
	return 0;
}
