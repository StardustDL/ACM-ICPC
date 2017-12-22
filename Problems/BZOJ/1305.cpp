/*
[CQOI2009]dance����
���������ִ�+�������жϿ���
		�Ȱ�ÿ����i��ֳ�ix��iy�����ڵ㣬
		ix����ϲ�����ˣ�iy����ϲ�����ˣ�����Ϊ1�������������i��Ů��j����ϲ��������ix����jx���������i��Ů��j���಻ϲ��������iy����jy����
		�ٽ�ÿ����������ix����iy������Ϊk��ÿ��Ů��iy����ix������Ϊk��
		��Դ����ÿ��������x�ڵ�����һ���ߣ�����ÿ��Ů����x�ڵ���������һ���ߣ�������Ϊa��
		����С����ö��a�����������flow��������a*n>flow(������)����ֹͣö�٣�a-1��Ϊ�𰸡�
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
struct edge{
	int v,nxt,c;
}es[205*205*4];
int tot=1,head[310],d[310],S,T;
int q[405];
void _addedge(int u,int v,int c){
	tot++;
	es[tot].v=v;es[tot].c=c;es[tot].nxt=head[u];head[u]=tot;
}
void addedge(int u,int v,int c){
	_addedge(u,v,c);
	_addedge(v,u,0);
}
bool bfs(){
	memset(d,-1,sizeof(d));d[S]=0;int h=0,t=1;q[h]=S;
	while(h<t){
		int u=q[h++];
		for(int i=head[u];i;i=es[i].nxt){
			if(es[i].c && d[es[i].v]==-1)
				d[q[t++]=es[i].v]=d[u]+1;
		}
	}
	return d[T]!=-1;
}
int dfs(int u,int a){
	if(u==T||a==0)return a;
	int flow=0;
	for(int i=head[u];i;i=es[i].nxt){
		edge &e=es[i];if(d[e.v]!=d[u]+1)continue;
		int w=dfs(e.v,min(e.c,a));
		if(!w)continue;
		flow+=w;a-=w;
		e.c-=w;es[i^1].c+=w;
		if(a==0)break;
	}
	if(flow==0)d[u]=-1;
	return flow;
}
int maxflow(){
	int ans=0;
	while(bfs())ans+=dfs(S,INF);
	return ans;
}
int n,k;
bool mp[55][55];
void build(int x){
	tot=1;memset(head,0,sizeof(head));
    S=0;T=(n<<2)+5;
    for(int i=1;i<=n;i++)addedge(0,i,x);
    for(int i=1;i<=n;i++)addedge(i,i+(n<<1),k);
    for(int i=1;i<=n;i++)addedge(n+i+(n<<1),n+i,k);
    for(int i=1;i<=n;i++)addedge(n+i,T,x);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
          if(mp[i][j])addedge(i,n+j,1);
          else addedge(i+(n<<1),n+j+(n<<1),1);
}
char ch[51];
int main(){
	scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
       scanf("%s",ch);
       for(int j=1;j<=n;j++)mp[i][j]=ch[j-1]=='Y';
    }
    int l=0,r=50,ans=l;
    while(l<=r){
        int mid=(l+r)>>1;
        build(mid);
        if(maxflow()>=n*mid){ans=mid;l=mid+1;}
        else r=mid-1;
    }
    printf("%d\n",ans);
	return 0;
}

