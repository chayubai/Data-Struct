#define _CRT_SECURE_NO_WARNINGS 1
//����һ��ֻ������(������)������{������}������[������]�����ַ���s���ж��ַ��������㣺
//1�������ű�������ͬ���͵������űպϡ�
//2�������ű�������ȷ��˳��պϡ�

//�磺
//���룺s = "(){}[]"
//�����true

//�磺
//���룺s = "(]";
//�����false

//�磺
//���룺s = "([)]";
//�����false

//˼·�������Ž�ջ�������ų�ջ���������ź�������ƥ��
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
//typedef char STDataType;
//typedef struct Stack
//{
//	STDataType* a;//ָ��a������ά������ջ
//	int top;//ջ����λ�ã���ջ�����±�
//	int capacity;//����ջ������
//}ST;
//
////����ջ��ʼ��
//void StackInit(ST* ps);
////����ջ����
//void StackDestroy(ST* ps);
////����ջ�������Ĳ���
//void StackPush(ST* ps, STDataType x);
////����ջ��������ɾ��
//void StackPop(ST* ps);
////ջ��������
//STDataType StackTop(ST* ps);
////����ջ�Ĵ�С
//int StackSize(ST* ps);
////�ж�ջ�Ƿ�Ϊ��
//bool StackEmpty(ST* ps);
//
//
////����ջ��ʼ��
//void StackInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0;//top = 0����ʾtopָ��ջ�����ݵ���һ�������ȷ�������++��top = -1.��ʾtopָ��ջ�����ݣ�����++�ٷ�����
//	ps->capacity = 0;
//}
//
////����ջ�Ĳ���
//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
//		if (tmp == NULL)
//		{
//			printf("realloc failed\n");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity = newCapacity;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
////����ջ����
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
////����ջ��ɾ��
//void StackPop(ST* ps)
//{
//	assert(ps);
//	//assert(ps->top > 0);
//	assert(!StackEmpty(ps));
//	ps->top--;
//}
//
////ջ��������
//STDataType StackTop(ST* ps)
//{
//	assert(ps);
//	//assert(ps->top > 0);
//	assert(!StackEmpty(ps));
//	return ps->a[ps->top - 1];
//}
//
////����ջ�Ĵ�С
//int StackSize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}
////�ж�ջ�Ƿ�Ϊ��
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//
//	return ps->top == 0;
//}
//
//bool IsValid(char* s)
//{
//	ST st;
//	StackInit(&st);
//	while (*s)//*s��ʾs[0]��Ϊ��
//	{
//		//����������ţ����ջ
//		if (*s == '(' || *s == '{' || *s == '[')
//		{
//			StackPush(&st, *s);
//			++s;
//		}
//		else
//		{
//			//���������ţ���ջ�������ݣ�˵��ǰ��û�������ţ���ƥ�䣬����false
//			if (StackEmpty(&st))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			//����������ų�ջ����ȡ���ķ������ַ����еķ��űȽ�
//			STDataType top = StackTop(&st);
//			StackPop(&st);
//			if ((*s == '}' && top != '{') || (*s == ']' && top != '[') || (*s == ')' && top != '('))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			else
//			{
//				++s;
//			}
//		}
//	}
//
//	//���ջ���ǿգ�˵��ջ�л���������δ��
//	//û��ƥ�䣬������false
//	//�����룺"["ʱ,ret = false
//	bool ret = StackEmpty(&st);
//
//	StackDestroy(&st);
//	return ret;
//}

/*
//s = "([]}"
//ջ��( [
//1�������ţ���ջ
//2�������ţ���ջ���������ţ����������ж��Ƿ�ƥ��
//���ƥ�䣬�������������ֹ
bool IsValid(char* s)
{
	ST st;
	StackInit(&st);
 	while (*s !='\0')//*s��ʾs[0]��Ϊ��
	{
		//����������ţ����ջ
		switch (*s)
		{
			case '(':
			case '{':
			case '[':
			{
				StackPush(&st, *s);
				++s;
				break;
			}
			case ')':
			case '}':
			case ']':
			{
				//�����룺"]"ʱ,ջΪ��
				//���������ţ���ջ�������ݣ�˵��ǰ��û�������ţ���ƥ�䣬����false
				if (StackEmpty(&st))
				{
					StackDestroy(&st);
					return false;
				}
				//�����ţ���ջ���������ţ����������ж��Ƿ�ƥ��
				char top = StackTop(&st);
				StackPop(&st);
				if ((*s == '}' && top != '{') || (*s == ']' && top != '[') || (*s == ')' && top != '('))
				{
					StackDestroy(&st);
					return false;
				}
				else
				{
					++s;
				}
				break;
			}
			default:
				break;
		}
	}
	//���ջ���ǿգ�˵��ջ�л���������δ��
	//û��ƥ�䣬������false
	//�����룺"["ʱ,ret = false
	bool ret = StackEmpty(&st);

	StackDestroy(&st);
	return ret;
}
*/
//int main()
//{
//	char* s = "([]}";
//	if (IsValid(s))
//	{
//		printf("ƥ��ɹ�\n");
//	}
//	else
//	{
//		printf("ƥ��ʧ��\n");
//	}
//	return 0;
//}