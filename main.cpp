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

	//�ҳ������
	for(int i = 1;i < nLen;i++)
	{
		if(nMax < arr[i])
		{
			nMax = arr[i];
		}
	}
	//����λ��
	while(nMax /= 10)
	{
		nBit++;
	}
	int n = 1;
	//����һ��ָ��������������,������10��Radix�ռ�
	Radix **pRadix = (Radix **)malloc(sizeof(Radix *)*10);
	Radix *pTemp = NULL;
	Radix *pMark = NULL;
	int nCount;
	Radix *pDel = NULL;
	//��ʼ��Ϊ��
	for(int i = 0;i < 10;i++)
	{
		pRadix[i] = NULL;
	}
	for(int i = 0;i < nBit;i++)
	{
		//��λ����
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
		//���������·Ż�ԭ����
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
	KeyType key;              		//�ؼ�����
	InfoType data;             		//����������
	struct node *lchild,*rchild;	//���Һ���ָ��
} BSTNode;           				//�����������������
bool InsertBST(BSTNode *&bt,KeyType k)
//�ڶ���������bt�в���һ���ؼ���Ϊk�Ľ�㡣����ɹ������棬���򷵻ؼ�
{	if (bt==NULL)						//ԭ��Ϊ�գ��²���Ľ��Ϊ�����
	{	bt=(BSTNode *)malloc(sizeof(BSTNode));
		bt->key=k; bt->lchild=bt->rchild=NULL;
		return true;
	}
	else if (k==bt->key) 				//���д�����ͬ�ؼ��ֵĽ�㣬���ؼ�
		return false;
	else if (k<bt->key)
		return InsertBST(bt->lchild,k);	//���뵽��������
	else
		return InsertBST(bt->rchild,k);	//���뵽��������
}

BSTNode *CreateBST(KeyType A[],int n)		//��������������
//����BST�������ָ��
{	BSTNode *bt=NULL;				//��ʼʱbtΪ����
	int i=0;
	while (i<n)
	{	InsertBST(bt,A[i]);			//���ؼ���A[i]�������������bt��
		i++;
	}
	return bt;						//���ؽ����Ķ����������ĸ�ָ��
}

void DispBST(BSTNode *bt)		//���һ�����������
{
	if (bt!=NULL)
	{	printf("%d",bt->key);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	printf("(");						//�к��ӽ��ʱ�����(
			DispBST(bt->lchild);				//�ݹ鴦��������
			if (bt->rchild!=NULL) printf(",");	//���Һ��ӽ��ʱ�����,
			DispBST(bt->rchild);				//�ݹ鴦��������
			printf(")");						//�к��ӽ��ʱ�����)
		}
	}
}
BSTNode *SearchBST(BSTNode *bt,KeyType k)
{
    if (bt==NULL || bt->key==k)      	//�ݹ��ս�����
		return bt;
	if (k<bt->key)
       	return SearchBST(bt->lchild,k);  //���������еݹ����
    else
     	return SearchBST(bt->rchild,k);  //���������еݹ����
}
BSTNode *SearchBST1(BSTNode *bt,KeyType k,BSTNode *f1,BSTNode *&f)
/*��bt�в��ҹؼ���Ϊk�Ľ��,�����ҳɹ�,�ú������ظý���ָ��,
f������˫�׽��;����,�ú�������NULL��
����÷�������:
	         SearchBST(bt,x,NULL,f);
����ĵ�3������f1�����м����,������f,��ʼ��ΪNULL*/
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
       	return SearchBST1(bt->lchild,k,bt,f);  //���������еݹ����
    else
     	return SearchBST1(bt->rchild,k,bt,f);  //���������еݹ����
}

