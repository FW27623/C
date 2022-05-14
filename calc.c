//#define _CRT_SECURE_NO_WARNINGS//解决vs编译器不支持的警告
#include<stdio.h>
int main(){
    int a = 0;
    int b = 0;
    int c = 0;
    printf("Enter a number: ");
    scanf("%d%d", &a,&b); 
    c = a + b;
    printf("%d+%d=%d\n",a,b,c);
    printf("%d",a+b);
    return 0;
}