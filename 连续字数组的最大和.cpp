#include<iostream>
using namespace std;
#if 0
/*
��Ŀ������
	����һ���������飬������������Ҳ�и����������е�һ��������������������һ�������顣
	������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n);
*/
/*
����һ���ҹ���
ʱ�临�Ӷ�ΪO(N)

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