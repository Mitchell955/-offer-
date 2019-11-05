#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#if 0
//方法一：排序 从头到尾进行遍历
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
//方法二：利用哈希表结构进行查找，查找时间复杂度为O(1)，空间复杂度为O(n)
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
//方法三：重排数组，从头开始遍历，为每个数字找到其对应的下标进行放置；
//当它和第m个下标的数字相等时就出现了重复数字；
//总的时间复杂度为O(n)，空间复杂度为O(1)
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