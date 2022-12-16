#include <stdio.h>
#include <stdlib.h>

int f(int *a,int n)
{
    int i;
    for(i=0;i<n/2;i++){
        int b=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=b;
    }

return 0;

}
int main(){
    int a[]={1,8,6,2,4};
    int i;
    f(a,sizeof(a)/sizeof(int));
    for(i=0;i<sizeof(a)/sizeof(int);i++){
        printf("%d ",a[i]);
    }
    return 0;
}




/*#include <stdio.h>
#include <stdlib.h>

typedef struct Radix
{
	int nValue;
	struct Radix *pNext;
}Radix;

void RadixSort(int arr[],int nLen)
{
	if(arr == NULL || nLen <= 0)
		return;

	int nBit = 1;
	int nMax = arr[0];

	//找出最大数
	for(int i = 1;i < nLen;i++)
	{
		if(nMax < arr[i])
		{
			nMax = arr[i];
		}
	}
	//计算位数
	while(nMax /= 10)
	{
		nBit++;
	}
	int n = 1;
	//定义一个指针数组来存数据,并开辟10个Radix空间
	Radix **pRadix = (Radix **)malloc(sizeof(Radix *)*10);
	Radix *pTemp = NULL;
	Radix *pMark = NULL;
	int nCount;
	Radix *pDel = NULL;
	//初始化为空
	for(int i = 0;i < 10;i++)
	{
		pRadix[i] = NULL;
	}
	for(int i = 0;i < nBit;i++)
	{
		//按位排序
		for(int j = 0;j < nLen;j++)
		{
			pTemp = (Radix*)malloc(sizeof(Radix));
			pTemp->nValue = arr[j];
			pTemp->pNext = NULL;

			if(pRadix[arr[j]/n%10] == NULL)
			{
				pRadix[arr[j]/n%10] = pTemp;
			}
			else
			{
				pMark = pRadix[arr[j]/n%10];
				while(pMark->pNext != NULL)
				{
					pMark = pMark->pNext;
				}
				pMark->pNext = pTemp;
			}
		}
		nCount = 0;
		//将数据重新放回原数组
		for(int j = 0;j < 10;j++)
		{
			while(pRadix[j] != NULL)
			{
				arr[nCount++] = pRadix[j]->nValue;
				pDel = pRadix[j];
				pRadix[j] = pRadix[j]->pNext;
				free(pDel);
				pDel = NULL;
			}
		}
		n *= 10;
	}
}

void Print(int arr[],int nLen)
{
	if(nLen <= 0) return;

	for(int i = 0;i < nLen;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{


	int n,i,s;
    scanf("%d",&n);
    int a[n]={0};
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    RadixSort(a,n);
	Print(a,n);
    return 0;
}
*/
/*#include <stdio.h>
#include <malloc.h>
typedef int KeyType;
typedef char InfoType[10];
typedef struct node
{
	KeyType key;              		//关键字项
	InfoType data;             		//其他数据域
	struct node *lchild,*rchild;	//左右孩子指针
} BSTNode;           				//二叉排序树结点类型
bool InsertBST(BSTNode *&bt,KeyType k)
//在二叉排序树bt中插入一个关键字为k的结点。插入成功返回真，否则返回假
{	if (bt==NULL)						//原树为空，新插入的结点为根结点
	{	bt=(BSTNode *)malloc(sizeof(BSTNode));
		bt->key=k; bt->lchild=bt->rchild=NULL;
		return true;
	}
	else if (k==bt->key) 				//树中存在相同关键字的结点，返回假
		return false;
	else if (k<bt->key)
		return InsertBST(bt->lchild,k);	//插入到左子树中
	else
		return InsertBST(bt->rchild,k);	//插入到右子树中
}

BSTNode *CreateBST(KeyType A[],int n)		//创建二叉排序树
//返回BST树根结点指针
{	BSTNode *bt=NULL;				//初始时bt为空树
	int i=0;
	while (i<n)
	{	InsertBST(bt,A[i]);			//将关键字A[i]插入二叉排序树bt中
		i++;
	}
	return bt;						//返回建立的二叉排序树的根指针
}

void DispBST(BSTNode *bt)		//输出一棵排序二叉树
{
	if (bt!=NULL)
	{	printf("%d",bt->key);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	printf("(");						//有孩子结点时才输出(
			DispBST(bt->lchild);				//递归处理左子树
			if (bt->rchild!=NULL) printf(",");	//有右孩子结点时才输出,
			DispBST(bt->rchild);				//递归处理右子树
			printf(")");						//有孩子结点时才输出)
		}
	}
}
BSTNode *SearchBST(BSTNode *bt,KeyType k)
{
    if (bt==NULL || bt->key==k)      	//递归终结条件
		return bt;
	if (k<bt->key)
       	return SearchBST(bt->lchild,k);  //在左子树中递归查找
    else
     	return SearchBST(bt->rchild,k);  //在右子树中递归查找
}
BSTNode *SearchBST1(BSTNode *bt,KeyType k,BSTNode *f1,BSTNode *&f)
/*在bt中查找关键字为k的结点,若查找成功,该函数返回该结点的指针,
f返回其双亲结点;否则,该函数返回NULL。
其调用方法如下:
	         SearchBST(bt,x,NULL,f);
这里的第3个参数f1仅作中间参数,用于求f,初始设为NULL*/
/*{
	if (bt==NULL)
	{
		f=NULL;
		return(NULL);
	}
	else if (k==bt->key)
	{
		f=f1;
		return(bt);
	}
	else if (k<bt->key)
       	return SearchBST1(bt->lchild,k,bt,f);  //在左子树中递归查找
    else
     	return SearchBST1(bt->rchild,k,bt,f);  //在右子树中递归查找
}

void Delete1(BSTNode *p,BSTNode *&r)  //当被删p结点有左右子树时的删除过程
{
	BSTNode *q;
	if (r->rchild!=NULL)
		Delete1(p,r->rchild);	//递归找最右下结点r
	else						//找到了最右下结点r
	{	p->key=r->key;			//将*结点的值赋给结点p
		q=r;
		r=r->lchild;			//直接将其左子树的根结点放在被删结点的位置上
		free(q);				//释放原结点r的空间
	}
}
void Delete(BSTNode *&p)		//从二叉排序树中删除p结点
{
	BSTNode *q;
	if (p->rchild==NULL)		//p结点没有右子树的情况
	{
		q=p;
		p=p->lchild;			//直接将其右子树的根结点放在被删结点的位置上
		free(q);
	}
	else if (p->lchild==NULL)	//p结点没有左子树的情况
	{
		q=p;
		p=p->rchild;			//将p结点的右子树作为双亲结点的相应子树
		free(q);
	}
	else Delete1(p,p->lchild);	//p结点既没有左子树又没有右子树的情况
}
int DeleteBST(BSTNode *&bt,KeyType k)	//在bt中删除关键字为k的结点
{
	if (bt==NULL)
		return 0;				//空树删除失败
	else
	{
		if (k<bt->key)
			return DeleteBST(bt->lchild,k);	//递归在左子树中删除为k的结点
		else if (k>bt->key)
			return DeleteBST(bt->rchild,k);	//递归在右子树中删除为k的结点
		else
		{
			Delete(bt);		//调用Delete(bt)函数删除*bt结点
			return 1;
		}
	}
}
void DestroyBST(BSTNode *&bt)		//销毁二叉排序树bt
{
	if (bt!=NULL)
	{
		DestroyBST(bt->lchild);
		DestroyBST(bt->rchild);
		free(bt);
	}
}
KeyType maxnode(BSTNode *p) //返回一棵二叉排序树中的最大结点
{
    while (p->rchild!=NULL)
    p=p->rchild;
    return(p->key);
}
KeyType minnode(BSTNode *p)	  //返回一棵二叉排序树中的最小结点
{
    while (p->lchild!=NULL)
    p=p->lchild;
    return(p->key);
}
void maxminnode(BSTNode *p)
{
	if (p!=NULL)
	{
		if (p->rchild!=NULL)
			printf("整棵树中最大结点为:%d\n",maxnode(p->rchild));
		if (p->lchild!=NULL)
			printf("整棵树中最小结点为:%d\n",minnode(p->lchild));
	}
}

int main()
{
	BSTNode *bt,*p,*f;
	int n=12,x=46;
	KeyType a[]={25,18,46,2,53,39,32,4,74,67,60,11};
    bt=CreateBST(a,n);
    DispBST(bt);
    maxminnode(bt);
	printf("2.删除%d结点\n",x);
	DeleteBST(bt,x);
	printf("BST:");
	DispBST(bt);
    x=180;
    p=NULL;
    f=NULL;
	printf("3.准备查找值为%d的结点\n",x);
    SearchBST1(bt,x,p,f);
	if(f!=NULL){
        printf("%d是存在的\n",x);
    }
    else{
        printf("%d是不存在的，需要插入到排序树中\n",x);
        InsertBST(bt,x);
        printf("插入后的排序树为：\n");
        DispBST(bt);
    }
    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //定义二维字符数组，用于存放5个字符串
    char *str[]={"Windows","Word","Excel","Foxpro","Visual Basic","Visual C++"};
    int i,j;
    char *temp;
    for(i=0;i<5;i++){
        for(j=0;j<5-i; j++){
            if(strlen(str[j])>strlen(str[j+1])){
                temp = str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }

    //输出排序后的二维字符数组的内容
    for(i=0;i<6;i++)
      printf("%s\n",str[i]);
    return 0;






}
*/
/*#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED
#include<string.h>
#include <iostream>
using namespace std;
struct Relation
{
    bool **Mat;  //存放关系矩矩阵
    string *Arr;  //存放元素集合
    int n;  //存放元素个数
};
void InitRelation(Relation &R,int n)  //初始化关系矩阵
{
    R.n=n;
    R.Arr=new string[n];
    R.Mat=new bool *[n];
    for(int j=0;j<n;j++)
    {
       R.Mat[j]=new bool[n];
       for(int k=0;k<n;k++)
        R.Mat[j][k]=false;
    }
}
void Show(Relation R)  //输出关系矩阵
{
    for(int i=0;i<R.n;i++){
        for(int j=0;j<R.n;j++){
            if(R.Mat[i][j]==0){
                continue;
            }else{
                cout<<'<'<<R.Arr[i]<<','<<R.Arr[j]<<'>';
            }
        }
    }
    cout<<endl;
    cout<<'{';
    for(int i=0;i<R.n-1;i++)
        cout<<R.Arr[i]<<", ";
    cout<<R.Arr[R.n-1]<<'}'<<endl;
    for(int i=0;i<R.n;i++)
    {
        for(int j=0;j<R.n;j++)
            cout<<R.Mat[i][j];
        cout<<endl;
    }
}
int Locate(Relation R,string str) //寻找目标元素在集合中的位置
{
    for(int i=0;i<R.n;i++)
    {
        if(str==R.Arr[i])
            return i;
    }
    return -1;
}
void CreateRelation(Relation &R) //输入关系
{
    string a,b;
    cout<<"请输入各元素"<<endl;
    for(int i=0;i<R.n;i++)
        cin>>R.Arr[i];
    cout<<"请给定各元素之间关系，以# #结束"<<endl;
    cin>>a;
    cin>>b;
    while(a!="#"||b!="#")
    {
        int i,j;
        i=Locate(R,a);
        j=Locate(R,b);
        if(i<0||j<0)
            cout<<"元素不合法，请检查！"<<endl;
        else
            R.Mat[i][j]=true;
        cin>>a;
        cin>>b;
    }

}
Relation ReflexiveClosure(Relation &R)   //求自反闭包
{
    Relation S;
    InitRelation(S,R.n);
    for(int i=0;i<R.n;i++)
    {
        S.Arr[i]=R.Arr[i];
        for(int j=0;j<R.n;j++)
            S.Mat[i][j]=R.Mat[i][j];
    }
    for(int i=0;i<S.n;i++)
        S.Mat[i][i]=true;
    return S;
}
Relation SymmetricClosure(Relation &R)  //求对称闭包
{
    Relation S;
    InitRelation(S,R.n);
    for(int i=0;i<R.n;i++)
    {
        S.Arr[i]=R.Arr[i];
        for(int j=0;j<R.n;j++)
            S.Mat[i][j]=R.Mat[i][j];
    }
    for(int i=0;i<S.n;i++)
    {
        for(int j=0;j<S.n;j++)
        {
            if(S.Mat[i][j]==true)
                S.Mat[j][i]=true;
        }
    }
    return S;
}
Relation TransitiveClosure(Relation &R)  //求传递闭包
{
    Relation S;
    InitRelation(S,R.n);
    for(int i=0;i<R.n;i++)
    {
        S.Arr[i]=R.Arr[i];
        for(int j=0;j<R.n;j++)
            S.Mat[i][j]=R.Mat[i][j];
    }
    for(int i=0;i<S.n;i++)
    {
        for(int j=0;j<S.n;j++)
        {
            if(S.Mat[i][j]==true)
            {
                for(int k=0;k<S.n;k++)
                {
                    if(S.Mat[j][k]==true)
                        S.Mat[i][k]=true;
                }
            }
        }
    }
    return S;
}
int NumOfEquivalent(int n)  //求等价关系数
{
    int a[n+1][n+1];
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        a[1][i]=1;
        a[i][i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
            a[i][j]=a[i-1][j-1]+i*a[i][j-1];
    }
   for(int i=1;i<=n;i++)
    sum+=a[i][n];
    return sum;
}
bool isReflexive(Relation R)  //验证自反性
{
    for(int i=0;i<R.n;i++)
    {
        if(R.Mat[i][i]!=true)
            return  false;
    }
    return true;
}
bool isSymmetric(Relation R)  //验证对称性
{
    for(int i=0;i<R.n;i++)
    {
        for(int j=i+1;i<R.n;j++)
        {
            if(R.Mat[i][j]!=R.Mat[j][i])
            return false;
        }
    }
    return true;
}
bool isTreansitive(Relation R)  //验证传递性
{
    for(int i=0;i<R.n;i++)
    {
        for(int j=0;j<R.n;j++)
        {
            if(R.Mat[i][j]==1)
            {
                for(int k=0;k<R.n;k++)
                {
                    if((R.Mat[j][k]==1&&R.Mat[i][k]==1)==false)
                        return false;
                }
            }
        }
    }
    return true;
}

void QuotientSet(Relation R)  //根据集合与关系求商集
{
    bool visited[R.n];
    for(int i=0;i<R.n;i++)
        visited[i]=false;
    if(isReflexive(R)==false&&isSymmetric(R)==false&&isTreansitive(R)==false)
    {
        cout<<"您输入的不是等价关系！"<<endl;
        return;
    }
    else
    {
        cout<<"商集为： "<<"{";
        for(int i=0;i<R.n;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
            cout<<"{";
            cout<<R.Arr[i];
            for(int j=0;j<R.n;j++)
            {
                if(R.Mat[i][j]==1&&visited[j]==false)
                {
                    visited[j]=true;
                    cout<<","<<R.Arr[j];
                }
            }
            cout<<"}";
            }
        }
        cout<<"}";
    }
}
#endif // RELATION_H_INCLUDED

int main()
{
    Relation A;
    cout<<"请输入元素个数"<<endl;
    int n;
    cin>>n;
    InitRelation(A,n);
    CreateRelation(A);
    cout<<"原始"<<endl;
    Show(A);
    cout<<"传递"<<endl;
    Show(TransitiveClosure(A));
    cout<<"自反"<<endl;
    Show(ReflexiveClosure(A));
    cout<<"对称"<<endl;
    Show(SymmetricClosure(A));
}*/



