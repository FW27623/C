// 已知一个整数序列A=(a0,a1,…an-1)其中,0<=ai<n,若存在ap1=ap2=ap3=…=apm=x且m>n/2,则称x为a的主元素。
// 例如a=(0,5,5,3,5,7,5,5)。则5为主元素.又如a=(0,5,5,3,5,1,5,7)，则A中没有主元素.

#include<stdio.h>

#define maxsize 50
typedef struct{
	int data[maxsize];
	int length;
}SqList;

int majority(SqList a){
	int i=0;
	int b[a.length]={0};
	while(i<a.length){
		b[a.data[i++]]++;//记录每个元素出现的次数
	}
	int m=b[0],maj=0;//m为最大的出现次数，maj为最大的出现次数的元素值
	for(int j=1;j<a.length;j++){
		if(b[j]>m){
			m=b[j];
			maj=j;
		}
	}
	if(m> a.length/2){
		return maj;//如果m>a.length/2，则返回主元素maj
	}	
	return -1;
}

int main(){
	SqList a;
	a.length=0;
	for(int i=0;i<maxsize;++i){
		scanf("%d",&a.data[i]);
		if(a.data[i]==-1) break;
		a.length++;
	}
	printf("%d",majority(a));
	return 0;
} 
