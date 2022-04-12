#include<stdio.h>
void Del(int a[],int N){
    int j=0;
    for(int i=0;i<N;i++){
        if(a[i]!=0){
            a[j]=a[i];
            j++;
        }
    }
    for(int i=0;i<j;i++){
        printf("%d ",a[i]);
    }
    printf("\n%d",j);
}
int main(){
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i=0; i<N; i++){
        scanf("%d",&a[i]);
    }
    Del(a,N);
}