/*#include <stdio.h>
#include <string.h>


int main(){
    char arr[20];
    gets(arr);
    int i,r=strlen(arr),b=0,d;
    int s=r;
    for(i=0;i<s;i++){
        d=(int)(arr[r-i-1])-48;
        int e;
        e=i;
        while(e!=0){
            d*=2;
            e--;
        }
        b=d+b;

    }
    printf("%d",b);

    return 0;
}
*/

/*int main()
{
    char str1[20],str2[20];
    int i=0,r=0,j=0,x=0;
    printf("输入第一个字符串");
    gets(str1);
    printf("输入第二个字符串");
    gets(str2);
    while(str1[i]!='\0'||str2[j]!='\0'){
        if(str1[i]!='\0'){
            r++;
            i++;
        }
        if(str2[j]!='\0'){
            x++;
            j++;
        }
    }
    if(r>x){
        printf("1");
    }
    else if(r==x){
        printf("0");
    }
    else{
        printf("-1");
    }




    return 0;
}*/


/*#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;              //数据元素
    struct node *lchild;        //指向左孩子
    struct node *rchild;        //指向右孩子
} BTNode;
void CreateBTNode(BTNode *&b,char *str);        //由str串创建二叉链
BTNode *FindNode(BTNode *b,ElemType x);     //返回data域为x的节点指针
BTNode *LchildNode(BTNode *p);  //返回*p节点的左孩子节点指针
BTNode *RchildNode(BTNode *p);  //返回*p节点的右孩子节点指针
int BTNodeDepth(BTNode *b); //求二叉树b的深度
void DispBTNode(BTNode *b); //以括号表示法输出二叉树
void DestroyBTNode(BTNode *&b);  //销毁二叉树


int main(void){
    struct node*b;
    char str[MaxSize],i;
    int f;
    printf("1.请以括号表示法输入要建立的二叉树\n");
    scanf("%s",str);
    CreateBTNode(b,str);
    printf("2.建立的二叉树如下:\n");
    DispBTNode(b);
    printf("\n3.请输入要查找的节点:\n");
    i='c';
    //BTNode *q=FindNode(b,i);
    printf("sgs");
   // BTNode *a=LchildNode(q);
   // BTNode *d=RchildNode(q);
   // printf("查找到%c的节点,该节点的左右孩子分别为%c %c\n",i,a->data,d->data);
    f=BTNodeDepth(b);
    printf("4.该二叉树的深度为%d\n",f);
    //DestroyBTNode(b);
    printf("5.操作结束，释放该二叉树");
    return 0;

 }

 void CreateBTNode(BTNode *&b,char *str)
{
        BTNode *St[MaxSize],*p=NULL;
        int top=-1,k,j=0;
        char ch;
        b=NULL;
        ch=str[j];
        while (ch!='\0')
        {
            switch(ch)
            {
                case '(':top++;St[top]=p;k=1; break;
                case ')':top--;break;
                case ',':k=2; break;
                default:p=(BTNode *)malloc(sizeof(BTNode));
                p->data=ch;p->lchild=p->rchild=NULL;
                if (b==NULL)
                    b=p;
                else
                {
                    switch(k)
                    {
                        case 1:St[top]->lchild=p;break;
                        case 2:St[top]->rchild=p;break;
                    }
                }
            }
            j++;
            ch=str[j];
        }

}
BTNode *FindNode(BTNode *b,ElemType x)  //返回data域为x的节点指针
{
    BTNode *p;
    if (b->data==x) return b;
    else
    {
        p=FindNode(b->lchild,x);
        if (p!=NULL) return p;
        else return FindNode(b->rchild,x);
    }



}
BTNode *LchildNode(BTNode *p)   //返回*p节点的左孩子节点指针
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p)   //返回*p节点的右孩子节点指针
{
    return p->rchild;
}
int BTNodeDepth(BTNode *b)  //求二叉树b的深度
{
    int lchilddep=0,rchilddep=0;
    lchilddep=BTNodeDepth(b->lchild);
    rchilddep=BTNodeDepth(b->rchild);
    return(lchilddep>rchilddep)?(lchilddep+1):(rchilddep+1);
}
void DispBTNode(BTNode *b)  //以括号表示法输出二叉树
{
    if (b!=NULL)
    {
        printf("%c",b->data);
        if (b->lchild!=NULL || b->rchild!=NULL)
        {
            printf("(");
            DispBTNode(b->lchild);
            if (b->rchild!=NULL)
            printf(",");
            DispBTNode(b->rchild);
            printf(")");
        }
    }
}
void DestroyBTNode(BTNode *&b)   //销毁二叉树
{
    if(b!=NULL){
        if (b->lchild!=NULL|| b->rchild!=NULL)
        {
            DispBTNode(b->lchild);
            if (b->rchild!=NULL)
            free(b->rchild);
            free(b);

        }
    }
}*/
/*int main(){
        int i,j=0,a[100],b[100];
        for(i=0;i<100;i++){
            a[i]=i;
        }
        for(i=0;i<100;i++){
            if(a[i]!=-1){
                b[j]=a[i];
                a[i]=-1;
                j++;
                i=(i+3)%99;
            }
        }
        for(i=0;i<100;i++){
            printf("%d ",b[i]);
        }


        return 0;
}*/



