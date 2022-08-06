#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
typedef struct{
    int *data;
    int length;
    int MaxSize;
}SeqList;

void InitList(SeqList &L){
    L.data = (int *)malloc(sizeof(int) * InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L,int len){
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for(int i = 0; i < L.length; i++){
        L.data[i] = p[i];
    }
    L.MaxSize= L.MaxSize + len;
    free(p);
}

int main(){
    SeqList L;
    InitList(L);
    //往顺序表插入元素1，2，3，4，5，6，7，8，9，10
    for(int i = 0; i < 10; i++){
        if(L.length == L.MaxSize){
            IncreaseSize(L, 10);
        }
        L.data[L.length] = i + 1;
        L.length++;
    }
    IncreaseSize(L,5);
    //插入新元素11，12，13，14，15
    for(int i = 0; i < 5; i++){
        if(L.length == L.MaxSize){
            IncreaseSize(L, 5);
        }
        L.data[L.length] = i + 11;
        L.length++;
    }
    //打印顺序表
    for(int i = 0; i < L.length; i++){
        printf("data[%d] = %d\n", i, L.data[i]);
    }
    return 0;
}