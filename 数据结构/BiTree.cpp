#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0 
#define OVERFLOW -2
typedef int Status;
typedef char TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;
Status CreateBiTree(BiTree &T){
	TElemType ch;
	scanf("%c",&ch);
	if(ch=='*') T = NULL;
	else{
		T = (BiTree)malloc(sizeof(BiTNode));
		if(!T) exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
} 
void PreOrderTraverse(BiTree T){
	if(T){
		putchar(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse(BiTree T){
	if(T){
		InOrderTraverse(T->lchild);
		putchar(T->data);
		InOrderTraverse(T->rchild);
	}
}
void PostrderTraverse(BiTree T){
	if(T){
	    PostrderTraverse(T->lchild);
	    PostrderTraverse(T->rchild);
	    putchar(T->data);
	}
}

int BiTreeDepth(BiTree T){
	int i,j;
	if(!T) return 0;
	i=BiTreeDepth(T->lchild);
	j=BiTreeDepth(T->rchild);
	return i>j?i+1:j+1;
}

int FullNodes(BiTree T){
	int num1,num2;
	if(!T)
	return 0;
	else
	{
		num1=FullNodes(T->lchild);
		num2=FullNodes(T->rchild);
		return (num1+num2+1);
	}
}

int Leafcount(BiTree T,int &num){
	if(T){
		if(T->lchild==NULL&&T->rchild==NULL){
			num++;
		}
		Leafcount(T->lchild,num);
		Leafcount(T->rchild,num);
	}
	return num;
}

int DsonNode(BiTree T){
	if(!T)
		return 0;
	else if(T->lchild!=NULL&&T->rchild!=NULL)
		return DsonNode(T->lchild)+DsonNode(T->rchild)+1;
	else
		return DsonNode(T->lchild)+DsonNode(T->rchild);
}

int main(){
	int a,b=0,c,d,num=0;
	BiTree T;
    if(CreateBiTree(T)){
    	printf("先序遍历:");
        PreOrderTraverse(T);
        printf("\n");
        printf("中序遍历:");
        InOrderTraverse(T);
        printf("\n");
        printf("后序遍历:");
        PostrderTraverse(T);
        printf("\n");
    }
    else{
        printf("二叉树创建失败!");
	}
	a=BiTreeDepth(T);
	printf("二叉树深度为:%d\n",a);
	b=FullNodes(T);
	printf("所有结点数为:%d\n",b);
	num=Leafcount(T,num);
	printf("叶子结点数为：%d\n",num);
	c=DsonNode(T);
	printf("双孩子结点数为:%d\n",c);
	d=b-num-c;
	printf("单孩子结点数为:%d\n",d);
    return 0;
}

