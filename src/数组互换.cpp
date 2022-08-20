//已知在一维数组A[m+n]中存放两个线性表(a1,a2,a3…,am)和(b1,b2,b3,b4…,bn)。试编写一个函数。将数组中两个顺序表的位置互换，即将 (b1,b2,b3,b4…,bn)放在 (a1,a2,a3…,am)的前面。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 50
typedef int ElemType;
typedef struct{
	int data[MaxSize];
	int length;
}SqList;

void Reverse(SqList &L,ElemType left,ElemType ArraySize){
    ElemType temp;//用来交换顺序表的两个元素的临时变量
    for(int j = left,i = 0;j < left + ArraySize/2;j++,i++){
        temp = L.data[j];
        L.data[j] = L.data[left + ArraySize - i - 1];//交换顺序表对称位置元素值
        L.data[left + ArraySize - i - 1] = temp;
    }
}

void Exchange(SqList &L,int m,int n){
	if(m + n != L.length || m < 0 || n < 0){
		return;//传入的参数 m,n不合法
	}
    ElemType temp = 0;
    Reverse(L,0,m);//交换顺序表前面部分 L[0,...,m]对称位置元素值
    Reverse(L,m,n);//交换顺序表后面部分 L[m,...,m+n]对称位置元素值
    Reverse(L,0,m+n);//交换整个顺序表 L[0,...,m+n]对称位置元素值
}

int main(){
	SqList a;
	a.length=0;
	for(int i=0;i<MaxSize;++i){
		scanf("%d",&a.data[i]);
		if(a.data[i]==-1) break;
		a.length++;
	}
	int m=3,n=7;
    Exchange(a,m,n);
	for(int i=0;i<a.length;++i){
		printf("%d ",a.data[i]);
	}
	return 0;
}