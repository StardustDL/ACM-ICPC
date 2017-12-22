/*
子数整数
*/
#include<stdio.h>
int main(){
	int k,i,a,b,c;
	scanf("%d",&k);
	for(i=10000;i<=30000;i++){
		a=i/100;b=i%10000/10;c=i%1000;
		if(a%k+b%k+c%k==0)printf("%d\n",i);
	}
	return 0;
}
