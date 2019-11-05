#include<iostream>
#include<stack>
using namespace std;
#if 0
/*
题目描述：
	定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数；
	在该栈中，调用min、push以及pop函数的时间复杂度都是O(1);
*/
#include<iostream>
#include<stack>
using namespace std;
//定义栈的数据结构实现
#include<assert.h>
template<typename T>
class MinofNuminStack
{
public:
	MinofNuminStack() {}//构造
    virtual ~MinofNuminStack() {}//析构
    T& top();//获取栈顶元素
    const T& top() const;//获取栈顶元素
    void push(const T& value);//入栈
    void pop();//出栈
    const T& min() const;//最小值
    bool empty() const;//判空
    size_t size() const;//长度
private:
	std::stack<T> sta1;//存放数据的初始栈
	std::stack<T> sta2;//辅助栈
};

template<typename T>
T& MinofNuminStack<T>::top()//获取栈顶元素
{
	return sta1.top();
}
template<typename T> 
const T& MinofNuminStack<T>::top() const;//获取栈顶元素
template<typename T>    
void MinofNuminStack<T>::push(const T& value)//入栈
{
	sta2.push(value);

  if(sta2.size() == 0 || value < sta2.top())
        sta2.push(value);
    else
        sta2.push(sta2.top());
}
template<typename T>    
void MinofNuminStack<T>::pop()//出栈
{
	assert(sta1.size() > 0 && sta2.size() > 0);
    sta1.pop();
    sta2.pop();
}
template<typename T>    
const T& MinofNuminStack<T>::min() const//最小值
{
	assert(sta1.size() > 0 && sta2.size() > 0);

    return sta2.top();
}
template<typename T>
bool MinofNuminStack<T>::empty() const//判空
{
	return sta1.empty();
}
template<typename T>
size_t MinofNuminStack<T>::size() const//长度
{
	return sta1.size();
}
//使用库中的栈的数据结构实现
int FindMinofNuminStack(int arr[],int len)
{
	if(arr == NULL || len <= 0)
	{
		return -1;
	}
	stack<int> sta1;//存放初始数据
	stack<int> sta2;//辅助栈  存放入栈到sta1时的当前最小数据
	sta1.push(arr[0]);
	sta2.push(sta1.top());
	for(int i = 1;i < len; i++)
	{
		sta1.push(arr[i]);
		if((sta1.top()) <= (sta2.top()))
		{
			sta2.push(sta1.top());
		}
		else
		{
			sta2.push(sta2.top());
		}
	}

	return sta2.top();
}
int main()
{
	int arr[] = {3,4,2,1};
	int len = sizeof(arr)/sizeof(arr[0]);
	cout<<FindMinofNuminStack(arr,len)<<endl;
	return 0;
}
#endif