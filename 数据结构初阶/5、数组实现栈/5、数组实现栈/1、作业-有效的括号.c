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
//������:( { [
//������: ) } ]
#include "Stack.h"
typedef char STDataType;
bool IsValid(char* s)
{
	ST st;
	StackInit(&st);
	while (*s)//s���ַ�����*s��ʾs[i] != '\0'����
	{
		//���s[i]�������ţ����ջ
		if (*s == '(' || *s == '{' || *s == '[')
		{
			StackPush(&st, *s);
			++s;
		}
		else
		{
			//�����룺"]"ʱ����ʱջΪ�ա�
			//û��������жϣ�StackTop(&st)�ͻᱨ����Ϊassert(!StackEmpty(ps));���Ա���
			if (StackEmpty(&st))
			{
				//ע�⣺��������ľ��������ţ���ջ�������ݣ�˵��ǰ��û�������ţ���ƥ�䣬����false����"[]]()"
				StackDestroy(&st);
				return false;
			}

			//���s[i]�������ţ���ȡջ���ķ������ַ����еķ���s[i]�Ƚϣ���ջ����Ԫ�س�ջ
			STDataType top = StackTop(&st);
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
		}
	}

	//���ջ���ǿգ�˵��ջ�л���������δ��ջ��û�����ַ���s[i]ƥ�䣬������false
	//�����룺"["ʱ,ret = false
	bool ret = StackEmpty(&st);

	StackDestroy(&st);//ע�⣺����ǰһ��Ҫ�ͷ�ջ�����������ڴ�й©��
	return ret;
}

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

#if 0
int main()
{
	char* s = "([]}";
	if (IsValid(s))
	{
		printf("ƥ��ɹ�\n");
	}
	else
	{
		printf("ƥ��ʧ��\n");
	}
	return 0;
}
#endif

//OJ������ν����
//1��������Ĳ����������������룬�ô��Ը����߶����롣
//2����������޷��������ֻ�ܰѴ��뿽����vs�ϵ���