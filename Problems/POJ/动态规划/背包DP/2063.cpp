/*
Investment
题意：给出初始资金，还有年数，然后给出每个物品的购买价格与每年获得的利益，要求在给出的年份后所能得到的最大本利之和。
分析：因为每种物品可以多次购买，可以看做是完全背包的题目，但是要注意的是，由于本金可能会很大，所以我们要对背包的大小进行压缩，值得注意的是，题目已经说了本金与物品的购买价格都是1000的倍数，所以我们可以将他们都除以1000来进行压缩，然后就是一道完全背包模板题了。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10,MAXV=100000,INF=0x3f3f3f3f;
int money,n,v[MAXN+3],w[MAXN+3],ans=0,opt[MAXV+3],T,year;
inline void input(){
	scanf("%d%d%d",&money,&year,&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&v[i],&w[i]),v[i]/=1000;
}
inline int dp(int maxv){
	memset(opt,0,sizeof(opt));
	for(int i=1;i<=n;i++)
		for(int j=v[i];j<=maxv;j++)opt[j]=max(opt[j-v[i]]+w[i],opt[j]);
	return opt[maxv];
}
inline int solve(){
	ans=money;
	while(year--)ans+=dp(ans/1000);
	return ans;
}
int main(){
	for(scanf("%d",&T);T;T--){
		input();
		printf("%d\n",solve());
	}
	return 0;
}

