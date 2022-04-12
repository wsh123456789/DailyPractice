#include <stdio.h>
int stringFind(char string[100],char dest[100]) {
    if (string == NULL|| dest == NULL) 
	printf("0\n");//都为空返回0 
    int i = 0;
    int j = 0;
	int flag=0;
    //比较的前提是母串不为空 
    while (string[i] != '\0') {
    	
    	//查找母串中和子串第一个字符相同的字符 
        if (string[i] != dest[0]) {
            i ++;
            continue;
        }
        j = 0;
        //依次比较符合条件的母串与子串的字符是否相同直到某一字符串为空 
        while (string[i+j] != '\0' && dest[j] != '\0') {
            if (string[i+j] != dest[j]) {
                break;
            }
            j ++;
        }
		//如果符合条件子串下一个字符是空，就输出位置为i+1 
        if (dest[j] == '\0') 
        {
		printf("%d\n",i+1);
		flag=1;
	}
       //进行下一次循环寻找是否还有其他相同的位置 
        i ++;
    }
    //flag为零说明没有符合条件输出零 
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
