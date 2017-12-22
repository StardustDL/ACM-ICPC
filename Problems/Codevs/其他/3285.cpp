/*
×ªÈ¦ÓÎÏ·
·ÖÎö£ºans=(x+m*(10^k))%n 
*/
#include<iostream>
using namespace std;
typedef long L;
L ksm(L a,L n,L mod){
	L ans=1;
	while(n>0){
		if(n&1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ans;
}
L n,m,k,x;
int main(){
	cin>>n>>m>>k>>x;
	cout<<(x+m*ksm(10,k,n))%n;
	return 0;
}
