//从有序顺序表中删除其值在给定值s与t之间（包含s和t，要求s<t）的所有元素。若s或t取值不合理或顺序表为空。则显示出错信息并退出运行。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
    int data[MaxSize];
    int length;
}sqList;
bool Del_s_t (sqList &L, ElemType s, ElemType t) {
    //删除顺序表L中值在给定值s与t之间（要求s<t）的所有元素
    int i,k=0;
    if (L.length==0 || s>=t)
        return false;  //线性表为空或s、t不合法，返回
    for(i=0;i<L.length;i++){
        if (L.data[i]< s || L.data[i] > t){
            L.data[k] = L.data[i];
            k++;    
        }
    }
    L.length=k;
    return true;
}

int main() {
    sqList L;
	L.length = 0;
	for(int i = 0; i < 10; i++){
		scanf("%d", &L.data[i]);
		L.length++;
	}
    Del_s_t(L,3,8);
	for(int i = 0; i < L.length; i++){
		printf("%d ", L.data[i]);
	}
	return 0; 
}