/*
int main()
{
    int a,b,c,d,e=0;
    for(a=1;a<17;a++){
        for(b=1;b<17;b++){
            for(c=1;c<17;c++){
                for(d=0;d<17;d++){
                    if((a+b+c+d)==34&&a!=b&&a!=c&&a!=d&&b!=c&&b!=c&&b!=d&&c!=d){
                        e++;
                    }
                }
            }
        }

    }
    printf("%d",e);

      return 0;
}8/

/*#ifndef SQQUEUE_H_INCLUDED
#define SQQUEUE_H_INCLUDED

#define MaxSize 15

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front,rear;     /*队首和队尾指针*/
/*} SqQueue;


void InitQueue(SqQueue *&q);  //初始化顺序环形队列
void DestroyQueue(SqQueue *&q); //销毁顺序环形队列
bool QueueEmpty(SqQueue *q);  //判断顺序环形队列是否为空
int QueueLength(SqQueue *q);   //返回队列中元素个数，也称队列长度
bool enQueue(SqQueue *&q,ElemType e);   //进队
bool deQueue(SqQueue *&q,ElemType &e);  //出队
void dispQueue(SqQueue *&q); // 打印队列
void outQueue(SqQueue *&q); // 全部出队

#endif // SQQUEUE_H_INCLUDED
int main(){
    SqQueue *q;
    InitQueue(q);
    printf("1、初始化队列\n\n");
    printf("2、数据依次进入队列，请输入字符串\n");
    printf("请输入要插入的元素：");
    char arr[MaxSize];
    char e;
    int i;
    scanf("%s",arr);
    for(i=0;arr[i]!='\0';i++){
        enQueue(q,arr[i]);
    }
    printf("\n3、入队成功，当前队列中的数据有：\n");
    dispQueue(q);
    printf("\n4、判断队列是否为空：\n");
    QueueEmpty(q);
    printf("\n5、出队一个元素\n");
    deQueue(q,e);
    printf("出队元素为:%c",e);
    printf("，出队后队列元素为：");
    dispQueue(q);printf("\n");
    printf("\n6、队列中元素的个数为：");
    QueueLength(q);printf("\n");
    printf("\n7、将队列中所有元素删除并输出序列:\n");
    outQueue(q);printf("\n");
    DestroyQueue(q);
    printf("8、释放队列······队列已释放！");

}
void InitQueue(SqQueue *&q)  //初始化顺序环形队列
{
    q=(SqQueue *)malloc (sizeof(SqQueue));
    q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q) //销毁顺序环形队列
{
    free(q);
}
bool QueueEmpty(SqQueue *q)  //判断顺序环形队列是否为空
{
    if(q->rear==0){
        return false;
    }
    else{
        printf("[队列非空]\n");
    }

}


int QueueLength(SqQueue *q)   //返回队列中元素个数，也称队列长度
{
   int i;
   i=(q->rear-q->front+MaxSize)%MaxSize;
   printf("%d",i);
   return 0;
}

bool enQueue(SqQueue *&q,ElemType e)   //进队
{
    if((q->rear+1)%MaxSize==q->front)
        return false;
        q->rear=(q->rear+1)%MaxSize;
        q->data[q->rear]=e;



}
bool deQueue(SqQueue *&q,ElemType &e)  //出队
{
    if(q->front==q->rear)
        return false;
    q->front=(q->front+1)%MaxSize;
    e=q->data[q->front];
    return true;



}

void dispQueue(SqQueue *&q)
{
     for(char i=q->front+1;i<=q->rear;i++){
        printf("%c ",q->data[i]);
     }


}

void outQueue(SqQueue *&q) // 全部出队
{
    char e;

    while(deQueue(q, e)) {
        printf("%c ", e);
    }

    printf("\n出队完毕！\n");
}*/
/* #include<stdio.h>
 #include<math.h>
int main(){
    double I,P,r,a,n;
    int i=1;
    scanf("%lf %lf %lf",&P,&n,&r);
    a=1+r;
    while(i<n){
        a=a*(1+r);
        i++;
    }
    I=P*a-P;
    printf("interest=%.2lf",I);

    return 0;
}*/
/*int main()
 {
     float a1,b1,a2,b2,a3,b3,a,b,c,q,p,r;
        printf("请输入第1个横纵坐标：");
        scanf("%f,%f",&a1,&b1);
        printf("请输入第2个横纵坐标：");
        scanf("%f,%f",&a2,&b2);
        printf("请输入第3个横纵坐标：");
        scanf("%f,%f",&a3,&b3);
        a=sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
        b=sqrt((a1-a3)*(a1-a3)+(b1-b3)*(b1-b3));
        c=sqrt((a2-a3)*(a2-a3)+(b2-b3)*(b2-b3));
        printf("三条边长为：");
        printf("%f ",a);
        printf("%f ",b);
        printf("%f\n",c);
        if((a+b)>c&&(a+c)>b&&(b+c)>a){
            r=a+b+c;
            p=(a+b+c)/2;
            q=sqrt(p*(p-a)*(p-b)*(p-c));
            printf("周长为%f\n",r);
            printf("面积为%f\n",q);
        }
        else{
            printf("Impossible");
        }
        return 0;
 }
*/


