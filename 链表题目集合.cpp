#include<iostream>
#include<vector>
#include<stack>
#include<assert.h>
using namespace std;

/*
��Ŀ������
	����һ�������ͷ��㣬��β��ͷ��������ӡÿ���ڵ��ֵ��Ҫ�󣺲����޸������ֵ
*/
typedef int ELEM_TYPE;
typedef struct Node //������Ľ��ṹ��
{
	ELEM_TYPE mdata; //������
	struct Node* pnext;//�ṹ��ָ�����͵�ָ�룬�������ָ����
	struct Node* pslib;//�����������һ��ָ����
}Node,*Link;
void Init(Link phead)//��ʼ�����������ǽ�ͷ����ָ�����ÿ�
{
	assert(phead != NULL);
	if(phead == NULL)
	{
		return ;
	}
	phead->pnext = NULL;
}
static Link BuyNode()//������
{
	struct Node* pnewnode = (struct Node*)malloc(sizeof(struct Node));
	assert(pnewnode != NULL);
	pnewnode->pnext = NULL;
	return pnewnode; 
}

bool InsertTail(Link phead, ELEM_TYPE val)//β�壺�ҵ������β�����в��루��β����㣬���½ڵ㣩
{
	if(phead == NULL)
	{
		return false;
	}
	struct Node* pCur = phead;//����һ���ṹ��ָ�룬����ָ��phead->pnext
	while(pCur->pnext != NULL)//����pCur�ҵ������β��
	{
		pCur = pCur->pnext;//Pcur����ƶ�
	}
	struct Node* pnewnode = BuyNode();//����һ���µĽ��
	pnewnode->mdata = val;//��valֵ����pnewnode��������

	pCur->pnext = pnewnode;//pCur�ҵ����һ����㣬����ָ������Ϊpnewnode���ڴ��ַ
	return true;
}
#if 0
/*
��������ĵ�һ���������
*/
/*
����һ��������������ջ��
	�ֱ����������ջ����ջ֮��ջ��Ԫ�ؾ��������β���ڵ㣻��ջ����ʼ���бȽϣ�
	�����ͬ������ջ��Ԫ�أ�������һ���Ƚϣ�֪���ҵ����һ����ͬ�Ľ�㣻
ʱ�临�Ӷȣ�O(m+n)  �ռ临�Ӷȣ�O(m+n)
*/
/*
��������
	�ֱ������������ĳ���
	�ó����������߲�ֵ����Ȼ������������ͬ��ǰ�������ҵ���һ����ͬ�Ľ��������ǵĹ������
ʱ�临�Ӷȣ�O(m+n) ����Ҫ�����ռ�
*/
unsigned int GetLen(Link phead)
{
	unsigned int len = 0;
	Node *pcur = phead->pnext;
	while (pcur != nullptr)
	{
		len++;
		pcur = pcur->pnext;
	}
	return len;
}
Node *FirstCommonNode(Link phead1,Link phead2)
{
	unsigned int len1 = GetLen(phead1);
	unsigned int len2 = GetLen(phead2);
	int sub = len1 - len2;
	Node *plong = phead1->pnext;
	Node *pshort = phead2->pnext;
	if(len1 < len2)
	{
		plong = phead2->pnext;
		pshort = phead1->pnext;
		sub = len2 - len1;
	}

	for(int i = 0;i < sub;++i)
	{
		plong = plong->pnext;
	}
	while(plong != nullptr && pshort != nullptr && plong != pshort)
	{
		plong = plong->pnext;
		pshort = pshort->pnext;
	}
	Node* pcommon = plong;
	return pcommon;
}
#endif
#if 0
/*
���Ƹ�������
*/
/*
����һ��
	��һ��������ԭʼ�����ÿ���ڵ㲢��pnext����������
	�ڶ���������pslibָ�򣻱����������Ҫ���õ�ÿ�����S��pslibָ���N��㣻
ʱ�临�Ӷȣ�O(N2)
*/
/*
��������
	��һ��������ԭʼ�����ÿ���ڵ㲢��pnext��������;�������ù�ϣ������<N,N'>�������Ϣ��
	�ڶ���������pslibָ�������ԭʼ�����н��N��pslbָ��S����ô�ڸ�ֵ�����е�N��Ӧ��ָ��S'��
	���ڹ�ϣ��Ĵ��ڣ����ǿ�����O(1)��ʱ��ܾ�S�ҵ�S����
�Կռ任ʱ�䣻�ռ临�Ӷ�O(N); ʱ�临�Ӷȣ�O(N)
*/
/*
��������
	��һ��������ԭʼ�����ÿ���ڵ㣬����Ӧ��N'���ӵ�ԭʼ����N�ĺ�ߣ��������γɣ�
	AA'BB'CC'DD'EE'����������ע�⣺ԭʼ�������Լ�pslib��ָ��
	�ڶ��������ø��Ƴ����Ľ���pslib��Nָ��S����ôN'ָ��S'��
	�����������������ֳ�������������λ�õ���ԭʼ����Ľ�㣻ż��λ�õ��Ǹ��ƺ������Ľ�㣻���ݴ˽��в�֣�
�����ø����ռ����ʱ�临�Ӷȣ�O(N)
*/
//ʵ�ַ�����
void CloneNodes(Link phead)
{
	Node* pnode = phead->pnext;
	while(pnode != nullptr)
	{
		Node *pclone = new Node();
		pclone->mdata = pnode->mdata;
		pclone->pnext = pnode->pnext;
		pclone->pslib = nullptr;
		
		pnode->pnext = pclone;
		pnode = pclone->pnext;
	}
}

