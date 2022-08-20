#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 10
typedef int ElemType;
typedef struct {
    int data[MaxSize];
    int length;
}sqList;

bool del_same (sqList &L){
    int i,j;
    if (L.length==0){
        return false;
    }
    for(i=0,j=1;j<L.length;j++){
        if(L.data[i]!=L.data[j]){
            L.data[++i]=L.data[j];
        }
    }
    L.length=i+1;
    return true;
}

int main() {
    sqList L;
    for(int i=0;i<MaxSize;i++){
	L.data[i] = 0;
    L.length = 0;
    }
    for(int i = 0; i < 10; i++){
		scanf("%d", &L.data[i]);
		L.length++;
	}
    del_same(L);
    for(int i = 0; i < L.length; i++){
		printf("%d ", L.data[i]);
	}
	return 0; 
}