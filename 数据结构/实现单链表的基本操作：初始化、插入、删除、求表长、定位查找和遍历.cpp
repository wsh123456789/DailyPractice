#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int data;
	struct node *next;
}Lnode;
//β���뷨����������
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
//�ڵ�����L�ڵ�i��λ�ò���ֵΪx��Ԫ�� 
void insert_linklist(Lnode *first,int i,int x){
	Lnode *s=NULL,*p=first;
	int count=0;
	printf("\n������Ҫ������λ�ú�ֵ��\n");
	scanf("%d %d",&i,&x);
	while(count<i-1&&p!=NULL){
		p=p->next;
		count++;
	}
	if(p==NULL)
		printf("���벻����");
	else{
	s=(Lnode *)malloc(sizeof(Lnode));
	s->data=x;
	s->next=p->next;
	p->next=s;
	}
}
//�ڵ�����L��ɾ����j��λ�õ�Ԫ�� 
void Delete_linklist(Lnode *first,int j){
	Lnode *s=NULL,*p=first;
	printf("\n������Ҫɾ����λ�ã�\n");
	scanf("%d",&j);
	int count=0;
	while(p->next&&count<j-1){
		p=p->next;
		count++;
	}
	if(!(p->next)||count>j-1)
	printf("ɾ��λ�ò�����");
		s=p->next;
		p->next=s->next;
		free(s);
}
//��λ���� 
void Locte_linklist(Lnode *first,int m){
	printf("\n��������Ҫ���ҵ�λ�ã�\n");
	scanf("%d",&m); 
	Lnode *s=NULL,*p=first;
	int count=0;
	while(p->next&&count<m-1){
		p=p->next;
		count++;
	}
	if(!(p->next)||count>m-1)
	printf("����λ�ò�����\n");
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

