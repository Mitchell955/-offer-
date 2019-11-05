#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#if 0
template<typename T>
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);
	void appendTail(const T& node);//插入元素，入队操作
	T deleteHead(); //出队操作
private:
	stack<T> stack1;
	stack<T> stack2;
};
template <typename T>
CQueue<T>::CQueue(void)
{
}

template <typename T> 
CQueue<T>::~CQueue(void)
{
}

template<typename T>
void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);
} 

template<typename T> 
T CQueue<T>::deleteHead()
{
    if(stack2.size()<= 0)
    {
        while(stack1.size()>0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if(stack2.size() == 0)
        throw new exception("queue is empty");

    T head = stack2.top();
    stack2.pop();

    return head;
}
int main()
{
	CQueue<char> queue;
	queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
   
    head = queue.deleteHead();

    queue.appendTail('d');
    head = queue.deleteHead();

    queue.appendTail('e');
    head = queue.deleteHead();
	
	head = queue.deleteHead();

	return 0;
}

template <typename T>
class MyQueue
{
public:
	MyQueue(){}
	void Push(const T val)
	{
		st1.push(val);
	}
	void Pop()
	{
		if(st1.empty())
			return;
		while(!st1.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}
		if(!st2.empty())
			st2.pop();
	}
	int Getfront()
	{
		if(st2.empty())
			return -1;
		T val = st2.top();
		st2.pop();
		return val;
	}
	int DeleteHead()
	{
		T tmp = 0;
		if(st2.empty())
		{
			while (!st1.empty())
			{
				tmp = st1.top();
				st2.push(tmp);
				st1.pop();
			}
		}
		tmp = st2.top();
		st2.pop();
		return val;
	}
private:
	stack<T> st1;
	stack<T> st2;
};
int main()
{
	MyQueue<int>myqu;
	for(int i = 0;i < 10;++i)
	{
		myqu.Push(i+1);
	}
	myqu.DeleteHead();
	return 0;
}
#endif