/*
3n+1Œ Ã‚
*/ 
#include<iostream>
using namespace std;
int ans=0,n,t;
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t-->0){
		cin>>n;
		ans=0;
		while(n!=1){
			ans++;
			if(n&1)n=3*n+1;
			else n>>=1;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
