// 定义域三元组(a,b,c)的距离D=|a-b|+|b-c|+|c-a|。给定3个非空整数集合S1,S2和S3。
// 按升序分别存储在三个数组中。请设计一个尽可能高效的算法。
// 计算并输出所有可能的三元组(a,b,c)中的最小距离。要求:
// 1给出算法的基本设计思想。
// 2.根据设计思想，采用c语言或c加加语言描述算法。关键之处给出注释。
// 3.说明你所设计算法的时间复杂度和空间复杂度。

// 最好时间复杂度为O(min(l,m,n));最坏时间复杂度为O(l+m+n)；
// 空间复杂度为O(1)；

#include<stdio.h>
#include<math.h>

#define maxsize 50
typedef struct{
	int data[maxsize];
	int length;
}SqList;

void min_dis(SqList a,SqList b,SqList c){
	int i=0,j=0,k=0,d,min=65536,min_a,min_b,min_c;//min为最小距离，min_a,min_b,min_c为最小距离对应的三元组
	while(i<a.length&&j<b.length&&k<c.length){
		d=abs(a.data[i]-b.data[j])+abs(b.data[j]-c.data[k])+abs(c.data[k]-a.data[i]);//计算三元组的距离
		if(d<min){//如果距离小于之前的最小距离，则更新最小距离和三元组
			min=d;
			min_a=a.data[i];
			min_b=b.data[j];
			min_c=c.data[k];
		}
		if(a.data[i]<b.data[j]&&a.data[i]<c.data[k]){//如果a.data[i]最小，则i++
			i++;
		}else if(b.data[j]<a.data[i]&&b.data[j]<c.data[k]){//如果b.data[j]最小，则j++
			j++;
		}else{
			k++;//如果c.data[k]最小，则k++
		}	
	}
	printf("%d (%d,%d,%d)\n",min,min_a,min_b,min_c);
}

int main(){
    SqList a,b,c;
    int i;
    a.length=3;
    b.length=4;
    c.length=5;
    a.data[0]=1;
    a.data[1]=2;
    a.data[2]=3;
    b.data[0]=2;
    b.data[1]=3;
    b.data[2]=4;
    b.data[3]=5;
    c.data[0]=3;
    c.data[1]=4;
    c.data[2]=5;
    c.data[3]=6;
    c.data[4]=7;
    min_dis(a,b,c);
    return 0;
}
