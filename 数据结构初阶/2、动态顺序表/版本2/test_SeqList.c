
#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
//дһ������һ��
//����ͷβ����ɾ��
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	//����SeqListInit(s)
	//�ڰ��У�F9��ϵ㣬F5ֱ�����е��ϵ㴦��F11���뺯���ڲ�
	//��������ܽ��뺯����ǿ�ƽ��룬�����ں����ڲ���һ���ϵ㣬�ڽ���

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
	//����SeqListPushBack()
	//�ڰ��У�F9��ϵ㣬F5ֱ�����е��ϵ㴦��F11���뺯���ڲ�
	//��������ܽ��뺯����ǿ�ƽ��룬�����ں����ڲ���һ���ϵ㣬�ڽ���
	//����size > capacity��Խ�������
	
	//βɾ��������
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	//��ӡ
	SeqListPrint(&s);

	//ͷ��-1��-2��-3�������ݣ����Խ����� - ����
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	//��ӡ
	SeqListPrint(&s);
	//����SeqListPushBack()
	//�ڰ��У�F9��ϵ㣬F5ֱ�����е��ϵ㴦��F11���뺯���ڲ�
	//��������ܽ��뺯����ǿ�ƽ��룬�����ں����ڲ���һ���ϵ㣬�ڽ���
	//����size > capacity��Խ�������

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	//��ӡ
	SeqListPrint(&s);

	//�ڵ�����λ�ú������1
	SeqListInsert(&s, 3, 1);
	//�ڵ�����λ�ú���ɾ��һ������
	SeqListErase(&s, 3);
	
	SeqListDestory(&s);

	//����5��Ȼ��ɾ��5
	int pos = SeqListFind(&s, 5);
	if (pos != -1)
	{
		SeqListErase(&s, pos);
	}
	//��ӡ
	SeqListPrint(&s);
}

//�����Ȳ�Ҫд�˵����������ÿ���ӿ�
void menu()
{
	printf("***************************************\n");
	printf("******1��β������  2��βɾ����******\n");
	printf("******3��ͷ������  4��ͷɾ����******\n");
	printf("******5����ӡ���� -1���˳�      ******\n");
	printf("**************************************\n");
	printf("��ѡ����Ĳ�����");
}

int main()
{
	SeqList s;
	SeqListInit(&s);
	int option = 0;
	int x = 0;
	while(option != -1)
	{
		menu();
		scanf("%d\n",&option);
		switch(option)
		{
			case 1:
				printf("���������ݣ���-1������");
				do
				{
					scanf("%d",&x);
					if(x! = -1)
					{
						SeqListPushBack(&s,x);
					}
				}while(x != -1);
				break;
			case 2:
				break;
		}
	}
	TestSeqList1();
	return 0;
}