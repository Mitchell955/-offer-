#include<iostream>
using namespace std;
#if 0
/*
题目描述：
	输入一个整数数组，实现一个函数来调整该数组，使得所有的奇数位于数组的前半部分；
	所有的偶数位于数组的后半部分；
*/
void AdjustArr(int *arr,int len)
{
	int i = 0;
	int j = len - 1;
	int tmp = arr[0];
	while(i < j)
	{
		while(i < j && arr[j] % 2 == 0)
			--j;
		arr[i] = arr[j];
		while(i < j && arr[i] % 2 != 0)
			++i;
		arr[j] = arr[i];
	}
	arr[i] = tmp;
}
void show(int *arr,int len)
{
	for(int i = 0;i < len;++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
/*
//延伸
//将负数放在所有非负数之前
//将能被3整除的放在所有不能被3整除之前
//将所有奇数放在偶数之前等等。。。
bool func(int data)
{
	//这个函数可以根据需要进行编写
}
void AdjustArr(int *arr,int len)
{
	int i = 0;
	int j = len - 1;
	int tmp = arr[0];
	while(i < j)
	{
		while(i < j && func(arr[i]))
			--j;
		arr[i] = arr[j];
		while(i < j && func(arr[i]))
			++i;
		arr[j] = arr[i];
	}
	arr[i] = tmp;
}
void show(int *arr,int len)
{
	for(int i = 0;i < len;++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
*/
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(arr)/sizeof(arr[0]);
	AdjustArr(arr,len);
	show(arr,len);
	return 0;
}
#endif