void ConnectSlibNodes(Link phead)
{
	Node *pnode = phead->pnext;
	while(pnode != nullptr)
	{
		Node *pclone = pnode->pnext;
		if(pnode->pslib != nullptr)
		{
			pclone->pslib = pnode->pslib->pnext;
		}
		pnode = pclone->pnext;
	}
}
Node* ReconnectNode(Link phead)
{
	Node *pnode = phead;
	Node *pclondehead = nullptr;
	Node *pclonenode = nullptr;
	if(pnode != nullptr)
	{
		pclondehead = pclonenode = pnode->pnext;
		pnode->pnext = pclonenode->pnext;
		pnode = pnode->pnext;
	}
	while(pnode != nullptr)
	{
		pclonenode->pnext = pnode->pnext;
		pclonenode = pclonenode->pnext;
		pnode->pnext = pclonenode->pnext;
		pnode = pnode->pnext;
	}
	return pclondehead;
}
Node* Clone(Link phead)
{
	CloneNodes(phead);
	ConnectSlibNodes(phead);
	ReconnectNode(phead);
}
#endif
#if 0
/*
�ϲ�������������
*/
Node* Merge(Link phead1,Link phead2)
{
	if(phead1 == nullptr && phead2 != nullptr)
		return phead2;
	if(phead1 != nullptr && phead2 == nullptr)
		return phead1;
	if(phead1 == nullptr && phead2 == nullptr)
		return nullptr;

	Node *pmehead = nullptr;
	if(phead1->mdata < phead2->mdata)
	{
		pmehead = phead1;
		pmehead->pnext = Merge(phead1->pnext,phead2);
	}
	else
	{
		pmehead = phead2;
		pmehead->pnext = Merge(phead1,phead2->pnext);
	}
	return pmehead;
}
#endif
#if 0
/*
����������/��ת����
*/
Node*  ReverseList(Link phead)
{
	if(phead == nullptr)
		return nullptr;
	Node *newhead = nullptr;//ָ�����ú������
	Node *pre = nullptr;//ǰ��
	Node *pcur = phead->pnext;//��ǰ���
	while(pcur != nullptr)
	{
		Node *pnex = pcur->pnext;//��ǰ������һ�����
		if(pnex==nullptr)
			newhead = pcur;
		pcur->pnext = pre;
		pre = pcur;
		pcur = pnex;
	}
	return newhead;
}
//�ݹ�ʵ������
Node*  ReverseList(Link phead)
{
    Node *p;
    p = phead;
    if (p->pnext == NULL)
    {
        return p;
    }
    else
    {
        ReverseList(p->pnext);
        p->pnext->pnext = p;
        if (p == phead)
        {
            p->pnext = NULL;
        }
    }
}
#endif

