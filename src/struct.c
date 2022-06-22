#include <stdio.h>

struct student
{
    int id;
    char name[10];
    char sex;
};

int main(){
    struct student stu;
    scanf("%d %s %c",&stu.id,&stu.name,&stu.sex);
    printf("%d %s %c",stu.id,stu.name,stu.sex);
    return 0;
}