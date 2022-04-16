#include<stdio.h>
void LoveYou(int n)//n为问题规模
{
    int i=1;
    while(i<=n)
    {
        printf("I Love You\n",i);
        i++;
    }
    printf("I Love You More than %d\n",n);
}
int main()
{
    LoveYou(3000);
}