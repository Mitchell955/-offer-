#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
/*
题目：
	给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
	说明:
	初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
	你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
	示例:
	输入：
	nums1 = [1,2,3,0,0,0], m = 3
	nums2 = [2,5,6],       n = 3
	输出: [1,2,2,3,5,6]
*/
#if 0
class Solution {
public:
	//合并后排序，时间复杂度高
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	{
		int j = 0;
		for(int i = m;i <(m+n);++i)
		{
			nums1[i] = nums2[j];
			j++;
		}
		sort(nums1.begin(),nums1.end());
    }
	//利用栈来实现，从尾到头遍历数组
	void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	{
		stack<int> st;
		int i = m-1;
		int j = n-1;
		while(i>=0 && j>=0)
		{
			if(nums2[j] >= nums1[i])
			{
				st.push(nums2[j]);
				--j;
			}
			else
			{
				st.push(nums1[i]);
				--i;
			}
		}
		while(i >= 0 && j < 0)
		{
			st.push(nums1[i]);
			--i;
		}
		while(i < 0 && j >= 0)
		{
			st.push(nums2[j]);
			--j;
		}
		for(int k = 0;k < (m+n);++k)
		{
			nums1[k] = st.top();
			st.pop();
		}
	}

};
int main()
{
	Solution pp;
	int n, m;
	cin >> m >> n;
	vector<int>nums1(n+m);
	vector<int>nums2(n);
	for(int i = 0;i < m+n;++i)
	{
		cin >> nums1[i];
	}
	for(int i = 0;i < n;++i)
	{
		cin >> nums2[i];
	}
	pp.merge1(nums1,m,nums2,n);
	for(int i=0;i<(m+n);++i)
	{
		cout << nums1[i] << " ";
	}
	cout<< endl;
	return 0;
}
#endif