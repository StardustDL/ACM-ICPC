/*
Êý×ÖÍ³¼Æ
*/
#include<stdio.h>
int times(int n){
	int s=0;
	while(n!=0){
		if(n % 10==2)s++;
		n/=10;
	}
	return s;
}
int main(){
	int n,m,i,k=0;
	scanf("%d%d",&n,&m);
	for(i=n;i<=m;i++)k+=times(i);
	printf("%d",k);
	return 0;
}
