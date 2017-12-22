/*
小B的询问
分析：莫队，考虑加一个数和删一个数对答案的影响：c(i)从0变化到c(i)，每次增加1或减少1 
		c(i)^2=?
		1+2+3+...+c(i)=(1+c(i))*(c(i))/2
		即c(i)^2=(1+2+3+...+c(i))*2-c(i)=(1*2-1)+(2*2-1)+...+(c(i)*2-1) 
		所以每次 修改对答案的影响是c(i)*2-1 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
#define sqr(x) ((x)*(x))
struct data{
	int l,r,b,id;
	bool operator <(const data &t)const{
		return b<t.b||b==t.b&&r<t.r;
	}
}ds[MAXN+3];
typedef long long LL;
LL Ans[MAXN+3],c[MAXN+3];
int n,m,k,b[MAXN+3];
void solve(){
	sort(ds+1,ds+m+1);
	int l=1,r=0;LL ans=0;
	for(int i=1;i<=m;i++){
		while(l<ds[i].l)ans-=c[b[l]]*2-1,c[b[l]]--,l++;
		while(r>ds[i].r)ans-=c[b[r]]*2-1,c[b[r]]--,r--;
		while(l>ds[i].l)l--,c[b[l]]++,ans+=c[b[l]]*2-1;
		while(r<ds[i].r)r++,c[b[r]]++,ans+=c[b[r]]*2-1;
		Ans[ds[i].id]=ans;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	int blo=sqrt(n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&ds[i].l,&ds[i].r);ds[i].id=i;ds[i].b=ds[i].l/blo;
	}
	solve();
	for(int i=1;i<=m;i++)printf("%lld\n",Ans[i]);
	return 0;
}