//�����л�����ڽ��
/*
��һ�����ж��Ƿ���ڻ�
*/
#if 0
Node* IsLoopAndMeetingNode(Link phead)
{
	if(phead == nullptr)
		return nullptr;
	Node* pfast = phead->pnext;
	Node* plow = pfast;
	while(plow != nullptr && pfast != nullptr)
	{
		if(pfast == plow)
		{
			return pfast;
			break;
		}
		plow = plow->pnext;
		pfast = pfast->pnext;
		if(pfast != nullptr)
			pfast = pfast->pnext;
		
	}
		return nullptr;
}
/*
�ڶ�������ȡ���н�����
*/
int LoopNodeNum(Link phead)
{
	Node *pcur = IsLoopAndMeetingNode(phead);
	int count = 0;
	if(pcur == nullptr)
		return count;
	Node* p = pcur;
	while(p != pcur)
	{
		p = p->pnext;
		count++;
	}
	return count;
}
/*
���������жϻ�����ڽ��
*/
Node* LoopEntryNode(Link phead)
{
	int count = LoopNodeNum(phead);
	if(count == 0)
		return nullptr;
	Node *pfast = phead->pnext;
	while(count != 0)
	{
		pfast = pfast->pnext;
		count--;
	}
	Node* plow = phead->pnext;
	while(plow != pfast)
	{
		plow = plow->pnext;
		pfast = pfast->pnext;
	}
	return pfast;
}
#endif
#if 0
/*
�����е�����K�����
*/
/*
����һ��
	��һ��ѭ����������������
	�ڶ���ѭ�������ҵ�len-k+1����������Ҫ�ĵ�����k�����
	ʱ�临�Ӷȣ�O(N2)
*/
Node *FindKOfTail1(Link phead,unsigned int k)
{
	if(phead == nullptr && k <= 0)
		return NULL;
	int index = 1;
	int len = 0;
	Node *p = phead->pnext;
	while(p != nullptr)
	{
		p = p->pnext;
		len++;
	}
	Node *pcur = phead->pnext;
	while(pcur != nullptr)
	{
		pcur = pcur->pnext;
		index++;
		if(index == (len-k+1))
		{
			break;
		}
	}
	return pcur;
}
/*
��������
	��������ָ�룬�������ָ�붼ָ���һ����㣻
	������һ��ָ������k-1��������ָ��һ����ǰ�ߣ�
	�����ߵ��Ǹ�ָ���ߵ����һ������ʱ�򣬺��ߵ��Ǹ�ָ����ָ��ľ���Ҫ��ĵ�����k����㣻
ע�⣺
	pheadΪNULL�Լ�k<=0�������
	�Լ���һ��ָ����k-1�����ߵ����һ���ڵ�����
*/
Node *FindKOfTail2(Link phead,unsigned int k)
{
	if(phead == nullptr && k <= 0)
		return NULL;
	Node *pcur = phead->pnext;
	Node *pnex = nullptr;
	//pcur����k-1��
	for(unsigned int i = 0;i < k-1;++i)
	{
		if(pcur->pnext != nullptr)
			pcur = pcur->pnext;
		else
			return nullptr;
	}
	pnex = phead->pnext;
	//pcur��pnex��ʼһ����ǰ�� ��pcur��next��Ϊ��ʱ��pnex��ָ��ľ��ǵ�����k�����
	while(pcur->pnext != nullptr)
	{
		pcur = pcur->pnext;
		pnex = pnex->pnext;
	}
	return pnex;
}
#endif
#if 0
/*
�������ɾ��  Ҫ��ʱ�临�Ӷ�ΪO(1)
ɾ�������еĽ��
*/
//��ȡҪɾ������ǰһ����㣬��ǰһ������next��ָ��Ҫɾ������next��
//ʱ�临�Ӷȣ�O(N)
void DeleteNodePre(Link phead,int val)
{
	if(phead == nullptr)
		return;
	Node* pcur = phead->pnext;
	Node* pre = pcur;
	while(pcur->mdata != val)
	{
		pre = pcur;
		pcur = pcur->pnext;
	}
	pre->pnext = pcur->pnext;
	free(pcur);
}

