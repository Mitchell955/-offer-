#include<iostream>
#include<assert.h>
using namespace std;
#if 0
/*
翻转字符串
题目描述：
	输入一给英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
	例如：输入“I am a student.”,输出为“student. a am I”;
*/
//非递归字符串逆置  例如“hello”逆置为“olleh”
void Reverse(char *pbegin,char *pend)
{
	if(pbegin == pend || pend == nullptr)
		return;
	while(pbegin < pend)
	{
		char tmp = *pbegin;
		*pbegin = *pend;
		*pend = tmp;
		pbegin++;
		pend--;
	}
}
//递归字符串逆置
void Reverse(char *str)
{
	if(str == nullptr)
		return ;
	char tmp;
	int len = strlen(str);
	if (len>1)
	{
		tmp = str[0];
		str[0] = str[len - 1];
		str[len - 1] = '\0';
		
		Reverse(str+1);
		
		str[len - 1] = tmp;
	}
}
//翻转英文句子字符串
char *ReverSen(char *str)
{
	if(str == nullptr)
		return nullptr;
	char *pbegin = str;
	char *pend = str;
	while(*pend != '\0')
		pend++;
	pend--;
	Reverse(pbegin,pend);//翻转整个句子  即就是将“I am a student.”翻转为“.tneduts a ma I”

	//翻转句子中的每个单词
	pbegin = pend = str;
	while(*pbegin != '\0')
	{
		if(*pbegin == ' ')
		{
			pbegin++;
			pend++;
		}
		else if(*pend == ' '|| *pend == '\0')
		{
			Reverse(pbegin,--pend);
			pbegin = ++pend;
		}
		else
			pend++;
	}
	return str;
}

//左旋转字符串
/*
题目描述：
	字符串中的左旋操作就是把字符串前面的若干字符转移到字符串的尾部。
	例如：给定“abcdefg”和2，输出“cdefgab”
*/
char* LeftRotate(char *str,int k)
{
	if(str != nullptr)
	{
		int len = strlen(str);
		if(len > 0 && k > 0 && k < len)
		{
			char *firststart = str;
			char *firstend = str + k - 1;
			char *secondstart = str + k;
			char *secondend = str + len - 1;
			//翻转前面的部分
			Reverse(firststart,firstend);
			//翻转后面的部分
			Reverse(secondstart,secondend);
			//翻转整个字符串
			Reverse(firststart,secondend);
		}
	}
	return str;
}
int main()
{
	char str1[] = "I am a student.";
	char *ch = ReverSen(str1);
	cout << ch << endl;
	char str2[] = "abcdefg";
	LeftRotate(str2,2);
	return 0;
}
#endif
#if 0
/*
表示数值的字符串
题目描述：
	请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
	例如：字符串"+100","5e2","-123","13.1416"以及 "-1E-16"都表示数值，
	但是"12e","1a2.14","1 2.3" "+-4","12e+5.4"都不能表示一个数值；
*/
//表示数值的字符串遵循的模式为：A[.[B]][e|EC]或者.[B][eE|C] 

//用料扫描字符串中-0~9的数位，可以用来匹配前面数值模式中的B部分
bool UnsignInterge(const char **str)
{
	const char *before = *str;
	while(**str != '\0' && **str >= '0' && **str <= '9')
	{
		++(*str);
	}
	return *str > before;
}
//扫描可能以表示正负的‘+’或者‘-’为起始的0~9的数位，用来匹配前面数值模式的A和C部分
bool SInterge(const char **str)
{
	if(**str == '+' || **str == '-')
	{
		++(*str);
	}
	return UnsignInterge(str);
}

bool IsNum(const char *str)
{
	if(str == nullptr)
		return false;
	bool res = SInterge(&str);
	if(*str == '.')
	{
		++str;
		res = UnsignInterge(&str) || res;
	}
	if(*str == 'e' || *str == 'E')
	{
		++str;
		res = res && SInterge(&str);
	}
	return res && *str == '\0';
}
#endif
#if 0
/*
正则表达式匹配
题目描述：
	请实现一个函数用来匹配包含'.'和'*'的正则表达式。
	模式中的字符‘.’表示任意一个字符，‘*’表示它前边的字符可以出现任意次（包含0次）
	在本题中，匹配是指字符串的所有字符匹配整个模式。例如：字符串“aaa”与模式“a.a”和“ab*ac*a”匹配
	但与“aa.a”和“ab*a”均不匹配。
*/
bool MatchCore(char *str, char *pattern)
{
	if(*str == '\0' && *pattern == '\0')
		return true;
	if(*str == '\0' && *pattern != '\0')
		return false;
	if(*(pattern+1) == '*')
	{
		if(*pattern == *str || (*pattern == '.' && *str != '\0'))//当前字符匹配成功
		{
			return MatchCore(str+1,pattern+2)|| MatchCore(str+1,pattern) 
				   || MatchCore(str,pattern+1);
			/*三种可能性：
				一：str后移一位，pattern后移两位； "aaa"  "a*ac*a"
				二：str后移一位，pattern不变；     "aaa"  "a*ac*a" 
				三：str不变，pattern后移一位；      
			*/
		}
		else
		{
			return MatchCore(str,pattern+2);// "aaa"  "b*aa."
		}
	}
	if(*str == *pattern || (*pattern == '.' && *str != '\0'))
		return MatchCore(str+1,pattern+1);//aaa   a.a
	
	return false;
}
bool Match(char *str,char *patern)
{
	if(str == nullptr || patern == nullptr)
		return false;
	return MatchCore(str,patern);
}

