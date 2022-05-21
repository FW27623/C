#include <stdio.h>

int main(){
    int total=0;
    int a[100];
    int b;
    scanf("%d",&b);
    for(int i=0;i<b;i++){
        scanf("%d",&a[i]);
        if (a[i]==2){
            total++;
        }
        
    }
    printf("%d",total);
}