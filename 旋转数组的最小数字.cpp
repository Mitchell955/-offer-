#include<iostream>
using namespace std;
/*
题目描述：
	把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
	输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组{3,4，5,1,2}为
	{1,2,3,4,5}的一个旋转，该数组的最小值为1。
*/
/*
思路：
	基于二分查找
*/
#if 0
int MinInOrder(int *arr,int left,int right)
{
	int res = arr[left];
	for(int i = left + 1;i <= right; ++i)
	{
		if(res > arr[i])
			res = arr[i];
	}
	return res;
}
int GetMin(int *arr,int len)
{
	if(arr == nullptr || len <= 0)
		throw new std::exception("arr is null");
	int left = 0;
	int right = len - 1;
	int mid = left;
	while(arr[left] >=  arr[right])
	{
		if(right - left == 1)
		{
			mid = right;
			break;
		}
		mid = (right-left)/2+left;
		//如果下标left，right和mid指向的三个数字相等，那就只能顺序查找
		if(arr[left] == arr[right] && arr[mid] == arr[left])
			return MinInOrder(arr,left,right);
		if(arr[mid] >= arr[left])
		{
			left = mid;
		}
		else if(arr[mid] <= arr[right])
		{
			right = mid;
		}
	}
	return arr[mid];
}
int main()
{
	int arr[] = {3,4,5,1,2};
	int len = sizeof(arr)/sizeof(arr[0]);
	cout << GetMin(arr,len) << endl;
	return 0;
}
#endif