#include<iostream>
#include<string>
using namespace std;
#if 0
/*
�滻�ո�
	���ַ����е�ÿ���ո��滻Ϊ"20%"�����磺"we are happy."==>"we20%are20%happy"
*/
//���������Ӻ���ǰ�������滻
void show(char str[],int len)
{
	int i = 0;
	while(str[i] != '\0')
	{
		cout<<str[i];
		++i;
	}
	cout << endl;
}

void ReplaceSpace1(char str[],int len)
{
	if(str == nullptr)
		return;
	int i = 0;
	int count =0;//�ո���
	int originalLen = 0;//ʵ�ʳ���
	while (str[i] != '\0')
	{
		++originalLen;
		if(isspace(str[i]))
			++count;
		++i;
	}
	int newlen = originalLen + count*2;
	if(newlen > len)
		return;
	int indexO = originalLen;
	int indexN = newlen;
	while(indexO >= 0 && indexN > indexO)
	{
		if(isspace(str[indexO]))
		{
			str[indexN--]='0';
			str[indexN--]='2';
			str[indexN--]='%';
		}
		else
		{
			str[indexN--] = str[indexO];
		}
		--indexO;
	}
	show(str,newlen);
}
//����һ������string���в����� ��ǰ������α���
void ReplaceSpace(char *str)
{
	string res;
	int i = 0;
	while(str[i] != '\0')
	{
		if(!isspace(str[i]))
		{
			res.push_back(str[i]);
		}
		else if(isspace(str[i]))
		{
			res.push_back('%');
			res.push_back('2');
			res.push_back('0');
		}
		++i;
	}
	cout << res << endl;
}
int main()
{
	char str[100] = "we are happy.";
	ReplaceSpace1(str,14);
	return 0;
}
#endif
#if 0
int main()
{
	char str1[] = "hello world";
	char str2[] = "hello world";
	char *str3 = "hello world";
	char *str4 = "hello world";
	if(str1 == str2)
		cout<< "str1 == str2" << endl;
	else
		cout << "str1 != str2" << endl;
	if(str3 == str4)
		cout << "str3 == str4" << endl;
	else
		cout << "str3 != str4"<<endl;
	return 0;

#endif
