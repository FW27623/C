#include <stdio.h>

int factorial(int a){
    int i,result=1;
    for(i=1;i<=a;i++){
        result*=i;
    }
    return result;
}

int main(){
    int a;
    scanf("%d",&a);
    printf("%d",factorial(a));
}