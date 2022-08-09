#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i;
    scanf("%d",&i);
    char *p;
    p=(char*)malloc(i);//malloc申请空间的单位是字节，所以要乘以sizeof(char)
    strcpy(p, "malloc success");
    puts(p);
    free(p);//free释放申请的空间
    p=NULL;
    return 0;
}