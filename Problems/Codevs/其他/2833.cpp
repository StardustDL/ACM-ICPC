/*
Ææ¹ÖµÄÃÎ¾³
·ÖÎö£ºÍØÆËÅÅĞò 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=10000,MAXM=MAXN*2.5;
struct edge{
	int u,v;
};
vector<edge> es;
vector<int> g[MAXN+3];
queue<int> vs;
int n,m,rd[MAXN+3];
void input(){
	memset(rd,0,sizeof(rd));
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		es.push_back((edge){u,v});
		g[u].push_back(es.size()-1);
		rd[v]++;
	}
}
int toposort(){
	int ans=n;
	for(int i=1;i<=n;i++)
		if(!rd[i])vs.push(i);
	while(!vs.empty()){
		int t=vs.front();vs.pop();ans--;
		for(int i=0;i<g[t].size();i++){
			if(--rd[es[g[t][i]].v]==0){
				vs.push(es[g[t][i]].v);
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	input();
	n=toposort();
	if(!n)cout<<"o(¡É_¡É)o"<<endl;
	else cout<<"T_T"<<endl<<n;
	return 0;
}
