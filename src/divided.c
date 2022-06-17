#include <stdio.h>

int change(int a){
    a=a/2;
    printf("%d",a);
}

int main(){
    int i;
    scanf("%d",&i);
    change(i);
    return 0;
}