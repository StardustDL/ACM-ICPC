/*
о╦╟Ш╥жая 2
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
int main(){
	L a,q;
	cin>>a>>q;
	cout<<ksm(2,a,q);
	return 0;
}
