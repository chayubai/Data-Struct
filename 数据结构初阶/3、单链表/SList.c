#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
//����ͷ ���� ��ѭ�� ����

//1��������ӡ����
void SListPrint(SListNode* phead)
{
    //assert(phead);//���ﲻ�ܼӶ��ԣ�����������ܴ�ӡ
	SListNode* cur = phead;
	while (cur != NULL)//cur���ڿգ���ʾͷ��ַû������ѭ������
	{
		printf("%d-> ", cur->data);
		//�ı�ָ�룬ָ����һ�����
		cur = cur->next;
	}
	printf("NULL\n");
}

//3�����ٽ��
SListNode* BuySListNode(SLDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	//�жϿ��ٿռ��Ƿ�ɹ�
	if (newNode == NULL)
	{
		printf("������ʧ��\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}

//��ֵ����:
//β�壺��NULL���ҵ��󣬸�ֵһ��malloc(sezof(slnode))��ַ
//void SListPushBack(SListNode* phead, SLDataType x)
//{//����ַ��Ϊֵ���ݣ�phead�ı䣬������Ӱ��pList
//	if (phead == NULL)//������һ�����ͽ����ò������ᵼ������
//	{
//		//��Ϊ������ʱ������һ���ռ䣬������ȥ
//		SListNode* phead = BuySListNode(x);
//	}
//	else
//	{
//		SListNode* tail = BuySListNode(x);
//		//����
//		//tail = newNode;
//	}
//
//}

//��ַ����
//2��β�壺��NULL���ҵ��󣬸�ֵһ��malloc(sezof(slnode))��ַ
void SListPushBack(SListNode** pphead, SLDataType x)
{//pphead��&pList��*pphead����pList

    assert(pphead);//pphead = &pListһ��������Ϊ�գ�����Ӷ�����Ҫ�Ƿ�ֹ���Դ�����
	//���ٽ��
	SListNode* newNode = BuySListNode(x);//���ﴴ���ռ䣬���������β����

	if (*pphead == NULL)//���û���ж��Ƿ�Ϊ�������ᵼ�½�����NULL������
	{
		//��Ϊ������ʱ������һ���ռ䣬������ȥ
		*pphead = newNode;
	}
	else//����Ϊ��
	{
		SListNode* tail = *pphead;//��֮���*pphead������NULL�����ǵ�һ�����ĵ�ַ

		//�ҵ���β,�ҵ�NULL
		//while (tail != NULL)//�ҵ���,��tailΪNULL��ѭ������
		//{
		//	tail = tail->next;
		//}
		//����
		//tail->next = newNode;//���Ϊ�����������½�㵽β�������ҵ���NULL����NULL�����ò�����������

		//�ҵ�β�ڵ��ָ�룬���Ϊ������һ�����ͽ��½�����ӵ�β�������ò���tail->next != NULL�ᵼ������
		while (tail->next != NULL)//�ҵ��ˣ���tail->nextΪNULL
		{
			tail = tail->next;
		}
		//����
		tail->next = newNode;//�����ǽ�newNode����NULL������������Ľ�����NULL�ٸ�ֵ
	    //ע�⣺tail�ǽ��ĵ�ַ��tail->next����һ�����ĵ�ַ��Ҳ����һ����������
	}
}
//  NULL     0x1
//*pphead     1 NULL
//  0x1
//
//
//   0x1     0x1     0x3     0x6
//*pphead     1 0x3   2 0x6   3 NULL

//6��βɾ������ǰһ������ָ�룬�����ڵ�ָ��Ŀռ��ͷŵ����ٽ�ǰһ������next��ΪNULL
//ֱ���ͷ�β�ڵ㣬����ǰһ������nextΪҰָ��
void SListPopBack(SListNode** pphead)
{
	//1��û�н��
	//2��һ�����
	//3��һ�����ϵĽ��
	if (*pphead == NULL)//û�н��
	{
		return;
	}
	else if ((*pphead)->next == NULL)//һ����㣬����һ�����ΪNULL
	{
		free(*pphead);//�ͷ�*ppheadָ��Ŀ��ٵĿռ�
		*pphead = NULL;//������
	}
	else//һ�����Ͻ��
	{
	    //����һ��
		//   0x1     0x1     0x3     0x6
		//*pphead     1 0x3   2 0x6   3 NULL

		//�ҵ�β���ٽ�ǰһ����ַ��ָ��NULL
		//ʹ��˫ָ�룬��ֹtail��ֵ������
		SListNode* prev = NULL;//tail�ƶ�ǰ����ַ��prev����
		SListNode* tail = *pphead;
		while (tail->next != NULL)//ע�⣺���Ϊ���������жϣ�ֱ��tail->next��ָ������ó�����
		{//���������п���
			prev = tail;//����tail��ǰһ�����ĵ�ַ
			tail = tail->next;
		}
		free(tail);
		tail = NULL;//���Բ�д���ֲ���������������������
		prev->next = NULL;//���Ϊһ�����ʱ��prev->next��ָ������ô������һ�����ʱ���п���

		//while (tail != NULL)
		//{
		//	prev = tail;//����tail��ǰһ�����ĵ�ַ
		//	tail = tail->next;
		//}
		//free(prev);
		//tail = NULL;//���Բ�д���ֲ���������������������
		//prev = NULL;
		//���ַ�ʽ��prevָ�����һ����㣬����û�н�ǰһ�����ĵ�ַ���ֵ��NULL

		/*
		//��������
		SListNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail = NULL;
		*/
	}
}

//4��ͷ��
void SListPushFront(SListNode** pphead, SLDataType x)
{
	// *pphead    0x1     0x1     0x3     0x6
	//  4 0x1  *pphead     1 0x3   2 0x6   3 NULL
	SListNode* newNode = BuySListNode(x);
	newNode->next = *pphead;

	//���µĽ����Ϊͷ���
	*pphead = newNode;
}

//5��ͷɾ
void SListPopFront(SListNode** pphead)
{
	//1��û�н��
	//2��һ����� + 3��һ�����ϵĽ��
	if (*pphead == NULL)//û�н��
	{
		return;
	}
	else
	{
	    /*
	    //����һ��
		//�������ͷſռ䣬������һ�����ĵ�ַ�Ͳ�֪����
		//������һ�����ĵ�ַ�����ͷŵ���һ�����Ŀռ�
		SListNode* next = (*pphead)->next;//���û���жϣ�������ָ�������

		//��������λ�ò��ܵߵ�
		free(*pphead);//�ͷſռ�
		//����һ�������Ϊ�µ�ͷ���
		*pphead = next;//������
        */

        //��������
		SListNode* tmp = *pphead;

		//��������λ�ò��ܵߵ�
		*pphead = (*pphead)->next;
		free(tmp);
	}
}

//7����������ң����ڴ˻����ϣ���Ϊ�����ݵĹ���
SListNode* SListFind(SListNode* phead, SLDataType x)
{
	//���ҵ������ݵĵ�ַ����
	SListNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	//û�ҵ�
	return NULL;
}

//8����pos��ǰ�����x
void SListInsertBefore(SListNode** pphead, SListNode* pos, SLDataType x)
{
    //�������ö���
    assert(pphead);
    assert(pos);
	if(pos == *pphead)
	{
		SListPushFront(pphead, x);//ע�⣺���ﴫ��Ĳ�����pphead����&pList
		/*
		//����
		SListNode* newNode = BuySListNode(x);
		newNode-next = *pphead;
		*pphead = newNode;
		*/
	}
	else
	{
	    //��ǰһ��������������ַ�����
	    //����һ��
	    SListNode* newNode = BuySListNode(x);
	    SListNode* prev = NULL;
		SListNode* cur = *pphead;
		while(cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
        prev->next = newNode;//��posΪ��һ�����ʱ��prev->next��ָ������ô���,������п��ǣ���ͷ��
		newNode->next = cur;//��ʱcur == pos

        /*//��������
        SListNode* newNode = BuySListNode(x);
		SListNode* prev = *pphead;
		while(prev->next != pos)//��pos��һ�����ʱ��prev�ӵ�һ����㿪ʼ����ֱ��NULL��û���ҵ�prev->next����pos
		{//���pos��һ�����ʱ�����п��ǣ���ͷ��
			prev = prev->next;
		}
        prev->next = newNode
		newNode >next = pos;
        */
	}
}

//9��ɾ��posָ��λ�õ�ֵ���ҵ�ǰһ�����ٽ��ý���nextָ��pos��next�Ľ���free��pos��ָ��ָ��Ŀռ�
void SListErase(SListNode** pphead, SListNode* pos)
{
	if(pos == *pphead)
	{
		SListPopFront(pphead);//ע�⣺���ﴫ��Ĳ�����pphead����&pList

		/*
		//����
        *pphead = pos->next;
        free(pos);
		*/
	}
	else
	{
		SListNode* prev = *pphead;
		while(prev->next != pos)//��pos��һ�����ʱ��prev�ӵ�һ����㿪ʼ����ֱ��NULL��û���ҵ�prev->next����pos
		{//���pos��һ�����ʱ�����п��ǣ���ͷɾ
			prev = prev->next;
		}
		//������
		prev->next = pos->next;
		//��free
		free(pos);
		pos = NULL;//���Բ���Ҫ���д���
		//ע�⣺�������ͷŵ�posָ��Ŀռ䣬�����Ҳ���pos->nextָ��Ŀռ�
	}
}

//��posλ��֮�����x
//����˼��Ϊʲô����posλ��֮ǰ���룿 - ��Ҫ�ҵ�ǰһ����㣬��ʱ����Ҫ����&pList
void SListInsertAfter(SListNode* pos, SLDataType x)
{	//					         newNode
	//                            0x9
	//                    pos      9 0x3
	// *pphead    0x1     0x1             0x3     0x6
	//  4 0x1  *pphead     1 0x9           2 0x6   3 NULL
	assert(pos);
	//���ٽ��
	SListNode* newNode = BuySListNode(x);

	//ע�⸳ֵ˳�򣬷�����Ұָ�룬���߿����ȱ���pos����һ����㣬������
	newNode->next = pos->next;

	pos->next = newNode;
}

//ɾ��posλ��֮���ֵ
//����˼��Ϊʲôɾ��posλ��֮ǰֵ�� - ��Ҫֱ��ǰһ����㣬��ʱ����Ҫ����&pList
void SListEraseAfter(SListNode* pos)
{
	//                    pos
	// *pphead    0x1     0x1             0x3     0x6
	//  4 0x1  *pphead     1 0x9           2 0x6   3 NULL

	// *pphead    0x1     0x1                0x6
	//  4 0x1  *pphead     1 0x6              3 NULL

	assert(pos);

	if (pos->next)
	{
		//ע�⸳ֵ˳��
		SListNode* next = pos->next;//����Ҫɾ���Ľ��ĵ�ַ����ֹҰָ��
		SListNode* nextNext = next->next;
		pos->next = nextNext;

		//ֱ�Ӻϲ�Ϊһ��pos->next = next->next;
		free(next);
		next = NULL;//���Բ���Ҫ��һ�д���
	}
}

//�ͷ����������ͷ�ÿһ���������ͷ�ǰһ�����֮ǰ������һ�����ĵ�ַ
void SListDestory(SListNode** pphead)
{
    asser(pphead);
    SListNode* cur = *pphead;
    while(cur)
    {
        SListNode* next = cur->next;
        free(cur);
        cur = next;
    }
    *pphead = NULL;
}
