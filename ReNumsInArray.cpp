#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#if 0
//����һ������ ��ͷ��β���б���
/*
void ReNum(int n,vector<int>vec)
{
	sort(vec.begin(),vec.end());
	int tmp;
	for(auto it = vec.begin();it < vec.end();++it)
	{
		if((it+1) < vec.end())
		{
			if((*it) == (*(it+1)))
			{
				tmp = *it;
				break;
			}
		}
	}
	cout << tmp << endl;
}
*/
//�����������ù�ϣ��ṹ���в��ң�����ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ�ΪO(n)
/*
int arr[1001];
void ReNum(int n,vector<int>vec)
{ 
	for(int i = 0;i < vec.size();++i)
	{
		if(arr[vec[i]] == 0)
		{
			arr[vec[i]] = vec[i];
		}
		else if(arr[vec[i]] == vec[i])
		{
			cout << vec[i] << endl;
		    break;
		}
	}
}
*/
//���������������飬��ͷ��ʼ������Ϊÿ�������ҵ����Ӧ���±���з��ã�
//�����͵�m���±���������ʱ�ͳ������ظ����֣�
//�ܵ�ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
void ReNum(int n,vector<int> vec)
{
	for(int i = 0;i < n;++i)
	{
		while(vec[i] != i)
		{
			if(vec[vec[i]] == vec[i])
			{
				cout << vec[i] << endl;
				return;
			}
			int tmp = vec[i];
			vec[i] = vec[tmp];
			vec[tmp]  = tmp;
		} 
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i = 0;i < n;++i)
	{
		cin >> vec[i];
	}
	ReNum(n,vec);
	return 0;
}
#endif