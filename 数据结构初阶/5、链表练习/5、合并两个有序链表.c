#define _CRT_SECURE_NO_WARNINGS 1
//�ϲ�������������
//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������н����ɵġ�
//���룺1 -> 2 -> 4,1 -> 3 - > 4 - > 5
//�����1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5

//����һ������������ƴ�ӵ���һ�������ϣ��ٶ���������
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* mergeTwoLists(struct ListNode* L1, struct ListNode* L2)
{
    //������ʱ���ж��Ƿ�ΪNULL�����������NULL��������
	if (L1 == NULL)
		return L2;//L1Ϊ�գ�L2��һ��Ϊ�գ�Ϊ�ջ�Ϊ��Ҳ�Ƿ���L2
	if (L2 == NULL)
		return L1;//L2Ϊ�գ�L1��һ��Ϊ�գ�Ϊ�ջ�Ϊ��Ҳ�Ƿ���L1

    //��L2���ӵ�L1��
    struct ListNode* cur = L2;
    while(cur->next)
    {
        cur = cur->next;
    }
    cur->next = L1;

    //��������
    //...
    //�����
}

//��������ȡL1�ϵĽ�㣬��L2�Ϻ��ʵ�λ�ò���

//����������ͷ��ʼ��ȡ��������С�Ľ�㣬β�嵽��������
//1�����ڱ�λ��ͷ���
//��ȡ���������У���һ���ڵ�С�Ľ����Ϊͷ���head���ٵ���ȡ��ֵС�Ľ����β�壬��ֵ��Ľ���β��
//���ڵ������β�壬�����ҵ�β���ٲ����µĽ�㣬ȡһ�������һ��β��ʱ�临�Ӷ�ΪO(N^2)��Ч�ʺܵͣ���ʱ��Ҫһ��β������tail
//��ˣ�����ʹ��tail����β�ڵ㣬����Ҫ��β������ֱ�����ӵ�tail��
//
// L1                 L2
// 1 -> 2 -> 4        1 -> 3 - > 4 - > 5
// head
// NULL
// tail

// L1                 L2
// 1 -> 2 -> 4        1 -> 3 - > 4 - > 5
//head = 1(L1)
// 1
//tail
// L1                 L2
// 2 -> 4             1 -> 3 - > 4 - > 5

// L1                 L2
// 2 -> 4             1 -> 3 - > 4 - > 5
//head
// L1   L2
// 1 -> 1
//tail
// L1   L2
// 1 -> 1
//      tail
// L1                 L2
// 2 -> 4			  3 - > 4 - > 5

// L1                 L2
// 2 -> 4			  3 - > 4 - > 5
//head
//           L1
// 1 -> 1 -> 2
//     tail
//           L1
// 1 -> 1 -> 2
//           tail
// L1              L2
// 4			   3 -> 4 - > 5

// L1              L2
// 4			   3 -> 4 - > 5
//head
//                L2
// 1 -> 1 -> 2 -> 3
//          tail
//                L2
// 1 -> 1 -> 2 -> 3
//                tail
// L1              L2
// 4			   4 - > 5

// L1              L2
// 4			   4 - > 5
//head
//                     L1
// 1 -> 1 -> 2 -> 3 -> 4
//               tail
//                     L1
// 1 -> 1 -> 2 -> 3 -> 4
//                     tail
//����һ������ΪNULLѭ������

//                          L2
// 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5
//                    tail
//tail�����ҵ�β����β��
/*
struct ListNode* mergeTwoLists(struct ListNode* L1, struct ListNode* L2)
{
	//������ʱ���ж��Ƿ�ΪNULL�����������NULL��������
	if (L1 == NULL)
		return L2;//L1Ϊ�գ�L2��һ��Ϊ�գ�Ϊ�ջ�Ϊ��Ҳ�Ƿ���L2
	if (L2 == NULL)
		return L1;//L2Ϊ�գ�L1��һ��Ϊ�գ�Ϊ�ջ�Ϊ��Ҳ�Ƿ���L1

	struct ListNode* head = NULL,*tail = NULL;//head���ڷ��أ�tail�����ҵ�β����β��

    while(L1!=NULL && L2 !=NULL)
    {
        if(L1->val<L2->val)
        {
            //�ж�ͷ���
            if(tail == NULL)
            {
                head = tail = L1;
                //L1 = L1->next;
            }
            else
            {
                //ȡС��β��
                tail->next = L1;
                tail = tail->next;
                //L1 = L1->next;
            }
            //������L1 = L1->next;�ŵ�����
            L1 = L1->next;
        }
        else
        {
            //�ж�ͷ���
            if(tail == NULL)
            {
                head = tail = L2;
                //L2 = L2->next;
            }
            else
            {
                //ȡС��β��
                tail->next = L2;
                tail = tail->next;
                //L2 = L2->next;
            }
            //������L2 = L2->next;�ŵ�����
            L2 = L2->next;
        }
    }
    //���һ�����������ˣ���һ������Ϊ�գ�ֱ�ӽ���Ϊ�յ��������ӵ�β��
    if(L1 != NULL)
        tail->next = L1;
    if(L2 != NULL)
        tail->next = L2;

	return head;
}
*/

