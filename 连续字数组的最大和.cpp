#include<iostream>
using namespace std;
#if 0
/*
题目描述：
	输入一个整型数组，数组里有正数也有负数。数组中的一个或者连续多个整数组成一个子数组。
	求所有子数组的和的最大值。要求时间复杂度为O(n);
*/
/*
方法一：找规律
时间复杂度为O(N)

*/
bool gflag = false;
int FindMaxSum(int arr[],int len)
{
	if(arr == nullptr || len <= 0)
	{
		gflag = true;
		return 0;
	}
	gflag = false;
	int sum = 0;
	int nmaxsum = 0;
	for(int i = 0;i < len;++i)
	{
		if(sum <= 0)
			sum =arr[i];
		else
			sum += arr[i];
		if(sum > nmaxsum)
			nmaxsum = sum;
	}
	return nmaxsum;
}
int main()
{
	int arr[] = {1,-2,3,10,-4,7,2,-5};
	int len = sizeof(arr)/sizeof(arr[0]);
	cout << FindMaxSum(arr,len) << endl;
	return 0;
}
#endif