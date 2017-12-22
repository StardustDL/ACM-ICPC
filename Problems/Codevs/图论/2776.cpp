/*
寻找代表元
分析：简单二分图匹配 
*/ 
#include<iostream>
#include<vector>
#include<bitset>
#include<cstring>
using namespace std;
const int MAXN=200;
int n,m,match[MAXN+3];
vector<int> g[MAXN+3];
bitset<MAXN+3> vis;
inline void add(int u,int v){g[u].push_back(v);}
bool dfs(int u){
	for(int i=0;i<g[u].size();i++){
		int t=g[u][i];
		if(!vis[t]){
			vis[t]=1;
			if(match[t]==-1||dfs(match[t])){
				match[t]=u;
				return true;
			}
		}
	}
	return false;
}
int Max(){
	int ans=0;memset(match,-1,sizeof(match));
	for(int i=1;i<=n;i++){
		vis=0;
		if(dfs(i))ans++;
	}
	return ans;
}
int main(){
	cin>>n>>m;
	int t;
	for(int i=1;i<=n;i++){
		cin>>t;
		while(t!=0){add(i,t);cin>>t;}
	}
	cout<<Max();
	return 0;
}
