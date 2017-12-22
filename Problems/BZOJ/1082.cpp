/*
[SCOI2005]栅栏
分析：二分搜索+剪枝
		将木板排序，二分可以切出木板的数量
		当然是切最小的ans块
		搜索每块木板用哪个木材切
		剪枝就是当木材大小小于最小的木块则丢弃
		记录当前丢弃的木材量，若加上ans块木板 > 所有的木材 则不合法 
	  但是题目中：对于店老板提供的和约翰需要的每块木板，你只能使用一次。这句话是什么意思？一块木板只能切一次？但是那样就WA了= = 
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std; 
const int MAXN=1000;
int v[MAXN+3], w[MAXN+3], sum[MAXN+3], c[MAXN+3], tot, rest, n, m;
bool dfs(int dep, int last) {
	if(!dep) return true;
	if(rest+sum[dep]>tot) return false;
	for(int i=last;i<=n;i++) {
		if(c[i]>=w[dep]) {
			c[i]-=w[dep];
			if(c[i]<w[1]) rest+=c[i];
			if(w[dep]==w[dep-1]) { if(dfs(dep-1, i)) return true; }
			else if(dfs(dep-1, 1)) return true;
			if(c[i]<w[1]) rest-=c[i];
			c[i]+=w[dep];
		}
	}
	return false;
}
bool check(int d) {
	memcpy(c,v,sizeof(int)*(n+1));
	rest=0;
	return dfs(d, 1);
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&v[i]);tot+=v[i];}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	sort(w+1,w+m+1);
	sort(v+1,v+n+1);
	for(int i=1;i<=m;i++) sum[i]=sum[i-1]+w[i];
	while(sum[m]>tot)--m;
	int l=0,r=m,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}

