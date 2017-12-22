/*
´òÓ¡»ú
*/
#include<stdio.h>
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n/2;i++){
		for(j=1;j<=n-i;j++)
			if((i==j)||(j==n-i+1))printf("X");
			else printf(" ");
		printf("X\n");
	}
	for(i=1;i<=n/2;i++)printf(" ");
	printf("X\n");
	for(i=n/2;i>=1;i--){
		for(j=1;j<=n-i;j++)
			if((i==j)||(j==n-i+1))printf("X");
			else printf(" ");
		printf("X\n");
	}
	return 0;
}
