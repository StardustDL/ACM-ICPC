/*
整数帝国问题
分析：快速幂 
*/ 
#include<iostream>
#include<cstdlib>
using namespace std;
typedef long ll;
ll ksm(ll a,ll n,ll mod){
	ll ans=1;
	while(n|0){
		if(n&1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ans;
}
bool isprime(int n,int y){
	if(n==2)return true;
	ll k=0,t=n-1;
	while(t&1){t>>=1;k++;}
	for(int i=1;i<=y;i++){
		ll a=rand()%n;
		while((a==0)||(n%a==0))a=rand()%n;//注意随机数不能是n的因数或为0
		int q=ksm(a,t,n);
		if(q==1)return true;
		for(int j=1;j<=k;j++)
			if((q=(q*q)%n)==-1)return true;
	}
	return false;
}
int main(){
	srand(rand());
	ll t;
	cin>>t;
	if(!isprime(t,3))cout<<"Yes!";
	else cout<<"No!";
	return 0;
}
