#include <stdio.h>

void change(char *d){
    *d='H';
    d[1]='E';
    *(d+2)='L';
}

int main(){
    char c[10]="hello";
    change(c);
    puts(c);
    return 0;
}