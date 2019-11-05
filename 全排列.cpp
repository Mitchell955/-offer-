#include<iostream>
#include<assert.h>
using namespace std;
#if 0
/*
面试题38：字符串的排列
题目描述：
	输入一个字符串，打印出该字符串中字符的所有排列。
	例如：输入“abc”，则打印出的是a b c所能排列的所有字符串；
*/
//全排列问题
void Perm1(char *str,char *begin)
{
	if(*begin == '\0')
		printf("%s\n",str);
	else
	{
		for(char*ch = begin;*ch != '\0';++ch)
		{
			char tmp = *ch;
			*ch = *begin;
			*begin = tmp;

			Perm1(str,begin+1);

			tmp = *ch;
			*ch = *begin;
			*begin = tmp;
		}
	}
}
void Perm(char *str)
{
	if(str == nullptr)
		return;
	Perm1(str,str);
}
int main()
{
	Perm("abc");
	return 0;
}
#endif