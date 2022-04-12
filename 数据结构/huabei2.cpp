#include <stdio.h>
#include<string.h>
int main() {
	char s[10][20];
	int T,i;
	scanf("%d",&T);
	getchar();
	for(i=0; i<T; i++) {
		gets(s[i]);
	}
	for(i=0; i<T; i++) {

		printf("%s\n",s[i]);

	}
	return 0;
}
