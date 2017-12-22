/*
½ÚÈÕ²ÊµÆ
*/
#include<stdio.h>
const char cc[5]={'p','r','b','y','g'};
int main(){
	int n;
	scanf("%d",&n);
	printf("%c",cc[n % 5]);
	return 0;
}
