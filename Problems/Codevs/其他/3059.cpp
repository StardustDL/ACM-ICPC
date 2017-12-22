/*
тк╥я
*/
#include<stdio.h>
int money(int n){
	if(n<=10)return 50;
	else if(n<=100)return 180;
	else if(n<=300)return 300;
	else if(n<=1000)return 1000;
	else if(n<=3000)return 2000;
	else return -1;
}
int main(){
	int n,a,k,s=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		k=money(a);
		if(k<0){
			printf("Can't transport!");
			return 0;
		}
		s+=k;
	}
	printf("%d",s);
	return 0;
}
