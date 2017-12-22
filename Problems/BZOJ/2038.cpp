/*
[2009国家集训队]小Z的袜子(hose)
分析：莫队算法，一个坐标分块，排序，暴力，注意修改顺序 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define sqr(x) ((LL)(x)*(x))
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
typedef long long LL;
struct query_data{
	int l,r,id;
}qs[MAXN+3];
int n,cq,block,cnt[MAXN+3],a[MAXN+3];
LL ans[MAXN+3][2];
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
bool cmp(const query_data &a,const query_data &b){
	return (a.l/block)==(b.l/block)?a.r<b.r:(a.l/block)<(b.l/block);
}
void solve(){
	LL tmp=0;
	int l=1,r=0;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=cq;i++){
		while(r<qs[i].r){
			r++;tmp-=sqr(cnt[a[r]]);cnt[a[r]]++;tmp+=sqr(cnt[a[r]]);
		}
		while(r>qs[i].r){
			tmp-=sqr(cnt[a[r]]);cnt[a[r]]--;tmp+=sqr(cnt[a[r]]);r--;
		}
		while(l<qs[i].l){
			tmp-=sqr(cnt[a[l]]);cnt[a[l]]--;tmp+=sqr(cnt[a[l]]);l++;
		}
		while(l>qs[i].l){
			l--;tmp-=sqr(cnt[a[l]]);cnt[a[l]]++;tmp+=sqr(cnt[a[l]]);
		}
		ans[qs[i].id][0]=tmp-(r-l+1);
		ans[qs[i].id][1]=(LL)(r-l+1)*(r-l);
		LL k=gcd(ans[qs[i].id][0],ans[qs[i].id][1]);
		ans[qs[i].id][0]/=k;
		ans[qs[i].id][1]/=k;
	}
}
int main(){
	scanf("%d%d",&n,&cq);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=cq;i++){scanf("%d%d",&qs[i].l,&qs[i].r);qs[i].id=i;}
	block=(int)sqrt(n);
	sort(qs+1,qs+cq+1,cmp);
	solve();
	for(int i=1;i<=cq;i++){
		printf("%lld/%lld\n",ans[i][0],ans[i][1]);
	}
	return 0;
}

