/*
[Usaco2005 feb]Aggressive cows 愤怒的牛
分析：二分答案 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
int n,c,p[MAXN+3]; 
bool check(int x){
	int lst=1,rest=c-1;
	for(int i=2;i<=n&&rest;i++)
		if(p[i]-p[lst]>=x)lst=i,rest--;
	return rest==0;
}
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	sort(p+1,p+n+1);
	int l=1,r=p[n],ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}

