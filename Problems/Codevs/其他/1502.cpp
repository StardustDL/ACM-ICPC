/*
这个月有几天
*/
#include<stdio.h>
bool isrun(int year){
	return (year%4==0&&year%100!=0||year%400==0);
}
int main(){
	int n,k,a[12];
	scanf("%d%d",&n,&k);
	if(k==2){
		if(isrun(n))printf("%d",29);
		else printf("28");
		return 0;
	}
	switch(k){
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:printf("31");break;
		case 4:case 6:case 9:case 11:printf("30");break;
	}
	return 0;
}
