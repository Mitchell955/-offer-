#include<iostream>
#include<assert.h>
using namespace std;
#if 0
/*
������38���ַ���������
��Ŀ������
	����һ���ַ�������ӡ�����ַ������ַ����������С�
	���磺���롰abc�������ӡ������a b c�������е������ַ�����
*/
//ȫ��������
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