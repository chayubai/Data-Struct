#define _CRT_SECURE_NO_WARNINGS 1

//���ƴ����ָ�������
//����һ������ÿ��������һ���������ӵ����ָ�룬��ָ�����ָ�������е��������ս��
//Ҫ�󷵻�����������ȿ�����
//������һ����n�������ɵ���������ʾ����/����е�����ÿ�������һ��[val,random_index]��ʾ��
//val��һ����ʾNode.val������
//random_index�����ָ��ָ��Ľ����������Χ��0��n-1���������ָ���κν�㣬��Ϊnull
//�磺7(next->13,random->NULL) -> 13(next->11,random->7) -> 11(next->10,random->1) ->
//10(next->1,random->11) -> 1(next->NULL,random->7)//ע�⣺���ָ��Ҳ����ָ���Լ�
//���룺head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//�����[[7,null],[13,0],[11,4],[10,2],[1,0]]
//7��ʾ����val��null��ʾrandom���ص���ָ��Ľ�������

//����һ��һ��һ���ĸ��ƽ�㣬�����ӣ���random�����ӿ���ͨ����Ծ�����ȷ������ָ��(ʱ�临�Ӷ�ΪO(N^2))
//��ͨ����ԭ�������randomָ���λ�ã�ȷ�����λ�ú���ȷ����������randomָ������λ�á�

//��������
//��1�������ο�����㣬Ȼ����뵽��Ӧԭ�ڵ�ĺ���
//��������ָ�������cur��copy��ne xt
//�����curָ��copy���Ҳ���ԭ�ڵ����һ�����ĵ�ַ��
//����Ҫ�ȸ�copyָ����һ��ԭ��㣬��curָ���ƵĽ�㡣������Ҫ����next����cur->next�ĵ�ַ
//ÿ�������ڵ���ÿ��ԭ�ڵ�ĺ��棬ÿ�������ڵ��randomҲ��ÿ��ԭ�ڵ��random�ĺ���
//    1   ->2   ->3   ->4  ->NULL
//1->  ->2   ->3   ->4
//��2��������������random
//������random��ָ����ԭ����random��ָ���next���
//��3���������������������ӳ�һ���������һָ�ԭ�������ӹ�ϵ
//��������ָ�������cur  ��copy��next
//��cur����ָ��ԭ�ڵ��next��copy����ָ���ƽ���next��
//cur��copy��next���������ߣ�һ�λָ��ϵ�����
//ʱ�临�Ӷȣ�O(N)

//���ģ����ƽ���random��ָ��Ϊ��ԭ����random��ָ���next��ָ��
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
	struct ListNode* random;
};
struct ListNode* copyRandom(struct ListNode* head)
{
	if (head == NULL)//�жϿ��������򣬵���cur->next��ָ�������
		return NULL;
	//��һ����
	struct ListNode* cur = head;//������ֱ���޸�head
	//����ԭ����ÿ����㣬���뵽��Ӧ�ڵ����
	while (cur != NULL)
	{
		//���ƽ��
		struct ListNode* copy = (struct ListNode*)malloc(sizeof(struct ListNode));
		copy->next = NULL;
		copy->random = NULL;
		copy->val = cur->val;

		//����copy���
		//������next�����������д��벻�ܵߵ�
		/*copy->next = cur->next;
		cur->next = copy;*/
		//���߶���next���浱ǰ������һ�����ĵ�ַ������������Եߵ�
		struct ListNode* next = cur->next;
		cur->next = copy;
		copy->next = next;//���һ�����ƽ���next����NULL

        //cur��copy����next������
		//������next
		//cur = copy->next;
		//����next
		cur = next;
		//ע�⣺copy�ǿ��ٵĿռ䣬next�ڱ�����һ�����ʱ��������һ��ѭ��copy��next��ʼ������
	}
	//�ڶ�����
	//����ԭ��㣬����������random
	cur = head;
	while (cur != NULL)
	{
		struct ListNode* copy = cur->next;
		//��������random��ԭ����random��next
		if (cur->random != NULL)//��֤cur->random����Ϊ�գ������¿�ָ�������
			copy->random = cur->random->next;
		else
			copy->random = NULL;//��һ�п��Բ��ã���Ϊcopy->random����һ���Ѿ���ʼ��NULL��

        //cur��copy����
		cur = cur->next->next;//�ȼ���cur = copy->next;
		//ע�⣺������һ��ѭ��copy��ʼ������
	}
	//ע�⣺�ڶ������Է��ڵ�һ�����档

