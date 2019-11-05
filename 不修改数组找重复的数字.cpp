#include<iostream>
#include<vector>
using namespace std;
#if 0
//����֤�ҳ����е��ظ�����
/*
ע��ʵ��Ҫ��
	�ҳ�����һ���ظ������ֻ������ҳ������ظ�������
	Ҫ��ʱ��Ч�ʻ��ǿռ�Ч��
*/
//���ù�ϣ���Կռ任ʱ�䣬���޸�ԭ��������ظ�����
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
//���ÿ����µĿռ�
//countRange������O(logN)�Σ�ÿ����Ҫ��ʱ�临�Ӷ�ΪO(N)����ʱ�临�Ӷ�ΪO(NlogN)���ռ临�Ӷ�ΪO(1)
/*
	����һ�����ֲ��ҵ�˼·
	�ܹ���1~n�����֣��������м�����m�����Ϊ������1~m��m+1~n;
	���1~m�����ֵ���Ŀ����m����ô��һ���������һ�������ظ����֣�
	������һ���m+1~n��һ�������ظ�������
	���Լ������������ֵ�����һ��Ϊ����ֱ���ҵ�һ���ظ����֣�
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
		int mid = ((end-start)>>1) + start;//���磺(7-1) = 6=> 0110 >> 1 ==> 0011  3+1=4
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