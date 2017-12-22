/*
Wormholes
���⣺�涴���⣬������n���㣬m���ߣ��������ڿ����ߵ�ͨ·��˫�򣩣������a��b�ʹ�b��a��Ҫ����cʱ�䣬�����ڵ��ϳ�����w���涴���涴������������a��b���ѵ�ʱ����-c(ʱ�䵹��,���ҳ涴�ǵ����)�����������ĳ���㿪ʼ�ߣ��ܻص���ǰ
����������һ��ͼ��Ȼ�󽫻ص���ǰ���Ϊ�Ƿ����ָ�Ȩ������bellman-ford�Ϳ��Խ���ˣ�������bfs�и����� 
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<vector> 
using namespace std;
const int MAXN=500,INF=0x3f3f3f3f;
const char OUT[2][5]={"NO","YES"};
vector<int> to[MAXN+3];
vector<int> wt[MAXN+3];
bitset<MAXN+3> vis;
int d[MAXN+3]; 
void addedge(int u,int v,int w){
	to[u].push_back(v);
	wt[u].push_back(w);
}
/*bool spfa(int u){
	for(int i=0;i<to[u].size();i++){
		int v=to[u][i],w=wt[u][i];
		if(d[v]>d[u]+w){
			if(vis[v])return false;
			else{
				d[v]=d[u]+w,vis[v]=1;
				if(!spfa(v))return false;
			}
		}
	}
	return true;
}*/ 
int len[MAXN+3];int n,m,w;
queue<int> q;
bool bfs(int s){
	memset(d,INF,sizeof(d));
	memset(len,0,sizeof(len));
	while(!q.empty())q.pop();
	vis=0;vis[s]=1;
	d[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();vis[u]=0;
		for(int i=0;i<to[u].size();i++){
			int v=to[u][i],w=wt[u][i];
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				len[v]=len[u]+1;
				if(len[v]>n)return false;
				if(!vis[v]){
					vis[v]=1;q.push(v);
				}
			}
		}
	}
	return true;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&w);
		for(int i=1;i<=n;i++)to[i].clear(),wt[i].clear();
		for(int i=1,a,b,c;i<=m;i++){
			scanf("%d%d%d",&a,&b,&c);
			addedge(a,b,c);
			addedge(b,a,c);
		}
		for(int i=1,a,b,c;i<=w;i++){
			scanf("%d%d%d",&a,&b,&c);
			addedge(a,b,-c);
		}
		vis=0;vis[1]=1;memset(d,INF,sizeof(d));d[1]=0;
		puts(OUT[!bfs(1)]);
	}
	return 0;
}

