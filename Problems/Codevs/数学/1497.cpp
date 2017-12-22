/*
取余运算
题意：快速幂，注意用long long 
*/
#include<iostream>
using namespace std;
long long b,p,k;
long long ksm(long long a,long long n,long long mod){
	long long ans=1;
	while(n>0){
		if(n&1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ans;
}
int main(){
	cin>>b>>p>>k;
	cout<<b<<"^"<<p<<" mod "<<k<<"="<<ksm(b,p,k);
	return 0;
}
