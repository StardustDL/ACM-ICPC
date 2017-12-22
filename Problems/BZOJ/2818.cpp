/*
Gcd
·ÖÎö£ºbzoj2820µÄÈõ»¯°æ 
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
	scanf("%d",&n);
	LL ans=0;
	for(int i=1,pos;i<=n;i=pos+1){
		pos=n/(n/i);
		ans+=(LL)(n/i)*(LL)(n/i)*(LL)(sum[pos]-sum[i-1]);
	}
	printf("%lld\n",ans);
	return 0;
}
