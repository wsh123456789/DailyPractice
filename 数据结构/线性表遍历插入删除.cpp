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
	printf("\n");
}
/*void list_Insert(list &l){
	int i;
	int x; 
	printf("��������Ҫ�����λ��: \n");
	scanf("%d",&i);
	printf("��������Ҫ��������ݣ�\n");
	scanf("%d",&x);
	if(i>=1&&i<l.length+1)
	for(int j=l.length;j>=i;j--){
		l.a[j]=l.a[j-1];
	}
	l.a[i-1]=x;
	l.length++;
	printf("������������ݺ����Ա��Ԫ�أ�\n"); 
	for(int i=0;i<l.length;i++){
		printf("%d ",l.a[i]);
	}
}*/
void list_delete(list &l){
	int i; 
	printf("��������Ҫɾ����λ��: \n");
	scanf("%d",&i);
	if(i>=1&&i<l.length+1)
	for(int j=l.length;j>=i;j--){
		l.a[j]=l.a[j-1];
	}
	l.length--;
	printf("�����ɾ�����ݺ����Ա��Ԫ�أ�\n"); 
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
