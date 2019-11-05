#include<iostream>
#include<vector>
#include<stack>
#include<assert.h>
using namespace std;

/*
题目描述：
	输入一个链表的头结点，从尾到头反过来打印每个节点的值。要求：不能修改链表的值
*/
typedef int ELEM_TYPE;
typedef struct Node //单链表的结点结构体
{
	ELEM_TYPE mdata; //数据域
	struct Node* pnext;//结构体指针类型的指针，链表结点的指针域
	struct Node* pslib;//复杂链表的另一个指针域
}Node,*Link;
void Init(Link phead)//初始化链表，即就是将头结点的指针域置空
{
	assert(phead != NULL);
	if(phead == NULL)
	{
		return ;
	}
	phead->pnext = NULL;
}
static Link BuyNode()//申请结点
{
	struct Node* pnewnode = (struct Node*)malloc(sizeof(struct Node));
	assert(pnewnode != NULL);
	pnewnode->pnext = NULL;
	return pnewnode; 
}

bool InsertTail(Link phead, ELEM_TYPE val)//尾插：找的链表的尾部进行插入（找尾部结点，连新节点）
{
	if(phead == NULL)
	{
		return false;
	}
	struct Node* pCur = phead;//声明一个结构体指针，将其指向phead->pnext
	while(pCur->pnext != NULL)//利用pCur找到链表的尾部
	{
		pCur = pCur->pnext;//Pcur向后移动
	}
	struct Node* pnewnode = BuyNode();//申请一个新的结点
	pnewnode->mdata = val;//将val值赋给pnewnode的数据域

	pCur->pnext = pnewnode;//pCur找到最后一个结点，将其指针域置为pnewnode的内存地址
	return true;
}
#if 0
/*
两个链表的第一个公共结点
*/
/*
方法一：利用两个辅助栈；
	分别将两个结点入栈，入栈之后，栈顶元素就是链表的尾部节点；从栈顶开始进行比较；
	如果相同，弹出栈顶元素；进行下一个比较，知道找到最后一个相同的结点；
时间复杂度：O(m+n)  空间复杂度：O(m+n)
*/
/*
方法二：
	分别求出两个链表的长度
	让长的链表先走差值步；然后两个链表异同向前遍历，找到第一个相同的结点就是它们的公共结点
时间复杂度：O(m+n) 不需要辅助空间
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
复制复杂链表
*/
/*
方法一：
	第一步：复制原始链表的每个节点并用pnext连接起来；
	第二步：设置pslib指向；遍历链表查找要设置的每个结点S和pslib指向的N结点；
时间复杂度：O(N2)
*/
/*
方法二：
	第一步：复制原始链表的每个节点并用pnext连接起来;并且利用哈希表设置<N,N'>的配对信息；
	第二步：设置pslib指向；如果在原始链表中结点N的pslb指向S，那么在赋值链表中的N’应该指向S'。
	由于哈希表的存在，我们可以在O(1)的时间很据S找到S’；
以空间换时间；空间复杂度O(N); 时间复杂度：O(N)
*/
/*
方法三：
	第一步：复制原始链表的每个节点，将对应的N'连接到原始链表N的后边；这样就形成：
	AA'BB'CC'DD'EE'这样的链表（注意：原始链表保持自己pslib的指向）
	第二步：设置复制出来的结点的pslib。N指向S，那么N'指向S'；
	第三步：将长链表拆分成两个链表。奇数位置的是原始链表的结点；偶数位置的是复制后的链表的结点；根据此进行拆分；
不利用辅助空间提高时间复杂度：O(N)
*/
//实现方法三
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
合并两个有序链表
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
单链表逆置/反转链表
*/
Node*  ReverseList(Link phead)
{
	if(phead == nullptr)
		return nullptr;
	Node *newhead = nullptr;//指向逆置后的链表
	Node *pre = nullptr;//前驱
	Node *pcur = phead->pnext;//当前结点
	while(pcur != nullptr)
	{
		Node *pnex = pcur->pnext;//当前结点的下一个结点
		if(pnex==nullptr)
			newhead = pcur;
		pcur->pnext = pre;
		pre = pcur;
		pcur = pnex;
	}
	return newhead;
}
//递归实现逆置
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

//链表中环的入口结点
/*
第一步：判断是否存在环
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
第二步：获取环中结点个数
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
第三步：判断环的入口结点
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
链表中倒数第K个结点
*/
/*
方法一：
	第一步循环遍历计算链表长度
	第二步循环遍历找第len-k+1个结点就是所要的倒数第k个结点
	时间复杂度：O(N2)
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
方法二：
	设置两个指针，起初两个指针都指向第一个结点；
	让其中一个指针先走k-1步后，两个指针一起向前走；
	当先走的那个指针走到最后一个结点的时候，后走的那个指针所指向的就是要求的倒数第k个结点；
注意：
	phead为NULL以及k<=0的情况；
	以及第一个指针走k-1步后走到最后一个节点的情况
*/
Node *FindKOfTail2(Link phead,unsigned int k)
{
	if(phead == nullptr && k <= 0)
		return NULL;
	Node *pcur = phead->pnext;
	Node *pnex = nullptr;
	//pcur先走k-1步
	for(unsigned int i = 0;i < k-1;++i)
	{
		if(pcur->pnext != nullptr)
			pcur = pcur->pnext;
		else
			return nullptr;
	}
	pnex = phead->pnext;
	//pcur和pnex开始一起向前走 当pcur的next域为空时，pnex所指向的就是倒数第k个结点
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
单链表的删除  要求时间复杂度为O(1)
删除链表中的结点
*/
//获取要删除结点的前一个结点，将前一个结点的next域指向要删除结点的next域；
//时间复杂度：O(N)
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

//找到要删除结点的下一个结点，将下一个的值赋给要删除的结点；然后将下一个结点删除
//使用于确定结点存在并且delnode直接指向的就是要删除的结点的位置
/*
时间复杂度分析：
	对于n-1个非尾节点而言，可以在O(1)的时间内把下一个结点的值覆盖到要删除节点上，并删除下一个结点；
	对于尾结点，需要顺序遍历，时间复杂度为O(N)；
	总的时间复杂度：[(n-1)*O(1)+ O(n)]/O(n) = O(1);
*/
void DeleteNodeNext(Link phead,Node *delnode)
{
	if(phead == nullptr || delnode == nullptr)
		return;
	//要删除的结点不是尾结点
	if(delnode->pnext != nullptr)
	{
		Node *next = delnode->pnext;
		delnode->mdata = next->mdata;
		delnode->pnext = next->pnext;
		free(next);
		next = nullptr;
	}
	//要删除的结点是第一个结点
	else if(phead->pnext == delnode)
	{
		free(delnode);
		delnode = nullptr;
		phead->pnext = nullptr;
	}
	//要删除的结点是尾结点
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
从尾到头打印单链表
*/
//用栈这个数据结构实现尾到头的打印
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

//递归实现，递归在某种意义上来讲就是显示生成栈空间，回溯打印
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