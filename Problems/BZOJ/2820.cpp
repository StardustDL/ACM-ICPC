/*
YY的GCD
分析：好难的一道题= =
	  容易想到枚举质数：
	  ans=sigma{p<=min(n,m),sigma{d<=min(n,m),miu[d]*(n/(pd))*(m/(pd))}}
	  令pd=T，先枚举T(n<m)：
	  ans=sigma{T<=n,(n/T)*(m/T)*sigma{p|T,miu(T/p)}}
	   现在要求出 sigma{p|T,miu(T/p)}关于T的前缀和
	   令g(x)= sigma{p|x,miu(x/p)}
	   有g(qx)={q|x时： sigma{p|qx,miu(qx/p)} 若q=p，则有miu(x)，否则miu(qx/p)=0，所以q|x => g(qx)=miu(x)
	   			q not |x：若q=p，则有miu(x)，否则会发现 miu(qx/p)=-miu(x/p) 所以对于所有q!=p的项,其和=-g(x)}
		这样g(x)也可以线性筛出来了
		但是这样预处理O(n)，查询O(sqrt(n)),感觉还是可能会超时的 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=10000000,INF=0x3f3f3f3f;
int mindiv[MAXN+3],miu[MAXN+3],t,n,m;
LL g[MAXN+3],sum[MAXN+3];
vector<int> pris;
inline void init(int size){
	miu[1]=1;
	for(int i=2;i<=size;i++){
		if(mindiv[i]==0){mindiv[i]=i;miu[i]=-1;g[i]=1;pris.push_back(i);}
		for(int j=0,k;j<pris.size()&&(k=pris[j]*i)<=size;j++){
			mindiv[k]=pris[j];
			if(pris[j]==mindiv[i]){miu[k]=0;g[k]=miu[i];break;}
			miu[k]=-miu[i];
			g[k]=miu[i]-g[i];
		}
	}
	for(int i=1;i<=size;i++)sum[i]=sum[i-1]+g[i];
}
int main(){
	init(MAXN);
	for(scanf("%d",&t);t;t--){
		scanf("%d%d",&n,&m);
		if(n>m)swap(n,m);
		LL ans=0;
		for(int i=1,pos;i<=n;i=pos+1){
			pos=min(n/(n/i),m/(m/i));
			ans+=(LL)(n/i)*(LL)(m/i)*(LL)(sum[pos]-sum[i-1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