/*#include "stdio.h"
#include "stdlib.h"
/****以下定义常量,****/
/*#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 //顺序表最大长度

/*以下定义类型的同义字*/
/*typedef int Status;    //凡遇到Status即为int类型
typedef int ElemType;  //凡遇到ElemType即为int类型

/*以下定义顺序表SeqList*/
/*typedef struct
{
    ElemType data[MAXSIZE]; //data用于存放表结点
    int length; // 表长度
}SeqList;
Status InitSeqList(SeqList *seqList) // *seqListL表示指向顺序表SeqList的指针
{
    seqList->length=0;  //置为空表
    return OK;
}
int GetDataByIndex(SeqList *seqList,int n);
void Display(SeqList *seqList);
Status Delete(SeqList *seqList,int n,ElemType *e);
Status Insert(SeqList *seqList,int n,ElemType e);
int GetSeqListLen(SeqList *seqList);
int main()
{
    //声明变量
    SeqList seqList; //创建顺序表
    int i,j,k,m,elem; //声明变量
    printf("\n*****************初始化************************\n");
    i=InitSeqList(&seqList);// 调用InitSeqList函数，其中&符号表示地址
    printf("初始化后表的长度为：%d\n",seqList.length);

    printf("\n*****************插入五条数据******************\n");
    for (j=1;j<=5;j++)
    {
	  printf("输入第%d条数据：",j);
	  scanf("%d",&m);
      i=Insert(&seqList,j,m);//调用Insert函数，在表头依次插入5个数
    }
    Display(&seqList); //调用Display函数，显示顺序表

    printf("\n*****************删除一条数据*******************\n");
    printf("删除哪条数据？");
	scanf("%d",&j);
    i=Delete(&seqList,j,&elem); //调用Delete函数，删除指定数据
    if (i==OK) printf("删除成功\n");
    Display(&seqList); //调用Display函数，显示顺序表

    printf("\n*****************按位置查找元素*****************\n");
	printf("查找第几条数据？");
	scanf("%d",&j);
    k=GetDataByIndex(&seqList,j);  //调用GetDataByIndex函数
    printf("\n第%d个元素为%d\n",j,k);

    printf("\n***************获取表的当前长度*****************\n");
    k=GetSeqListLen(&seqList);  //调用GetSeqListLen函数
    printf("当前表中还有%d个元素\n\n",k);
    getchar();
    return 0;
}
int GetDataByIndex(SeqList *seqList,int n)
{
    //检查位置是否超出范围
    if (n<1||n>seqList->length) return ERROR;
    return seqList->data[n-1];
}

/*打印结果*/
/*void Display(SeqList *seqList)
{
    int i;
    printf("\n********展示数据********\n");
    for (i=0;i<seqList->length;i++)
    {
        printf("%d\n",seqList->data[i]);
    }
    printf("\n");


}
Status Delete(SeqList *seqList,int n,ElemType *e)
{
    int k;

    //判断数组是否为空
    if (seqList->length==0) return ERROR;

    //判断n的位置是否合法
    if (n<1||n>seqList->length) return ERROR;

    *e=seqList->data[n-1];

    //如果删除不是最后位置
    if (n<seqList->length)
    {
        //将删除位置后继元素依次前移
        for (k=n;k<seqList->length;k++)
        {
            seqList->data[k-1]=seqList->data[k];
        }
    }

    //表长减1
    seqList->length--;
    return OK;
}
Status Insert(SeqList *seqList,int n,ElemType e)
{
    int k;
    //检查数组是否已满
    if (seqList->length>=MAXSIZE) return ERROR;

    //检查n的位置是否超出范围
    if (n<1||n>seqList->length+1) return ERROR;

    //若插入数据位置不在表尾
    if (n<=seqList->length)
    {
        //将要插入位置之后元素依次向后移动一位
        for (k=seqList->length-1;k>=n-1;k--)
        {
            seqList->data[k+1]=seqList->data[k];
        }
    }

    //将新元素插入到腾出的位置，并将表长加1
    seqList->data[n-1]=e;
    seqList->length++;
    return OK;
}
int GetSeqListLen(SeqList *seqList)
{
    return seqList->length;
}*/



