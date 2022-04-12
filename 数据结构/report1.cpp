#include <stdio.h>
#define Maxsize 100
typedef struct{
	int a[Maxsize];
	int length;
}list;
void creat_list(list &L){
	int i=0;
	printf("请输入线性表元素\n"); 
	while(scanf("%d",&L.a[i])!=EOF)
	{
		i++;
	}
	L.length=i;
}
void visit(list &L){
	printf("线性表长度为:\n");
	printf("%d\n",L.length);
	printf("线性表元素为：\n");
	for(int i=0;i<L.length;i++)
	printf("%d ",L.a[i]);
}
void SeqList_Inset(list &L,int i,int x)
{
	if(L.length>=Maxsize)
	printf("ERROR\n");
	if(i<1||i>L.length+1)
	printf("ERROR\n");
	for(int j=L.length;j>=i;j--)
	L.a[j]=L.a[j-1];
	L.a[i-1]=x;
	L.length++;
}
void SeqList_Delete(list &L,int i)
{
	if(i<1||i>L.length)
	printf("ERROR\n");
	for(int j=i;j<L.length;j++)
	L.a[j-1]=L.a[j];
	L.length--;
}
void SeqList_Get(list &L,int i)
{
	if(i<1||i>L.length)
	printf("ERROR\n");
	else
	printf("%d",L.a[i-1]);
 } 
void SeqList_Locte(list &L,int x)
{
	for(int i=0;i<L.length;i++)
		if(L.a[i]==x) 
		printf("%d",i+1);
}
int main(){
	list L;
	creat_list(L);
	visit(L);
	int i,x;
	printf("\n请输入插入位置和元素\n");
	scanf("%d%d",&i,&x);
	SeqList_Inset(L,i,x);
	visit(L);
	int j;
	printf("\n请输入要第几个删除元素：\n");
	scanf("%d",&j);
	SeqList_Delete(L,j);
	visit(L);
	int k,y;
	printf("\n请输入要查找第几个元素\n");
	scanf("%d",&k);
	SeqList_Get(L,k);
	printf("\n请输入要查找元素\n");
	scanf("%d",&y);
	SeqList_Locte(L,y);
	return 0;
}