	//��������
	//�������ƽ�㣬β������
    /*
	//����һ���ָ�ԭ��㣬���Ӹ��ƽ��
    //����next���������
    cur = head;
	struct ListNode* copyHead = head->next;//���ڷ��أ���ֹ���Ƶ�ͷ����Ҳ������������̸ı��ˣ�
	while (cur != NULL)
	{
		struct ListNode* copy = cur->next;
		struct ListNode* next = copy->next;

		//�Ȼָ�ԭ����ϵ
		cur->next = next;
		//�����Ӹ��ƽ��
		if (next != NULL)//��֤next����Ϊ�գ�����next->next���¿�ָ�������
			copy->next = next->next;
		else
			copy->next = NULL;

		//cur��copy��next����
		cur = next;
		//ע�⣺������һ��ѭ��copy��next��ʼ������
	}
    */

    /*
    //������next
	cur = head;
	struct ListNode* copyHead = head->next;//���ڷ��أ���ֹͷ����Ҳ������������̸ı��ˣ�
	while (cur != NULL)
	{
		struct ListNode* copy = cur->next;
		//�Ͽ�ԭ����븴�ƽ��Ĺ�ϵ�������Ӹ��Ƶ������ϵ�������ָ������nextָ��ָ�������Ľ��
		cur->next = copy->next;
		if (copy->next != NULL)//��֤copy->next����Ϊ�գ������¿�ָ�������
			copy->next = copy->next->next;
		else
			copy->next = NULL;
		//��������
		cur = cur->next;
		copy = copy->next;
	}
    */

     //��������ȡ���ƽ��β��
	//����next
	struct ListNode* copyHead = NULL,*copyTail = NULL;
	cur = head;
	//copyHead���ڷ��أ���ֹͷ����Ҳ������������̸ı��ˣ�copyTail����β��㣬���㲻��Ҫ��β��ֱ��β��
	while (cur != NULL)
	{
		struct ListNode* copy = cur->next;
		struct ListNode* next = copy->next;//�������
        //ȡ���ƽ������
		if (copyTail == NULL)
        {
            //ͷ��
            copyHead = copyTail = copy;
        }
		else
        {
            //β��
            copyTail->next = copy;
            copyTail = copy;//����βָ��
        }
        //�ָ�ԭ����
        cur->next = next;
		//cur��copy��next����
		cur = next;//copy��next��������һ��ѭ����ʼ����
	}
	//ע�⣺���Ӹ��ƽ���ԭ����͸����������һ������next��ΪNULL��������ʱ��һ��Ҫϸ�¡�

	return copyHead;
}
/*
int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val = 2;
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val = 3;
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val = 4;

	n1->next = n2;
	n1->random = n3;
	n2->next = n3;
	n2->random = n1;
	n3->next = n4;
	n3->random = n3;
	n4->next = NULL;
	n4->random = NULL;

	struct ListNode* copyHead = copyRandom(n1);
	while (copyHead)
	{
		printf("%d -> ", copyHead->val);
		copyHead = copyHead->next;
	}
	printf("NULL");
	return 0;
}
 */

//����ڲ��ı�����Ľṹʵ�ָù��ܣ�

//��ͼ(ϸ�£�ÿһ�����̶�Ҫ����)���߶����룬д���͡