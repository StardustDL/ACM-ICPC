/*
�ϵ��뼯�ϵ���ȷ�÷�
��������p=2^k*q����ans=2^k(2^(...-k) mod q)
	  ŷ�������ans=2^k(2^((...-k)mod phi(q) ) mod q)
	  ÿ��ģ������ż��������qÿ�γ���2��������logpʱ����q=1�����ƻ�ȥ�ý� 
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
	if(x!=1)ans=ans/x*(x-1);//������µ�һ��>sqrt(x)������ 
	return ans;
}
int qpow(long long a,int n,int mod){
	long long ans=1%mod;//ע��mod������Ϊ1��������Ϊ2ʱ�ͻ� 
	for(;n;a=a*a%mod,n>>=1)if(n&1)ans=ans*a%mod;
	return ans;
}
int solve(int p){
	//cout<<p<<endl;
	if(p==1)return 0;
	int cnt=0;while((p&1)==0)p>>=1,cnt++;
	int ph=phi(p),t=solve(ph);//solve(phi(p'))
	t=(t-cnt%ph+ph)%ph;//�µ�ָ�� 2^t mod p'��ע��cnt%ph����Ȼ���������������Ŀ����ݾͻ���ѭ�� 
	return (qpow(2,t,p))<<cnt;//ans=(2^t mod p')*2^cnt
}
int main(){
	int T,p;
	for(scanf("%d",&T);T;T--){
		scanf("%d",&p);printf("%d\n",solve(p));
	}
	return 0;
}

