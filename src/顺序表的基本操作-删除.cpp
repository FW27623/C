#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int length;
}SqList;

void InitList(SqList &L){
    for(int i=0; i<MaxSize; i++)
        L.data[i] = 0;
    L.length = 0;
}

bool ListInsert(SqList &L, int i,int e){//在L的位序i处插入元素e
	if(i<1 || i>L.length+1) //判断i的范围是否有效
		return false;
	if(L.length >= MaxSize)//当前存储空间已满，不能插入
		return false;
    for(int j=L.length; j>=i ; j--) //将第i个元素及之后的元素后移
        L.data[j] = L.data[j-1];
    L.data[i-1]=e;  //在位置i处放入e
    L.length++; //长度加1
    return true;
}

bool ListDelete(SqList &L, int i, int &e){
    if(i <1 || i> L.length)//判断i的范围是否有效
        return false;
    e = L.data[i - 1]; //将被删除的元素赋值给e
    
    for(int j=i; j<L.length; j++)//将第i个位置后的元素前移
        L.data[j-1] = L.data[j];
    L.length--;//线性表长度减1
    return true;
} 

int main(){
    SqList L;//声明一个顺序表
    InitList(L);//初始化顺序表
    ListInsert(L,1,1);
    ListInsert(L,2,2);
    ListInsert(L,3,4);
    ListInsert(L,4,5);
    ListInsert(L,5,6);
    
    int e=-1;//用变量e把删除的元素“带回来”
    if(ListDelete(L, 3, e))
        printf("已删除第3个元素，删除的元素为%d\n",e);
    else
        printf("位序i不合法，删除失败\n");
    return 0;
}
