#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#if 0
/*
��Ŀ������
��һ����ά�����У�ÿһ���Ǵ������ҵ��������У�ÿһ���Ǵ��ϵ��µ��������У�
����һ����ֵ��һ����ά���飬�ڶ�ά�������ж��Ƿ��и���ֵ
*/
/*
���⣺
�����Ͻǵ�������Ϊ��ʼλ�ÿ�ʼ��
����Ҫ���ҵ����ֺ�����бȽϣ����==��ֱ�ӷ���true
���ڣ���--
С�ڣ���++
*/
bool IsExistNum(vector<vector<int>>vec,int num)
{
	if(vec.empty())
		return false;;
	int row = vec.size();
	int col = vec[0].size();
	int i = 0;
	int j = col -1;
	while(i < row && j >= 0)
	{
		if(vec[i][j] == num)
		{
			return true;
		}
		else if(vec[i][j] > num)
			--j;
		else
			++i;
	}
	return false;
}
int main()
{
	int data;
	vector<vector<int>> vec;
	for(int i= 0;i <4;++i)
	{
		vector<int> tmp;
		for(int j= 0;j <4;++j)
		{
			cin >>data;
			tmp.push_back(data);
		}
		vec.push_back(tmp);
	}
	cout << IsExistNum(vec,16) << endl;
	return 0;
}
#endif