//�Ż�1��
/*
 struct ListNode* mergeTwoLists(struct ListNode* L1, struct ListNode* L2)
{
	//������ʱ���ж��Ƿ�ΪNULL�����������NULL��������
	if (L1 == NULL)
		return L2;//L1Ϊ�գ�L2��һ��Ϊ�գ�Ϊ�ջ�Ϊ��Ҳ�Ƿ���L2
	if (L2 == NULL)
		return L1;//L2Ϊ�գ�L1��һ��Ϊ�գ�Ϊ�ջ�Ϊ��Ҳ�Ƿ���L1

	struct ListNode* head = NULL,*tail = NULL;//head���ڷ��أ�tail�����ҵ�β����β��
	//ȷ��ͷ���
	if (L1->val < L2->val)
	{
		head = tail = L1;
		L1 = L1->next;
	}
	else
	{
		head = tail = L2;
		L2 = L2->next;
	}
    //β������
	//ȷ��ͷ����ʱ�򣬰����������󣬾�Ӧ��������һ�Σ���ѭ������ȡС��β��

	//ȡС��β�壬����һ��Ϊ�վͽ���ѭ����������������
	//�ж�����������ǽ�����������д���Ǽ���������
	while (L1 != NULL && L2 != NULL)//while (L1 && L2)
	{
		if (L1->val < L2->val)
		{
			tail->next = L1;
			L1 = L1->next;
		}
		else
		{
			tail->next = L2;
			L2 = L2->next;
		}
		tail = tail->next;//�൱�ڷֱ���L1 = L1->next;��L2 = L2->next;ǰ�����tail = L1��tail = L2
	}
	if (L1 != NULL)
		tail->next = L1;
	else
		tail->next = L2;
	return head;
}
*/

//�Ż�2�����ڱ�λ��ͷ��㣬��ʱ�����ж�ͷ��㣬ֱ��ȡС�Ľ��β��
//ע�ⷵ��ͷ���ʱ�����ص����ڱ�λ��һ�����
/*
struct ListNode* mergeTwoLists(struct ListNode* L1, struct ListNode* L2)
{
	//������ʱ���ж��Ƿ�ΪNULL�����������NULL��������
	if (L1 == NULL)
		return L2;
    if (L2 == NULL)
		return L1;

	struct ListNode* head = NULL, * tail = NULL;
	// �ڱ�λ��㣬ֱ�����ڱ�λ������β�壬����Ҫȷ��ͷ���
	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));//�ڱ�λ��ͷ���

	//β������
	while (L1 != NULL && L2 != NULL)//while (L1 && L2)
	{
		if (L1->val < L2->val)
		{
			tail->next = L1;
			L1 = L1->next;
		}
		else
		{
			tail->next = L2;
			L2 = L2->next;
		}
		tail = tail->next;
	}
	if (L1 != NULL)
		tail->next = L1;
	else
		tail->next = L2;

	struct ListNode* realHead = head->next;
	free(head);

	return realHead;//����������ͷ���
}

int main()
{
	//L1
	struct ListNode* m1 = malloc(sizeof(struct ListNode));
	m1->val = 1;
	struct ListNode* m2 = malloc(sizeof(struct ListNode));
	m2->val = 2;
	struct ListNode* m3 = malloc(sizeof(struct ListNode));
	m3->val = 4;
	m1->next = m2;
	m2->next = m3;
	m3->next = NULL;
	//L2
	struct ListNode* n1 = malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode* n2 = malloc(sizeof(struct ListNode));
	n2->val = 3;
	struct ListNode* n3 = malloc(sizeof(struct ListNode));
	n3->val = 4;
	struct ListNode* n4 = malloc(sizeof(struct ListNode));
	n4->val = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	struct ListNode* pHead = mergeTwoLists(m1 ,n1);
	while (pHead != NULL)
	{
		printf("%d -> ", pHead->val);
		pHead = pHead->next;
	}
	printf("NULL\n");
	return 0;
}
 */
