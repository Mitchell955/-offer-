#if 0
#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
#include<iterator>
#include<set>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int Partition(vector<int>arr,int left,int right)//划分
    {
        int i = left;
        int j = right;
        int temp = arr[i];
        while(i < j)
        {
            while(i<j && arr[j] > temp) --j;
            if(i < j) arr[i] = arr[j];
            while(i<j && arr[i] <= temp) ++i;
            if(i < j) arr[j] = arr[i];
        }
        arr[i] = temp;
        return i;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) //找最小的k个数
    {
        int len = input.size();
        vector<int> output(k);
        int start = 0;
        int end = len-1;
        int index = Partition(input,start,end);
        while(index != k-1)
        {
            if(index > k-1)
            {
                end = index - 1;
                index = Partition(input,start,end);
            }
            else
            {
                start = index +1;
                index = Partition(input,start,end);
            }
        }
        for(int i = 0;i < k;++i)
        {
            output[i] = input[i];
        }
        return output;
    }
};
int main()
{
	int arr[] = {4,5,1,2,3,6,7,8};
	int len = sizeof(arr)/sizeof(arr[0]);
	vector<int>input (arr,arr+len);
	Solution pp;
	vector<int>output = pp.GetLeastNumbers_Solution(input,4);
	for(int i = 0;i < 4;++i)
	{
		cout << output[i] << endl;
	}
	return 0;
}

//回溯法
bool hasPathCore(const char *matrix,int rows,int cols,int row,int col,
				 const char *str,int pathLength,bool *visited)
{
	if(str[pathLength] == '\0')
	{
		return true;
	}
	bool hasPath = false;
	if(row >= 0 && row < rows && col >= 0 && col < cols 
	 && matrix[row*rows+col]==str[pathLength] && !visited[row*cols+col])
	 // 找到了对应的字符                               之前没有被访问过
	{
		++pathLength;
		visited[row*rows+col] = true;//修改访问状态
		//去该格子的四周查找下一个字符，是否能在路径内
		hasPath = hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited) 
					 ||hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited)
					 ||hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited)
					 ||hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited);
		if(!hasPath)
		{
			//未查到时，回溯到上一次查找，并修改访问权限
			--pathLength;
			visited[row*cols+col] = false;
		}
	}
	return hasPath;
}
bool hasPath(char *matrix,int rows,int cols,char *str)
{
	if(matrix == NULL || rows < 1 || cols < 1 || str == NULL )
	{
		return NULL;
	}
	bool *visited = new bool[rows*cols];//判断矩阵，判断是否经过了这个格子
	memset(visited,0,rows*cols);

	int pathLength = 0;//路径长度
	for(int row = 0;row < rows;++row)
	{
		for(int col = 0;col < cols;++col)
		{
			if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	char *matrix = {"abtgcfcsjdeh"};
	int rows = 3;
	int cols = 4;
	char *str = {"bfce"};
	cout << hasPath(matrix,rows,cols,str) << endl;
	return 0;
}

typedef multiset<int,greater<int>> intSet;
typedef multiset<int,greater<int>>::iterator setIterator;
void GetLeastNumbers(const vector<int>&data,intSet& leastNumbers,int k)
{
	leastNumbers.clear();
	if(k < 1 || data.size() < k)
	{
		return ;
	}
	vector<int>::const_iterator iter = data.begin();
	for(;iter != data.end();++iter)
	{
		if(leastNumbers.size() < k)
		{
			leastNumbers.insert(*iter);
		}
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
//利用划分进行查找
int Partition(int *arr,int left,int right)
{
	int i = left;
	int j = right;
	int temp = arr[i];
	while(i < j)
	{
		while(i<j && arr[j] > temp) --j;
		if(i < j) arr[i] = arr[j];
		while(i<j && arr[i] <= temp) ++i;
		if(i < j) arr[j] = arr[i];
	}
	arr[i] = temp;
	return i;
}
void  GetLeastNumbers(int *input,int n,int *output,int k)
{
	if(input == NULL || output == NULL || k>n ||n<=0||k<=0)
	{
		return ;
	}
	int start = 0;
	int end = n-1;
	int index = Partition(input,start,end);
	while(index != k-1)
	{
		if(index > k-1)
		{
			end = index - 1;
			index = Partition(input,start,end);
		}
		else
		{
			start = index +1;
			index = Partition(input,start,end);
		}
	}
	for(int i = 0;i < k;++i)
	{
		output[i] = input[i];
	}
}
int main()
{
	int input[] = {4,5,1,6,2,7,3,8};
	int len = sizeof(input)/sizeof(input[0]);
	int k = 4;
	int output[4] = {0};
	GetLeastNumbers(input,len,output,k);
	for(int i = 0;i < k;++i)
	{
		printf("%d ",output[i]);
	}
	printf("\n");
	return 0;
}


/*
方法一：
利用list容器模拟实现环的状态；
当迭代器指向了list容器的尾部时，调整迭代器指向，让它重新指向首部，这样就能模拟一个环的状态。
当然也可以实现一个循环单链表去存储数据，再删除时删掉第m个数据即可。
*/
int LastRemaining1(unsigned int n,unsigned int m)
{
	if(n < 1 || m < 1)
	{
		return -1;
	}
	unsigned int i = 0;
	list<int> numbers;
	for(i = 0;i < n;++i)
	{
		numbers.push_back(i);
	}
	list<int>::iterator current = numbers.begin();
	while (numbers.size() > 1)
	{
		for(int i = 1;i<m;++i)
		{
			++current;
			if(current == numbers.end())
			{
				current = numbers.begin();
			}
		}
		list<int>::iterator next = ++current;
		if(next == numbers.end())
		{
			next = numbers.begin();
		}
		--current;
		numbers.erase(current);
		current = next;
	}
	return *(current);
}

/*
方法二：
分析每次被删除的数字的规律，找到规律后可以直接计算出所剩下的数据
*/
int LastRemaining2(unsigned int n,unsigned int m)
{
	if(n < 1 || m < 1)
	{
		return -1;
	}
	int last = 0;
	for(int i = 2;i <= n;i++)
	{
		last = (last + m)%i;
	}
	return last;
}

int LastRemaining3(unsigned int n,unsigned int m)
{
	if(n < 1 || m < 1)
	{
		return -1;
	}
	return (LastRemaining3(n-1,m)+m)%n;
}
int main()
{
	cout << LastRemaining1(4000,3) <<endl;
	cout << LastRemaining1(0,3) <<endl;
	cout << LastRemaining1(8,3) <<endl;

	cout << LastRemaining2(4000,3) <<endl;
	cout << LastRemaining2(0,3) <<endl;
	cout << LastRemaining2(8,3) <<endl;

	cout << LastRemaining3(4000,3) <<endl;
	cout << LastRemaining3(0,3) <<endl;
	cout << LastRemaining3(8,3) <<endl;
	return 0;
}
  
#endif