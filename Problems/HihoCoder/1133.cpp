#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k,a[1000000+3];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(k>n){puts("-1");return 0;}
	nth_element(a+1,a+k,a+n+1);
	printf("%d\n",a[k]);
	return 0;
}