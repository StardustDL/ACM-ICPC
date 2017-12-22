/*
[Usaco2007 Mar]Monthly Expense 月度开支
分析：二分答案 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
int n,m,a[MAXN+3],mx=0;
bool check(int x){
	int lst=0,cnt=1;
	for(int i=1;i<=n;i++){
		if(a[i]-a[lst]>x)cnt++,lst=i-1;
	}
	return cnt<=m;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);mx=max(mx,a[i]);a[i]+=a[i-1];} 
	int l=mx,r=a[n],ans=l;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}

