#include<iostream>
using namespace std;
/*
������15����������1�ĸ���
��ʵ��һ������������һ��������������������Ʊ�ʾ��1�ĸ�����
*/
#if 0
/*
����һ�� �������ݳ���
		��������2��ԭ�������ֽ������һ��0��
		�������������ʾ��ǰλ����һ��1��
*/
int Count(int data)
{
	int num = 0;
	while(data)
	{
		if(data%2 == 1)
		{
			num++;
		}
		v = data/2;
	}
	return num;
}
/*
��������ʹ��λ����
		���ж�data���һλ��ֵΪ��0�����ǡ�1��
		�ǡ�1������������++������++��
		������λ��������ȥ�����һλ
*/
int Count(int data)
{
	int num = 0;
	while(data)
	{
		num+= data &0x01;
		data >>= 1;
	}
	return num;
}
/*
��������ʹ��λ����
	��data��data-1���С�&��������һ��&���ҵ�һ����1����
	����data = (data-1),֪��data = 0ʱ����
(���ַ�����Ч����ߵ�)
*/

int Count(int data)
{
	int num = 0;
	while(data)
	{
		data &= (data-1);
		num++;
	}
	return num;
}
int main()
{
	int count = Count(12);
	cout << count << endl;
	return 0;
}
#endif