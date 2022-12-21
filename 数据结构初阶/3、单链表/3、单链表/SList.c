#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
//����ͷ ���� ��ѭ�� ����

//1��������ӡ����
void SListPrint(SListNode* phead)
{
    //assert(phead);//���ﲻ�ܼӶ��ԣ�����������ܴ�ӡ
	SListNode* cur = phead;
	while (cur != NULL)//cur���ڿգ���ʾͷ��ַû������ѭ������
	{//ѭ��д���Ǽ���������������ǽ���������
		printf("%d-> ", cur->data);
		//�ı�ָ�룬ָ����һ�����
		cur = cur->next;//cur->next���ǵ�ǰ����ָ�������ݣ�Ҳ����һ�����
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
	//�ѣ�һ��2G��ջ��8M��
}

//2��β�壺�ҵ�β�ڵ��ָ�룬�ҵ��󣬸�ֵһ��malloc(sizeof(slnode))��ַ
//��ֵ����:
/*
void SListPushBack(SListNode* phead, SLDataType x)
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

	SListNode* tail = phead;
	while (tail != NULL)//�ҵ���,��tailΪNULL��ѭ������
	{
		tail = tail->next;
	}
	//����
	tail->next = newNode;
	//˼�����ó����Ƿ�������
}
void SListPushBack(SListNode* phead, SLDataType x)
{//����ַ��Ϊֵ���ݣ�phead�ı䣬������Ӱ��pList
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	//�жϿ��ٿռ��Ƿ�ɹ�
	if (newNode == NULL)
	{
		printf("������ʧ��\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;

	if (phead == NULL)//������һ�����ͽ����ò������ᵼ������
	{
		//��Ϊ������ʱ������һ���ռ䣬������ȥ
		SListNode* phead = newNode;
	}
	else
	{
		SListNode* tail = phead;
		//�ҵ�β�ڵ��ָ�롣
		while (tail->next != NULL)//���û���ж�pheadΪNULL,�������ֱ�ӽ����ô���
		{
			tail = tail->next;
		}
		//����
		tail->next = newNode;
	}
	//˼�����ó����Ƿ�������
}
*/
//��ַ����
void SListPushBack(SListNode** pphead, SLDataType x)
{//pphead��&pList��*pphead����pList
    assert(pphead);//pphead = &pListһ��������Ϊ�գ�����Ӷ�����Ҫ�Ƿ�ֹ���Դ���pList������󣬿��ٶ�λ����
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
		//tail->next = newNode;//���Ϊ������ֱ�������½�㵽β��������⣬�����ҵ���β��tailΪNULL����NULL�����ò�����������

		//�ҵ�β�ڵ��ָ�롣���Ϊ������һ�����ͽ��½�����ӵ�β�������ò���tail->next != NULL�ᵼ�����⡣
		//���ԣ���Ҫ�Կ���������ж�
		while (tail->next != NULL)//�ҵ��ˣ���tail->nextΪNULL
		{
			tail = tail->next;
		}
		//����
		tail->next = newNode;//�����ǽ�newNode����NULL������������Ľ�����NULL�ٸ�ֵ
		//ע�⣺tail�ǽ��ĵ�ַ��tail->next����һ�����ĵ�ַ��Ҳ����һ�����ĵ�ַ������
		
		/*
		SLDataType* prev = NULL;
		while (tail != NULL)//�ҵ��ˣ���tail->nextΪNULL
		{
			prev = tail;
			tail = tail->next;
		}
		tail = prev;
		tail->next = newNode;
		*/
	}
}
//ע�⣺��ַ��ԭ���ǣ�Ϊ�˽�������һ���������⡣����֮��Ľ����Բ�������ָ�룬��Ϊ����ֱ��ͨ���ṹ��ָ��ı�ṹ������ݡ�
//�ʣ�������һ����ͷ�ڵ�������Ϳ��Բ�Ҫ������ָ�롣
//ע�⣺Ӱ���һ����㣬����Ҫ������ָ�롣β���һ�������Ҫ������ָ�롣β���2�����Ժ�Ľ�㲻��Ҫ������ָ�롣
//���ԣ�Ϊ�����һ�£�����β�廹��Ҫ������ָ�롣
//  NULL     0x1
//*pphead     1 NULL
//  0x1
//
//   0x1     0x1     0x3     0x6
//*pphead     1 0x3   2 0x6   3 NULL

