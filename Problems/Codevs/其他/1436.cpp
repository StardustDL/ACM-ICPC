/*
ÂÏÉúËØÊı 2
*/
#include<stdio.h>
bool iszhi(int n){
	for(int i=2;i*i<=n;i++)if(n%i==0)return false;
	return true;
}
int main(){
	int m,n,i,j,s=0;
	scanf("%d%d",&m,&n);
	for(i=2;i<=m-n;i++){
		if(iszhi(i)&&iszhi(i+n)){
			printf("%d %d\n",i,i+n);
			s++;
		}
	}
	printf("Total Is:%d",s);
	return 0;
}
