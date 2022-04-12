#include <stdio.h>
typedef struct{
	int a[100];
	int length;
}list;
void creat_list(list &l){
	int i=0;
	while(getchar()!='#'){
		scanf("%d",&l.a[i]);
		i++;
	}
	l.length=i;
}
void visit(list &l){
	printf("输出线性表的长度：%d\n",l.length);
	printf("输出线性表元素：\n");
	for(int i=0;i<l.length;i++){
		printf("%d ",l.a[i]);
	}
	printf("\n");
}
/*void list_Insert(list &l){
	int i;
	int x; 
	printf("请输入需要插入的位置: \n");
	scanf("%d",&i);
	printf("请输入需要插入的数据：\n");
	scanf("%d",&x);
	if(i>=1&&i<l.length+1)
	for(int j=l.length;j>=i;j--){
		l.a[j]=l.a[j-1];
	}
	l.a[i-1]=x;
	l.length++;
	printf("请输出插入数据后线性表的元素：\n"); 
	for(int i=0;i<l.length;i++){
		printf("%d ",l.a[i]);
	}
}*/
void list_delete(list &l){
	int i; 
	printf("请输入需要删除的位置: \n");
	scanf("%d",&i);
	if(i>=1&&i<l.length+1)
	for(int j=l.length;j>=i;j--){
		l.a[j]=l.a[j-1];
	}
	l.length--;
	printf("请输出删除数据后线性表的元素：\n"); 
	for(int i=0;i<l.length;i++){
		printf("%d ",l.a[i]);
	}
}
int main(){
	void creat_list(list &l);
	void visit(list &l);
	//void list_Insert(list &l);
	void list_delete(list &l);
	
	list l;
	creat_list(l);
	visit(l);
	//list_Insert(l);
	list_delete(l);
	return 0;
}
