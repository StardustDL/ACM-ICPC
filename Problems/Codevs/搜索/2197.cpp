/*
·ÖÌÇ¹û
·ÖÎö£ºBFS 
*/
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN=100000;
struct node{
	int u,t;
};
int n,c,m,tme=0;
vector<int> g[MAXN+3];
queue<node> q;
bitset<MAXN+3> vis=0;
void input(){
	int p,a,b;
	cin>>n>>p>>c>>m;
	while(p-->0){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}
int bfs(){
	q.push((node){c,1});
	vis=0;
	vis[c]=1;
	while(!q.empty()){
		node t=q.front();q.pop();
		tme=max(tme,t.t+m);
		for(int i=0;i<g[t.u].size();i++){
			int v=g[t.u][i];
			if(!vis[v]){
				q.push((node){v,t.t+1});
				vis[v]=1;
			}
		}
	}
	return tme;
}
int main(){
	input();
	cout<<bfs();
	return 0;
}
