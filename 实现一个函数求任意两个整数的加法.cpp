#include<iostream>
#include<string>
#include<stack>
using namespace std;
/*
��Ŀ������
	����������������������һ�����������
���㣺
	�����Ĵ������ַ���
*/
#if 0
void Sum(char *num1,char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	stack<int> st1;
	stack<int> st2;
	stack<int> res;
	string csum;// ��¼���յ���ͽ��
	int tmp = 0;//��¼���λ��ֵ
	int sum = 0;//��¼��Ӧλ�͵Ľ��
	for(int i = 0;i < len1;++i)
	{
		st1.push(num1[i]-'0');
	}
	for(int i = 0;i < len2;++i)
	{
		st2.push(num2[i]-'0');
	}
	while(!st1.empty()&& !st2.empty())
	{
		
		sum = st1.top()+st2.top() + tmp;
		if(sum >= 10)
		{
			tmp = sum/10;
			res.push(sum%10);
		}
		else
		{
			res.push(sum);
			tmp = 0;
		}
		st1.pop();
		st2.pop();
	}
	while(!st1.empty())
	{
		sum = st1.top() + tmp;
		if(sum >= 10)
		{
			res.push(sum%10);
			tmp = sum/10;
		}
		res.push(sum);
		st1.pop();
	}
	while(!st2.empty())
	{
		sum = st2.top() + tmp;
		if(sum >= 10)
		{
			res.push(sum%10);
			tmp = sum/10;
		}
		res.push(sum);
		st2.pop();
	}
	while(!res.empty())
	{
		csum.push_back(res.top()+'0');
		res.pop();
	}
	cout << csum << endl;
}
int main()
{
	Sum("1214578","874532");
	return 0;
}
#endif