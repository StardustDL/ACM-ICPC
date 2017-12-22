/*
覆盖
分析：和棋盘覆盖基本一样 
*/ 
#include<iostream>
#include<vector>
#include<bitset>
#include<cstring>
using namespace std;
const int MAXN=100;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int mp[MAXN+3][MAXN+3],n,m,match[MAXN*MAXN+3];
struct edge{
	int u,v;
};
vector<int> g[MAXN*MAXN+3];
vector<edge> es;
bitset<MAXN*MAXN+3> inq; 
void add(int u,int v){
	es.push_back((edge){u,v});
	g[u].push_back(es.size()-1);
}
int id(int x,int y){
	return (x-1)*m+y;
}
bool dfs(int u){
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(!inq[e.v]){
			inq[e.v]=1;
			if(match[e.v]==0||dfs(match[e.v])){
				match[e.v]=u;
				return true;
			}
		}
	}
	return false;
}
int Max(){
	int ans=0;
	memset(match,0,sizeof(match));
	for(int i=1;i<=n*m;i++){
		inq=0;
		if(dfs(i))ans++;
	}
	return ans;
}
int main(){
	int q,a,b;
	cin>>n>>m>>q;
	memset(mp,0,sizeof(mp));
	while(q-->0){
		cin>>a>>b;
		mp[a][b]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==1)continue;
			int s=id(i,j);
			for(int k=0;k<4;k++){
				int x=i+dx[k],y=j+dy[k];
				if(x<1||y<1||x>n||y>m||mp[x][y]==1)continue;
				add(s,id(x,y));
			}
		}
	}
	cout<<Max()/2;
	return 0;
}
