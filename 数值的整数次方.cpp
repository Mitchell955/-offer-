#include<iostream>
using namespace std;
/*
题目描述：
	实现函数double Power(double base,int exponent)；
	求base的exponent次方，不得使用库函数，同时不需要考虑大数问题；
*/
#if 0
/*
double Power(double base,int exponent)
{
	double res = 1;
	bool flag = true;
	if((base == 0 && exponent == 0) || exponent == 0)
		return 1;
	if(base == 0 && exponent != 0)
		return res;
	int i = 1;
	while(i <= exponent)
	{
		if(base < 0)
		{
			if(i % 2 == 0)
			{
				res *= (base * 1);
			}
			else
			{
				res *=  (base * -1);
			}
		}
		else
		{
			res *= base;
		}
		++i;
	}
	return res;
}
*/
//例如：要求的x的32次方，在上述中就要做31次循环；
//那么更高效的做法，要求32次方，我们会知道16次方，求16次方会知道8次方，8次方会知道4次方；
//4次方会知道2次方，，这样一次类推求32次方只需要做5次乘法即可；
//先求平方，在平方的基础上求4 ，在4的基础上求8等等，，，
double Power(double base,int exponent)
{
	bool flag = true;
	if((base == 0 && exponent == 0) || exponent == 0)
		return 1;
	if(base == 0 && exponent != 0)
		return 0;
	double res = Power(base,exponent >> 1);
	res *= res;

	if((exponent & 0x1) == 1)
		res *= base;
	return res;
}
int main()
{
	cout<< Power(-2,3) << endl;
	cout<< Power(0,0) << endl;
	cout<< Power(2,0) << endl;
	return 0;
}
#endif