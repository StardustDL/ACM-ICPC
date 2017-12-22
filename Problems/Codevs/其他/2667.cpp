/*
’“¥Œ¥Û÷µ
*/
#include<iostream>
using namespace std;
int main(){
	int n,t,mx=-(1<<20),ans=mx;
	cin>>n;
	while(n-->0){
		cin>>t;
		if(t>mx){
			ans=mx;mx=t;
		}
		else if(t>ans)ans=t;
	}
	cout<<ans;
}
