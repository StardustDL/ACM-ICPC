/*
上帝与集合的正确用法
分析：令p=2^k*q，则ans=2^k(2^(...-k) mod q)
	  欧拉定理得ans=2^k(2^((...-k)mod phi(q) ) mod q)
	  每次模数都是偶数，所以q每次除以2，可以在logp时间内q=1，逆推回去得解 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=10000000,INF=0x3f3f3f3f;
/*int T,p,cnt;
int pri[MAXN+3],phi[MAXN+3];
bool mark[MAXN+3];
void getphi(){
	phi[1]=1;
	for(int i=2;i<=MAXN;i++){
		if(!mark[i])phi[i]=i-1,pri[++cnt]=i;
		for(int j=1;j<=cnt&&i*pri[j]<=MAXN;j++){
			mark[i*pri[j]]=1;
			if(i%pri[j]==0){phi[i*pri[j]]=phi[i]*pri[j];break;}
			else phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
}*/
int phi(int x){
	int ans=x;
	for(int i=2;i*i<=x;i++){
		if(x%i)continue;
		ans=ans/i*(i-1);
		while(x%i==0)x/=i;
	}
	if(x!=1)ans=ans/x*(x-1);//最后余下的一个>sqrt(x)的质数 
	return ans;
}
int qpow(long long a,int n,int mod){
	long long ans=1%mod;//注意mod数可能为1，当输入为2时就会 
	for(;n;a=a*a%mod,n>>=1)if(n&1)ans=ans*a%mod;
	return ans;
}
int solve(int p){
	//cout<<p<<endl;
	if(p==1)return 0;
	int cnt=0;while((p&1)==0)p>>=1,cnt++;
	int ph=phi(p),t=solve(ph);//solve(phi(p'))
	t=(t-cnt%ph+ph)%ph;//新的指数 2^t mod p'，注意cnt%ph，不然会减出负数，后面的快速幂就会死循环 
	return (qpow(2,t,p))<<cnt;//ans=(2^t mod p')*2^cnt
}
int main(){
	int T,p;
	for(scanf("%d",&T);T;T--){
		scanf("%d",&p);printf("%d\n",solve(p));
	}
	return 0;
}

