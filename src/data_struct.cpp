#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef int ElemType;//顺序表中元素的类型

//静态分配
typedef struct {
    ElemType data[MaxSize];//定义的数组，用来存放元素
    int length;//当前顺序表中的元素个数
} SqList;

//插入操作
//i为插入位置，e为待插入的元素
bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) {
        printf("插入位置不合法！\n");//判断插入的位置是否合法
        return false;
    }
    if (L.length == MaxSize) {
        printf("顺序表已满！\n");//判断顺序表是否已满
        return false;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];//将后面的元素向后移动一位
    }
    L.data[i - 1] = e;//数组下标从0开始，所以i-1
    L.length++;
    return true;
}

//删除操作
//i为删除位置，e为删除的元素
bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) {
        printf("删除位置不合法！\n");//判断删除的位置是否合法
        return false;
    }
    if (L.length == 0){
        printf("顺序表为空！\n");//判断顺序表是否为空
        return false;
    }
    e = L.data[i - 1];//获取顺序表中对应的元素，赋值给e
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;//删除一个元素，顺序表长度减1
    return true;
}

//查找操作
//i为查找位置，e为查找的元素
int ListFind(SqList L, ElemType e) {
    int i = 1;
    for (i = 1; i <= L.length; i++) {
        if (L.data[i - 1] == e) {
            return i+1;
        }
    }
    return 0;
}

//打印顺序表元素
void PrintList(SqList& L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

//主函数
int main(){
    SqList L;//顺序表的名称
    bool ret;//查看返回值，值的类型为布尔值
    ElemType del;//用来存储要删除的元素
    //手动在顺序表内插入元素
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;//顺序表的长度为3，代表插入了三个元素

    //插入元素
    ret=ListInsert(L,2,60);
    if(ret){
        printf("插入成功\n");
        printf("插入后的顺序表为：");
        PrintList(L);//打印成功后顺序表
        printf("\n");
    }else{
        printf("插入失败\n\n");
    }

    //手动在顺序表内删除元素
    ret=ListDelete(L,2,del);//删除元素
    if(ret){
        printf("删除成功\n");
        printf("删除的元素为%d\n\n",del);//打印删除的元素
        PrintList(L);//打印成功后顺序表
    }else{
        printf("删除失败\n\n");
    }

    //手动在顺序表内查找元素
    int i=ListFind(L,2);//查找元素
    if(i){
        printf("查找成功\n");
        printf("查找的元素为%d\n\n",i);//打印查找的元素
    }else{
        printf("查找失败\n\n");
    }
    return 0;
}