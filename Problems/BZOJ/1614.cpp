/*
[Usaco2007 Jan]Telephone Lines����绰��
���������ִ𰸣����ж��Ƿ����ʱ��ֻ��Ҫ�ж��Ƿ���Ѱ�ҵ�һ��·����ʹ�ø�·���ϴ������Ƕ��ֵ����ֵ�ı߲�����k����
	  ʵ���Ͼ������·����һ�����ζ��ѣ�С�ڶ��ֵ�ֵ�ı߿��Կ�����ȨΪ0�����ڵĿ��Կ�����ȨΪ1��ֱ�������·���Ƿ�С��k���� 
*/
#include<iostream>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){} 
};
vector<edge> es;
vector<int> g[MAXN+3];
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	g[u].push_back(es.size()-1);
}
int n,p,k,cnt,ans=-1;
int d[MAXN+3];
bool inq[MAXN+3];
queue<int> q;
bool spfa(int x){
	memset(d,INF,sizeof(d));
    while(!q.empty())q.pop();
    memset(inq,0,sizeof(inq));
    q.push(1);inq[1]=1;d[1]=0;
    while(!q.empty()){
    	int u=q.front();q.pop();inq[u]=0;
     	for(int i=0;i<g[u].size();i++){
     		edge &e=es[g[u][i]];
     		if(d[e.v]>d[e.u]+(e.w>x)){d[e.v]=d[e.u]+(e.w>x);if(!inq[e.v]){inq[e.v]=1;q.push(e.v);}}
		}
	}
    return d[n]<=k;
 }
int main(){
    scanf("%d%d%d",&n,&p,&k);
    for(int i=1,u,v,w;i<=p;i++){
		scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);addedge(v,u,w);
    }
    int l=0,r=INF;
    while(l<=r){
		int mid=(l+r)>>1;
        if(spfa(mid)){ans=mid;r=mid-1;}
        else l=mid+1;
	} 
    printf("%d",ans);
    return 0;
}
