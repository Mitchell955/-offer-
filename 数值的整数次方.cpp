#include<iostream>
using namespace std;
/*
��Ŀ������
	ʵ�ֺ���double Power(double base,int exponent)��
	��base��exponent�η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⣻
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
//���磺Ҫ���x��32�η����������о�Ҫ��31��ѭ����
//��ô����Ч��������Ҫ��32�η������ǻ�֪��16�η�����16�η���֪��8�η���8�η���֪��4�η���
//4�η���֪��2�η���������һ��������32�η�ֻ��Ҫ��5�γ˷����ɣ�
//����ƽ������ƽ���Ļ�������4 ����4�Ļ�������8�ȵȣ�����
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