#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100 //���Ա���ռ�ĳ�ʼ������ 
#define LIST_INCREMENT 10 //���Ա���ռ�ķ������� 
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
using namespace std;
typedef int ElemType; //Ԫ�ص��������� 
typedef int Status;//Statusֵ�Ǻ������״̬���룬��ok�� 
typedef struct{
	ElemType *elem;  //����ռ��ַ 
	int length;  //���Ա���
	int listsize; //��ǰ����Ĵ洢���� 
	ElemType data[MAXSIZE];//���˳���Ԫ�� 
}SqList;
//��ʼ�����Ա� 
Status InitList_Sq(SqList &L){
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem) return ERROR;    //�洢����ʧ�� 
	L.length = 0;					//�ձ���Ϊ�� 
	L.listsize = LIST_INIT_SIZE; //��ʼ�洢���� 
	return OK; 
} 
//�������Ա� 
Status DestoryList(SqList &L){
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}
//�����Ա���
Status GetLength(SqList &L)
{
	return L.length;
 } 
//�����Ա��е�i��Ԫ��
Status GetElem(SqList L,int i,ElemType &e)
{
	if(i < 1 || i > L.length)
		return ERROR;
	e = *(L.elem + i - 1);
	return OK;
 } 
//��ֵ����
Status LocateElem(SqList L,ElemType e)
{
	ElemType *p;
	int i = 1;   //i�ĳ�ֵΪ��һ��Ԫ�ص�λ�� 
	p=L.elem;  //p�ĳ�ֵΪ��һ��Ԫ�صĴ洢λ�� 
	while(i <= L.length&&(*p++ != e))
		++i;
	if(i <= L.length)
		return i;
	else
		return 0;
 } 
Status ListInsert_Sq(SqList &L,int i,ElemType e)
{
	ElemType *p;
	if(i < 1|| i > L.length+1)
		return ERROR;           //iֵ���Ϸ� 
	if(L.length >= L.listsize){ //������ռ��������������� 
		ElemType *newbase = (ElemType *)realloc(L.elem,(L.listsize + LIST_INCREMENT)*sizeof(ElemType));
	if(!newbase)
		return ERROR;   //�洢����ʧ�� 
	L.elem = newbase;	//�»�ַ 
	L.listsize += LIST_INCREMENT;//���Ӵ洢���� 
}
	ElemType *q = &(L.elem[i-1]);//qΪ����λ�� 
	for(p = &(L.elem[L.length-1]);p >=q;--p)
		*(p+1) = *p	;	//����λ�ü�֮���Ԫ������ 
	*q = e;				//����e 
	++L.length;         //����һ 
	return 0;
 } 
 //ɾ���㷨 
Status ListDelete_Sq(SqList &L,int i,ElemType &e)
{
	ElemType *p,*q;
	if(i < 1 || i > L.length)
		return ERROR;		//iֵ���Ϸ� 
	p = &(L.elem[i-1]);		//pΪ��ɾ��Ԫ�ص�λ�� 
	e = *p;					//��ɾԪ�ص�ֵ����e 
	q = L.elem + L.length-1;//��βԪ�ص�λ�� 
	for(++p; p <= q; ++p)	
		*(p-1) = *p;		//��ɾ��Ԫ��֮���Ԫ������ 
	--L.length;				//����һ 
	return  OK; 
 } 

