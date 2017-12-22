/*
与3和5无关的数
*/
#include<stdio.h>
bool isyoug(int n){
	if((n%3==0)||(n%5==0))return false;
	while(n!=0){
		if((n%10==3)||(n%10==5))return false;
		n/=10;
	} 
	return true;
}
int main(){
	int n,s=0,i; 
	scanf("%d",&n);
	for(i=1;i<=n;i++)if(isyoug(i))s+=i*i;
	printf("%d",s);
	return 0;
}