//�ҵ�Ҫɾ��������һ����㣬����һ����ֵ����Ҫɾ���Ľ�㣻Ȼ����һ�����ɾ��
//ʹ����ȷ�������ڲ���delnodeֱ��ָ��ľ���Ҫɾ���Ľ���λ��
/*
ʱ�临�Ӷȷ�����
	����n-1����β�ڵ���ԣ�������O(1)��ʱ���ڰ���һ������ֵ���ǵ�Ҫɾ���ڵ��ϣ���ɾ����һ����㣻
	����β��㣬��Ҫ˳�������ʱ�临�Ӷ�ΪO(N)��
	�ܵ�ʱ�临�Ӷȣ�[(n-1)*O(1)+ O(n)]/O(n) = O(1);
*/
void DeleteNodeNext(Link phead,Node *delnode)
{
	if(phead == nullptr || delnode == nullptr)
		return;
	//Ҫɾ���Ľ�㲻��β���
	if(delnode->pnext != nullptr)
	{
		Node *next = delnode->pnext;
		delnode->mdata = next->mdata;
		delnode->pnext = next->pnext;
		free(next);
		next = nullptr;
	}
	//Ҫɾ���Ľ���ǵ�һ�����
	else if(phead->pnext == delnode)
	{
		free(delnode);
		delnode = nullptr;
		phead->pnext = nullptr;
	}
	//Ҫɾ���Ľ����β���
	else 
	{
		Node *pcur = phead->pnext;
		while (pcur != delnode)
		{
			pcur = pcur->pnext;
		}
		pcur->pnext = nullptr;
		free(delnode);
		delnode = nullptr;
	}
}
#endif
#if 0
/*
��β��ͷ��ӡ������
*/
//��ջ������ݽṹʵ��β��ͷ�Ĵ�ӡ
/*
void Print(Node* phead)
{
	stack<int> st;
	Node *pCur = phead->pnext;
	while(pCur != NULL)
	{
		st.push(pCur->mdata);
		pCur = pCur->pnext;
	}
	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

vector<int> printListFromTailToHead(Node* head)
    {
        stack<int> st;
        vector<int> vec;
        Node *pCur = head->pnext;
        while(pCur != NULL)
        {
			st.push(pCur->mdata);
            pCur = pCur->pnext;
        }
        while(!st.empty())
        {
            vec.push_back(st.top());
            st.pop();
        }
        return vec;
}
*/

//�ݹ�ʵ�֣��ݹ���ĳ������������������ʾ����ջ�ռ䣬���ݴ�ӡ
vector<int> printListFromTailToHead(Node* head)
{
	vector<int> vec;
	if(head == NULL)
		return vec;
	else
	{
		if(head->pnext != nullptr)
		{
			printListFromTailToHead(head->pnext);
		}
		vec.push_back(head->mdata);
	}
	return vec;
}
#endif
#if 0
int main()
{
	Node head1;
	Init(&head1);
	for(int i =0;i<5;++i)
	{
		InsertTail(&head1,i+1);
	}
	/*
	Node head2 ;
	Init(&head2);
	InsertTail(&head2,2);
	InsertTail(&head2,3);
	InsertTail(&head2,5);
	InsertTail(&head2,8);
	Node * pme = Merge(&head1,&head2);
	*/
	/*
	Node *p = FindKOfTail2(&head,5);
	cout << p->mdata << endl;
	*/
	//DeleteNodePre(&head,3);
	//printListFromTailToHead(&head);
	return 0;
}
#endif