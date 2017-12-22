/*
[BeiJing2006]��ץ����
��������С��ת���������˵Ҫ��ƽ��ͼת��żͼ�����Ϻõ�������Ҳ�ܹ��������Լ��Ĵ��뽻��ȥRE
	  ע������������ͼ���ܷ��㹹���żͼ�� 
	  ��żͼ������
	  	ƽ��ͼ�Ķ�żͼ�ܺù��죺��ԭͼ�е�������ͼ�еĵ㣬ԭͼ�У�ÿ���߱ض��ָ��������棬����ͼ�У���Ӧ�ĵ�֮�����һ���ߣ���Ȩ����ԭͼ�бߵı�Ȩ�� 
	    ��ԭͼ�е�һ��ȫ�ֵĸ�Ͷ�Ӧ����ͼ�е�һ������Ҳ����˵�������Ҫ��ԭͼ�е�һ��ȫ����С�ֻ��Ҫ����ͼ����һ����С������
		��ô���ԭͼ�зָ�̶��� s �� t��s �� t ����һ�����ߴ��ƽ��ı�Ե�� ��һ����С���أ�
		��������ԭͼ����� s �� t �ıߣ���ԭͼ������һ����
		��������ԭͼ�Ķ�żͼ�����������߶����ӵ������Ӧ�ĵ���Ϊ S��������ƽ���Ӧ�ĵ���Ϊ T
		����ɾ����żͼ�� S �� T ֱ�������ıߣ���� S �� T �����·�Ϳ����� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000*1000;
struct edge{
	int u,v,w,c,f;
	edge(int u,int v,int w,int c,int f):u(u),v(v),w(w),c(c),f(f){} 
};
vector<edge> es;
vector<int> g[MAXN+3];
int d[MAXN+3],cur[MAXN+3],S,T;
queue<int> q;
bitset<MAXN+3> vis;
void addedge(int u,int v,int w,int c){
	es.push_back(edge(u,v,w,c,0));
	es.push_back(edge(v,u,-w,0,0));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
bool bfs(){
	vis=0;
	while(!q.empty())q.pop();
	memset(d,-1,sizeof(d));
	q.push(S);vis[S]=1;d[S]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(vis[e.v]||e.c-e.f<=0)continue;
			vis[e.v]=1;
			d[e.v]=d[u]+1;
			q.push(e.v);
		}
	}
	return vis[T];
}
int dfs(int u,int a){
	if(u==T||a==0)return a;
	int rel=0,f;
	for(int &i=cur[u];i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(d[e.v]==d[u]+1 && (f=dfs(e.v,min(a,e.c-e.f)))>0){
			e.f+=f;
			es[g[u][i]^1].f-=f;
			rel+=f;
			a-=f;
			if(!a)break;
		}
	}
	return rel;
}
int maxflow(int s,int t){
	S=s;T=t;
	int ans=0;
	while(bfs()){
		memset(cur,0,sizeof(cur));
		ans+=dfs(s,INF);
	}
	return ans;
}
int n,m;
inline int id(int x,int y){
	return (x-1)*m+y;
}
int main(){
	scanf("%d%d",&n,&m);int k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			scanf("%d",&k);
			addedge(id(i,j),id(i,j+1),0,k);
			addedge(id(i,j+1),id(i,j),0,k);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&k);
			addedge(id(i,j),id(i+1,j),0,k);
			addedge(id(i+1,j),id(i,j),0,k);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			scanf("%d",&k);
			addedge(id(i,j),id(i+1,j+1),0,k);
			addedge(id(i+1,j+1),id(i,j),0,k);
		}
	}
	printf("%d\n",maxflow(id(1,1),id(n,m)));
	return 0;
}
/*���������� 
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#define MAXN 1000005
#define MAXM 6000005
#define oo 2000000000
#define ll long long
using namespace std;
struct Dinic
{
      struct node 
      {
            int x,y,c,next;
      }line[MAXM];   
      int Lnum,_next[MAXN],dis[MAXN];
      void initial(int n) 
      {
             for (int i=0;i<=n;i++) _next[i]=-1;
             Lnum=-1;
      } 
      void addline(int x,int y,int c)
      {
             line[++Lnum].next=_next[x],_next[x]=Lnum;
             line[Lnum].x=x,line[Lnum].y=y,line[Lnum].c=c;
             line[++Lnum].next=_next[y],_next[y]=Lnum;
             line[Lnum].x=y,line[Lnum].y=x,line[Lnum].c=c;             
      }
      bool BFS(int s,int e)
      { 
             queue<int> Q;
             while (!Q.empty()) Q.pop();
             memset(dis,0,sizeof(dis));
             dis[s]=1;
             Q.push(s);
             while (!Q.empty())
             {
                   int h,k;
                   h=Q.front(),Q.pop();
                   if (h==e) return dis[e];
                   for (k=_next[h];k!=-1;k=line[k].next)
                      if (line[k].c && !dis[line[k].y])
                         dis[line[k].y]=dis[h]+1,Q.push(line[k].y);                 
             } 
             return false;
      }
      int dfs(int x,int flow,int e)  
      {     
             if (x==e) return flow;   
             int temp,cost=0;  
             for (int k=_next[x];k!=-1;k=line[k].next)  
             if (line[k].c && dis[line[k].y]==dis[x]+1)  
             {  
                    temp=dfs(line[k].y,min(flow-cost,line[k].c),e);   
                    if (temp)  
                    {  
                           line[k].c-=temp,line[k^1].c+=temp;  
                           cost+=temp;  
                           if (flow==cost) return cost;  
                    }else dis[line[k].y]=-1;  
             }  
             return cost;
      }  
      int MaxFlow(int s,int e)
      {
             int MaxFlow=0;
             while (BFS(s,e)) 
                MaxFlow+=dfs(s,oo,e); 
             return MaxFlow;
      }
}T;
int main()  
{         
       int n,m,i,j,c;   
       freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
       while (~scanf("%d%d",&n,&m))  
       {  
               T.initial(n*m-1);
               for (i=0;i<n;i++)
                  for (j=0;j<m-1;j++)
                  {
                          scanf("%d",&c);
                          T.addline(i*m+j,i*m+j+1,c);
                  }
               for (i=0;i<n-1;i++)
                  for (j=0;j<m;j++)
                  {
                          scanf("%d",&c);
                          T.addline(i*m+j,(i+1)*m+j,c);
                  }
               for (i=0;i<n-1;i++)
                  for (j=0;j<m-1;j++)
                  {
                          scanf("%d",&c);
                          T.addline(i*m+j,(i+1)*m+j+1,c);
                  }
               printf("%d\n",T.MaxFlow(0,n*m-1));
       }  
       return 0;  
}  
*/
/*��żͼ���·����
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<functional>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN (999*999*2+2+10)
#define MAXM (MAXN*3)
#define For(i,n) for(int i=1;i<=n;i++)
int n,m,N,M,s,t,pre[MAXN]={0},edge[MAXM],next[MAXM],weight[MAXM],size=0;
int no(int i,int j,int k){return (i-1)*2*M+j*2-(k^1);}
void addedge(int u,int v,int w){
	edge[++size]=v;
	weight[size]=w;
	next[size]=pre[u];
	pre[u]=size;
}
void addedge2(int u,int v){int w;scanf("%d",&w);addedge(u,v,w),addedge(v,u,w);}
int q[MAXN*9],d[MAXN];
void SPFA(){
	memset(d,127,sizeof(d));d[s]=0;
	int head=1,tail=1;
	q[1]=s;
	while (head<=tail){
		int now=q[head];
		for (int p=pre[now];p;p=next[p]){
			int &v=edge[p];
			if (d[now]+weight[p]<d[v]){
				d[v]=d[now]+weight[p];
				q[++tail]=v;
			}
		}
		head++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	N=n-1,M=m-1;
	s=N*M*2+1;t=s+1;
	For(i,n) For(j,m-1) {
		if (i==1) addedge2(s,2*j);
		else if (i==n) addedge2(no(i-1,j,0),t);
		else addedge2(no(i,j,1),no(i-1,j,0));
	}
	For(i,n-1) For(j,m) {
		if (j==1) addedge2(t,2*M*(i-1)+1);
		else if (j==m) addedge2(2*M*i,s);
		else addedge2(no(i,j-1,1),no(i,j,0));
	}
	For(i,n-1) For(j,m-1) addedge2(no(i,j,0),no(i,j,1));
	SPFA();
	cout<<d[t]<<endl;
	return 0;
} 
*/ 

