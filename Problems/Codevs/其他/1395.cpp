/*
��һ�������м�λ
*/
#include<stdio.h>
int main(){
	int s,k=0;
	scanf("%d",&s);
	while(s!=0){
		k++;
		s=s/10;
	}
	printf("%d",k);
	return 0;
}