void Delete1(BSTNode *p,BSTNode *&r)  //����ɾp�������������ʱ��ɾ������
{
	BSTNode *q;
	if (r->rchild!=NULL)
		Delete1(p,r->rchild);	//�ݹ��������½��r
	else						//�ҵ��������½��r
	{	p->key=r->key;			//��*����ֵ�������p
		q=r;
		r=r->lchild;			//ֱ�ӽ����������ĸ������ڱ�ɾ����λ����
		free(q);				//�ͷ�ԭ���r�Ŀռ�
	}
}
void Delete(BSTNode *&p)		//�Ӷ�����������ɾ��p���
{
	BSTNode *q;
	if (p->rchild==NULL)		//p���û�������������
	{
		q=p;
		p=p->lchild;			//ֱ�ӽ����������ĸ������ڱ�ɾ����λ����
		free(q);
	}
	else if (p->lchild==NULL)	//p���û�������������
	{
		q=p;
		p=p->rchild;			//��p������������Ϊ˫�׽�����Ӧ����
		free(q);
	}
	else Delete1(p,p->lchild);	//p����û����������û�������������
}
int DeleteBST(BSTNode *&bt,KeyType k)	//��bt��ɾ���ؼ���Ϊk�Ľ��
{
	if (bt==NULL)
		return 0;				//����ɾ��ʧ��
	else
	{
		if (k<bt->key)
			return DeleteBST(bt->lchild,k);	//�ݹ�����������ɾ��Ϊk�Ľ��
		else if (k>bt->key)
			return DeleteBST(bt->rchild,k);	//�ݹ�����������ɾ��Ϊk�Ľ��
		else
		{
			Delete(bt);		//����Delete(bt)����ɾ��*bt���
			return 1;
		}
	}
}
void DestroyBST(BSTNode *&bt)		//���ٶ���������bt
{
	if (bt!=NULL)
	{
		DestroyBST(bt->lchild);
		DestroyBST(bt->rchild);
		free(bt);
	}
}
KeyType maxnode(BSTNode *p) //����һ�ö����������е������
{
    while (p->rchild!=NULL)
    p=p->rchild;
    return(p->key);
}
KeyType minnode(BSTNode *p)	  //����һ�ö����������е���С���
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
			printf("�������������Ϊ:%d\n",maxnode(p->rchild));
		if (p->lchild!=NULL)
			printf("����������С���Ϊ:%d\n",minnode(p->lchild));
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
	printf("2.ɾ��%d���\n",x);
	DeleteBST(bt,x);
	printf("BST:");
	DispBST(bt);
    x=180;
    p=NULL;
    f=NULL;
	printf("3.׼������ֵΪ%d�Ľ��\n",x);
    SearchBST1(bt,x,p,f);
	if(f!=NULL){
        printf("%d�Ǵ��ڵ�\n",x);
    }
    else{
        printf("%d�ǲ����ڵģ���Ҫ���뵽��������\n",x);
        InsertBST(bt,x);
        printf("������������Ϊ��\n");
        DispBST(bt);
    }
    return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //�����ά�ַ����飬���ڴ��5���ַ���
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

    //��������Ķ�ά�ַ����������
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
    bool **Mat;  //��Ź�ϵ�ؾ���
    string *Arr;  //���Ԫ�ؼ���
    int n;  //���Ԫ�ظ���
};
void InitRelation(Relation &R,int n)  //��ʼ����ϵ����
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
void Show(Relation R)  //�����ϵ����
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
int Locate(Relation R,string str) //Ѱ��Ŀ��Ԫ���ڼ����е�λ��
{
    for(int i=0;i<R.n;i++)
    {
        if(str==R.Arr[i])
            return i;
    }
    return -1;
}
void CreateRelation(Relation &R) //�����ϵ
{
    string a,b;
    cout<<"�������Ԫ��"<<endl;
    for(int i=0;i<R.n;i++)
        cin>>R.Arr[i];
    cout<<"�������Ԫ��֮���ϵ����# #����"<<endl;
    cin>>a;
    cin>>b;
    while(a!="#"||b!="#")
    {
        int i,j;
        i=Locate(R,a);
        j=Locate(R,b);
        if(i<0||j<0)
            cout<<"Ԫ�ز��Ϸ������飡"<<endl;
        else
            R.Mat[i][j]=true;
        cin>>a;
        cin>>b;
    }

}
Relation ReflexiveClosure(Relation &R)   //���Է��հ�
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
Relation SymmetricClosure(Relation &R)  //��ԳƱհ�
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
Relation TransitiveClosure(Relation &R)  //�󴫵ݱհ�
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
int NumOfEquivalent(int n)  //��ȼ۹�ϵ��
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
bool isReflexive(Relation R)  //��֤�Է���
{
    for(int i=0;i<R.n;i++)
    {
        if(R.Mat[i][i]!=true)
            return  false;
    }
    return true;
}
bool isSymmetric(Relation R)  //��֤�Գ���
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
bool isTreansitive(Relation R)  //��֤������
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

