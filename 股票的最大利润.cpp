#include<iostream>
using namespace std;
/*
��Ŀ������
	�����ĳ��Ʊ�ļ۸���ʱ���Ⱥ�˳��洢�������У����������ù�Ʊһ�ο��ܻ�õ���������Ƕ��٣�
	���磺һֻ��Ʊ��ĳЩ�¼����ļ۸�Ϊ{9,11,8,5,7,12,16,14}����������ڼ۸�5��ʱ�����벢��16��ʱ��������
	���ܻ���������11��
*/
#if 0
/*
˼·��
	diff[i]Ϊ������Ϊ�����е�i������ʱ���ܻ�õ�����
	�������۹̶�ʱ�������Խ������Խ��
	��ɨ�赽����ĵ�i������ʱ��������Ҫ��¼i֮ǰ�����е���Сֵ�����������ǰ��λ����ʱ���ܻ�õ�����
	���бȽϣ��õ��������ֵ��
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