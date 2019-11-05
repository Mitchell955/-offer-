#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <functional>
using namespace std;
#if 0
//����һ������֮���ӡǰK��  �������ʱ��Ҳ��Ҫһ����ʱ�临�Ӷȣ����ݲ�ͬ�������㷨���ҵ�ʱ�临�Ӷ�O(K)
//��ʱ�临�Ӷ�ΪO(NlogN)
//�������ڴ��㹻������������ڴ��������Ƶģ����������ܴ�ﵽ�ڴ����Ƶ�ʱ�򣬴˷����Ͳ������ˡ��Ҹ��㷨Ҳ����Ч
void FindTopK1(vector<int>vec,int k)
{
	int len = vec.size();
	if(k > len)
		return;
	sort(vec.begin(),vec.end());
	for(int i = 0;i < k;++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}
//������;���η� ����
//ʱ�临�Ӷ�ΪO��N��  ��ֻʹ�����ڴ湻�������
int Patition(vector<int> &vec,int start,int end)
{
	int i = start;
	int j = end;
	int tmp = vec[i];
	while(i < j)
	{
		while(i < j && vec[j] > tmp) --j;
		if(i < j)
			vec[i] = vec[j];
		while(i < j && vec[i] < tmp) ++i;
		if(i < j)
			vec[j] = vec[i];
	}
	vec[i] = tmp;
	return i;
}
void Select_K(vector<int>vec,int left,int right,int k)
{
	int pos = Patition(vec,left,right);
	while(pos != k-1)
	{
		if(pos > k-1)
		{
			right = pos-1;
			pos = Patition(vec,left,right);
		}
		else
		{
			left = pos + 1;
			pos = Patition(vec,left,right);
		}
	}
	for(int i = 0;i < k;++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}
void FindTopK2(vector<int>vec,int k)
{
	int len = vec.size();
	Select_K(vec,0,len-1,k);
}
//�������ѻ��ߺ�����Ľⷨ��STL�е�set��map�ײ�����ú����ʵ�ֵģ�������ʱ����ֱ����set����map��
//�����ں������ݵĴ���
//�ȹ���һ������ΪK�������ṹ���洢��Ҫ��K������
/*
�������ڵ���������k���������n�������н��ж�ȡ���룻
����������ʱ��Ҫ������һ�����ص�ʱ�������һ����ֵ�����������Ļ�Ҫ��������������������������n�������е���һ����
��������������Ҫ���ص�����С��������������ֵʱ����Ҫ���ص������ֵ�Ž���������ɾ��������������ֵ��

���ԣ���������Ҫ�������飺һ�����������������п���ɾ�����������������п��ܲ���һ���µ�����
*/
//������������set���д���
typedef multiset<int, std::greater<int> >            intSet; 
typedef multiset<int, std::greater<int> >::iterator  setIterator;
void FindTopK3(const vector<int>& data, intSet& leastNumbers, int k)
{
    leastNumbers.clear();
	int len = data.size();
    if(k < 1 || len < k)
        return;
	int numlen = leastNumbers.size();
    vector<int>::const_iterator iter = data.begin();
    for(; iter != data.end(); ++ iter)
    {
        if((numlen) < k)
            leastNumbers.insert(*iter);

        else
        {
            setIterator iterGreatest = leastNumbers.begin();

            if(*iter < *(leastNumbers.begin()))
            {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
}

//�����ģ���ϣ����������
/*
�����Щ�������кܶ��ظ������ݣ�������ͨ��hash�������ظ�����ȥ������������ظ��ʺܸߵĻ�������ٺܴ���ڴ��������Ӷ���С����ռ䡣
��������������ܹ������ڴ棬�����ֱ�����򣻷������ʹ�÷��η�������С�ѷ����������ݡ�
*/
int main()
{
	int arr[] = {54,67,23,67,73,8,55,78,99,100,56};
	int len = sizeof(arr)/sizeof(arr[0]);
	vector<int> vec(arr,arr+len);
	FindTopK2(vec,3);
	return 0;
}
#endif