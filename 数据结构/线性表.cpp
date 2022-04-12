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
}
int main(){
	void creat_list(list &l);
	void visit(list &l);
	list l;
	creat_list(l);
	visit(l);
	return 0;
}
