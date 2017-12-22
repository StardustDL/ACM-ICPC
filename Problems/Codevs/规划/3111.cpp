/*
CYD¿Ð¹ÇÍ·
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXK=1000;
int n,a,b,m,opt[MAXK+3];
int main(){
	ios::sync_with_stdio(false);
	cin>>m>>n;
	while(n-->0){
		cin>>a>>b;
		for(int i=m;i>=a;i--)
			opt[i]=max(opt[i],opt[i-a]+b);
	}
	cout<<opt[m];
	return 0;
}
