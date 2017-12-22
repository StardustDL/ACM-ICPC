/*
开心的金明
分析：典型背包DP 
*/ 
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=30003,MAXM=27;
int n,m,w[MAXM],v[MAXM],opt[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>v[i]>>w[i];
	for(int i=1;i<=m;i++){
		for(int j=n;j>=v[i];j--)
			opt[j]=max(opt[j],opt[j-v[i]]+w[i]*v[i]);
	cout<<opt[n];
	return 0;
}
