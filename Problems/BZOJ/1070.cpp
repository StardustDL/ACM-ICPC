/*
[SCOI2007]�޳�
��������ÿ�����˲��N���㡣��ΪA[i,j]��ʾ��i�������޵�����j������
		ÿ����������N*M�����˲���ĵ����ߡ�����Ϊ1������Ϊtime[i,j]*(m-k+1)����time[i][j]*kҲ���ԣ���Ϊ�����ѭ��ʱ������� �� 
		Դ��ÿ�������ߣ�N*M����ͻ����ߣ�������Ϊ1������ͬΪ0��
		Ϊʲô��ô��ͼ�أ�
		���ǵ�i�����ˣ����޵�j����ֻ�Ժ���Ҫ�޵ĳ���Ӱ�죬��ǰ���޹��ĳ��Ѿ��Ե�ǰû��Ӱ���ˡ�
			�����Ӱ����Ǻ���ÿ����Ҫ����ĳ�����ȴ���time��ʱ�䡣����Ҫ�޵ľ���m-k+1���� 
			������������Ϊ1����Ȼ�ģ�ÿ������һ�Σ�ÿ������һ��ʱ��ֻ������һ������
		��㣬ʹ�ÿ���ʵ���޶�������
		���Ǹ��������ṩ����Щ������ͬʱ����������������ô��������Զ�ѡ�������������ŵġ� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector> 
#include<cstring>
using namespace std;
const int MAXN=60,MAXM=9,INF=0x3f3f3f3f;
struct edge{
	int u,v,w,c,f;
	edge(int u,int v,int w,int c):u(u),v(v),w(w),c(c),f(0){}
};
vector<int> g[MAXN*MAXM+100+3];
vector<edge> es;
int d[MAXN*MAXM+100+3],p[MAXN*MAXM+100+3];
queue<int> q;
bool inq[MAXN*MAXM+100+3];
void addedge(int u,int v,int w,int c){
	es.push_back(edge(u,v,w,c));
	g[u].push_back(es.size()-1);
	es.push_back(edge(v,u,-w,0));
	g[v].push_back(es.size()-1);
}
bool spfa(int s,int t){
	memset(d,INF,sizeof(d));
	memset(p,-1,sizeof(p));
	memset(inq,0,sizeof(inq));
	while(!q.empty())q.pop();
	d[s]=0;q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(e.c-e.f>0 && d[e.v]>d[e.u]+e.w){
				d[e.v]=d[e.u]+e.w;
				p[e.v]=g[u][i];
				if(!inq[e.v]){q.push(e.v);inq[e.v]=1;}
			}
		}
	}
	return d[t]<INF;
}
int ans=0,n,m;
void augment(int s,int t){
	int mn=INF;
	for(int i=p[t];i!=-1;i=p[es[i].u])mn=min(mn,es[i].c-es[i].f);
	for(int i=p[t];i!=-1;i=p[es[i].u])es[i].f+=mn,es[i^1].f-=mn,ans+=mn*es[i].w;
}
int tme[MAXN+3][MAXM+3];
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&tme[i][j]);
	int S=n*m+n+2,T=S+1;
	for(int i=1;i<=n*m;i++)addedge(S,i,0,1);
	for(int i=n*m+1;i<=n*m+n;i++)addedge(i,T,0,1);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				addedge((i-1)*n+j,n*m+k,tme[k][i]*(n-j+1),1);
	while(spfa(S,T))augment(S,T);
	printf("%.2lf\n",ans*1.0/n);
	return 0;
}

