#include<iostream>
#include<string.h>
using namespace std;
#if 0
class CMyString
{
public:
	CMyString(char *data=nullptr)//���캯��
	{
		data = new char[strlen(pdata)+1];
		strcpy(pdata,data);
	}
	//�������캯��
	CMyString(const CMyString&rhs)
	{
		if(&rhs != this)
		{
			pdata = new char[strlen(rhs.pdata)+1];
			strcpy(pdata,rhs.pdata);
		}
	}
	/*
	��ֵ����������غ��� ������
	�жϴ���Ĳ����͵�ǰ��ʵ����*this���Ƿ���ͬһ��ʵ�������ǵĻ��������������ǵĻ�ֱ�ӷ���*this
	�ͷ�this.pdata����Դ�������ÿգ�
	��this.pdata�����µ��ڴ棬��С��rhs.pdata��ȣ�
	��rhs.pdata������this.pdata
	*/
	CMyString& operator=(const CMyString&rhs)//��ֵ���㸻���غ���
	{
		if(this != &rhs)
		{
			delete[]pdata;
			pdata = nullptr;
			pdata = new char[strlen(rhs.pdata)+1];//�ڴ治��ʱ������ʧ�ܣ��ᵼ�³������
			strcpy(pdata,rhs.pdata);
		}
		return *this;
	}
	/*
	���߼��ĸ�ֵ����������غ����������쳣��ȫ�ԵĽⷨ��
	����һ����ʱʵ�����ڽ�����ʱʵ����ԭ����ʵ����
	*/
	/*
	CMyString& operator=(const CMyString&rhs)//��ֵ���㸻���غ���
	{
		if(this != &rhs)
		{
			CMyString strTemp(rhs);//�ڴ�֮ǰ��ԭ����ʵ����û�б��޸ĵģ�
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