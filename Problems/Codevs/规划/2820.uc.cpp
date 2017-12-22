/*
��صĸ���
������Ŀǰ��˼·�������ģ��������ߣ����޻��Ļ��ͻ�õ�һ��ɭ�֣���ô����DP��
	  �������ȥ���أ����Ȳ������ȥ����a->b,c->b,d->a,b->c��Ӧȥ��b->c�����������㣬��Ϊ���ڲ���һ���������ѡ���������Ҳ�У��ڲ�һ��ѡһ��ĵ㡣 
*/ 
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm> 
#include<bitset>
using namespace std;
const int MAXN=1000000;
struct edge{
	int u,v;
};
vector<edge> es;
vector<int> g[MAXN+3];
bitset<MAXN+3> vis;
int n,opt[MAXN+3][2],rd[MAXN+3];
inline void addedge(int u,int v){
	es.push_back((edge){u,v});
	rd[v]++;
	g[u].push_back(es.size()-1);
}
void input(){
	int a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;if(a==0)continue;
		addedge(a,i);
	}
}
void dfs(int u){
	if(u==0)return;
	vis[u]=1;
	int &A=opt[u][0],&B=opt[u][1];
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		dfs(e.v);
		A=max(opt[e.v][0],opt[e.v][1]);
		B=max(B,opt[e.v][0]);
	}
	B+=1;
	cout<<u<<":"<<A<<" "<<B<<endl;
}
int dp(){
	int ans=0;
	vis=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]&&rd[i]==0){
			cout<<i<<endl;
			dfs(i);
			ans+=max(opt[i][0],opt[i][1]);
			//cout<<ans<<endl;
		}
	}
	return ans;
}
int main(){
	input();
	cout<<dp();
	return 0;
}
