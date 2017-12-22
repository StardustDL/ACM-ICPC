/*
Êý×Ö·´×ª
*/
#include<stdio.h>
int main(){
	int n;
	bool b = true;
	scanf("%d",&n);
	if(n<0){
		printf("-");
		n=n*-1;
	}
	else if(n==0)printf("0");
	while(n!=0){
		if(n%10!=0){
			printf("%d",n%10);
			b=false;
		}
		else if(!b)printf("0");
		n = n/10;
	}
	return 0;
}
