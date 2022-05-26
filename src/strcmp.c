#include <stdio.h>
#include <string.h>

int main(){
    char c[100];
    char d[100];
    gets(c);
    int i;
    int j;
    for (i=strlen(c)-1,j=0;i>=0;i--,j++){
        d[j]=c[i];
    }
    //d[j]='\0';//把末尾换成\0，防止输出错误字符
    puts(d);
    int result = strcmp(c, d);
    if (result < 0){
        printf("%d\n",-1);
    }
    else if (result > 0){
        printf("%d\n", 1);
        }
        else{
            printf("%d\n", 0);
            }
        return 0;
}