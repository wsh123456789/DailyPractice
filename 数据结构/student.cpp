#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define listSize 100
//学生信息结构体 
typedef struct {
	long num;
	char name[10];
	int score;
} Student;
//顺序表结构体
typedef struct {
	Student stu[listSize];
	int length;
} List;
//函数声明
void Menu();
void initList(List *L);
void createList(List *L,int len);
void searchList1(List *L,int pos);
void searchList2(List *L,char s[10]);
void insertList(List *L,int pos,Student *stu);
void changeList(List *L,int pos);
void deleteList(List *L,int pos,Student *e);
void inputInfor(List *L,int index);
void travelList(List *L);
//展示系统菜单
void Menu() {
	printf("******************************************************\n\n");
	printf("***************欢迎使用学生成绩管理系统***************\n\n");
	printf("***                 1.创建学生信息                 ***\n");
	printf("***                 2.查找学生信息                 ***\n");
	printf("***                 3.插入学生信息                 ***\n");
	printf("***                 4.修改学生信息                 ***\n");
	printf("***                 5.删除学生信息                 ***\n");
	printf("***                 6.退出学生系统                 ***\n\n");
	printf("******************************************************\n");
}
//初始化顺序表
void initList(List *L) {
	L->length = 0;
}
//学生信息输入
void inputInfor(List *L,int index) {
	printf("学号：");
	scanf("%d",&L->stu[index].num);
	printf("姓名：");
	scanf("%s",L->stu[index].name);
	printf("分数：");
	scanf("%d",&L->stu[index].score);
}
//创建学生信息
void createList(List *L,int len) {
	int i;
	for(i = 0; i < len; i++)
	{
		printf("请输入第%d个学生信息：\n",i+1);
		inputInfor(L,i);
		L->length++;
	}
}
//查找学生信息
//按学号查找 
void searchList1(List *L,int pos)
{
	int i;
	{
		for(i = 0;i < L->length;i++)
		{
			if(L->stu[i].num == pos)
			{
				printf("	学号	姓名	成绩 \n");
				printf("	 %d     %s	 %d\n",L->stu[i].num,L->stu[i].name,L->stu[i].score);
				break;
			}
		}
		if(i == L->length)
		printf("未找到相关信息\n"); 
	}
}
void searchList2(List *L,char s[10])
{
	int i;
		for(i = 0;i < L->length;i++)
		{
			if((strcmp(L->stu[i].name,s)) == 0)
			{
				printf("	学号	姓名	成绩 \n");
				printf("	 %d     %s	 %d\n",L->stu[i].num,L->stu[i].name,L->stu[i].score);
				break;
			}
		}
		if(i == L->length)
		printf("未找到相关信息\n");
}
//插入学生信息
void insertList(List *L,int pos,Student *stu) {
	int i;
	if(L->length == listSize) {
		printf("学生信息储存上限，无法插入\n");
	} else if(pos < 1 ||pos > L->length + 1) {
		printf("插入位置非法，无法插入\n");
	} else {
		for(i = L->length; i >= pos; i--)
			L->stu[i] = L->stu[i-1];
		L->stu[pos-1] = *stu;
		L->length++;
		printf("插入成功\n");
	}
}
//修改学生信息
void changeList(List *L,int pos)
{
	int choose,num,score;
	char name[10];
	printf("请选择您要修改的信息：\n1.学号\n2.姓名\n3.成绩\n");
	scanf("%d",&choose);
	switch(choose){
		case 1:
			printf("请输入修改后的学号：");
			scanf("%d",&num);
			L->stu[pos-1].num = num;
			break;
		case 2:
			printf("请输入修改后的姓名：");
			scanf("%s",L->stu[pos-1].name);
			break;
		case 3:
			printf("请输入修改后的成绩：");
			scanf("%d",&score);
			L->stu[pos-1].score = score;
			break;
		default:
			printf("选项不存在");
	}
}
//删除学生信息
void deleteList(List *L,int pos,Student *e) {
	int i;
	if(L->length == 0) {
		printf("无学生信息无法删除\n");
	} else if(pos < 1||pos > L->length)
		printf("删除位置不合法，删除失败\n");
	else {
		*e = L->stu[pos - 1];
		for(i = pos; i < L->length; i++) {
			L->stu[i-1] = L->stu[i];
		}
		L->length--;
		printf("删除成功\n");
	}
}
//遍历顺序表，显示学生信息
void travelList(List *L) {
	int i;
	if(L->length == 0) {
		printf("无学生信息\n");
	}
	printf("	学号	姓名	成绩	\n");
	for(i = 0; i < L->length; i++) {
		printf("	 %d     %s	 %d\n",L->stu[i].num,L->stu[i].name,L->stu[i].score);
	}
}
int main() {
	int choice,len,pos;
	char s[10];
	List Stu;
	Student stu,*p;
	initList(&Stu);
	while(true) {
		Menu();
		printf("请输入您的选择:");
		scanf("%d",&choice);
		system("cls");
		switch(choice) {
			case 1:
				printf("请输入要记录的学生数量:");
				scanf("%d",&len);
				createList(&Stu,len);
				printf("该班级学生信息为:\n");
				system("cls");
				printf("*******************************************\n");
				printf("              学生信息显示\n");
				travelList(&Stu);
				printf("*******************************************\n\n");
				break;
			case 2:
				int sum;
				printf("请选择要查找的方式\n1.按学号查找\n2.按名字查找\n");
				scanf("%d",&sum);
				if(sum == 1)
				{
					printf("请输入要查找的学号：");
					scanf("%d",&pos);
					searchList1(&Stu,pos);
				}
				else if(sum == 2)
				{
					printf("请输入要查找的姓名：");
					scanf("%s",s);
					searchList2(&Stu,s);
				}
				else
				printf("选项不存在");
				break;
			case 3:
				printf("请输入待插入学生的信息:\n");
				printf("学号:");
				scanf("%d",&stu.num);
				printf("姓名:");
				scanf("%s",stu.name);
				printf("分数:");
				scanf("%d",&stu.score);
				p = &stu;
				printf("请输入需要插入学生信息的位置:");
				scanf("%d",&pos);
				system("cls");
				printf("*******************************************\n");
				printf("    您需要插入的学生信息\n");
				printf("	学号	姓名	成绩 \n");
				printf("	 %d     %s	 %d\n",stu.num,stu.name,stu.score);
				printf("*******************************************\n");
				insertList(&Stu,pos,p);
				printf("*******************************************\n");
				printf("        插入学生后信息显示\n");
				travelList(&Stu);
				printf("*******************************************\n\n");
				break;
			case 4:
				printf("请输入要修改第几位学生的数据:");
				scanf("%d",&pos);
				changeList(&Stu,pos);
				printf("*******************************************\n");
				printf("              学生信息显示\n");
				travelList(&Stu);
				printf("*******************************************\n\n");
				break;
			case 5: 
					printf("请输入需要删除学生信息的位置:");
					scanf("%d",&pos);
					system("cls"); 
				deleteList(&Stu,pos,&stu);
				printf("*******************************************\n");
				printf("        删除学生后信息显示\n");
				travelList(&Stu);
				printf("*******************************************\n\n");
				break;
			case 6:
				printf("退出系统成功\n");
				break;
			default:
				printf("您的输入有误!\n");
		}
	}
	return 0;
}
