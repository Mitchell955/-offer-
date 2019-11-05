#include<iostream>
using namespace std;
#if 0
//递归解法  但并不是最好的；对于这个题目，递归会导致出现多次的重复计算，效率并不高
long long Fibo(unsigned int n)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	return Fibo(n-1)+Fibo(n-2);
}

//高效的解法：非递归  避免重复计算
/*
斐波那契数列解决青蛙跳台问题：一只青蛙一次可以
        0                   n=0 
f(n)=   1                   n=1
      f(n-1)+f(n-2)         n>1
*/
long long fun(unsigned int n)
{
	int res[2] = {0,1};
	if(n < 2)
		return res[n];
	long long f1 = 1;//记录第一个数字
	long long f2 = 0;//记录第二个数字
	long long f3 = 0;//记录结果
	for(unsigned int i = 2;i <= n;++i)
	{
		f3 = f1 + f2;//做计算
		f2 = f1;//交换f3，f2,f1
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