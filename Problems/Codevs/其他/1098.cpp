/*
¾ù·ÖÖ½ÅÆ
*/
#include<stdio.h>
int main()
{
	int n,a[101],i,t=0,s=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		t+=a[i];
	}
	t/=n;
	for(i=1;i<=n-1;i++){
		if(a[i]!=t){
			a[i+1]=a[i+1]+a[i]-t;
			s++;
		}
	}
	printf("%d",s);
    return 0;
}
