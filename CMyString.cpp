#include<iostream>
#include<string.h>
using namespace std;
#if 0
class CMyString
{
public:
	CMyString(char *data=nullptr)//构造函数
	{
		data = new char[strlen(pdata)+1];
		strcpy(pdata,data);
	}
	//拷贝构造函数
	CMyString(const CMyString&rhs)
	{
		if(&rhs != this)
		{
			pdata = new char[strlen(rhs.pdata)+1];
			strcpy(pdata,rhs.pdata);
		}
	}
	/*
	赋值运算符的重载函数 三步：
	判断传入的参数和当前的实例（*this）是否是同一个实例；不是的话，以下三步，是的话直接返回*this
	释放this.pdata的资源，将其置空；
	给this.pdata申请新的内存，大小和rhs.pdata相等；
	将rhs.pdata拷贝到this.pdata
	*/
	CMyString& operator=(const CMyString&rhs)//赋值运算富重载函数
	{
		if(this != &rhs)
		{
			delete[]pdata;
			pdata = nullptr;
			pdata = new char[strlen(rhs.pdata)+1];//内存不足时，开辟失败，会导致程序崩溃
			strcpy(pdata,rhs.pdata);
		}
		return *this;
	}
	/*
	更高级的赋值运算符的重载函数（考虑异常安全性的解法）
	创建一个临时实例，在交换临时实例和原来的实例。
	*/
	/*
	CMyString& operator=(const CMyString&rhs)//赋值运算富重载函数
	{
		if(this != &rhs)
		{
			CMyString strTemp(rhs);//在此之前，原来的实例是没有别修改的；
			char *pTemp = strTemp.pdata;
			rhs.pdata = pdata;
			pdata = pTemp;
		}
		return *this;
	}
	*/
	~CMyString(void);
private:
	char *pdata;
};
int main()
{
	CMyString str1 = "hello";
	CMyString str2 = str1;
	CMyString str3 = "world";
	str3 = str1;
	return 0;
}
#endif