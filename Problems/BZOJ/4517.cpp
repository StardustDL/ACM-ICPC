/*
[Sdoi2016]排列计数
分析：ans=C(n,m)*F[n-m]
		F[i] i个数的全错位排列
		F[i]=(i-1)*(F[i-1]+F[i-2]) 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
typedef long long LL;
const LL MOD=1000000007;
LL fac[MAXN+3],inv[MAXN+3];
LL qpow(LL a,LL n){
	LL ans=1;
	while(n){
		if(n&1)ans=ans*a%MOD;
		a=a*a%MOD;
		n>>=1;
	}
	return ans;
}
LL f[MAXN+3];
void pre(){
	fac[0]=1;inv[0]=1;
	for(int i=1;i<=MAXN;i++)fac[i]=(fac[i-1]*i)%MOD;
	inv[MAXN]=qpow(fac[MAXN],MOD-2);
	for(int i=MAXN-1;i>=1;i--)inv[i]=(inv[i+1]*(i+1))%MOD;
	f[1]=0;f[2]=1;f[0]=1;
	for(int i=3;i<=MAXN;i++)f[i]=(i-1)*((f[i-1]+f[i-2])%MOD)%MOD;
}
LL C(int n,int m){
	return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main(){
	int T,n,m;
	pre();
	for(scanf("%d",&T);T;T--){
		scanf("%d%d",&n,&m);
		printf("%lld\n",C(n,m)*f[n-m]%MOD);
	}
	return 0;
}

