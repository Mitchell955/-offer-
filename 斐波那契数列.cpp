#include<iostream>
using namespace std;
#if 0
//�ݹ�ⷨ  ����������õģ����������Ŀ���ݹ�ᵼ�³��ֶ�ε��ظ����㣬Ч�ʲ�����
long long Fibo(unsigned int n)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	return Fibo(n-1)+Fibo(n-2);
}

//��Ч�Ľⷨ���ǵݹ�  �����ظ�����
/*
쳲��������н��������̨���⣺һֻ����һ�ο���
        0                   n=0 
f(n)=   1                   n=1
      f(n-1)+f(n-2)         n>1
*/
long long fun(unsigned int n)
{
	int res[2] = {0,1};
	if(n < 2)
		return res[n];
	long long f1 = 1;//��¼��һ������
	long long f2 = 0;//��¼�ڶ�������
	long long f3 = 0;//��¼���
	for(unsigned int i = 2;i <= n;++i)
	{
		f3 = f1 + f2;//������
		f2 = f1;//����f3��f2,f1
		f1 = f3;
	}
	return f3;
}
int main()
{
	cout << fun(4) << endl;
	return 0;
}
#endif 