/*#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#include <malloc.h>
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;		//指向后继结点
} LinkNode;
void InitList(LinkNode *&L);
void DispList(LinkNode *L);
bool ListInsert(LinkNode *&L,int i,ElemType e);
void CreateListR(LinkNode *&L,ElemType a[],int n);
void CreateListF(LinkNode *&L,ElemType a[],int n);
void  del_x(LinkNode *&L,int x);


#endif // LINKLIST_H_INCLUDED
#define N 6
int main()
{
	LinkNode *L;
	int i,a[N];
    int x;
	for (i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }

	InitList(L);
	CreateListR(L,a,N);
    printf("L:");DispList(L);
    printf("请输入要删除的元素：\n");
    scanf("%d",&x);
    del_x(L,x);
	printf("删除后为:\n");
	DispList(L);
}
void CreateListF(LinkNode *&L,ElemType a[],int n)
//头插法建立单链表
{
	LinkNode *s;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//创建头结点
	L->next=NULL;
	for (int i=0;i<n;i++)
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));//创建新结点s
		s->data=a[i];
		s->next=L->next;			//将结点s插在原开始结点之前,头结点之后
		L->next=s;
	}
}
void CreateListR(LinkNode *&L,ElemType a[],int n)
//尾插法建立单链表
{
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//创建头结点
	L->next=NULL;
	r=L;					//r始终指向终端结点,开始时指向头结点
	for (int i=0;i<n;i++)
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));//创建新结点s
		s->data=a[i];
		r->next=s;			//将结点s插入结点r之后
		r=s;
	}
	r->next=NULL;			//终端结点next域置为NULL
}
void InitList(LinkNode *&L)
{
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//创建头结点
	L->next=NULL;
}
void DestroyList(LinkNode *&L)
{
	LinkNode *pre=L,*p=pre->next;
	while (p!=NULL)
	{	free(pre);
		pre=p;
		p=pre->next;
	}
	free(pre);	//此时p为NULL,pre指向尾结点,释放它
}
bool ListEmpty(LinkNode *L)
{
	return(L->next==NULL);
}

void DispList(LinkNode *L)
{
	LinkNode *p=L->next;
	while (p!=NULL)
	{	printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

bool ListInsert(LinkNode *&L,int i,ElemType e)
{
	int j=0;
	LinkNode *p=L,*s;
	if (i<=0) return false;			//i错误返回假
	while (j<i-1 && p!=NULL)		//查找第i-1个结点p
	{	j++;
		p=p->next;
	}
	if (p==NULL)					//未找到位序为i-1的结点
		return false;
	else							//找到位序为i-1的结点*p
	{	s=(LinkNode *)malloc(sizeof(LinkNode));//创建新结点*s
		s->data=e;
		s->next=p->next;			//将s结点插入到结点p之后
		p->next=s;
		return true;
	}
}





void  del_x(LinkNode *&L,int x)
{
    LinkNode *s;
    LinkNode *q;
    LinkNode *p;
    q=L->next;
    L->next=NULL;
    for(s=q;s!=NULL;){
        if(s->data==x){
                s=s->next;
        }
        else{
                q=s;
                s=s->next;
                q->next=NULL;
                if(L->next==NULL){
                    L->next=q;
                    p=L->next;
                }
                else{
                    p->next=q;
                    p=p->next;
                }
            }
    }




}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int main( )
{
  int a=0,b=0;      // a用于产生的随机数，b用于接收用户输入的数。
  int count=0;      //count用于存放猜数的次数

  srand(time(0));
  a=rand()%100;     //产生100以内的随机数


  while(a!=b)		//当两个数不相等时循环
  {
      ++count;
      printf("开始第%d次猜数：",count);
      scanf("%d",&b);   //要求用户输入b的值
      if(b>a)
        printf("高了，再来！\n");
      else
        printf("低了，再来！\n");
  }
  printf("恭喜你，共用%d次猜对！\n",count);
  return 0;
}*/









