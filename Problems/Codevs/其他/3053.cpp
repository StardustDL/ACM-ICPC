/*
¼ÆËã
*/
#include<stdio.h>
int cf(int n,int k){
	int s=1;
	for(int i=1;i<=k;i++)s*=n;
	return s;
}
int main(){
	int i,n,a[201],m;
	double s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		scanf("%d",&m);
		s+=cf(a[i],m);
	}
	printf("%.0lf",s);
	return 0;
}
