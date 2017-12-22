/*
×ÔÃİÊı
*/
#include<stdio.h>
int a[6],m,n,i,j,k,s;
int doing(int n){
	int i=0;
	while(n!=0){
		i++;
		a[i] = n % 10;
		n/=10;
	}
	return i;
}
int cf(int n,int k){
	int i;
	int s = 1;
	for(i=1;i<=k;i++)s*=n;
	return s;
}
int main(){
	bool b = false;
	scanf("%d%d",&m,&n);
	for(i=m;i<=n;i++){
		s = 0;
		k=doing(i);
		for(j=1;j<=k;j++)s+=cf(a[j],k);
		if(s==i){
			printf("%d\n",i);
			b = true;
		}
	}
	if(!b)printf("No solution!");
	return 0;
}