//定义数据结构，length为顺序表实际元素个数
/*#define MAXSIZE 50

typedef struct
{
	int elem[MAXSIZE];
	int length;
}SeqList;

//------------------创建顺序表------------------
void creat(SeqList* s)
{
	int n, len, i;
	printf("输入顺序表的长度:\n");
	scanf("%d", &len);
	s->length = len;
	printf("输入顺序表的元素:\n");
	for (i = 0; i < len; i++)
	{
		scanf("%d", &n);
		s->elem[i] = n;
	}
}

//--------------------合并算法--------------------
void merge(SeqList* LA, SeqList* LB, SeqList* LC)
{
	int i, j, k;
	i = 0; j = 0; k = 0;
	while (i < LA->length && j < LB->length)
	{
		if (LA->elem[i] <= LB->elem[j])
		{
			LC->elem[k] = LA->elem[i];
			i++; k++;
		}
		else
		{
			LC->elem[k] = LB->elem[j];
			j++; k++;
		}
	}
	//当表LA比表LB长时，将表LA剩下的元素赋给表LC
	while (i < LA->length)
	{
		LC->elem[k] = LA->elem[i];
		i++; k++;
	}
	while (j < LB->length)
	{
		LC->elem[k] = LB->elem[j];
		j++; k++;
	}
	LC->length = LA->length + LB->length;
}
//--------------------输出所有元素--------------------
void print(SeqList* L)
{
	int i;
	if (L->length == 0) return;
	for (i = 0; i < L->length; i++)
		printf("%d  ", L->elem[i]);
	printf("\n");
}
int main()
{
	SeqList LA, LB, LC;
	creat(&LA);
	creat(&LB);
	printf("顺序表LA的元素为:\n");
	print(&LA);
	printf("顺序表LB的元素为:\n");
	print(&LB);
	printf("--------------开始合并顺序表------------\n");
	merge(&LA, &LB, &LC);
	printf("合并结果LC的元素为:\n");
	print(&LC);
	return 0;
}*/

