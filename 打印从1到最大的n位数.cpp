#include<iostream>
#include<string>
using namespace std;
#if 0
/*
输入数字n，按顺序打印出从1到最大的n位十进制数。
比如输入3，则打印出1、2、3一直到最大的三位数999
这个题目的考点：
	一是对于大数的处理，字符串是对大数进行处理的最好的一种方法
	二是利用字符串处理时，打印的时候按照习惯如何打印，例如：存储的是098 => 习惯98
*/
void Print(char *number)
{
	bool flag = true;
	int nlen = strlen(number);
	for(int i = 0;i < nlen;++i)
	{
		if(flag && number[i] != '0')
			flag = false;
		if(!flag)
			printf("%c",number[i]);
	}
	printf("\t");
}
//递归全排列实现
/*
void Print1ToMaxPrem(char *number,int n,int index)//全排列
{
	if(index == n -1)
	{
		Print(number);
		return;
	}
	for(int i = 0;i < 10;++i)//0~9的全排列
	{
		number[index+1] = i + '0';
		Print1ToMaxPrem(number,n,index+1);
	}
}
void Print1ToMax(int n)
{
	if(n <= 0)
		return;
	char *number = new char[n+1];
	number[n] = '\0';
	for(int i = 0;i < 10;++i)
	{
		number[0] = i + '0';
		Print1ToMaxPrem(number,n,0);
	}
	delete[] number;
}
*/
//字符串操作
bool Increment(char* number)
{
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);

    for (int i = nLength - 1; i >= 0; i--)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
            nSum++;

        if (nSum >= 10)
        {
            if (i == 0)
                isOverflow = true;
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }

    return isOverflow;
}
void Print1ToMax(int n)
{
    if (n <= 0)
        return;

    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!Increment(number))
    {
        Print(number);
    }

    delete[]number;
}
int main() 
{
	Print1ToMax(3);
	return 0;
}
#endif