#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    scanf("%d",&a);
    char *p;
    p=(char*)malloc(sizeof(a));
    char b;
    scanf("%c",&b);
    gets(p);
    puts(p);
    return 0;
}