#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100 //线性表储存空间的初始分配量 
#define LIST_INCREMENT 10 //线性表储存空间的分配增量 
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
using namespace std;
typedef int ElemType; //元素的数据类型 
typedef int Status;//Status值是函数结果状态代码，如ok等 
typedef struct{
	ElemType *elem;  //储存空间基址 
	int length;  //线性表长度
	int listsize; //当前分配的存储容量 
	ElemType data[MAXSIZE];//存放顺序表元素 
}SqList;
//初始化线性表 
Status InitList_Sq(SqList &L){
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem) return ERROR;    //存储分配失败 
	L.length = 0;					//空表长度为零 
	L.listsize = LIST_INIT_SIZE; //初始存储容量 
	return OK; 
} 
//销毁线性表 
Status DestoryList(SqList &L){
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}
//求线性表长度
Status GetLength(SqList &L)
{
	return L.length;
 } 
//求线性表中第i个元素
Status GetElem(SqList L,int i,ElemType &e)
{
	if(i < 1 || i > L.length)
		return ERROR;
	e = *(L.elem + i - 1);
	return OK;
 } 
//按值查找
Status LocateElem(SqList L,ElemType e)
{
	ElemType *p;
	int i = 1;   //i的初值为第一个元素的位序 
	p=L.elem;  //p的初值为第一个元素的存储位置 
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
		return ERROR;           //i值不合法 
	if(L.length >= L.listsize){ //当储存空间已满，增加容量 
		ElemType *newbase = (ElemType *)realloc(L.elem,(L.listsize + LIST_INCREMENT)*sizeof(ElemType));
	if(!newbase)
		return ERROR;   //存储分配失败 
	L.elem = newbase;	//新基址 
	L.listsize += LIST_INCREMENT;//增加存储容量 
}
	ElemType *q = &(L.elem[i-1]);//q为插入位置 
	for(p = &(L.elem[L.length-1]);p >=q;--p)
		*(p+1) = *p	;	//插入位置及之后的元素右移 
	*q = e;				//插入e 
	++L.length;         //表长加一 
	return 0;
 } 
 //删除算法 
Status ListDelete_Sq(SqList &L,int i,ElemType &e)
{
	ElemType *p,*q;
	if(i < 1 || i > L.length)
		return ERROR;		//i值不合法 
	p = &(L.elem[i-1]);		//p为被删除元素的位置 
	e = *p;					//被删元素的值赋给e 
	q = L.elem + L.length-1;//表尾元素的位置 
	for(++p; p <= q; ++p)	
		*(p-1) = *p;		//被删除元素之后的元素左移 
	--L.length;				//表长减一 
	return  OK; 
 } 

