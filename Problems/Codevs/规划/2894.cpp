/*
Txxøº ‘
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXK=100000;
int n,t,p,k,opt[MAXK+3],s=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>k>>n;
	while(n-->0){
		cin>>t>>p;s+=p;
		for(int i=k;i>=t;i--){
			opt[i]=max(opt[i],opt[i-t]+p);
		}
	}
	cout<<s-opt[k];
	return 0;
}
