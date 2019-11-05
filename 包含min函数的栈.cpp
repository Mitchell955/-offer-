#include<iostream>
#include<stack>
using namespace std;
#if 0
/*
��Ŀ������
	����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص�min������
	�ڸ�ջ�У�����min��push�Լ�pop������ʱ�临�Ӷȶ���O(1);
*/
#include<iostream>
#include<stack>
using namespace std;
//����ջ�����ݽṹʵ��
#include<assert.h>
template<typename T>
class MinofNuminStack
{
public:
	MinofNuminStack() {}//����
    virtual ~MinofNuminStack() {}//����
    T& top();//��ȡջ��Ԫ��
    const T& top() const;//��ȡջ��Ԫ��
    void push(const T& value);//��ջ
    void pop();//��ջ
    const T& min() const;//��Сֵ
    bool empty() const;//�п�
    size_t size() const;//����
private:
	std::stack<T> sta1;//������ݵĳ�ʼջ
	std::stack<T> sta2;//����ջ
};

template<typename T>
T& MinofNuminStack<T>::top()//��ȡջ��Ԫ��
{
	return sta1.top();
}
template<typename T> 
const T& MinofNuminStack<T>::top() const;//��ȡջ��Ԫ��
template<typename T>    
void MinofNuminStack<T>::push(const T& value)//��ջ
{
	sta2.push(value);

  if(sta2.size() == 0 || value < sta2.top())
        sta2.push(value);
    else
        sta2.push(sta2.top());
}
template<typename T>    
void MinofNuminStack<T>::pop()//��ջ
{
	assert(sta1.size() > 0 && sta2.size() > 0);
    sta1.pop();
    sta2.pop();
}
template<typename T>    
const T& MinofNuminStack<T>::min() const//��Сֵ
{
	assert(sta1.size() > 0 && sta2.size() > 0);

    return sta2.top();
}
template<typename T>
bool MinofNuminStack<T>::empty() const//�п�
{
	return sta1.empty();
}
template<typename T>
size_t MinofNuminStack<T>::size() const//����
{
	return sta1.size();
}
//ʹ�ÿ��е�ջ�����ݽṹʵ��
int FindMinofNuminStack(int arr[],int len)
{
	if(arr == NULL || len <= 0)
	{
		return -1;
	}
	stack<int> sta1;//��ų�ʼ����
	stack<int> sta2;//����ջ  �����ջ��sta1ʱ�ĵ�ǰ��С����
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