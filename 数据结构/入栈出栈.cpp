#include <stdio.h>
#include <malloc.h>
#define Elemtype int
typedef struct Lqueue{
	Elemtype data;
	struct Lqueue *next;
}Lqueue;
Lqueue *front,*rear;
void initqueue(){
	front = (Lqueue*)malloc(sizeof(Lqueue));
	front->next = NULL;
	rear = front;
}
//入栈 
void inqueue(int data){ 
	Lqueue* newqueue = (Lqueue*)malloc(sizeof(Lqueue));   //定义一个新结点 
	newqueue->data = data;
	newqueue->next = NULL;
	rear->next = newqueue;
	rear = newqueue;
}
//出栈 
void outqueue(){
	if(front->next == NULL)   //判空 
		return ; 
	Lqueue* move = front->next;  //定义一个移动指针等于头结点 
	front->next = move->next;
	if(move->next == NULL)
		rear = front;
	free(move);
}
int main(){
	initqueue();
	inqueue(3);
	inqueue(5);
	inqueue(6);
	inqueue(7);
	inqueue(8);
	outqueue();
	outqueue();
	printf("%d",front->next->data);
	return 0;
}
