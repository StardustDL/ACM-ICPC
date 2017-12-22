/*
ÌÕÌÕÕªÆ»¹û
*/
#include<stdio.h>
int main(){
	int a[11],k,s=0;
	for(int i=1;i<=10;i++)scanf("%d",&a[i]);
	scanf("%d",&k);
	k+=30;
	for(int i=1;i<=10;i++)
		if(k>=a[i])s++;
	printf("%d",s);
	return 0;
}
