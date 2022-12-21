#define _CRT_SECURE_NO_WARNINGS 1
//����һ�����ͷָ��ListNode* pHead����һ��ֵx��
//��дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ�������ݵ�˳��
//�����������к�������ͷָ��
//���룺4 -> 2 -> 5 -> 3 -> 6 -> 9 -> 0    x = 4
//�����2 -> 3 -> 0 -> 4 -> 5 -> 6 -> 9
//���룺1 -> 9 -> 3 -> 5 -> 6 -> 7   x = 4
//�����1 -> 3 -> 9 -> 5 -> 6 -> 7

//������������˳������ȡ��㣬С��xֵͷ�壬����xֵβ�壬
//ʹ��newhead��newtail����ͷ��β������Ҫ��ͷ����β������ͷ�����β�塣

//ʹ����������(�����ڱ�λ�Ľ��)����һ������ΪlessHead������β������С��x�Ľ��
//�ڶ�������ΪgreaterHead������β�����Ӵ��ڻ����x�Ľ��
//�������������������
//cur
//1 -> 9 -> 3 -> 5 -> 6 -> 7 -> NULL  x = 4
//��ÿ��������������ڶ�Ӧ�����µ�β��
//             lessTail
//lessHead->1->3
//                      greaterTail
//greaterHead->9->5->6->7
//lessHead->1->3->greaterHead->9->5->6->7
//׼������������ڱ�λ��㣬lessTail��greaterTail���㲻��Ҫ��β��ֱ��β�壬������ϲ���������

#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
/*
struct ListNode* partition(struct ListNode* pHead, int x)
{
	struct ListNode* lessHead, *lessTail;
	struct ListNode* greaterHead, *greaterTail;
	//���������ڱ�λ��ͷ��㣬����Ҫ�����Ƿ�Ϊ��
	lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));

	//��ʼ�����������û�б�xС��ֵ��greaterHead->next���������ֵ��������������ʱ���������������ֵ
	lessHead->next = greaterHead->next = NULL;

	//����ԭ����
	struct ListNode* cur = pHead;
	//����ȡ�½�����ӵ���Ӧ��β
	while (cur != NULL)
	{
		if (cur->val < x)
		{
			//β��
			lessTail->next = cur;
			//βָ��������
			lessTail = lessTail->next;
		}
		else
		{
            //β��
			greaterTail->next = cur;
			//βָ��������
			greaterTail = greaterTail->next;
		}
		//��������
		cur = cur->next;
	}
	//������������
	lessTail->next = greaterHead->next;//ע�⣺��������greaterHead������greaterHead->next
	//���������ڱ�λ
	struct ListNode* list = lessHead->next;
	free(lessHead);
	free(greaterTail);
	return list;//���ֱ�ӷ���lessHead->next��lessHeadû���ͷ�
}
 */

//���ϴ�������ԭ�����������ᵼ����ѭ�����絹���ڶ����������һ�����ǰ���С
//������
//                         cur
//1 -> 9 -> 3 -> 5 -> 6 -> 7 -> 2 -> NULL  x = 4
//                  lessTail
//lessHead->1->3 -> 2 -> NULL
//                      greaterTail
//greaterHead->9->5->6->7->2
//��ʱgreaterTail->nextָ��2�Ľ��
//��lessTail->next = greaterTail->next���������������ʱ�������˻�
//lessHead->1->3->2->greaterHead->9->5->6->7->2->...
//�������������ӽ����󣬽�greaterTail->next�ÿ�

struct ListNode* partition(struct ListNode* pHead, int x)
{
	struct ListNode* lessHead, * lessTail;
	struct ListNode* greaterHead, * greaterTail;
	//���������ڱ�λ��ͷ��㣬����Ҫ�����Ƿ�Ϊ��
	lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));

	//��ʼ�����������û�б�xС��ֵ����ýڵ��next�������ֵ
	lessHead->next = greaterHead->next = NULL;

	//����ԭ����
	struct ListNode* cur = pHead;
	//����ȡ�½�����ӵ���Ӧ��β
	while (cur != NULL)
	{
		if (cur->val < x)
		{
			//β��
			lessTail->next = cur;
			//βָ��������
			lessTail = lessTail->next;
		}
		else
		{
			greaterTail->next = cur;
			greaterTail = greaterTail->next;
		}
		cur = cur->next;
	}
	//������������
	lessTail->next = greaterHead->next;
	greaterTail->next = NULL;//greaterTail->next�ÿգ���ֹ�γɻ�

	//��������ʹ��Ȩ
	struct ListNode* list = lessHead->next;
	free(lessHead);
	free(greaterHead);

	return list;//���ֱ�ӷ���lessHead->next��lessHeadû���ͷ�
}

/*
int main()
{
	struct ListNode* n1 = malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode* n2 = malloc(sizeof(struct ListNode));
	n2->val = 9;
	struct ListNode* n3 = malloc(sizeof(struct ListNode));
	n3->val = 3;
	struct ListNode* n4 = malloc(sizeof(struct ListNode));
	n4->val = 5;
	struct ListNode* n5 = malloc(sizeof(struct ListNode));
	n5->val = 6;
	struct ListNode* n6 = malloc(sizeof(struct ListNode));
	n6->val = 7;
	struct ListNode* n7 = malloc(sizeof(struct ListNode));
	n7->val = 2;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = NULL;

	struct ListNode* pHead = partition(n1,4);
	while (pHead != NULL)
	{
		printf("%d -> ", pHead->val);
		pHead = pHead->next;
	}
	printf("NULL\n");
	return 0;
}
 */

//��ͼ���߶����룬д���͡