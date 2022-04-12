#include<stdio.h>
int main()
{
	int m,n,i;
    int x,k=0;
	int sum=0;
	int a[31];
	scanf("%d %d %d",&m,&n,&x);
	sum=m+n;
	do
	{
		a[k]=sum%x;
		sum=sum/x;
		k++;
	}while(sum!=0);
	for(i=k-1;i >= 0; i--)
		printf("%d",a[i]);
    printf("\n");
	return 0;
} 
