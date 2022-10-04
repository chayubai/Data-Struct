#define _CRT_SECURE_NO_WARNINGS 1
//给定一个只包括‘(’，‘)’，‘{’，‘}’，‘[’，‘]’的字符串s，判断字符串需满足：
//1、左括号必须用相同类型的右括号闭合。
//2、左括号必须以正确的顺序闭合。

//如：
//输入：s = "(){}[]"
//输出：true

//如：
//输入：s = "(]";
//输出：false

//如：
//输入：s = "([)]";
//输出：false

//思路：左括号进栈，右括号出栈，则左括号和右括号匹配
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
//typedef char STDataType;
//typedef struct Stack
//{
//	STDataType* a;//指针a，用来维护数组栈
//	int top;//栈顶的位置，即栈顶的下标
//	int capacity;//数组栈的容量
//}ST;
//
////数组栈初始化
//void StackInit(ST* ps);
////数组栈销毁
//void StackDestroy(ST* ps);
////数组栈（顶）的插入
//void StackPush(ST* ps, STDataType x);
////数组栈（顶）的删除
//void StackPop(ST* ps);
////栈顶的数据
//STDataType StackTop(ST* ps);
////数组栈的大小
//int StackSize(ST* ps);
////判断栈是否为空
//bool StackEmpty(ST* ps);
//
//
////数组栈初始化
//void StackInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0;//top = 0，表示top指向栈顶数据的下一个，即先放数据再++。top = -1.表示top指向栈顶数据，即先++再放数据
//	ps->capacity = 0;
//}
//
////数组栈的插入
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
////数组栈销毁
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
////数组栈的删除
//void StackPop(ST* ps)
//{
//	assert(ps);
//	//assert(ps->top > 0);
//	assert(!StackEmpty(ps));
//	ps->top--;
//}
//
////栈顶的数据
//STDataType StackTop(ST* ps)
//{
//	assert(ps);
//	//assert(ps->top > 0);
//	assert(!StackEmpty(ps));
//	return ps->a[ps->top - 1];
//}
//
////数组栈的大小
//int StackSize(ST* ps)
//{
//	assert(ps);
//	return ps->top;
//}
////判断栈是否为空
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
//	while (*s)//*s表示s[0]不为空
//	{
//		//如果是左括号，则进栈
//		if (*s == '(' || *s == '{' || *s == '[')
//		{
//			StackPush(&st, *s);
//			++s;
//		}
//		else
//		{
//			//遇到右括号，但栈中无数据，说明前面没有左括号，不匹配，返回false
//			if (StackEmpty(&st))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			//如果是右括号出栈，并取顶的符号与字符串中的符号比较
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
//	//如果栈不是空，说明栈中还有左括号未出
//	//没有匹配，返回是false
//	//当输入："["时,ret = false
//	bool ret = StackEmpty(&st);
//
//	StackDestroy(&st);
//	return ret;
//}

/*
//s = "([]}"
//栈：( [
//1、左括号，入栈
//2、右括号，出栈顶的左括号，跟右括号判断是否匹配
//如果匹配，则继续，否则终止
bool IsValid(char* s)
{
	ST st;
	StackInit(&st);
 	while (*s !='\0')//*s表示s[0]不为空
	{
		//如果是左括号，则进栈
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
				//当输入："]"时,栈为空
				//遇到右括号，但栈中无数据，说明前面没有左括号，不匹配，返回false
				if (StackEmpty(&st))
				{
					StackDestroy(&st);
					return false;
				}
				//右括号，出栈顶的左括号，跟右括号判断是否匹配
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
	//如果栈不是空，说明栈中还有左括号未出
	//没有匹配，返回是false
	//当输入："["时,ret = false
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
//		printf("匹配成功\n");
//	}
//	else
//	{
//		printf("匹配失败\n");
//	}
//	return 0;
//}