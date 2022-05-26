#include <stdio.h>

int main(){
    int a;
    int b=1;
    int total =1;
    scanf("%d",&a);
    while(b<=a){
        total=total*b;
        b++;
    }
    printf("%d",total);
    return 0;
}