#include<iostream>
#include<string>
using namespace std;
#if 0
/*
��������n����˳���ӡ����1������nλʮ��������
��������3�����ӡ��1��2��3һֱ��������λ��999
�����Ŀ�Ŀ��㣺
	һ�Ƕ��ڴ����Ĵ����ַ����ǶԴ������д������õ�һ�ַ���
	���������ַ�������ʱ����ӡ��ʱ����ϰ����δ�ӡ�����磺�洢����098 => ϰ��98
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
//�ݹ�ȫ����ʵ��
/*
void Print1ToMaxPrem(char *number,int n,int index)//ȫ����
{
	if(index == n -1)
	{
		Print(number);
		return;
	}
	for(int i = 0;i < 10;++i)//0~9��ȫ����
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
//�ַ�������
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