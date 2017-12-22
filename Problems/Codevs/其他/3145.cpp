/*
ººÅµËþÓÎÏ·
*/
#include<stdio.h>
#include<cmath>
void move(int n,char a,char c,char b){
	if(n==1)printf("%d from %c to %c\n",n,a,c);
	else{
		move(n-1,a,b,c);
		printf("%d from %c to %c\n",n,a,c);
		move(n-1,b,c,a);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%.0lf\n",pow(2,n)-1);
	move(n,'A','C','B');
	return 0;
}
