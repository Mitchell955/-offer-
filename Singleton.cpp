#include<iostream>
using namespace std;
#if 0
//����ģʽ������ǰ���أ��������̰߳�ȫ����
//���Ƕ�����ǰ���ش���һ������Դ�˷�����
class Singtleton
{
public:
	static Singtleton* GetInstance()
	{
		return mysig;
	}
private:
	Singtleton(){}
	Singtleton(const Singtleton&rhs){}
	Singtleton operator=(const Singtleton&rhs){}
	static Singtleton *mysig;
};
Singtleton *Singtleton::mysig = new Singtleton();
//����ģʽ�����ӳټ��أ������̰߳�ȫ����
//�ʺϵ��̵߳ĵ���ģʽ,���ڶ��̶߳����ǲ���ȫ��
class Singtleton
{
public:
	static Singtleton* GetInstance()
	{
		if(mysig == nullptr)
		{
			mysig = new Singtleton();
		}
		return mysig;
	}
private:
	Singtleton(){}
	Singtleton(const Singtleton&rhs){}
	Singtleton operator=(const Singtleton&rhs){}
	static Singtleton *mysig;
};
Singtleton *Singtleton::mysig = nullptr;

//��linux����pthread_mutex_lock()���м�������pthread_mutex_unlock()���н�����
//�Ľ�һ�����û��������иĽ���һ��������;ÿ�ε���getinstanceʱ��Ҫ������Ӱ��Ч��
class Singtleton
{
public:
	static Singtleton::Singtleton* GetInstance()
	{
		//lock();
		if(mysig == nullptr)
		{
			mysig = new Singtleton();
		}
		//unlock();
		return mysig;
}
private:
	Singtleton(){}
	Singtleton(const Singtleton&rhs){}
	Singtleton operator=(const Singtleton&rhs){}
	static Singtleton *mysig;
};
Singtleton *Singtleton::mysig = nullptr;

/*
�Ľ��������ö��������ƣ���˫����������;
���ǵ�ִ��mysig = new Singtleton();ʱ��������Singtleton��û����ɳ�ʼ����mysig���Ѿ���ֵ�ˣ�
�����ᵼ������һ������GetInstance()�������̻߳�ȡ����δ��ɳ�ʼ����mysigָ�룻
*/
class Singtleton
{
public:
	static Singtleton::Singtleton* GetInstance()
	{
		if(mysig == nullptr)
		{
			//lock()
			if(mysig == nullptr)
			{
				mysig = new Singtleton();
			}
			//unlock()
		}
		return mysig;
}
private:
	Singtleton(){}
	Singtleton(const Singtleton&rhs){}
	Singtleton operator=(const Singtleton&rhs){}
	static Singtleton *mysig;
};
Singtleton *Singtleton::mysig = nullptr;
//��Linux�л���һ��ʵ�ַ�ʽ��Linux�ṩ��һ��pthread_once()�ĺ�����������֤��һ�������У�ĳ������ִֻ��һ�Σ�
int main()
{

	return 0;
}
#endif