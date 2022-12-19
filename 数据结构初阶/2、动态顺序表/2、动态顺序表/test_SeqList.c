#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
//дһ��ģ�����һ��ģ��
//����ͷβ����ɾ��
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
	//SeqListPopBack(&s);
	//���ԣ�����sizeԽ�磬Ϊ-1��ps[size] = x�Ƿ�����
	
	//��ӡ
	SeqListPrint(&s);

	SeqListDestory(&s);
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

	SeqListDestory(&s);
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
	//ɾ���±�Ϊ3λ�õ�����
	SeqListErase(&s, 3);
	//��ӡ
	SeqListPrint(&s);

	//����5��Ȼ��ɾ��5������ж��5������ʹ��ѭ��ɾ��
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

/*
void Test()
{
	SeqList s;
	SeqListInit(&s);
	//����SeqListInit(s)
	//�ڰ��У�F9��ϵ㣬F5ֱ�����е��ϵ㴦��F11���뺯���ڲ�
	//��������ܽ��뺯����ǿ�ƽ��룬�����ں����ڲ���һ���ϵ㣬�ٽ���

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
	//��������ܽ��뺯����ǿ�ƽ��룬�����ں����ڲ���һ���ϵ㣬�ٽ���
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
	//����SeqListPushFront()
	//�ڰ��У�F9��ϵ㣬F5ֱ�����е��ϵ㴦��F11���뺯���ڲ�
	//��������ܽ��뺯����ǿ�ƽ��룬�����ں����ڲ���һ���ϵ㣬�ٽ���
	//����size > capacity��Խ�������

	//ͷɾ��������
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	//��ӡ
	SeqListPrint(&s);

	//���±�Ϊ3λ�ò���1
	SeqListInsert(&s, 3, 1);
	//ɾ���±�Ϊ3λ�õ�����
	SeqListErase(&s, 3);

	//����5���±꣬Ȼ��ɾ��5
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
	Test();
	return 0;
}
*/

//----------------------------------------------------------------------------

//�����Ȳ�Ҫд�˵���һ����д�˵����������ÿ���ӿڡ������нӿڶ�ʵ�����Ҳ���û�������д�˵���
/*
void menu()
{
	printf("***************************************\n");
	printf("****** 1��β������   2��βɾ���� ******\n");
	printf("****** 3��ͷ������   4��ͷɾ���� ******\n");
	printf("****** 5����ӡ����  -1���˳�     ******\n");
	printf("***************************************\n");
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
		scanf("%d",&option);//�Ż������ηǷ�����
		switch(option)
		{
			case 1:
				printf("���������ݣ���-1������");
				do
				{
					scanf("%d",&x);//ע�⣺���������һ��ֻ�ܽ���һ�����ݣ�����-1��������
					if(x != -1)
					{
						SeqListPushBack(&s,x);//��ȱ�� ���ܲ���-1
					}
				}while(x != -1);
				break;
			case 2:
				SeqListPopBack(&s);
				break;
			case 3:
				printf("���������ݣ���-1������");
				scanf("%d",&x);
				while(x != -1)
				{
					if(x != -1)
					{
						SeqListPushBack(&s,x);//��ȱ�� ���ܲ���-1
						scanf("%d",&x);//ע�⣺���������һ��ֻ�ܽ���һ�����ݣ�����-1��������
					}
				}
				break;
			case 4:
				SeqListPopFront(&s);
				break;
			case 5:
				SeqListPrint(&s);
				break;
		}
	}
	SeqListDestory(&s);
	return 0;
}
*/