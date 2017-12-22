/*
[ZJOI2009]�Ǻ���Ĺ���
�������ھ�դ���ı��ʣ�ֻ�ܽ��������������ҽ��ú�ʹ���Ǻ���֮�䲻����ͨ·������Ķ����ǣ�ʹS����T��������ͨ·������Ŀ��Ҫ�󽨵�դ�����٣����Ǿ�����С�������ˡ�
		��Դ������������һ���޵ıߣ���������������һ���޵ıߣ��������ܱ�֤�Ǻ����ڲ�ͬ�ĵ㼯�Ȼ���ٴ��ǵ����ڵ���Ϳյأ��յص����ڵĿյغ�����һ������Ϊ1�ıߣ����������С��ɡ� 
	  ��vector������ը= = 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=200,INF=0x3f3f3f3f;
int n,m,a[MAXN+3][MAXN+3];
int head[10005],q[10005],h[10005],cnt=1;
struct edge{
	int v,c,nxt;
}e[500001];
void ins(int u,int v,int w)
{e[++cnt].v=v;e[cnt].nxt=head[u];e[cnt].c=w;head[u]=cnt;}
void insert(int u,int v,int w)
{ins(u,v,w);ins(v,u,0);}
int S,T,d[100*100+3];
bool bfs(){
	memset(d,-1,sizeof(d));
	int t=0,w=1;
	d[S]=0;
	q[0]=S;
	while(t<w){
		int u=q[t];t++;
		for(int i=head[u];i;i=e[i].nxt){
			if(e[i].c&&d[e[i].v]==-1){
				d[e[i].v]=d[u]+1;
				q[w++]=e[i].v;
			}
		}
	}
	return d[T]!=-1;
}
int dfs(int u,int a){
	if(u==T||a==0)return a;
	int flow=0,f;
	for(int i=head[u];i;i=e[i].nxt){
		if(e[i].c&&d[e[i].v]==d[u]+1){
			int w=a-flow;
			w=dfs(e[i].v,min(w,e[i].c));
			flow+=w;
			e[i].c-=w;
			e[i^1].c+=w;
			a-=f;
			if(a==0)break;
		}
	}
	if(flow==0)d[u]=-1;
	return flow;
}
int Maxflow(){
	int ans=0;
	while(bfs()){
		ans+=dfs(S,INF);
	}
	return ans;
}
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
int main(){
	scanf("%d%d",&n,&m);S=n*m+1,T=S+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(a[i][j]==1)insert(S,(i-1)*m+j,INF);
        else if(a[i][j]==2)insert((i-1)*m+j,T,INF);
    	for(int k=0;k<4;k++)
    	{
            int nowx=i+xx[k],nowy=j+yy[k];
            if(nowx<1||nowx>n||nowy<1||nowy>m||a[i][j]==2)continue;
            if(a[i][j]!=1||a[nowx][nowy]!=1)
            	insert((i-1)*m+j,(nowx-1)*m+nowy,1);
        }
    }
	printf("%d\n",Maxflow());
	return 0;
}
