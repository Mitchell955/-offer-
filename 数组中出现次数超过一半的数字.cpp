#include<iostream>
#include<vector>
using namespace std;
#if 0
/*
题目描述：
	数组中有一个数字出现的次数查过数组长度的一半，请找出这个数字。
	例如：输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}.由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2；
*/
/*
方法一：排序后查找，时间复杂度高O(nlogn)
*/

/*
方法二：基于划分，借鉴快排的思想；
	如果把这个数组排序，那么排序之后为于数组中间的数字一定就是那个出现次数超过数组长度一般的数字；
	也就是中位数，第N/2大的数字；时间复杂度为O(N)；

	三个指针start，mid，end，进行划分，一趟划分结束后返回一个下标值；
	如果inddex和mid相等，表明该值就是中位数，可能就是所要求的出现次数超过一半的数字；在CheckmoreHalf中进行进一步判断
*/
template<class Type>
int Patition(Type *arr,int left,int right)
{
	int i = left;
	int j = right;
	Type temp = arr[i];
	while(i < j)
	{
		while(i<j && arr[j] > temp) --j;
		if(i < j) arr[i] = arr[j];
		while(i<j && arr[i] <= temp) ++i;
		if(i < j) arr[j] = arr[i];
	}
	arr[i] = temp;
	return i;
}
bool gflag = false;
bool CheckMoreHalf(int arr[],int len,int res)
{
	int times = 0;
	for(int i = 0;i < len;++i)
	{
		if(arr[i] == res)
			times++;
	}
	bool ismore = true;
	if(times*2 <= len)
	{
		gflag = true;
		ismore = false;
	}
	return ismore;
}
/*
int MoreHalfNum(int arr[],int len)
{
	if(arr == nullptr || len <= 0)
		return 0;
	int mid = len / 2;
	int start = 0;
	int end = len-1;
	int index = Patition(arr,start,end);
	while(index != mid)
	{
		if(index > mid)
		{
			end = index - 1;
			index = Patition(arr,start,end);
		}
		else if(index <= mid)
		{
			start = index + 1;
			index = Patition(arr,start,end);
		}
	}
	int res  = arr[index];
	if(!CheckMoreHalf(arr,len,res))
		res = 0;
	return res;
}
*/

/*
方法三：根据数组特点找时间复杂度为O(n)的算法
	保存两个值，一个是数组中的数字，一个次数；当我们遍历到下一个数字的时候，如果下一个数字和之前保存的相等，则次数加1；
	不等，则次数减1；若次数为0，我们只需要保存下一个数字，并把次数设1；
	由于要找的数字出现次数比其他所有数字出现次数之和还要多，那么要找的数字肯定是最后一次吧次数设为1的那个数字；
*/
/*
int MoreHalfNum(int arr[],int len)
{
	if(arr == nullptr || len <= 0)
		return 0;
	int res = arr[0];
	int times = 1;
	for(int i = 1;i < len;++i)
	{
		if(times == 0)
		{
			res= arr[i];
			times = 1;
		}
		else if(arr[i] == res)
			times++;
		else
			times--;
	}
	if(!CheckMoreHalf(arr,len,res))
		res= 0;
	return res;
}
*/
/*
方法四：哈希  将每个数字出现的次数按照下标对应到哈希表数组中 
然后查表找最大的
*/
int Ha[1001] = {0};
int MoreHalfNum(int arr[],int len)
{
	if(arr == nullptr || len <= 0)
		return 0;
	for(int i = 0;i < len;++i)
	{
		Ha[arr[i]]++;
	}
	int res = 0;
	for(int i = 1;i < 100;++i)
	{
		if(Ha[i] > Ha[i-1])
		{
			res = i;
		}
	}
	return res;
}
int main()
{
	int arr[] = {1,2,3,2,2,2,5,4,2};
	int len = sizeof(arr)/sizeof(arr[0]);
	cout << MoreHalfNum(arr,len) << endl;
	return 0;
}
#endif