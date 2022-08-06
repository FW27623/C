#include <stdio.h>

#define MaxSize 10
typedef struct{
    int data[MaxSize];
    int length;
}SqList;

// 初始化顺序表
void InitList(SqList &L){
    L.length = 0;// 初始化长度为0
}

int main(){
    SqList L;
    InitList(L);
    // for(int i = 0; i < L.length; i++)//使用这句的话，括号里的printf不会执行
    for(int i = 0; i < MaxSize; i++){
        printf("data[%d] = %d\n", i, L.data[i]);//不规范操作，内存中存在脏数据
    }
    return 0;
}
