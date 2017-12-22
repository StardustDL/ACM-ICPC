/*
微子危机——战略
分析：一定要用scanf，并且是无向图 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
};
vector<edge> es;
vector<int> g[MAXN+3];
int mp[MAXN+3][MAXN+3]; 
int dis[MAXN+3],s,t,n,m;
bitset<MAXN+3> inq;
queue<int> q;
void add(int u,int v,int w){
	es.push_back((edge){u,v,w});
	g[u].push_back(es.size()-1);
}
void spfa(int from){
	inq=0;inq[from]=1;while(!q.empty())q.pop();q.push(from);
	memset(dis,INF,sizeof(dis));dis[from]=0;
	while(!q.empty()){
		int t=q.front();q.pop();inq[t]=0;
		for(int i=0;i<g[t].size();i++){
			edge &e=es[g[t][i]];
			if(dis[e.v]>dis[t]+e.w){
				dis[e.v]=dis[t]+e.w;
				if(!inq[e.v]){
					inq[e.v]=1;q.push(e.v);
				}
			}
		}
	}
}
void input(){
	int l,a,b,c;
	scanf("%d %d %d",&n,&m,&l);
	memset(mp,INF,sizeof(mp));
	for(int i=1;i<=n;i++)mp[i][i]=0;
	while(l-->0){
		scanf("%d %d %d",&a,&b,&c);
		mp[a][b]=min(mp[a][b],c);
		mp[b][a]=mp[a][b];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//cout<<mp[i][j]<<" ";
			if(i!=j&&mp[i][j]!=INF){
				add(i,j,mp[i][j]);
			}
		}
		//cout<<endl;
	}
}
int solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		//cout<<dis[i]<<" ";
		if(dis[i]==INF)return -1;
		ans+=dis[i];
	}
	/*for(int i=1;i<=n;i++){
		cout<<mp[i][m]<<" ";
		if(mp[i][m]==INF)return -1;
		ans+=mp[i][m];
	}*/
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	input();
	spfa(m);
	int ans=solve();
	if(ans==-1)cout<<"Sth wrong.";
	else cout<<ans<<" M(s) are needed.";
	return 0;
}
