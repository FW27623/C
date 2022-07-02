#include <stdio.h>

void change(int *p_1,int *p_2){
    int p;
    p=*p_1;
    *p_1=*p_2;
    *p_2=p;
}

int main(){
    int a;
    int b;
    int *p_1;
    int *p_2;
    scanf("%d %d",&a,&b);
    p_1=&a;//使用指针变量p_1来存储a的地址
    p_2=&b;//使用指针变量p_2来存储b的地址
    printf("a:%d \nb:%d\n" ,a,b);
    if (p_1>p_2){
        change(p_1,p_2);//符合p_1>P_2的，调用change函数完成交换
        printf("p_1:%d \np_2:%d\n",*p_1,*p_2);
    }
}