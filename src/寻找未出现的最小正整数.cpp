// 给定一个含n个整数的数组。请设计一个在时间上尽可能高效的算法。找出数组中未出现的最小正整数。例如，数组{-5,3,2,3}中未出现的最小正整数是1。数组{1,2，3}中未出现的最小正整数是4.要求：
// 1。给出算法的基本设计思想。
// 2。根据设计思想，采用C或C++语言描述算法。关键之处给出注释。
// 3。说明你所设计算法的时间复杂度和空间复杂度。

#include<stdio.h>

#define maxsize 50
typedef struct{
	int data[maxsize];
	int length;
}SqList;

int min_z(SqList a){
	int i=0;
	int b[maxsize]={0};//记录每个元素出现的次数
	while(i<a.length){
		if(a.data[i]>0){
			b[a.data[i]]++;//统计数组b中每个元素出现的次数
		}
		i++;
	}
	for(int j=1;j<maxsize;j++){
		if(b[j]==0){
			return j;//如果b[j]=0，则说明j为未出现的最小正整数
		}
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
	printf("%d\n",min_z(a));
	return 0;
} 
