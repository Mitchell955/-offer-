#include<iostream>
using namespace std;
/*
���ݷ������ӽ������ÿһ�������п���ѡ����ϵͳ��ѡ���һ�����еĽ��������
���ݷ��ǳ��ʺ��ж��������ɵ����⣬����ÿ�����趼�ж��ѡ���������ĳһ��ѡ��������һ��ѡ��ʱ��
�ͽ�����һ����Ȼ���������µ�ѡ�һֱ�����ظ�ѡ��ֱ���������յ�״̬��
*/
#if 0
/*
������12�������е�·��
��Ŀ������
	���һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
	·�����ԴӾ��������һ��ʼ��ÿһ�������ھ����������ҡ��ϡ����ƶ�һ��
	���һ��·�������˾����ĳһ����ô��·�������ٴν���ø��ӣ�
*/
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
	 // �ҵ��˶�Ӧ���ַ�                               ֮ǰû�б����ʹ�
	{
		++pathLength;
		visited[row*rows+col] = true;//�޸ķ���״̬
		//ȥ�ø��ӵ����ܲ�����һ���ַ����Ƿ�����·����
		hasPath = hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited) 
					 ||hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited)
					 ||hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited)
					 ||hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited);
		if(!hasPath)
		{
			//δ�鵽ʱ�����ݵ���һ�β��ң����޸ķ���Ȩ��
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
	bool *visited = new bool[rows*cols];//�жϾ����ж��Ƿ񾭹����������
	memset(visited,0,rows*cols);

	int pathLength = 0;//·������
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
#endif 
#if 0
/*
������13���������˶���Χ
��Ŀ������
	������һ��m��n�еķ���һ�������˴�����(0,0)�ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ��
	�����ܽ�������������������λ֮�ʹ���k�ĸ��ӡ���λ֮��ָ����ÿ������ÿһλ֮�ͣ�
	���磺��kΪ18��ʱ�򣬻������ܹ�����ķ���(35,37),��Ϊ3+5+3+7=18���������ܽ��뷽��35,38������Ϊ3+5+3+8>18
	�ʻ������ܹ�������ٸ�����?
*/
int GetDigSum(int number)
{
	int sum = 0;
	while(number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}
bool Check(int thre,int rows,int cols,int row,int col,bool *visited)
{
	if(row >= 0 && row < rows && col >= 0 && col < cols 
		&& GetDigSum(row)+GetDigSum(col) <= thre
		&& !visited[row*cols + col])
		return true;
	return false;
}
int MovingCountCore(int thre,int rows,int cols,int row,int col,bool *visited)
{
	int count = 0;
	if(Check(thre,rows,cols,row,col,visited))
	{
		visited[row*cols+col] = true;
		count  = 1 + MovingCountCore(thre,rows,cols,row-1,col,visited)
			       + MovingCountCore(thre,rows,cols,row,col-1,visited)
				   + MovingCountCore(thre,rows,cols,row+1,col,visited)
				   + MovingCountCore(thre,rows,cols,row,col+1,visited);
	}
	return count;
}
int MovingCount(int thre,int rows,int cols)
{
	if(thre < 0 || rows <= 0 || cols <= 0)
		return 0;
	bool *visited = new bool[rows*cols];
	for(int i = 0;i < rows*cols;++i)
	{
		visited[i] = false;
	}
	int count = MovingCountCore(thre,rows,cols,0,0,visited);
	delete[] visited;
	return count;
}
int main()
{
	int arr[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	cout << MovingCount(4,4,4) << endl;
	return 0;
}
#endif