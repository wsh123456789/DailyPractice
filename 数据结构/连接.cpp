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
	printf("������Ա�ĳ��ȣ�%d\n",l.length1);
	printf("�����һ�����Ա�Ԫ��Ԫ�أ�\n");
	for(int i=0;i<l.length1;i++){
		printf("%d ",l.a[i]);
	}
	printf("\n");
}
void visit_list2(list &l){
	printf("������Ա�ĳ��ȣ�%d\n",l.length2);
	printf("����ڶ������Ա�Ԫ�أ�\n");
	for(int j=0;j<l.length2;j++){
		printf("%d ",l.b[j]);
	}
	printf("\n");
}
void concatenate_list(list &l)
 {
 	int i,j;
 	int a[100];
 	printf("��������Ӻ�����Ա��Ԫ�أ�\n");
 	if(maxsize>=l.length1+l.length2)
 	for(i=0,i>l.length1+l.length2;j=l.length1;j++,i++){
 		if(i==l.length1)
 		a[i]=a[j];
 		printf("%2d",l.a[i]);
	 }
	if(maxsize<l.length1+l.length2)
	printf("�ռ䲻�㣡");
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
