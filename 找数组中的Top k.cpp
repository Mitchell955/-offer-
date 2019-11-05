#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <functional>
using namespace std;
#if 0
//方法一：排序之后打印前K个  在排序的时候也需要一定的时间复杂度，根据不同的排序算法；找的时间复杂度O(K)
//总时间复杂度为O(NlogN)
//适用于内存足够的情况；但是内存是有限制的，当数据量很大达到内存限制的时候，此方法就不适用了。且该算法也不高效
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
//方法二;分治法 划分
//时间复杂度为O（N）  （只使用于内存够的情况）
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
//利用最大堆或者红黑树的解法（STL中的set和map底层就是用红黑树实现的，所以有时可以直接用set或者map）
//适用于海量数据的处理
//先构建一个容量为K的容器结构来存储所要的K个数；
/*
当容器内的数据少于k个数，则从n个整数中进行读取存入；
当容器满的时候，要进行下一个加载的时候，如果下一个数值比容器中最大的还要大，则就抛弃这个整数，继续遍历n个整数中的下一个；
当容器满，但是要加载的数据小于容器中最大的数值时，把要加载的这个数值放进容器，且删除容器中最大的数值；

所以，容器满后：要做的事情：一是找最大的数；二是有可能删除这个最大数；三是有可能插入一个新的数字
*/
//方法三：利用set进行处理
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

//方法四：哈希处理海量数据
/*
如果这些数据中有很多重复的数据，可以先通过hash法，把重复的数去掉。这样如果重复率很高的话，会减少很大的内存用量，从而缩小运算空间。
处理后的数据如果能够读入内存，则可以直接排序；否则可以使用分治法或者最小堆法来处理数据。
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