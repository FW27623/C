#include <stdio.h>

int main(){
    int a,b,c,d,total=0;
    for (a=1;a<=40;a++){
        for(b=1;b<=40;b++){
            for(c=1;c<=40;c++){
                for(d=1;d<=40;d++){
                    if(10*a+5*b+c*2+d*1==100&&a+b+c+d==40){
                        total=total+1;
                    }
                }
            }
        }
    }
    printf("%d",total);
}