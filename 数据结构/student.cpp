#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define listSize 100
//ѧ����Ϣ�ṹ�� 
typedef struct {
	long num;
	char name[10];
	int score;
} Student;
//˳���ṹ��
typedef struct {
	Student stu[listSize];
	int length;
} List;
//��������
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
//չʾϵͳ�˵�
void Menu() {
	printf("******************************************************\n\n");
	printf("***************��ӭʹ��ѧ���ɼ�����ϵͳ***************\n\n");
	printf("***                 1.����ѧ����Ϣ                 ***\n");
	printf("***                 2.����ѧ����Ϣ                 ***\n");
	printf("***                 3.����ѧ����Ϣ                 ***\n");
	printf("***                 4.�޸�ѧ����Ϣ                 ***\n");
	printf("***                 5.ɾ��ѧ����Ϣ                 ***\n");
	printf("***                 6.�˳�ѧ��ϵͳ                 ***\n\n");
	printf("******************************************************\n");
}
//��ʼ��˳���
void initList(List *L) {
	L->length = 0;
}
//ѧ����Ϣ����
void inputInfor(List *L,int index) {
	printf("ѧ�ţ�");
	scanf("%d",&L->stu[index].num);
	printf("������");
	scanf("%s",L->stu[index].name);
	printf("������");
	scanf("%d",&L->stu[index].score);
}
//����ѧ����Ϣ
void createList(List *L,int len) {
	int i;
	for(i = 0; i < len; i++)
	{
		printf("�������%d��ѧ����Ϣ��\n",i+1);
		inputInfor(L,i);
		L->length++;
	}
}
//����ѧ����Ϣ
//��ѧ�Ų��� 
void searchList1(List *L,int pos)
{
	int i;
	{
		for(i = 0;i < L->length;i++)
		{
			if(L->stu[i].num == pos)
			{
				printf("	ѧ��	����	�ɼ� \n");
				printf("	 %d     %s	 %d\n",L->stu[i].num,L->stu[i].name,L->stu[i].score);
				break;
			}
		}
		if(i == L->length)
		printf("δ�ҵ������Ϣ\n"); 
	}
}
void searchList2(List *L,char s[10])
{
	int i;
		for(i = 0;i < L->length;i++)
		{
			if((strcmp(L->stu[i].name,s)) == 0)
			{
				printf("	ѧ��	����	�ɼ� \n");
				printf("	 %d     %s	 %d\n",L->stu[i].num,L->stu[i].name,L->stu[i].score);
				break;
			}
		}
		if(i == L->length)
		printf("δ�ҵ������Ϣ\n");
}
//����ѧ����Ϣ
void insertList(List *L,int pos,Student *stu) {
	int i;
	if(L->length == listSize) {
		printf("ѧ����Ϣ�������ޣ��޷�����\n");
	} else if(pos < 1 ||pos > L->length + 1) {
		printf("����λ�÷Ƿ����޷�����\n");
	} else {
		for(i = L->length; i >= pos; i--)
			L->stu[i] = L->stu[i-1];
		L->stu[pos-1] = *stu;
		L->length++;
		printf("����ɹ�\n");
	}
}
//�޸�ѧ����Ϣ
void changeList(List *L,int pos)
{
	int choose,num,score;
	char name[10];
	printf("��ѡ����Ҫ�޸ĵ���Ϣ��\n1.ѧ��\n2.����\n3.�ɼ�\n");
	scanf("%d",&choose);
	switch(choose){
		case 1:
			printf("�������޸ĺ��ѧ�ţ�");
			scanf("%d",&num);
			L->stu[pos-1].num = num;
			break;
		case 2:
			printf("�������޸ĺ��������");
			scanf("%s",L->stu[pos-1].name);
			break;
		case 3:
			printf("�������޸ĺ�ĳɼ���");
			scanf("%d",&score);
			L->stu[pos-1].score = score;
			break;
		default:
			printf("ѡ�����");
	}
}
//ɾ��ѧ����Ϣ
void deleteList(List *L,int pos,Student *e) {
	int i;
	if(L->length == 0) {
		printf("��ѧ����Ϣ�޷�ɾ��\n");
	} else if(pos < 1||pos > L->length)
		printf("ɾ��λ�ò��Ϸ���ɾ��ʧ��\n");
	else {
		*e = L->stu[pos - 1];
		for(i = pos; i < L->length; i++) {
			L->stu[i-1] = L->stu[i];
		}
		L->length--;
		printf("ɾ���ɹ�\n");
	}
}
//����˳�����ʾѧ����Ϣ
void travelList(List *L) {
	int i;
	if(L->length == 0) {
		printf("��ѧ����Ϣ\n");
	}
	printf("	ѧ��	����	�ɼ�	\n");
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
		printf("����������ѡ��:");
		scanf("%d",&choice);
		system("cls");
		switch(choice) {
			case 1:
				printf("������Ҫ��¼��ѧ������:");
				scanf("%d",&len);
				createList(&Stu,len);
				printf("�ð༶ѧ����ϢΪ:\n");
				system("cls");
				printf("*******************************************\n");
				printf("              ѧ����Ϣ��ʾ\n");
				travelList(&Stu);
				printf("*******************************************\n\n");
				break;
			case 2:
				int sum;
				printf("��ѡ��Ҫ���ҵķ�ʽ\n1.��ѧ�Ų���\n2.�����ֲ���\n");
				scanf("%d",&sum);
				if(sum == 1)
				{
					printf("������Ҫ���ҵ�ѧ�ţ�");
					scanf("%d",&pos);
					searchList1(&Stu,pos);
				}
				else if(sum == 2)
				{
					printf("������Ҫ���ҵ�������");
					scanf("%s",s);
					searchList2(&Stu,s);
				}
				else
				printf("ѡ�����");
				break;
			case 3:
				printf("�����������ѧ������Ϣ:\n");
				printf("ѧ��:");
				scanf("%d",&stu.num);
				printf("����:");
				scanf("%s",stu.name);
				printf("����:");
				scanf("%d",&stu.score);
				p = &stu;
				printf("��������Ҫ����ѧ����Ϣ��λ��:");
				scanf("%d",&pos);
				system("cls");
				printf("*******************************************\n");
				printf("    ����Ҫ�����ѧ����Ϣ\n");
				printf("	ѧ��	����	�ɼ� \n");
				printf("	 %d     %s	 %d\n",stu.num,stu.name,stu.score);
				printf("*******************************************\n");
				insertList(&Stu,pos,p);
				printf("*******************************************\n");
				printf("        ����ѧ������Ϣ��ʾ\n");
				travelList(&Stu);
				printf("*******************************************\n\n");
				break;
			case 4:
				printf("������Ҫ�޸ĵڼ�λѧ��������:");
				scanf("%d",&pos);
				changeList(&Stu,pos);
				printf("*******************************************\n");
				printf("              ѧ����Ϣ��ʾ\n");
				travelList(&Stu);
				printf("*******************************************\n\n");
				break;
			case 5: 
					printf("��������Ҫɾ��ѧ����Ϣ��λ��:");
					scanf("%d",&pos);
					system("cls"); 
				deleteList(&Stu,pos,&stu);
				printf("*******************************************\n");
				printf("        ɾ��ѧ������Ϣ��ʾ\n");
				travelList(&Stu);
				printf("*******************************************\n\n");
				break;
			case 6:
				printf("�˳�ϵͳ�ɹ�\n");
				break;
			default:
				printf("������������!\n");
		}
	}
	return 0;
}
