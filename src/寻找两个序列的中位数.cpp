// 一个长度为L(L>=1)的升序序列s,处在第L/2个位置的数称为s的中位数。例如，若序列s1=(11,13,15,17,19)，则s1的中位数是 15。两个序列的中位数是含他们所有元素的升序序列的中位数。例如，若s2=（2，4，6，8，20）。则s1和s2的中位数是11。现在有两个等长升序序列A和B。试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数,要求:
// 1.给出算法的基本设计思想。
// 2.根据设计思想，采用C，C++，或java语言描述算法。关键之处给出注释。
// 3.说明你所设计算法的时间复杂度和空间复杂度。
#include<stdio.h>

#define maxsize 50
typedef struct{
	int data[maxsize];
	int length;
}SqList;
int mid_num(SqList a,SqList b){
	if(a.length!=b.length) return -1;
	int i=0,j=0,k=0,mid;
	while(i<a.length&&j<b.length&&k!=a.length){//这里需要都成立才能进入下一步，i、j、k为了避免重复计算
		if(a.data[i]<=b.data[j]){//i和j比大小，如果i的结果小于等于b的结果
			mid=a.data[i++];//将a的元素存入mid变量中，每次调用都将i加1
			k++;
		}else{
			mid=a.data[j++];
			k++;
		}	
	}
	while(i<a.length&&k!=a.length){
		mid=a.data[i++];
		k++;
	}
	while(j<b.length&&k!=a.length){
		mid=a.data[j++];
		k++;
	}
	return mid;
}

int main(){
	SqList a,b;               
	a.length=0;
	b.length=0;
	for(int i=0;i<maxsize;++i){
		scanf("%d",&a.data[i]);
		if(a.data[i]==-1) break;
		a.length++;
	}
	for(int i=0;i<maxsize;++i){
		scanf("%d",&b.data[i]);
		if(b.data[i]==-1) break;
		b.length++;
	}
	printf("%d ",mid_num(a,b));
	return 0;
} 
