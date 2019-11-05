#include<iostream>
#include<stack>
using namespace std;
#if 0
/*
��Ŀ������
	���������������У���һ�����б�ʾջ��ѹ�����У����жϵڶ��������Ƿ�Ϊ��ջ�ĵ������У�
	����ѹ��ջ���������־�����ȡ����磺����{1,2,3,4,5}��ĳջ����ջ���У�����{4,5,3,2,1}
	�Ǹ�ջ��һ���������У�����{4,3,5,1,2}�Ͳ������Ǹ�ջ�ĵ������У�
*/
/*
˼·��
	����һ������ջ�����в�����
*/
bool IsPopOrder(const int *pusharr,const int *poparr,int len)
{
	if(pusharr == nullptr || poparr == nullptr || len <= 0)
		return false;
	bool flag = false;
	stack<int> st1;
	const int *pnextpush = pusharr;
	const int *pnextpop = poparr;
	while(pnextpop - poparr < len)//����������������
	{
		while(st1.empty() || st1.top() != *pnextpop)//��ջΪ�ջ���ջ��Ԫ�ز�����*pnextpopʱ
		{
			if(pnextpush - pusharr == len)//��ʾѹջ�����е��������ֶ��ڸ���ջ��
			{
				break;
			}
			//ѹ��ѹջ���е�����
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
	//���գ�������ջΪ�ղ���pnextpopָ���ջ���е�β��ʱ����ʾ�˳�ջ���кϷ�
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