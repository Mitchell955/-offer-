#include<iostream>
using namespace std;
/*
��Ŀ������
	��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
	����һ����������������һ����ת�������ת�������СԪ�ء����磬����{3,4��5,1,2}Ϊ
	{1,2,3,4,5}��һ����ת�����������СֵΪ1��
*/
/*
˼·��
	���ڶ��ֲ���
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
		//����±�left��right��midָ�������������ȣ��Ǿ�ֻ��˳�����
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