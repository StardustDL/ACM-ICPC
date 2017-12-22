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
	int a,t,n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>t;
		cout<<ksm(a,t,1012)<<endl;
	}
	return 0;
}

