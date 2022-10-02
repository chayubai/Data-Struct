#define _CRT_SECURE_NO_WARNINGS 1
//�Ƴ�����Ԫ��
//ɾ�������е��ڸ���ֵval�����н�㡣
//���룺1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6,val = 6
//�����1 -> 2 - >3 -> 4 -> 5

//����1����дһ�����Ҹ����ݵ�ָ��Ľӿں������ҵ�һ��������ָ�룬���䷵�غ󣬲�ɾ����������ͷ�����ң�ֱ��ȫ��ɾ��
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};
/*
struct ListNode* SListFind(struct ListNode* head, int val)
{
    struct ListNode* cur = head;
    while (cur)
    {
        if (cur->val == val)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
void SListErase(struct ListNode** pphead, struct ListNode* pos)
{
    if (pos == *pphead)
    {
        //ͷɾ
        *pphead = pos->next;
        free(pos);
    }
    else
    {
        struct ListNode* prev = *pphead;
        while (prev->next != pos)//��pos��һ�����ʱ��prev�ӵ�һ����㿪ʼ����ֱ��NULL��û���ҵ�prev->next����pos
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
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* val_node = SListFind(head, val);

    while (val_node)
    {
        //������һ�����
        struct ListNode* next = val_node->next;
        //ɾ��val���ڵĽ��
        SListErase(&head, val_node);
        val_node = SListFind(next, val);
    }
    return head;//���������ͷ����ָ��
}
 */

//����2���ҵ�val���ڵĽ�㣬����prev����ǰһ����㣬��val����ͷŵ�
//     head
//prev cur
//NULL  6 -> 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6

//     head
//prev cur
//      1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6

//     prev cur
// 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6

//     prev cur
// 1 -> 2 -> 3 -> 4 -> 5 -> 6
//cur��λ���֣��ҵ���ɾ����������
//ע��ͷ���Ϊ6�ǣ�����prev->next = cur->next;ʱ��prevΪ�գ������ó�������
//��ʱ����һ�������Ϊ�µ�ͷ��㣬�ͷžɵ�ͷ���Ŀռ䣬��cur����Ϊͷ���
//���cur = head->next;��curָ����ǵ������ڵ㣬�ڶ������û�бȽ�

struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* prev = NULL;//���︳ֵ���ܸ�ֵΪhead
	struct ListNode* cur = head;
	//�ж��Ƿ�Ϊ������
	if (head == NULL)
		return head;
	//ѭ������
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			//���ɾ������ͷ���ʱ��������һ���ڵ��Ϊ�µ�ͷ���
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;//cur����ָ���µ�ͷ���
				//���cur = head->next;��curָ����ǵ������ڵ㣬�ڶ������û�бȽ�
			}
			else
			{
				//��ͷɾ�����ɾ��
				prev->next = cur->next;//ǰһ�����������һ�����
				free(cur);//�ͷſռ䣬curΪҰָ�룬������cur����������
				cur = prev->next;//ɾ��������curָ����һ�����
			}
		}
		else
		{
			//���������д����˳���ܷ�
			prev = cur;
			cur = cur->next;
		}
	}
	return head;//���������ͷ����ָ��
}
//�������У���β��Ժ�������ȷ�� - �ֶ���������
/** \brief
 int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->val = 6;
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n2->val = 6;
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n3->val = 1;
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n4->val = 6;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    struct ListNode* newphead = removeElements(n1, 6);//ͨ������ȷ���Ƿ���ȷ
    while (newphead != NULL)
    {
        printf("%d -> ", newphead->val);
        newphead = newphead->next;
    }
    printf("NULL\n");
    return 0;
}
 */


