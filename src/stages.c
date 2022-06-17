#include <stdio.h>

int calc(int a){
    if(a==1){
        return 1;
    }
    if(a==2){
        return 2;
    }
    return calc(a-1)+calc(a-2);//斐波那契数列
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",calc(n));
    return 0;
}