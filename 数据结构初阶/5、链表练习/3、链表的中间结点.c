#define _CRT_SECURE_NO_WARNINGS 1
//������м���
//����һ��ͷ���Ϊhead�ķǿյ���������������м����ֵ��
//����������м��㣬�򷵻صڶ����м����ֵ��
//���룺[1,2,3,4,5]
//������������м����ֵ��3

//����1���������������ܵĽ�����������2����ӡ�м������
//ʱ�临�Ӷ�Ϊ��O(N)
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* cur = head;
    int count = 0;
	while(cur)
    {
        count++;
        cur = cur->next;
    }
    struct ListNode* middlenode = head;
    //1 2 3 4 5 count=5
    //1 2 3 4 5 6 count=6
    for(int i = 0;i < count/2;i++)
    {
        middlenode = middlenode->next;
    }
	return middlenode;//�м����ָ��
}

//����2��ֻ��������һ�Ρ�����ָ��
//����ָ��ֱ�ָ���һ����㣬һ��ָ��Ϊ��ָ�룬һ��ָ��Ϊ��ָ��
//��ָ��һ����һ������ָ��һ����������
//���������ʱ������ָ���ߵ�βʱ����ָ���ߵ��м䴦(fast->next == NULL)
//ż�������ʱ������ָ���ߵ�NULLʱ����ָ���ߵ��ڶ����м��㴦(fast == NULL)

/*
struct ListNode* middleNode(struct ListNode* head)
{
	//ע��ÿ�α�������ֵʱ��һ��Ҫȷ�������Ƿ�Ϊ�գ�
	//һǰһ������ָ��ĸ�ֵ�����磺headΪ�գ�struct ListNode* fast = head->next;�ͱ���

	struct ListNode* slow = head;
	struct ListNode* fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		//��ż�������ʱ��fast/slowΪ�գ�ѭ������
		//�����������ʱ��fast->nextΪ�գ�ѭ������
		//��fast != NULL && fast->next != NULL����Ϊ�գ�ѭ������
	}
	return slow;//�м����ָ��
}

int main()
{
	struct ListNode* n1 = malloc(sizeof(struct ListNode));
	n1->val = 6;
	struct ListNode* n2 = malloc(sizeof(struct ListNode));
	n2->val = 3;
	struct ListNode* n3 = malloc(sizeof(struct ListNode));
	n3->val = 2;
	struct ListNode* n4 = malloc(sizeof(struct ListNode));
	n4->val = 4;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	struct ListNode* middlepNode = middleNode(n1);//ͨ������ȷ���Ƿ���ȷ
	printf("%d\n", middlepNode->val);
	return 0;
}
 */
