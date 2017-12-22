/*

*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
double sta[MAXN+3],x,a[MAXN+3];
int top=0,n,ans=0,f[MAXN+3],g[MAXN+3]; 
int getup(int l,int r){
	sta[top=0]=-5;
	for(int i=l;i<=r;i++){
		if(a[i]>sta[top])sta[++top]=a[i];
		else sta[lower_bound(sta+1,sta+top+1,x)-sta]=a[i];
		f[i]=top;                                                                                           
	}
	return top;
}
int getdown(int l,int r){
	sta[top=0]=-5;
	for(int i=l;i<=r;i++){
		if(-a[i]>sta[top])sta[++top]=-a[i];
		else sta[lower_bound(sta+1,sta+top+1,x)-sta]=-a[i];
		g[i]
	}
	return top;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
	for(int i=1;i<n;i++){
		ans=max(ans,getup(1,i)+getdown(i+1,n));
	}
	printf("%d\n",n-ans);
	return 0;
}
