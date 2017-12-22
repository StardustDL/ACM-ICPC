/*
序列统计
分析：只要选出了一些属于[l..r]的数，他们一定可以排列成一个单调不降的，所以Ans=sigma{C(r-l+1,i)|1<=i<=n}
		Ans=sigma{C(r-l+1,i)|1<=i<=n}
			sigma{C(r-l+1,i)|0<=i<=n}-1
			C(r-l+1+n,n)-1
		用lucas定理C(n,m)%p=C(n/p,m/p)*C(n%p,m%p)求解即可		
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f,MOD=1000003;
typedef long long LL;
LL fac[MOD+3],inv[MOD+3];
LL qpow(LL a,LL n){
	LL ans=1;
	while(n){
		if(n&1)ans=ans*a%MOD;
		n>>=1;
		a=a*a%MOD;
	}
	return ans;
}
void init(){
	fac[0]=1;inv[0]=1;
	for(int i=1;i<MOD;i++)fac[i]=fac[i-1]*i%MOD;
	inv[MOD-1]=qpow(fac[MOD-1],MOD-2);
	for(int j=MOD-2;j>=1;j--)inv[j]=inv[j+1]*(j+1)%MOD;
}
LL C(int n,int m){
	if(m>n)return 0;
	if(n<MOD&&m<MOD)return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
	return C(n/MOD,m/MOD)*C(n%MOD,m%MOD)%MOD;
}
int main(){
	init();int t;scanf("%d",&t);
	for(int l,r,n;t;t--){
		scanf("%d%d%d",&n,&l,&r);
		printf("%lld\n",(C(r-l+1+n,n)+MOD-1)%MOD);
	}
	return 0;
}

