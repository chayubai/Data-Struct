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
//左括号:( { [
//右括号: ) } ]
#include "Stack.h"
typedef char STDataType;
bool IsValid(char* s)
{
	ST st;
	StackInit(&st);
	while (*s)//s是字符串，*s表示s[i] != '\0'继续
	{
		//如果s[i]是左括号，则进栈
		if (*s == '(' || *s == '{' || *s == '[')
		{
			StackPush(&st, *s);
			++s;
		}
		else
		{
			//当输入："]"时，此时栈为空。
			//没有下面的判断，StackTop(&st)就会报错。因为assert(!StackEmpty(ps));断言报错。
			if (StackEmpty(&st))
			{
				//注意：如果遇到的就是右括号，但栈中无数据，说明前面没有左括号，不匹配，返回false。如"[]]()"
				StackDestroy(&st);
				return false;
			}

			//如果s[i]是右括号，则取栈顶的符号与字符串中的符号s[i]比较，并栈顶的元素出栈
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

	//如果栈不是空，说明栈中还有左括号未出栈，没有与字符串s[i]匹配，返回是false
	//当输入："["时,ret = false
	bool ret = StackEmpty(&st);

	StackDestroy(&st);//注意：返回前一定要释放栈，否则会造成内存泄漏。
	return ret;
}

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

#if 0
int main()
{
	char* s = "([]}";
	if (IsValid(s))
	{
		printf("匹配成功\n");
	}
	else
	{
		printf("匹配失败\n");
	}
	return 0;
}
#endif

//OJ报错如何解决：
//1、看报错的测试用例，分析代码，用大脑跟着走读代码。
//2、如果还是无法解决，就只能把代码拷贝到vs上调试