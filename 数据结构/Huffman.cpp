#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0 
#define OVERFLOW -2
typedef int Status;
 typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char * * HuffmanCode;
void Select(HuffmanTree HT,int &s1,int &s2,int n)
{
    int k;
    for(k=1;k<=n;++k)   
    {
        if(HT[k].parent==0)
        {
            s1=k;
            break;
        }
    }
    for(k=1;k<=n;++k)             
    {
        if(HT[k].parent==0 && HT[k].weight<HT[s1].weight)
        {
            s1=k;
        }
    }
    for(k=1;k<=n;++k)      
    {
        if(HT[k].parent==0 && k!=s1)
        {
            s2=k;
            break;
        }
    }
    for(k=1;k<=n;++k)            
    {
        if(HT[k].parent==0&&HT[k].weight<HT[s2].weight&&k!=s1)
        {
            s2=k;
        }
    }
    
    printf("s1:%d,s2:%d\n",s1,s2);
}

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n){
	HuffmanTree p;
	int m,i,start,s1,s2,c,f;
	char *cd;
	if(n<=1)return;
	m=2*n-1;  
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));  
	for(p=HT+1,i=1;i<=n;++i,++p,++w){
		p->weight=*w;
		p->parent=0;
		p->lchild=0;
		p->rchild=0;
	} 
	for(;i<=m;++i,++p){
		p->weight=0;
		p->parent=0;
		p->lchild=0;
		p->rchild=0;
	}
	for(i=n+1;i<=m;++i){
		 
		Select(HT,s1,s2,i-1);  
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	
	HC=(HuffmanCode)malloc((n+1)*sizeof(char*));   
	cd=(char*)malloc(n*sizeof(char));   
	cd[n-1]='\0';  
	for(i=1;i<=n;++i){
		start=n-1;   
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)  
		if(HT[f].lchild==c)
		cd[--start]='0';
		else cd[--start]='1';
		HC[i]=(char*)malloc((n-start)*sizeof(char));  
		strcpy(HC[i],&cd[start]);  
	} 
	free(cd);   
} 

int main(){
	int i;
	HuffmanTree HT;
	HuffmanCode HC;
	int w[8]={5,29,7,8,14,23,3,11};
	HuffmanCoding(HT,HC,w,8);
	for(i=1;i<=8;i++){
		printf("%s\n",HC[i]);
	}
	return 0;
	
}

