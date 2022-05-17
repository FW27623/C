#include <stdio.h>

int main(){
    int a,b=0,c,temp;
	scanf("%d", &a);
	c = a;
	while (a) 
	{
		temp = a % 10;
		b = b * 10 + temp;
		a = a / 10;
	}
	if (c == b) 
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	return 0;
}