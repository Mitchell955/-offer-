#include<iostream>
#include<cstdlib>
using namespace std;
#if 0
//二维矩阵求解01背包
int V[200][200];
int Max(int a,int b)
{
	return a>=b?a:b;
}
//求最大价值
int KnapSack(int n,int w[],int v[],int c)
{
	int i,j;
	/*
	for(i = 0;i <= n;++i)
		V[i][0] = 0;
	for(j = 0;j <= c;++j)
		V[0][j] = 0;
	*/
	for(i = 0;i < n;++i)
	{
		for(j = 0;j <= c;++j)
		{
			if(j < w[i])
				V[i][j] = V[i-1][j];
			else
				V[i][j] = Max(V[i-1][j],V[i-1][j-w[i]] + v[i]);
		}
	}
	return V[n-1][c];
}
//打印二位矩阵结果
void Print(int n,int w[],int v[],int x[],int c)
{
	int i = 0;
	int j = 0;
	j = c;
	for(i = n - 1;i >= 0;i--)
	{
		if(V[i][j] > V[i-1][j])
		{
			x[i] = 1;
			j = j - w[i];
		}
		else
			x[i] = 0;
	}
	cout << "选中的物品是：" ;
	for(i = 0;i < n;++i)
	{
		cout << x[i] << " ";
	}
	cout << endl;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < c+1;j++)
		{
			cout << V[i][j] << "    ";
			if(j == c)
				cout << endl;
		}
	}
}
#endif
/*
一维矩阵求解01背包
*/
#if 0
int V[200];
void FindMaxValue(int n,int c,int w[],int v[])
{
	int i,j;
	for(i = 1;i <= n;++i)
	{
		for(j = 1;j <= c;++j)
		{
			if((V[j-w[i]] + v[i]) > V[j])
			{
				V[j] = V[j-w[i]] + v[i];
			}
		}
	}
	for(int i = 0;i <= c;++i)
	{
		cout << V[i] << " ";
	}
	cout << endl;
	
	cout << V[c-1] << endl;
}
int main()
{
	int s;
	int w[5] = {2,2,6,5,4};
	int v[5] = {6,3,5,4,6};
	int x[5] = {0};
	int n = 5;
	int c = 10;
	/*s =KnapSack(n,w,v,c);
	Print(n,w,v,x,c);
	cout << s << endl;*/
    FindMaxValue(n,c,w,v);
	return 0;
}
#endif