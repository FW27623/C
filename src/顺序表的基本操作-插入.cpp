#include<stdio.h>
#define MaxSize 10  //定义最大的长度
typedef struct {
    int data[MaxSize];  //用静态的“数组”存放数据元素
    int length;     //顺序表的当前长度
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


int main(){
    SqList L; //声明一个顺序表
    InitList(L); // 初始化顺序表
    ListInsert(L,1,1);
    ListInsert(L,2,2);
    ListInsert(L,3,4);
    ListInsert(L,4,5);
    ListInsert(L,5,6);
    ListInsert(L,3,3);
    for(int i=0;i<L.length;i++)
        printf("data[%d]=%d\n",i,L.data[i]);
    
    return 0;
}
