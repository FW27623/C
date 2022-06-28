#include <stdio.h>
#include <stdlib.h>

void cite(char *&p){
    // p=(char*)malloc(sizeof(p));
    p=(char*)malloc(100);
    fgets(p,100,stdin);
}

int main(){
    char *p;
    cite(p);
    puts(p);
    return 0;
}