//6��βɾ������ǰһ������ָ�룬�����ڵ�ָ��Ŀռ��ͷŵ����ٽ�ǰһ������next��ΪNULL
//ֱ���ͷ�β�ڵ㣬����ǰһ������nextΪҰָ��
/*
void SListPopBack(SListNode** pphead)
{
	//�ҵ�β�ڵ��ָ�룬�ٽ�ǰһ����ַ��ָ��NULL
	//ʹ��˫ָ�룬��ֹtail��ֵ������
	SListNode* prev = NULL;//tail�ƶ�ǰ����ַ��prev����
	SListNode* tail = *pphead;
	while (tail->next != NULL)//ע�⣺���Ϊ���������жϣ�ֱ��tail->next��ָ������ó�����
	{//���������п���
		prev = tail;//����tail��ǰһ�����ĵ�ַ
		tail = tail->next;
	}
	free(tail);
	//tail = NULL;//���Բ�д���ֲ���������������������
	//��Ȼtail��NULL�ˣ�ǰһ������next����tail�����ǵ�tail���ٺ�tailΪҰָ�롣ǰһ������next����һ��Ұָ�롣
	prev->next = NULL;//ע�⣺���Ϊһ�����ʱ��prev->next��ָ������ô������һ�����ʱ���п���

	//����һ������ʱ������л���û��tail = NULL����ʹ�����ͷ��ˣ�plistҲ���Ϊ��Ұָ��

	//˼�����ó����Ƿ�������
}
*/
//ע�⣺Ӱ���һ����㣬����Ҫ������ָ�롣βɾ��һ�������Ҫ������ָ�롣βɾ��2�����Ժ�Ľ�㲻��Ҫ������ָ�롣
//���ԣ�Ϊ�����һ�£�����βɾ����Ҫ������ָ�롣
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
		prev->next = NULL;//ע�⣺���Ϊһ�����ʱ��prev->next��ָ������ô������һ�����ʱ���п���

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
		while (tail->next->next != NULL)//���ַ�ʽҲҪ���������
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
		*/
	}
}

//4��ͷ��
void SListPushFront(SListNode** pphead, SLDataType x)
{
	//û�н���ͷ����ж������ͷ������������
	// *pphead    0x1     0x1     0x3     0x6
	//  4 0x1  *pphead     1 0x3   2 0x6   3 NULL
	SListNode* newNode = BuySListNode(x);
	newNode->next = *pphead;//��һ������Ҫ����ָ�룬�����βε���ƣ�������Ҫ��*pphead

	//���µĽ����Ϊͷ���
	*pphead = newNode;//��һ����Ҫ����ָ�룬����ʵ�ε�ͷ�ڵ�
}
//ע�⣺Ӱ���һ����㣬����Ҫ������ָ�롣
//ͷ��һ��Ҫ������ָ�롣

//5��ͷɾ
/*
void SListPopFront(SListNode** pphead)
{
	//�������ͷſռ䣬������һ�����ĵ�ַ�Ͳ�֪����
	//������һ�����ĵ�ַ�����ͷŵ���һ�����Ŀռ�
	SListNode* next = (*pphead)->next;//ע�⣺���û���жϣ�������ָ�������

	//��������λ�ò��ܵߵ�
	free(*pphead);//�ͷſռ�
	//����һ�������Ϊ�µ�ͷ���
	*pphead = next;//������
	
	//˼�����ó����Ƿ�������
}
*/
//ע�⣺Ӱ���һ����㣬����Ҫ������ָ�롣ͷɾ��Ҫ������ָ�롣
//ͷɾһ��Ҫ������ָ�롣
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
		SListNode* next = (*pphead)->next;//ע�⣺���û���жϣ�������ָ�������

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

