/*
棋盘覆盖
分析：先想的二分图染色，但是不对
	  正解是二分图匹配，相邻的点连边，求最大匹配 
	  二分图的实现：
	  	1.分成二部图，match只记录左边点所匹配的右边点，然后对所有左边点dfs 
		2.不分二部图，match记录所有点的匹配点，注意改变路的时候只改变一方 
	  本题另一种二分图方法：先黑白染色，黑点向相邻白点连边，然后遍历黑点，dfs 
*/ 
#include<iostream>
#include<vector>
#include<bitset>
#include<cstring>
using namespace std;
const int MAXN=100;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int mp[MAXN+3][MAXN+3],n,match[MAXN*MAXN+3];
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
	return (x-1)*n+y;
}
bool dfs(int u){
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(!inq[e.v]){
			inq[e.v]=1;
			if(match[e.v]==0||dfs(match[e.v])){
				match[e.v]=u;
				//不要加match[u]=e.v; 
				return true;
			}
		}
	}
	return false;
}
int Max(){
	int ans=0;
	memset(match,0,sizeof(match));
	for(int i=1;i<=n*n;i++){
		inq=0;
		if(dfs(i))ans++;
	}
	return ans;
}
int main(){
	int m,a,b;
	cin>>n>>m;
	memset(mp,0,sizeof(mp));
	while(m-->0){
		cin>>a>>b;
		mp[a][b]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]==1)continue;
			int s=id(i,j);
			for(int k=0;k<4;k++){
				int x=i+dx[k],y=j+dy[k];
				if(x<1||y<1||x>n||y>n||mp[x][y]==1)continue;
				add(s,id(x,y));
			}
		}
	}
	cout<<Max()/2;
	return 0;
}
/*二分图染色，居然过了8个点 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100;
int mp[MAXN+3][MAXN+3],n;
void dfs(int x,int y,int color){
	if(x<1||y<1||x>n||y>n||mp[x][y]!=-1)return;
	mp[x][y]=color;
	dfs(x+1,y,!color);
	dfs(x,y+1,!color);
	dfs(x-1,y,!color);
	dfs(x,y-1,!color);
}
int solve(){
	int b=0,w=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(mp[i][j]==1)w++;else if(mp[i][j]==0)b++;
	cout<<b<< " "<<w<<endl;
	return min(b,w);
}
int main(){
	int m,a,b;
	cin>>n>>m;
	memset(mp,-1,sizeof(mp));
	while(m-->0){
		cin>>a>>b;
		mp[a][b]=-2;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)dfs(i,j,1); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]==-2)cout<<'*';
			else cout<<mp[i][j];
		}
		cout<<endl;
	}
	cout<<solve();
	return 0;
}*/
