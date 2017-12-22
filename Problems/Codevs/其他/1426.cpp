/*
ÕÒÁãÇ®µÄ³ÌĞò
*/
#include<stdio.h>
int main(){ 
	int n,m;
	scanf("%d%d",&n,&m);
	m = n-m;
	n = m;
	printf("%d\n",m);
	bool a[6] = {false,false,false,false,false,false};
	if(m>=100){
		printf("100*%d",m / 100);
		m = m % 100;
		a[0]=true;
	}
	if(m>=50){
		if(a[0])printf("+");
		printf("50*%d",m / 50);
		m = m % 50;
		a[1]=true;
	}
	else a[1] = a[0];
	if(m>=20){
		if(a[1])printf("+");
		printf("20*%d",m / 20);
		m = m % 20;
		a[2]=true;
	}
	else a[2] = a[1];
	if(m>=10){
		if(a[2])printf("+");
		printf("10*%d",m / 10);
		m = m % 10;
		a[3]=true;
	}
	else a[3] = a[2];
	if(m>=5){
		if(a[3])printf("+");
		printf("5*%d",m / 5);
		m = m % 5;
		a[4]=true;
	}
	else a[4] = a[3];
	if(m>=1){
		if(a[4])printf("+");
		printf("1*%d",m / 1);
		m = m % 1;
		a[5]=true;
	}
	else a[5] = a[4];
	printf("=%d",n);
	return 0;
}
