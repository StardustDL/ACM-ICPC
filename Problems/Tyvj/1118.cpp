#include<iostream>
using namespace std;
int ksm(int a,int n,int mod){
	int ans=1;
	while(n>0){
		if(n&1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		n/=2;
	}
	return ans;
}
int main(){
	int a,n;
	cin>>a>>n;
	cout<<ksm(a,n,1012);
	return 0;
}

