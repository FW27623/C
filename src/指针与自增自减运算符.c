#include <stdio.h>

int main(){
    int a[3]={3,5,2};
    int *p;
    int j;
    p=a;//指针p指向数组a的第一个元素
    j=*p++;//j=*p;p++
    // j=(*p)++;//j=*p;(*p)++
    printf("a[0]=%d,j=%d,*p=%d\n",a[0],j,*p);//3,3,5
    j=p[0]++;//j=p[0];p[0]++
    printf("a[0]=%d,j=%d,*p=%d\n",a[0],j,*p);//3,5,6
    return 0;
}