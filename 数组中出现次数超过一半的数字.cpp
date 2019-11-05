#include<iostream>
#include<vector>
using namespace std;
#if 0
/*
��Ŀ������
	��������һ�����ֳ��ֵĴ���������鳤�ȵ�һ�룬���ҳ�������֡�
	���磺����һ������Ϊ9������{1,2,3,2,2,2,5,4,2}.��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2��
*/
/*
����һ���������ң�ʱ�临�Ӷȸ�O(nlogn)
*/

/*
�����������ڻ��֣�������ŵ�˼�룻
	������������������ô����֮��Ϊ�������м������һ�������Ǹ����ִ����������鳤��һ������֣�
	Ҳ������λ������N/2������֣�ʱ�临�Ӷ�ΪO(N)��

	����ָ��start��mid��end�����л��֣�һ�˻��ֽ����󷵻�һ���±�ֵ��
	���inddex��mid��ȣ�������ֵ������λ�������ܾ�����Ҫ��ĳ��ִ�������һ������֣���CheckmoreHalf�н��н�һ���ж�
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
�����������������ص���ʱ�临�Ӷ�ΪO(n)���㷨
	��������ֵ��һ���������е����֣�һ�������������Ǳ�������һ�����ֵ�ʱ�������һ�����ֺ�֮ǰ�������ȣ��������1��
	���ȣ��������1��������Ϊ0������ֻ��Ҫ������һ�����֣����Ѵ�����1��
	����Ҫ�ҵ����ֳ��ִ����������������ֳ��ִ���֮�ͻ�Ҫ�࣬��ôҪ�ҵ����ֿ϶������һ�ΰɴ�����Ϊ1���Ǹ����֣�
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
�����ģ���ϣ  ��ÿ�����ֳ��ֵĴ��������±��Ӧ����ϣ�������� 
Ȼ����������
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