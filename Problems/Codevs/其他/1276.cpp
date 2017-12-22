/*
Í¼±êËõ·Å
*/
#include<stdio.h>
int main(){
	int k,i,j;
	scanf("%d",&k);
	for(j=1;j<=k;j++){
		for(i=1;i<=k;i++)printf("*");
		for(i=1;i<=k;i++)printf("x");
		for(i=1;i<=k;i++)printf("*");
		printf("\n");
	}
	for(j=1;j<=k;j++){
		for(i=1;i<=k;i++)printf("  ");
		for(i=1;i<=2*k;i++)printf("x");
		printf("\n");
	}
	for(j=1;j<=k;j++){
		for(i=1;i<=k;i++)printf("*");
		for(i=1;i<=k;i++)printf("  ");
		for(i=1;i<=k;i++)printf("*");
		printf("\n");
	}
	return 0;
}