/*#include "a.h"
#define _DEFINE_H
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define SQLMAXSIZE 100
typedef int Status;
typedef int SqlElemType;
typedef struct _Sqlist{
    SqlElemType*base;
    int length;
}Sqlist;
Status InitSL(Sqlist*L,int length){
    L->base=(SqlElemType*)malloc(sizeof(SqlElemType)*SQLMAXSIZE);
    if(!L->base)
        return OVERFLOW;
    L->length=0;

    for(int i=1;i<length+1;i++){
        SqlElemType e;
        scanf("%d",&e);
        SqlInsert(L,i,e);
    }
    return OK;
}
Status InitSL(Sqlist*L,int length){
    L->base =(SqlElemType*)malloc(sizeof(SqlElemType)*SQLMAXSIZE);
    if (!L->base)
        return OVERFLOW;
    L->length=0;

    for (int i=q;i<length+1;i++){
        SqlElemType e;
        scanf("%d",&e);
        SqlInsert(L,i,e);
    }
    return OK;
}
int main(){

    return 0;

}
/*int main()
{
    int i=1;
    do
    {
        printf("使用计算器请扣1，或按任意数字退出");
        scanf("%d",&i);
        if(i>1){
            return 0;
        }
        printf("你要算加减乘除那一种，用1234代替");
        int e,w,y;
        scanf("%d",&e);
        printf("输入你想要计算的数字");
        scanf("%d %d",&w,&y);
        switch(e)
        {
            case 1:
                Add(w,y);
                break;
            case 2:
                subtraction(w,y);
                break;
            case 3:
                multiplicate(w,y);
                break;
            case 4:
                division(w,y);
                break;


        }
    }while(i==1);
    return 0;
}*/
