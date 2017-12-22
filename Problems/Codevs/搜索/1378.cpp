/*
选课
分析：建立虚拟根节点，每次枚举最优解 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=300;
struct edge{
	int u,v;
};
vector<edge> es;
vector<int> g[MAXN+3];
int opt[MAXN+3][MAXN+3],a[MAXN+3],n,m;
void add(int u,int v){es.push_back((edge){u,v});g[u].push_back(es.size()-1);}
void input(){
	cin>>n>>m;
	int t;
	for(int i=1;i<=n;i++){
		cin>>t>>a[i];
		add(t,i);
	}
}
/*int dfs(int u,int c){
	if(opt[u][c])return opt[u][c];
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		for(int j=0;j<=c;j++){
			opt[u][c]=max(opt[u][c],opt[u][c-j]+dfs(e.v,j));
		}
	}
	//for(int i=c;i>=1;i--)opt[u][i]=opt[u][i-1]+a[u];
	opt[u][c]=opt[u][c-1]+a[u];
	return opt[u][c];
}*/
void dfs(int u){
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		dfs(e.v);
		for(int j=m;j>=0;j--){
			for(int k=0;k<=j;k++){
				opt[u][j]=max(opt[u][j],opt[u][k]+opt[e.v][j-k]);
			}
		}
	}
	if(u==0)return;
	for(int i=m;i>=1;i--){
		opt[u][i]=opt[u][i-1]+a[u];
	}
}
int main(){
	input();
	//for(int i=0;i<=m;i++)dfs(0,i);
	dfs(0);
	cout<<opt[0][m];
	return 0;
}
 
