/*
�������
���������ǵ�����ƥ�佨ͼ�������࣬���ǲ��ý��߷���ķ����Ż�������a������ֵ�ܱ�x������b������ֵ�ܱ�y���������е㣬ֻҪ��������һ���ܹ�ƥ�䣬����������ƥ���������ģ���м�����һ�������ĵ㣬����Ҫ������ҵ�ֱ�������������ȨΪ��������ǵ�x��yֻ���������������ĵ㹲������3*46*46����1��200������46��������200<2*3*5*7����������ÿ������������3*3*3���ߡ��������ǹ�����һ��70000���㣬2000000���ߵ�����������Ȼ�Ƿֲ�ͼ������dinic�м��ѵ��ٶ����ƣ�ͨ��100�����ݡ� 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
struct edge{
	int v,nxt,c;
}es[2000005];
struct data{
	int x,y,z;
}a[30005],b[30005];
int head[70005],q[70005],d[70005];
int n1,n2,ans,tot=1,S,T;
vector<int> pri;
vector<int> v[205];
bool mark[205];
int id[50][50],ind;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void _addedge(int u,int v,int c){
	es[++tot].v=v;es[tot].c=c;es[tot].nxt=head[u];head[u]=tot;
}
void insert(int u,int v,int c){
	_addedge(u,v,c);
	_addedge(v,u,0);
}
bool bfs(){
	int h=0,t=1;memset(d,-1,sizeof(d));
	q[h]=S;d[S]=0;
	while(h<t){
		int u=q[h];h++;
		for(int i=head[u];i;i=es[i].nxt){
			if(d[es[i].v]==-1&&es[i].c>0){
				d[es[i].v]=d[u]+1;
				q[t++]=es[i].v;
			}
		}
	}
	return d[T]!=-1;
}
int dfs(int u,int a){
	if(u==T||a==0)return a;
	int flow=0;
	for(int i=head[u];i;i=es[i].nxt){
		if(d[es[i].v]==d[u]+1){
			int w=dfs(es[i].v,min(a,es[i].c));
			es[i].c-=w;es[i^1].c+=w;a-=w;flow+=w;
			if(a==0)break;
		}
	}
	if(flow==0)d[u]=-1;
	return flow;
}
int Maxflow(){
	int ans=0;
	while(bfs())ans+=dfs(S,INF);
	return ans;
}
void pre(){
	for(int i=2;i<=200;i++){
		if(!mark[i])pri.push_back(i);
		for(int j=0;j<pri.size()&&pri[j]*i<=200;j++){
			mark[pri[j]*i]=1;
			if(i%pri[j]==0)break;
		}
	}
	for(int i=2;i<=200;i++)
		for(int j=0;j<pri.size();j++)
			if(i%pri[j]==0)v[i].push_back(j);
}
void build(int t,int f){
	int x,y,z;
	if(!f)x=a[t].x,y=a[t].y,z=a[t].z;
	else x=b[t].x,y=b[t].y,z=b[t].z;
	for(int i=0;i<v[x].size();i++)
		for(int j=0;j<v[y].size();j++){
			int b=n1+n2+id[v[x][i]][v[y][j]];
			if(!f)insert(t,b,1);
			else insert(b,n1+t,1);
		}
	for(int i=0;i<v[x].size();i++)
		for(int j=0;j<v[z].size();j++){
			int b=n1+n2+id[v[x][i]][v[z][j]]+46*46;
			if(!f)insert(t,b,1);
			else insert(b,n1+t,1);
		}
	for(int i=0;i<v[y].size();i++)
		for(int j=0;j<v[z].size();j++){
			int b=n1+n2+id[v[y][i]][v[z][j]]+46*46*2;
			if(!f)insert(t,b,1);
			else insert(b,n1+t,1);
		}
}
int main(){
	pre();
	n1=read();n2=read();T=n1+n2+46*46*3+1;S=0;
	for(int i=1;i<=n1;i++)
		a[i].x=read(),a[i].y=read(),a[i].z=read();
	for(int i=1;i<=n2;i++)
		b[i].x=read(),b[i].y=read(),b[i].z=read();
	for(int i=0;i<46;i++)
		for(int j=0;j<46;j++)
			id[i][j]=++ind;
	for(int i=1;i<=n1;i++){
		insert(S,i,1);build(i,0);
	}
	for(int i=1;i<=n2;i++){
		insert(n1+i,T,1);build(i,1);
	}
	printf("%d\n",Maxflow());
	return 0;
}


