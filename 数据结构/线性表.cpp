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
	printf("������Ա�ĳ��ȣ�%d\n",l.length);
	printf("������Ա�Ԫ�أ�\n");
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
