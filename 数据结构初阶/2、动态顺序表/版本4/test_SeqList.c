
#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
//дһ������һ��
//����ͷβ����ɾ��
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);

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

	//ͷɾ��������
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	//��ӡ
	SeqListPrint(&s);

	//���±�Ϊ3λ�ò���1
	SeqListInsert(&s, 2, 5);
	//��ӡ
	SeqListPrint(&s);

	//���±�Ϊ0λ��ɾ��һ������
	SeqListErase(&s, 0);
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

//�����Ȳ�Ҫд�˵����������ÿ���ӿ�
void menu()
{
	printf("***************************************\n");
	printf("*******1��β������  2��βɾ����********\n");
	printf("*******3��ͷ������  4��ͷɾ����********\n");
	printf("*******5����ӡ����  -1���˳�   ********\n");
	printf("***************************************\n");
	printf("��ѡ����Ĳ�����");
}

void menuTest()
{
    SeqList s;
	SeqListInit(&s);

	int option = 0;
	int x = 0;
	while(option != -1)
	{
		menu();
		scanf("%d",&option);
		switch(option)
		{
			case 1: //β��
				printf("���������ݣ���-1������");
				do
				{
					scanf("%d",&x);
					if(x != -1)
					{
						SeqListPushBack(&s,x);
					}
				}while(x != -1);
				break;
			case 2: //βɾ
                SeqListPopBack(&s);
				break;
            case 3: //ͷ��
                printf("���������ݣ���-1������");
				do
				{
					scanf("%d",&x);
					if(x != -1)
					{
						SeqListPushFront(&s, x);
					}
				}while(x != -1);
                break;
            case 4: //ͷɾ
                SeqListPopFront(&s);
                break;
            case 5: //��ӡ
                SeqListPrint(&s);
                break;
            case -1://�˳�
                printf("�����˳�...\n");
                SeqListDestory(&s);
                break;
            default:
                printf("����������������룡\n");
                break;
		}
	}
}

int main()
{
	//TestSeqList1();
	menuTest();
	return 0;
}
