#include<iostream>
using namespace std;
#if 0
//饿汉模式——提前加载，不存在线程安全问题
//但是对于提前加载存在一定的资源浪费问题
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
//懒汉模式——延迟加载，存在线程安全问题
//适合单线程的单例模式,对于多线程而言是不安全的
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

//在linux下用pthread_mutex_lock()进行加锁；用pthread_mutex_unlock()进行解锁；
//改进一：利用互斥锁进行改进，一重锁机制;每次调用getinstance时都要加锁，影响效率
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
改进二：利用二重锁机制，“双检锁”机制;
但是当执行mysig = new Singtleton();时，可能类Singtleton还没有完成初始化，mysig就已经有值了，
这样会导致另外一个调用GetInstance()方法的线程获取到还未完成初始化的mysig指针；
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
//在Linux中还有一种实现方式，Linux提供了一个pthread_once()的函数，函数保证在一个进程中，某个函数只执行一次；
int main()
{

	return 0;
}
#endif