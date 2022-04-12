#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int data;
	struct node *next;
}Lnode;
//尾插入法建立单链表
Lnode *link_creat(){
	Lnode *first=NULL,*s=NULL;
	Lnode *r=NULL;
	first=(Lnode *)malloc(sizeof(Lnode));
	first->next=NULL;
	r=first;
	int count=0;
	while(count<5){
		s=(Lnode *)malloc(sizeof(Lnode));
		scanf("%d",&s->data);
		s->next=r->next;
		r->next=s;
		r=s;
		count++;
	}
	return first;
} 
//在单链表L在第i个位置插入值为x的元素 
void insert_linklist(Lnode *first,int i,int x){
	Lnode *s=NULL,*p=first;
	int count=0;
	printf("\n请输入要插入在位置和值：\n");
	scanf("%d %d",&i,&x);
	while(count<i-1&&p!=NULL){
		p=p->next;
		count++;
	}
	if(p==NULL)
		printf("插入不合理！");
	else{
	s=(Lnode *)malloc(sizeof(Lnode));
	s->data=x;
	s->next=p->next;
	p->next=s;
	}
}
//在单链表L中删除第j个位置的元素 
void Delete_linklist(Lnode *first,int j){
	Lnode *s=NULL,*p=first;
	printf("\n请输入要删除的位置：\n");
	scanf("%d",&j);
	int count=0;
	while(p->next&&count<j-1){
		p=p->next;
		count++;
	}
	if(!(p->next)||count>j-1)
	printf("删除位置不合理！");
		s=p->next;
		p->next=s->next;
		free(s);
}
//定位查找 
void Locte_linklist(Lnode *first,int m){
	printf("\n请输入需要查找的位置：\n");
	scanf("%d",&m); 
	Lnode *s=NULL,*p=first;
	int count=0;
	while(p->next&&count<m-1){
		p=p->next;
		count++;
	}
	if(!(p->next)||count>m-1)
	printf("查找位置不合理！\n");
	else
	printf("%d",p->next->data);
}
void visit_linklist(Lnode *first){
	Lnode *p=NULL;
	p=first->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
int main(){
	Lnode *link_creat(); 
	void visit_linklist(Lnode *first);
	void insert_linklist(Lnode *first,int i,int x);
	void Delete_linklist(Lnode *first,int j);
	void Locte_linklist(Lnode *first,int m);
	Lnode *L;
	L=link_creat();
	visit_linklist(L);
	int i,x;
	int j;
	int m;
	insert_linklist(L,i,x);
	visit_linklist(L);
	Delete_linklist(L,j);
	visit_linklist(L);
	Locte_linklist(L,m);
	return 0;
}

