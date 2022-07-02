#include <stdio.h>

int main(){
    int a=50;
    int b=100;
    int *p_1;//定义一个指针变量p_1
    int *p_2;//定义一个指针变量p_2
    p_1=&a;//将a的地址赋值给p_1
    p_2=&b;//将b的地址赋值给p_2
    printf("a:%d \nb:%d\n" ,a,b);
    printf("p_1:%d \np_2:%d\n",*p_1,*p_2);//
}