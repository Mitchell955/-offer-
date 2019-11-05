#include<iostream>
using namespace std;
/*
回溯法：它从解决问题每一步的所有可能选择里系统的选择出一个可行的解决方案。
回溯法非常适合有多个步骤组成的问题，并且每个步骤都有多个选项。当我们在某一部选择了其中一个选项时，
就进入下一步，然后又面临新的选项。一直这样重复选择直到到达最终的状态。
*/
#if 0
/*
面试题12：矩阵中的路径
题目描述：
	设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
	路径可以从矩阵的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
	如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子；
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
#endif 
#if 0
/*
面试题13：机器人运动范围
题目描述：
	地上有一个m行n列的方格。一个机器人从坐标(0,0)的格子开始移动，他每次可以向左、右、上、下移动一格；
	但不能进入行坐标和列坐标的数位之和大于k的格子。数位之和指的是每个数的每一位之和；
	例如：当k为18的时候，机器人能够进入的方格(35,37),因为3+5+3+7=18；但他不能进入方格（35,38），因为3+5+3+8>18
	问机器人能够到达多少个格子?
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