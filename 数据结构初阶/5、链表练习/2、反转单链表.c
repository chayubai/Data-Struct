#define _CRT_SECURE_NO_WARNINGS 1
//��תһ��������
//���룺1 -> 2 -> 3 -> 4 -> 5 -> NULL
//�����5 -> 4 -> 3 -> 2 -> 1 -> NULL
//������õ������ߵݹ�ķ�ת�������ܷ������ַ����������⣿

//����һ����ת���� - ��ָ�뷨
// n1    n2   n3
//NULL   1 -> 2 -> 3 -> 4 -> 5 -> NULL
// n1    n2   n3
//NULL <-1    2 -> 3 -> 4 -> 5 -> NULL
//���ڽ�n2->nextָ��n1���Ҳ���n2����һ����㣬���޷���ת��һ������ָ�룬�����Ҫ��n3������һ������ָ��
//ԭ��1ָ��2��2ָ��3��n1��n2������ת��
//��ʱ1ָ��NULL����n1 = NULL��2ָ��1����n2->next = n1��Ȼ��n1��n2��n3ͬʱ������
//n2->nextָ��n1����Ҫ��ǰ��n2-next�ĵ�ַ���浽n3����head->next,�����´ε������Ҳ������������

//��ת����
//	n1<- n2   n3
//NULL <-1    2 -> 3 -> 4 -> 5 -> NULL
//		 n1   n2   n3
//NULL <-1 <- 2    3 -> 4 -> 5 -> NULL
//		      n1   n2   n3
//NULL <-1 <- 2 <- 3    4 -> 5 -> NULL
//		           n1   n2   n3
//NULL <-1 <- 2 <- 3 <- 4    5 -> NULL
//		                n1   n2   n3
//NULL <-1 <- 2 <- 3 <- 4 <- 5    NULL
//		                     n1   n2   n3
//NULL <-1 <- 2 <- 3 <- 4 <- 5    NULL
//NULL <-1 <- 2 <- 3 <- 4 <- 5
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};
/*
//��ʼ�������������̡���������
struct ListNode* reverseList(struct ListNode* head)
{
	//�жϿ�����
	if (head == NULL)//������ֻ��һ����㣬ѭ������һ��
		return head;
	//������Ϊ�գ�ֱ��n2->next����ָ������ô���
	struct ListNode* n1 = NULL,*n2 = head,*n3 = n2->next;

	while (n2)//n2Ϊ�ս���
	{
		//��ת  n2ָ��n1
		n2->next = n1;

		//���� - n1��n2��n3��������
		n1 = n2;
		n2 = n3;
		if(n3)//��n3Ϊ�գ����ٵ���������n3Ϊ�գ�n3->next�����ô���
			n3 = n3->next;
	}

	return n1;
}
*/

//��������ͷ�巨
//ע�⣺���ǿ���һ����㣬Ȼ��ͷ��һ������Ϊ���ص�ͷ�����ԭ����Ľ��
//�����µĿ�������ԭ����ļ����������ͷ�嵽���µ�ͷ�����
//   cur  next
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
//   cur  next
//   1    2 -> 3 -> 4 -> 5 -> NULL
//   cur
//   1 -> NULL
//˼·��ȡcurͷ�嵽��newheadΪͷ���������ϡ�
//����cur���ӵ��µ������ͷ����ϣ��Ҳ�����һ����㣬���޷�ͷ����һ����㣬�����Ҫ��next������һ�����
//next������һ�����ĵ�ַ����ֹcur�����ݱ�����¸����ĵ�ַ�����仯�����Ҳ�����һ�����
//��cur��Ϊ�µ�ͷ���ʱ��cur->next�ĵ�ַ�����˱仯����ʱ��Ҫ��ԭ�����µ�ͷ���ͷ����Ҳ���ԭ�����ͷ���

//�����һ����㣬�ٽ�cur���뵽ͷ�ϣ��ٸ����µ�ͷ���newhead����cur��next��������
//   cur  next
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
//   cur  next
//   1    2 -> 3 -> 4 -> 5 -> NULL
// newhead
//   cur  newhead    cur = next
//   1 -> NULL

//        cur  next
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
//        cur  next
//        2    3 -> 4 -> 5 -> NULL
//   cur  newhead
//    2 -> 1 -> NULL

//             cur  next
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
//             cur  next
//             3    4 -> 5 -> NULL
//   cur  newhead
//    3 -> 2 -> 1 -> NULL

//                  cur  next
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
//                  cur  next
//                  4    5 -> NULL
//   cur  newhead
//    4 -> 3 -> 2 -> 1 -> NULL

//                       cur  next
//   1 -> 2 -> 3 -> 4 -> 5 -> NULL
//                       cur  next
//                       5    NULL
//   cur  newhead
//    5 -> 4 -> 3 -> 2 -> 1 -> NULL
//                            cur  next
//                            NULL
//cur = NULLʱ����ѭ��ֹͣ

#if 0
struct ListNode* reverseList(struct ListNode* head)
{
    //�������������ͷ���
	struct ListNode* newhead = NULL;

	struct ListNode* cur = head;

	//�жϿ�����������Բ���Ҫ�жϣ�curΪNULL��������ѭ��
 	//if (head == NULL)
	//	return head;

	while (cur != NULL)
	{
	    //�������̣�

	    //������һ�����
		struct ListNode* next = cur->next;
		//ͷ��
		cur->next = newhead;

        //�����������ͷ���
		newhead = cur;
        //cur��next��������
		cur = next;
    }
	return newhead;
}

//������ӡ����
void SListPrint(struct ListNode* phead)
{
	struct ListNode* cur = phead;
	while (cur != NULL)//cur���ڿգ���ʾͷ��ַû������ѭ������
	{
		printf("%d-> ", cur->val);
		//�ı�ָ�룬ָ����һ�����
		cur = cur->next;
	}
	printf("NULL\n");
}


int main()
{
    /** //���ֲ����Ǵ���ģ���Ϊָ��δ��ʼ���������÷Ƿ�����
    struct ListNode* n1 ,*n2,*n3,*n4,*n5;
	n1->next = n2;
	n1->val = 1;

	n2->next = n3;
	n2->val = 2;

	n3->next = n4;
	n3->val = 3;

	n4->next = n5;
	n4->val = 4;

	n5->next = NULL;
	n5->val = 5;
     */

    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val = 2;
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val = 3;
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val = 4;
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n5->val = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	SListPrint(n1);

	struct ListNode* newphead = reverseList(n1);
	SListPrint(newphead);
	return 0;
}
#endif
