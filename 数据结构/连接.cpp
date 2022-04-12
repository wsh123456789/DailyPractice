#include <stdio.h>
#define maxsize 100
typedef struct{
	int a[100];
	int b[100];
	int length1;
	int length2;
}list;
void creat_list1(list &l){
	int i=0;
	while(getchar()!='*'){
		scanf("%d",&l.a[i]);
		i++;
	}
	l.length1=i;
}
void creat_list2(list &l){
	int j=0;
	while(getchar()!='#'){
		scanf("%d",&l.b[j]);
		j++;
	}
	l.length2=j;
}
void visit_list1(list &l){
	printf("输出线性表的长度：%d\n",l.length1);
	printf("输出第一个线性表元素元素：\n");
	for(int i=0;i<l.length1;i++){
		printf("%d ",l.a[i]);
	}
	printf("\n");
}
void visit_list2(list &l){
	printf("输出线性表的长度：%d\n",l.length2);
	printf("输出第二个线性表元素：\n");
	for(int j=0;j<l.length2;j++){
		printf("%d ",l.b[j]);
	}
	printf("\n");
}
void concatenate_list(list &l)
 {
 	int i,j;
 	int a[100];
 	printf("请输出连接后的线性表的元素：\n");
 	if(maxsize>=l.length1+l.length2)
 	for(i=0,i>l.length1+l.length2;j=l.length1;j++,i++){
 		if(i==l.length1)
 		a[i]=a[j];
 		printf("%2d",l.a[i]);
	 }
	if(maxsize<l.length1+l.length2)
	printf("空间不足！");
 }
int main(){
	void creat_list1(list &l);
	void creat_list2(list &l);
	void visit_list1(list &l);
	void visit_list2(list &l);
	void concatenate(list &l);
	list l;
	creat_list1(l);
	creat_list2(l);
	visit_list1(l);
	visit_list2(l);
	concatenate(l); 
	return 0;
}
