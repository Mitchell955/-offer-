#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#if 0
/*
题目描述：
在一个二维数组中，每一行是从左向右递增的序列，每一列是从上到下递增的序列；
给定一个数值和一个二维数组，在二维数组中判断是否含有该数值
*/
/*
解题：
以右上角的数字作为起始位置开始；
用所要查找的数字和其进行比较，如果==，直接返回true
大于：列--
小于：行++
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