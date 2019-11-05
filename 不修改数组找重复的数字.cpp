#include<iostream>
#include<vector>
using namespace std;
#if 0
//不保证找出所有的重复数字
/*
注意实现要求：
	找出任意一个重复的数字或者是找出所有重复的数字
	要求时间效率还是空间效率
*/
//利用哈希表，以空间换时间，不修改原数组查找重复数字
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
//不用开辟新的空间
//countRange被调用O(logN)次，每次需要的时间复杂度为O(N)；总时间复杂度为O(NlogN)，空间复杂度为O(1)
/*
	基于一个二分查找的思路
	总共有1~n个数字，按照其中间数字m将其分为两部分1~m和m+1~n;
	如果1~m的数字的数目超过m，那么这一半的区间里一定包含重复数字；
	否则，另一半的m+1~n中一定包含重复的数字
	可以继续将这两部分的区间一份为二，直到找到一个重复数字；
	*/
int countRange(const vector<int>vec,int n,int start,int end)
{
	int count = 0;
	for(int i = 0;i < n;++i)
	{
		if(vec[i] >= start && vec[i] <= end)
			++count;
	}
	return count;
}
void ReNum(int n,vector<int>vec)
{
	int start = 1;
	int end = n-1;
	while(end >= start)
	{
		int mid = ((end-start)>>1) + start;//例如：(7-1) = 6=> 0110 >> 1 ==> 0011  3+1=4
		int count = countRange(vec,n,start,mid);
		if(end == start)
		{
			if(count > 1)
			{
				cout << start << endl;
				break;
			}
			else
				break;
		}
		if(count > (mid - start + 1))
		{
			end = mid;
		}
		else
			start = mid + 1;
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