int main()
{
	/*cout << IsNum("123.6543e3") << endl;
	cout << IsNum("123.+6543e3") << endl;*/
	/*cout << Match("aaa","a.a") << endl;
	cout << Match("aaa","a*ab*a") << endl;
	cout << Match("aaa","aaa*aa") << endl;
	cout << Match("aaa","...") << endl;
	*/
	return 0;
}

#endif

#if 0
/*
	strcpy
	strcmp
	strcat
	strlen
*/
int MyStrlen(char *des)
{
	int count = 0;
	while(*des != '\0')
	{
		count++;
		des++;
	}
	return count;
}
void Mystrcpy3(char *des,char *src)
{
	assert(des != NULL && src != NULL);
	while(*src != '\0')
	{
		*des = *src;
		des++;
		src++;
	}
	*des = '\0';
}

void Mystrcpy4(char *des,char *src)//++和*的优先级一样，按照运算法则，从右向左运算。
{
	assert(des != NULL && src != NULL);
	while(*src != '\0')
	{
		//*des++ = *src++;
		*(des++)=*(src++);//等价
	}
	*des = '\0';
}

void Mystrcpy5(char *des,char *src)
{
	assert(des != NULL && src != NULL);
	if(des == NULL && src == NULL)
	{
		return ;
	}
	while(*des++ = *src++);//当为'\0'时，while为0，循环为假，循环结束
	*des = '\0';
}
char *Mystrcpy6(char *des,char *src)
//返回值的目的：支持链式表达
//返回目标字符串的首地址
{
	char *p = des;//保存首地址
	while(*des++ = *src++);//当为'\0'时，while为0，循环为假，循环结束
	return p;
}

int Mystrcmp(char *str1,char *str2)
{
	assert(str1);
	assert(str2);
	int gap;
	while((gap=*str1-*str2)==0 && *str2!='\0')
	{
		str1++;
		str2++;
	}
	return gap;
}
char *Mystrcat(char *des,const char *src)
{
	assert(des!=NULL && src!=NULL);
	if(des==NULL || src==NULL)
	{
		return des;
	}
	char *p = des;
	while(*des != '\0')
	{
		des++;
	}
	while(*des++ = *src++);
	return p;
}

/*
	strncpy
	strncmp
	strncat
*/
//将src中的第n个字符之前的拷贝到des中
char *Mystrncpy(char *des,const char *src,size_t n)

{
	assert(des!=NULL && src!=NULL);
	size_t i;
	for(i = 0;i<n && src!='\0';i++)
	{
		des[i] = src[i];
	}
	while(i<n)
	{
		des[i++] = '\0';
	}
	return des;
}
//将src的前n个字符和des中的前n个字符进行比较
int Mystrncmp(const char *des,const char *src,size_t n)
{
	assert(des!=NULL && src!=NULL);
	size_t i = 0;
	for(;des!='\0' && src!='\0' && i<n;i++)
	{
		if(des[i] > src[i])
		{
			return 1;
		}
		else if(des[i] < src[i])
		{
			return -1;
		}
	}
	if(des[i] == '\0')
	{
		return 1;
	}
	else if(src[i] == '\0')
	{
		return -1;
	}
	else
		return 0;
}
//将src的前n个字符连接到des后边
char *Mystrncat(char *des,const char *src,int n)
{
	assert(des!=NULL && src!=NULL);
	int i;
	//char *p = des;
	while(*des != '\0')//先将des遍历到‘\0’处
	{
		des++;
	}
	
	for(i = 0;src[i]!='\0' && i<n;i++)//将src连接到des后边
	{
		des[i] = src[i];
	}
	des[i] = '\0';
	return des;
}

//字符串逆置/翻转
void Reverse(char *str)
{
	char *p = str;
	while(*p != '\0')
	{
		p++;
	}
	char tmp;
	for(p--;str<p;str++,p--)
	{
		tmp = *str;
		*str = *p;
		*p = tmp;
	}
}
//递归实现字符串翻转
char * ReverseD(char *des)
{
	assert(des!=nullptr);
	int len = strlen(des);   
    if( len > 1 )   
    {   
        char ctemp =des[0];   
        des[0] = des[len-1];      
        des[len-1] = '\0';// 最后一个字符在下次递归时不再处理   
        ReverseD(des+1); // 递归调用   
        des[len-1] = ctemp;   
    }   
    return des;   
}
//栈实现
void ReversePrint(char* arr,int len)
{
	stack<char> sta;
	int i = 0;
	for(i = 0 ;i < len;i++)
	{
		sta.push(arr[i]);  //入栈
	}
	while((sta.size()) > 0 ) //出栈
	{
		printf("%c",sta.top());
		sta.pop();
	}
	printf("\n");
}
int main()
{
	char des[100] = "hello";
	char src[] = "world";
	ReverseD(des);
	printf("%s\n",des);
	/*Mystrcpy4(des,src);
	printf("%s\n",des);

	int i = Mystrcmp(des,src);

	Mystrcat(des,src);
	printf("%s\n",des);
	int count = MyStrlen(src);
	cout << count<< endl;*/
	return 0;
}
#endif