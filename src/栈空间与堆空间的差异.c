#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char *print_stack(){
//     char c[]="I am print stack";
//     puts(c);
//     return c;
// }

char *print_malloc(){
    char *p=(char*)malloc(20);
    strcpy(p, "I am print malloc");
    puts(p);
    return p;
}

int main(){
    char *p;
    // p=print_stack();//栈空间会随着函数的执行结束而释放
    // puts(p);
    p=print_malloc();//堆空间不会随着函数的执行结束而释放
    puts(p);
    free(p);//释放申请的空间
    return 0;
}