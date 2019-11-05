#include<iostream>
using namespace std;
#if 0
/*
��Ŀ������
	����һ���������飬ʵ��һ�����������������飬ʹ�����е�����λ�������ǰ�벿�֣�
	���е�ż��λ������ĺ�벿�֣�
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
//����
//�������������зǸ���֮ǰ
//���ܱ�3�����ķ������в��ܱ�3����֮ǰ
//��������������ż��֮ǰ�ȵȡ�����
bool func(int data)
{
	//����������Ը�����Ҫ���б�д
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