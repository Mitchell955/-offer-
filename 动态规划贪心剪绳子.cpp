#include<iostream>
using namespace std;
#if 0
//动态
规划
int MaxProduct(int len)//len为绳子长度
{
	if(len < 2)
		return 0;
	if(len == 2)
		return 1;
	if(len == 3)
		return 2;
	int *arr = new int[len+1];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	int max = 0;
	for(int i = 4;i <= len;++i)
	{
		max = 0;
		for(int j = 1;j <= i/2;++j)
		{
			int tmp = arr[j] * arr[i-j];
			if(max < tmp)
				max = tmp;
			arr[i] = max;
		}
	}
	max = arr[len];
	delete [] arr;
	return max;
}

//贪心算法
/*
	当n>=5时，我们尽可能多地剪长度为3的绳子；因为首先2(n-2)>n并且3(n-3)>n,又3(n-3) >= 2(n-2),所以尽可能剪长度为3的绳子；
	当剩下的绳子长度为4时，把绳子剪为两段为2的绳子；
*/
int MaxCutting(int len)
{
	if(len < 2)
		return 0;
	if(len == 2)
		return 1;
	if(len == 3)
		return 2;
	
	//尽可能剪为长度为3的绳子
	int times3 = len / 3;
	
	if(len - times3*3 == 1)
		times3 = 1;
	int times2 = (len - times3*3)/2;

	return (int)(pow(3,times3))*(int)(pow(2,times2));

}
int main()
{
	cout << MaxProduct(4) << endl;
	return 0;
}  
#endif