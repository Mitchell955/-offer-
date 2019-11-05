#include<iostream>
#include<string>
using namespace std;
#if 0
/*
替换空格：
	把字符串中的每个空格替换为"20%"；例如："we are happy."==>"we20%are20%happy"
*/
//方法二：从后向前遍历，替换
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
	int count =0;//空格数
	int originalLen = 0;//实际长度
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
//方法一；利用string进行操作， 从前向后依次遍历
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
