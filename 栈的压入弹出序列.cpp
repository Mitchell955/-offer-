#include<iostream>
#include<stack>
using namespace std;
#if 0
/*
题目描述：
	输入两个整数序列，第一个序列表示栈的压入序列，请判断第二个序列是否为该栈的弹出序列；
	假设压入栈的所有数字均不相等。例如：序列{1,2,3,4,5}是某栈的入栈序列，序列{4,5,3,2,1}
	是该栈的一个弹出序列，但是{4,3,5,1,2}就不可能是该栈的弹出序列；
*/
/*
思路：
	借用一个辅助栈来进行操作；
*/
bool IsPopOrder(const int *pusharr,const int *poparr,int len)
{
	if(pusharr == nullptr || poparr == nullptr || len <= 0)
		return false;
	bool flag = false;
	stack<int> st1;
	const int *pnextpush = pusharr;
	const int *pnextpop = poparr;
	while(pnextpop - poparr < len)//遍历整个弹出序列
	{
		while(st1.empty() || st1.top() != *pnextpop)//当栈为空或者栈顶元素不等于*pnextpop时
		{
			if(pnextpush - pusharr == len)//表示压栈序列中的左右数字都在辅助栈中
			{
				break;
			}
			//压入压栈序列的数字
			st1.push(*pnextpush);
			pnextpush++;
		}
		if(st1.top() != *pnextpop)
		{
			break;
		}
		st1.pop();
		pnextpop++;
	}
	//最终，当辅助栈为空并且pnextpop指向出栈序列的尾部时，表示此出栈序列合法
	if(st1.empty() && pnextpop-poparr == len)
	{
		flag = true;
	}
	return flag;
}
int main()
{
	int arr[] = {1,2,3,4,5};
	int brr[] = {4,5,3,2,1};
	int crr[] = {4,5,3,1,2};
	cout << IsPopOrder(arr,brr,5) << endl;
	cout << IsPopOrder(arr,crr,5) << endl;
	return 0;
}
#endif