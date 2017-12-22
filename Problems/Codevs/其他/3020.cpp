/*
÷Ì∞ÀΩ‰≥‘Ã“
*/
#include<iostream>
using namespace std;
typedef unsigned long long ll;
ll n,m,t;
int main(){	
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>t;
		if(n<=t){
			cout<<"-"<<i;
			return 0;
		}
		else n=n*2-t*2;
	}
	cout<<n;
	return 0;
}
