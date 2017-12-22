/*
≤…“©
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=101,MAXT=1003;
int t,m,v,w,opt[MAXT];
int main(){
	cin>>t>>m;
	while(m-->0){
		cin>>v>>w;
		for(int j=t;j>=v;j--)
			opt[j]=max(opt[j],opt[j-v]+w);
	}
	cout<<opt[t];
	return 0;
}

