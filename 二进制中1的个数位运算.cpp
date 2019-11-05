#include<iostream>
using namespace std;
/*
面试题15：二进制中1的个数
请实现一个函数，输入一个整数，输出该数二进制表示的1的个数。
*/
#if 0
/*
方法一： 整型数据除法
		该整数除2，原来的数字将会减少一个0；
		若有余数，则表示当前位置有一个1；
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
方法二：使用位操作
		先判断data最后一位的值为“0”或是“1”
		是“1”，给计数器++，否则不++；
		再利用位运算右移去掉最后一位
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
方法三：使用位操作
	用data和data-1进行“&”操作，一次&后，找到一个“1”；
	重置data = (data-1),知道data = 0时结束
(这种方法是效率最高的)
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