/*
CYDÀ¢Ã‚
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXK=500;
int n,a,b,c,m,q,opt[MAXK+3];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	while(n-->0){
		cin>>a>>b>>c;
		if(c>q)continue;
		for(int i=m;i>=b;i--)
			opt[i]=max(opt[i],opt[i-b]+a);
	}
	cout<<opt[m];
	return 0;
}
