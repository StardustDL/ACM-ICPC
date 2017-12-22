/*
Zhenhuan
·ÖÎö£ºÍ¬1863 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=20000,INF=0x3f3f3f3f;
int mx[MAXN+3],mn[MAXN+3],a[MAXN+3],n,l,r,ans;
bool check(int x){
	mx[1]=mn[1]=a[1];
	for(int i=2;i<=n;i++){
		mx[i]=min(a[i],a[1]-mn[i-1]);
		mn[i]=max(0,a[1]+a[i]+a[i-1]-mx[i-1]-x);
	}
	return mn[n]==0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);l=max(l,a[i]+a[i-1]);}
	r=l<<1;ans=l;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans); 
	return 0;
}

