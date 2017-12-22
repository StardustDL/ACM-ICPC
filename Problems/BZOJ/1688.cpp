/*
[Usaco2005 Open]Disease Manangement 疾病管理
分析：状压DP，注意是个01背包 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1000,POW=15;
int n,d,K,ed,ans;
int bin[POW+3],a[MAXN+3],f[1<<POW];
bool check(int x){
	int cnt=0;
	for(int i=0;i<d;i++)cnt+=(x&bin[i])!=0;
	return cnt<=K;
}
int main(){
	bin[0]=1;for(int i=1;i<=POW;i++)bin[i]=(bin[i-1]<<1);
	scanf("%d%d%d",&n,&d,&K);
	for(int i=1,x,t;i<=n;i++){
		a[i]=0;
		scanf("%d",&x);
		while(x--){
			scanf("%d",&t);
			a[i]+=bin[t-1];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=(1<<d)-1;j;j--)f[j|a[i]]=max(f[j|a[i]],f[j]+1);
	for(int i=0;i<(1<<d);i++)if(check(i))ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
