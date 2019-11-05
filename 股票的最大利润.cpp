#include<iostream>
using namespace std;
/*
题目描述：
	假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
	例如：一只股票在某些事件结点的价格为{9,11,8,5,7,12,16,14}，如果我们在价格5的时候买入并在16的时候卖出，
	则能获得最大利润11；
*/
#if 0
/*
思路：
	diff[i]为卖出价为数组中第i个数字时可能获得的利润；
	在卖出价固定时，买入价越低利润越大；
	当扫描到数组的第i个数字时，我们需要记录i之前数字中的最小值，就能算出当前价位卖出时可能获得的利润；
	进行比较，得到最大利润值；
*/
int MaxDiff(int *arr,int len)
{
	if(arr == nullptr && len <= 0)
		return 0;
	int min = arr[0];
	int maxdiff  = arr[1] - min;
	for(int i = 2;i < len;++i)
	{
		if(arr[i-1] < min)
			min = arr[i-1];
		int cur = arr[i] - min;
		if(cur > maxdiff)
			maxdiff = cur;
	}
	return maxdiff;
}
int main()
{
	int arr[] = {9,11,16,7,8,5,12,14};
	int len = sizeof(arr)/sizeof(arr[0]);
	cout << MaxDiff(arr,len) << endl;
	return 0;
}
#endif