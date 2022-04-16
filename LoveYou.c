#include<stdio.h>
void LoveYou(int n)//n为问题规模
{
    int i=1;//①--1次
    while(i<=n)//②--3001次
    {
        printf("I Love You\n",i);//③--3000次
        i++;//④--3000次
    }
    printf("I Love You More than %d\n",n);//⑤--1次
}
//T*(3000)=1+3001+2*3000+1
//T*(n)=3n+3
int main()
{
    LoveYou(3000);
}