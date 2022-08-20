#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
    int data[MaxSize];
    int length;
}sqList;

bool merge_two_sqlist(sqList &L1, sqList &L2, sqList &L3){
    int i=0,j=0,k=0;
    if(L1.length+L2.length>L3.length){
        return false;
    }
    while(i<L1.length&&j<L2.length){
        if(L1.data[i]<L2.data[j]){
            L3.data[k++]=L1.data[i++];
        }else{
            L3.data[k++]=L2.data[j++];
        }
    }
    while(i<L1.length){
        L3.data[k++]=L1.data[i++];
    }
    while(j<L2.length){
        L3.data[k++]=L2.data[j++];
    }
    L3.length=k;
    return true;
}

int main() {
    sqList L1,L2,L3;
    L1.length = 0;
    L2.length = 0;
    for(int i = 0; i < 10; i++){
        scanf("%d", &L1.data[i]);
        if(L1.data[i]==-1) break;
        L1.length++;
    }
    for(int i = 0; i < 10; i++){
        scanf("%d", &L2.data[i]);
        if(L2.data[i]==-1) break;
        L2.length++;
    }
    merge_two_sqlist(L1,L2,L3);
    for(int i = 0; i < L3.length; i++){
        printf("%d ", L3.data[i]);
    }
    return 0; 
}