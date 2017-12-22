/*
今年天数
*/
#include<stdio.h>
bool isrun(int year){
	return (year%4==0&&year%100!=0||year%400==0);
}
int main(){
	int n;
	scanf("%d",&n);
	if(isrun(n))printf("366");
	else printf("365");
	return 0;
}
