#include <stdio.h>
int stringFind(char string[100],char dest[100]) {
    if (string == NULL|| dest == NULL) 
	printf("0\n");//��Ϊ�շ���0 
    int i = 0;
    int j = 0;
	int flag=0;
    //�Ƚϵ�ǰ����ĸ����Ϊ�� 
    while (string[i] != '\0') {
    	
    	//����ĸ���к��Ӵ���һ���ַ���ͬ���ַ� 
        if (string[i] != dest[0]) {
            i ++;
            continue;
        }
        j = 0;
        //���αȽϷ���������ĸ�����Ӵ����ַ��Ƿ���ֱͬ��ĳһ�ַ���Ϊ�� 
        while (string[i+j] != '\0' && dest[j] != '\0') {
            if (string[i+j] != dest[j]) {
                break;
            }
            j ++;
        }
		//������������Ӵ���һ���ַ��ǿգ������λ��Ϊi+1 
        if (dest[j] == '\0') 
        {
		printf("%d\n",i+1);
		flag=1;
	}
       //������һ��ѭ��Ѱ���Ƿ���������ͬ��λ�� 
        i ++;
    }
    //flagΪ��˵��û�з������������ 
    if(flag==0)
    printf("0\n");
}

int main()
{
	char a[100],b[100];
	gets(a);
	gets(b);
	stringFind(a,b);
	
 } 