void QuotientSet(Relation R)  //���ݼ������ϵ���̼�
{
    bool visited[R.n];
    for(int i=0;i<R.n;i++)
        visited[i]=false;
    if(isReflexive(R)==false&&isSymmetric(R)==false&&isTreansitive(R)==false)
    {
        cout<<"������Ĳ��ǵȼ۹�ϵ��"<<endl;
        return;
    }
    else
    {
        cout<<"�̼�Ϊ�� "<<"{";
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
    cout<<"������Ԫ�ظ���"<<endl;
    int n;
    cin>>n;
    InitRelation(A,n);
    CreateRelation(A);
    cout<<"ԭʼ"<<endl;
    Show(A);
    cout<<"����"<<endl;
    Show(TransitiveClosure(A));
    cout<<"�Է�"<<endl;
    Show(ReflexiveClosure(A));
    cout<<"�Գ�"<<endl;
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
    printf("�����һ���ַ���");
    gets(str1);
    printf("����ڶ����ַ���");
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
    ElemType data;              //����Ԫ��
    struct node *lchild;        //ָ������
    struct node *rchild;        //ָ���Һ���
} BTNode;
void CreateBTNode(BTNode *&b,char *str);        //��str������������
BTNode *FindNode(BTNode *b,ElemType x);     //����data��Ϊx�Ľڵ�ָ��
BTNode *LchildNode(BTNode *p);  //����*p�ڵ�����ӽڵ�ָ��
BTNode *RchildNode(BTNode *p);  //����*p�ڵ���Һ��ӽڵ�ָ��
int BTNodeDepth(BTNode *b); //�������b�����
void DispBTNode(BTNode *b); //�����ű�ʾ�����������
void DestroyBTNode(BTNode *&b);  //���ٶ�����


int main(void){
    struct node*b;
    char str[MaxSize],i;
    int f;
    printf("1.�������ű�ʾ������Ҫ�����Ķ�����\n");
    scanf("%s",str);
    CreateBTNode(b,str);
    printf("2.�����Ķ���������:\n");
    DispBTNode(b);
    printf("\n3.������Ҫ���ҵĽڵ�:\n");
    i='c';
    //BTNode *q=FindNode(b,i);
    printf("sgs");
   // BTNode *a=LchildNode(q);
   // BTNode *d=RchildNode(q);
   // printf("���ҵ�%c�Ľڵ�,�ýڵ�����Һ��ӷֱ�Ϊ%c %c\n",i,a->data,d->data);
    f=BTNodeDepth(b);
    printf("4.�ö����������Ϊ%d\n",f);
    //DestroyBTNode(b);
    printf("5.�����������ͷŸö�����");
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
BTNode *FindNode(BTNode *b,ElemType x)  //����data��Ϊx�Ľڵ�ָ��
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
BTNode *LchildNode(BTNode *p)   //����*p�ڵ�����ӽڵ�ָ��
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p)   //����*p�ڵ���Һ��ӽڵ�ָ��
{
    return p->rchild;
}
int BTNodeDepth(BTNode *b)  //�������b�����
{
    int lchilddep=0,rchilddep=0;
    lchilddep=BTNodeDepth(b->lchild);
    rchilddep=BTNodeDepth(b->rchild);
    return(lchilddep>rchilddep)?(lchilddep+1):(rchilddep+1);
}
void DispBTNode(BTNode *b)  //�����ű�ʾ�����������
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
void DestroyBTNode(BTNode *&b)   //���ٶ�����
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
    int front,rear;     /*���׺Ͷ�βָ��*/
/*} SqQueue;


void InitQueue(SqQueue *&q);  //��ʼ��˳���ζ���
void DestroyQueue(SqQueue *&q); //����˳���ζ���
bool QueueEmpty(SqQueue *q);  //�ж�˳���ζ����Ƿ�Ϊ��
int QueueLength(SqQueue *q);   //���ض�����Ԫ�ظ�����Ҳ�ƶ��г���
bool enQueue(SqQueue *&q,ElemType e);   //����
bool deQueue(SqQueue *&q,ElemType &e);  //����
void dispQueue(SqQueue *&q); // ��ӡ����
void outQueue(SqQueue *&q); // ȫ������

#endif // SQQUEUE_H_INCLUDED
int main(){
    SqQueue *q;
    InitQueue(q);
    printf("1����ʼ������\n\n");
    printf("2���������ν�����У��������ַ���\n");
    printf("������Ҫ�����Ԫ�أ�");
    char arr[MaxSize];
    char e;
    int i;
    scanf("%s",arr);
    for(i=0;arr[i]!='\0';i++){
        enQueue(q,arr[i]);
    }
    printf("\n3����ӳɹ�����ǰ�����е������У�\n");
    dispQueue(q);
    printf("\n4���ж϶����Ƿ�Ϊ�գ�\n");
    QueueEmpty(q);
    printf("\n5������һ��Ԫ��\n");
    deQueue(q,e);
    printf("����Ԫ��Ϊ:%c",e);
    printf("�����Ӻ����Ԫ��Ϊ��");
    dispQueue(q);printf("\n");
    printf("\n6��������Ԫ�صĸ���Ϊ��");
    QueueLength(q);printf("\n");
    printf("\n7��������������Ԫ��ɾ�����������:\n");
    outQueue(q);printf("\n");
    DestroyQueue(q);
    printf("8���ͷŶ��С������������������ͷţ�");

}
void InitQueue(SqQueue *&q)  //��ʼ��˳���ζ���
{
    q=(SqQueue *)malloc (sizeof(SqQueue));
    q->front=q->rear=0;
}
void DestroyQueue(SqQueue *&q) //����˳���ζ���
{
    free(q);
}
bool QueueEmpty(SqQueue *q)  //�ж�˳���ζ����Ƿ�Ϊ��
{
    if(q->rear==0){
        return false;
    }
    else{
        printf("[���зǿ�]\n");
    }

}


int QueueLength(SqQueue *q)   //���ض�����Ԫ�ظ�����Ҳ�ƶ��г���
{
   int i;
   i=(q->rear-q->front+MaxSize)%MaxSize;
   printf("%d",i);
   return 0;
}

bool enQueue(SqQueue *&q,ElemType e)   //����
{
    if((q->rear+1)%MaxSize==q->front)
        return false;
        q->rear=(q->rear+1)%MaxSize;
        q->data[q->rear]=e;



}
bool deQueue(SqQueue *&q,ElemType &e)  //����
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

void outQueue(SqQueue *&q) // ȫ������
{
    char e;

    while(deQueue(q, e)) {
        printf("%c ", e);
    }

    printf("\n������ϣ�\n");
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
        printf("�������1���������꣺");
        scanf("%f,%f",&a1,&b1);
        printf("�������2���������꣺");
        scanf("%f,%f",&a2,&b2);
        printf("�������3���������꣺");
        scanf("%f,%f",&a3,&b3);
        a=sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
        b=sqrt((a1-a3)*(a1-a3)+(b1-b3)*(b1-b3));
        c=sqrt((a2-a3)*(a2-a3)+(b2-b3)*(b2-b3));
        printf("�����߳�Ϊ��");
        printf("%f ",a);
        printf("%f ",b);
        printf("%f\n",c);
        if((a+b)>c&&(a+c)>b&&(b+c)>a){
            r=a+b+c;
            p=(a+b+c)/2;
            q=sqrt(p*(p-a)*(p-b)*(p-c));
            printf("�ܳ�Ϊ%f\n",r);
            printf("���Ϊ%f\n",q);
        }
        else{
            printf("Impossible");
        }
        return 0;
 }
*/


/*#include "stdio.h"
#include "stdlib.h"
/****���¶��峣��,****/
/*#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 //˳�����󳤶�

/*���¶������͵�ͬ����*/
/*typedef int Status;    //������Status��Ϊint����
typedef int ElemType;  //������ElemType��Ϊint����

/*���¶���˳���SeqList*/
/*typedef struct
{
    ElemType data[MAXSIZE]; //data���ڴ�ű���
    int length; // ����
}SeqList;
Status InitSeqList(SeqList *seqList) // *seqListL��ʾָ��˳���SeqList��ָ��
{
    seqList->length=0;  //��Ϊ�ձ�
    return OK;
}
int GetDataByIndex(SeqList *seqList,int n);
void Display(SeqList *seqList);
Status Delete(SeqList *seqList,int n,ElemType *e);
Status Insert(SeqList *seqList,int n,ElemType e);
int GetSeqListLen(SeqList *seqList);
int main()
{
    //��������
    SeqList seqList; //����˳���
    int i,j,k,m,elem; //��������
    printf("\n*****************��ʼ��************************\n");
    i=InitSeqList(&seqList);// ����InitSeqList����������&���ű�ʾ��ַ
    printf("��ʼ�����ĳ���Ϊ��%d\n",seqList.length);

    printf("\n*****************������������******************\n");
    for (j=1;j<=5;j++)
    {
	  printf("�����%d�����ݣ�",j);
	  scanf("%d",&m);
      i=Insert(&seqList,j,m);//����Insert�������ڱ�ͷ���β���5����
    }
    Display(&seqList); //����Display��������ʾ˳���

    printf("\n*****************ɾ��һ������*******************\n");
    printf("ɾ���������ݣ�");
	scanf("%d",&j);
    i=Delete(&seqList,j,&elem); //����Delete������ɾ��ָ������
    if (i==OK) printf("ɾ���ɹ�\n");
    Display(&seqList); //����Display��������ʾ˳���

    printf("\n*****************��λ�ò���Ԫ��*****************\n");
	printf("���ҵڼ������ݣ�");
	scanf("%d",&j);
    k=GetDataByIndex(&seqList,j);  //����GetDataByIndex����
    printf("\n��%d��Ԫ��Ϊ%d\n",j,k);

    printf("\n***************��ȡ��ĵ�ǰ����*****************\n");
    k=GetSeqListLen(&seqList);  //����GetSeqListLen����
    printf("��ǰ���л���%d��Ԫ��\n\n",k);
    getchar();
    return 0;
}
int GetDataByIndex(SeqList *seqList,int n)
{
    //���λ���Ƿ񳬳���Χ
    if (n<1||n>seqList->length) return ERROR;
    return seqList->data[n-1];
}

/*��ӡ���*/
/*void Display(SeqList *seqList)
{
    int i;
    printf("\n********չʾ����********\n");
    for (i=0;i<seqList->length;i++)
    {
        printf("%d\n",seqList->data[i]);
    }
    printf("\n");


}
Status Delete(SeqList *seqList,int n,ElemType *e)
{
    int k;

    //�ж������Ƿ�Ϊ��
    if (seqList->length==0) return ERROR;

    //�ж�n��λ���Ƿ�Ϸ�
    if (n<1||n>seqList->length) return ERROR;

    *e=seqList->data[n-1];

    //���ɾ���������λ��
    if (n<seqList->length)
    {
        //��ɾ��λ�ú��Ԫ������ǰ��
        for (k=n;k<seqList->length;k++)
        {
            seqList->data[k-1]=seqList->data[k];
        }
    }

    //����1
    seqList->length--;
    return OK;
}
Status Insert(SeqList *seqList,int n,ElemType e)
{
    int k;
    //��������Ƿ�����
    if (seqList->length>=MAXSIZE) return ERROR;

    //���n��λ���Ƿ񳬳���Χ
    if (n<1||n>seqList->length+1) return ERROR;

    //����������λ�ò��ڱ�β
    if (n<=seqList->length)
    {
        //��Ҫ����λ��֮��Ԫ����������ƶ�һλ
        for (k=seqList->length-1;k>=n-1;k--)
        {
            seqList->data[k+1]=seqList->data[k];
        }
    }

    //����Ԫ�ز��뵽�ڳ���λ�ã���������1
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
	struct LNode *next;		//ָ���̽��
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
    printf("������Ҫɾ����Ԫ�أ�\n");
    scanf("%d",&x);
    del_x(L,x);
	printf("ɾ����Ϊ:\n");
	DispList(L);
}
void CreateListF(LinkNode *&L,ElemType a[],int n)
//ͷ�巨����������
{
	LinkNode *s;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ���
	L->next=NULL;
	for (int i=0;i<n;i++)
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½��s
		s->data=a[i];
		s->next=L->next;			//�����s����ԭ��ʼ���֮ǰ,ͷ���֮��
		L->next=s;
	}
}
void CreateListR(LinkNode *&L,ElemType a[],int n)
//β�巨����������
{
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ���
	L->next=NULL;
	r=L;					//rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
	for (int i=0;i<n;i++)
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));//�����½��s
		s->data=a[i];
		r->next=s;			//�����s������r֮��
		r=s;
	}
	r->next=NULL;			//�ն˽��next����ΪNULL
}
void InitList(LinkNode *&L)
{
	L=(LinkNode *)malloc(sizeof(LinkNode));  	//����ͷ���
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
	free(pre);	//��ʱpΪNULL,preָ��β���,�ͷ���
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
	if (i<=0) return false;			//i���󷵻ؼ�
	while (j<i-1 && p!=NULL)		//���ҵ�i-1�����p
	{	j++;
		p=p->next;
	}
	if (p==NULL)					//δ�ҵ�λ��Ϊi-1�Ľ��
		return false;
	else							//�ҵ�λ��Ϊi-1�Ľ��*p
	{	s=(LinkNode *)malloc(sizeof(LinkNode));//�����½��*s
		s->data=e;
		s->next=p->next;			//��s�����뵽���p֮��
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
  int a=0,b=0;      // a���ڲ������������b���ڽ����û����������
  int count=0;      //count���ڴ�Ų����Ĵ���

  srand(time(0));
  a=rand()%100;     //����100���ڵ������


  while(a!=b)		//�������������ʱѭ��
  {
      ++count;
      printf("��ʼ��%d�β�����",count);
      scanf("%d",&b);   //Ҫ���û�����b��ֵ
      if(b>a)
        printf("���ˣ�������\n");
      else
        printf("���ˣ�������\n");
  }
  printf("��ϲ�㣬����%d�β¶ԣ�\n",count);
  return 0;
}*/









//�������ݽṹ��lengthΪ˳���ʵ��Ԫ�ظ���
/*#define MAXSIZE 50

typedef struct
{
	int elem[MAXSIZE];
	int length;
}SeqList;

//------------------����˳���------------------
void creat(SeqList* s)
{
	int n, len, i;
	printf("����˳���ĳ���:\n");
	scanf("%d", &len);
	s->length = len;
	printf("����˳����Ԫ��:\n");
	for (i = 0; i < len; i++)
	{
		scanf("%d", &n);
		s->elem[i] = n;
	}
}

//--------------------�ϲ��㷨--------------------
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
	//����LA�ȱ�LB��ʱ������LAʣ�µ�Ԫ�ظ�����LC
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
//--------------------�������Ԫ��--------------------
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
	printf("˳���LA��Ԫ��Ϊ:\n");
	print(&LA);
	printf("˳���LB��Ԫ��Ϊ:\n");
	print(&LB);
	printf("--------------��ʼ�ϲ�˳���------------\n");
	merge(&LA, &LB, &LC);
	printf("�ϲ����LC��Ԫ��Ϊ:\n");
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
        printf("ʹ�ü��������1�������������˳�");
        scanf("%d",&i);
        if(i>1){
            return 0;
        }
        printf("��Ҫ��Ӽ��˳���һ�֣���1234����");
        int e,w,y;
        scanf("%d",&e);
        printf("��������Ҫ���������");
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
