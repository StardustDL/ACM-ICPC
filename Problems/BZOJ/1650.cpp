/*
[Usaco2006 Dec]River Hopscotch 跳石子
分析：二分答案+判定 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
int l,n,m,d[MAXN+3];
bool check(int x){
	 int cnt=0,lst=d[0];
	 for(int i=1;i<=n;i++){
			 if(d[i]-lst<x)cnt++;
			 else lst=d[i];
	 }
	 return d[n+1]-lst>=x&&cnt<=m;
}
int solve(int l,int r){
	int ans=l;
	while (l<=r){
		  int mid=(l+r)>>1;
		  if(check(mid))ans=mid,l=mid+1;
		  else r=mid-1;
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&l,&n,&m);
	d[0]=0;
	d[n+1]=l;
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	sort(d+1,d+n+1); 
	printf("%d\n",solve(0,l));
	return 0;
}
