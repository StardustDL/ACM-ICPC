/*
三角形面积
*/
#include<stdio.h>
#include<math.h>
int main(){
	int a,b,c;
	double p;
	scanf("%d%d%d",&a,&b,&c);
	if((a+b<=c)||(a+c<=b)||(b+c<=a)){
		printf("No answer");return 0;
	}
	p=(a+b+c)/2.0;
	printf("%.2f",sqrt(p*(p-a)*(p-b)*(p-c)));
	return 0;
}