//8����pos����ǰ�����һ�����x������β�壬��ʱ�临�Ӷ�O(N)
//�ҵ�pos��ǰһ��λ��
/*
void SListInsertBefore(SListNode** pphead, SListNode* pos, SLDataType x)
{
	SListNode* newNode = BuySListNode(x);
	SListNode* prev = *pphead;//��ֵΪ��һ�����
	while(prev->next != pos)//��pos��һ�����ʱ(���뵽��һ�����ǰ)��prev�ӵ�һ����㿪ʼ����ֱ��NULL��û���ҵ�prev->next����pos
	{//���pos��һ�����ʱ�����п��ǣ���ͷ��
		prev = prev->next;
	}
	prev->next = newNode
	newNode->next = pos;

	//˼������������Ƿ�������
}
*/
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
		newNode->next = *pphead;
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
        prev->next = newNode;//ע�⣺��posΪ��һ�����ʱ��prev->next��ָ������ô���,������п��ǣ���ͷ��
		newNode->next = cur;//��ʱcur == pos

        /*
		//��������
        SListNode* newNode = BuySListNode(x);
		SListNode* prev = *pphead;//��ֵΪ��һ�����
		while(prev->next != pos)//��pos��һ�����ʱ(���뵽��һ�����ǰ)��prev�ӵ�һ����㿪ʼ����ֱ��NULL��û���ҵ�prev->next����pos
		{//���pos��һ�����ʱ�����п��ǣ���ͷ��
			prev = prev->next;
		}
        prev->next = newNode
		newNode->next = pos;
        */
	}
}

//9��ɾ��posָ��λ�õ�ֵ���ҵ�ǰһ�����ٽ��ý���nextָ��pos��next�Ľ���free��pos��ָ��ָ��Ŀռ�
//����βɾ��ʱ�临�Ӷ�O(N)
/*
void SListErase(SListNode** pphead, SListNode* pos)
{
	SListNode* prev = *pphead;
	while (prev->next != pos)//ע�⣺��pos��һ�����ʱ(ɾ����һ�����)��prev�ӵ�һ����㿪ʼ����ֱ��NULL��û���ҵ�prev->next����pos
	{//���pos��һ�����ʱ�����п��ǣ���ͷɾ
		prev = prev->next;
	}
	//������
	prev->next = pos->next;
	//��free
	free(pos);
	pos = NULL;//���Բ���Ҫ���д���
	//ע�⣺�������ͷŵ�posָ��Ŀռ䣬�����Ҳ���pos->nextָ��Ŀռ�

	//˼������������Ƿ�������
}
*/
void SListErase(SListNode** pphead, SListNode* pos)
{
	assert(pos);
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
		while(prev->next != pos)//ע�⣺��pos��һ�����ʱɾ����һ����㣬prev�ӵ�һ����㿪ʼ����ֱ��NULL��û���ҵ�prev->next����pos
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

//��posָ��λ��֮�����x��ʱ�临�Ӷ�O(1)
//ע�⣺����ı�ͷ��㡣
//����˼��Ϊʲô����posλ��֮ǰ���룿 - ��Ϊ��Ҫ�ҵ�ǰһ����㣬��ʱ����Ч����ʧ
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

//ɾ��posָ��λ��֮���ֵ��ʱ�临�Ӷ�O(1)
//����˼��Ϊʲô��ɾ��posλ��֮ǰֵ�� - ��Ϊ��Ҫ�ҵ�ǰһ����㣬��ʱ����Ч����ʧ
void SListEraseAfter(SListNode* pos)
{
	//                    pos
	// *pphead    0x1     0x1       0x9     0x6
	//  4 0x1  *pphead     1 0x9     2 0x6   3 NULL

	// *pphead    0x1     0x1       0x6
	//  4 0x1  *pphead     1 0x6     3 NULL

	assert(pos);

	if (pos->next)//pos�ĺ���Ϊ�գ���ɾ��
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