/*
[POI2008]Sta
��������f[x]Ϊ��xΪ�������������֮��
	  ���������ҵ�����һ���ڵ�������ѣ�ͳ�Ƴ�ÿ�������Ĵ�С���Լ����е�����֮��
		Ȼ�����Ըýڵ�Ϊ������һ�飬��ʱ״̬�Ӹ��ڵ�ת�����ӽڵ㣬ת�Ʒ������£�
		�����ǽ����ڵ��a�ڵ��Ϊb�ڵ�ʱ��b�����������-1������ĵ� ��+1 
	  �ʵõ�״̬ת�Ʒ��̣�
		f[x]=f[fa[x]]+n-2*size[x]
	  vector�ᱻ��ʱ���ڽӱ�����9s��TAT 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=1000000,INF=0x3f3f3f3f;
int sz[MAXN+3],n,ans;
LL ans_d;
int head[MAXN+3],next[2*MAXN+3],to[2*MAXN+3],tot=0;
void dfs(int x,int fa,int d){
	sz[x]=1;ans_d+=d;
	for(int i=head[x];i!=0;i=next[i]){
		if(to[i]==fa)continue;
		dfs(to[i],x,d+1);
		sz[x]+=sz[to[i]];
	}
}
void solve(int x,int fa,LL cur_d){
	if(cur_d>ans_d){ans_d=cur_d,ans=x;}
	else if(cur_d==ans_d){ans=min(ans,x);}
	for(int i=head[x];i!=0;i=next[i]){
		if(to[i]==fa)continue;
		solve(to[i],x,cur_d-sz[to[i]]+(n-sz[to[i]]));
	}
}
void addedge(int a,int b){
	to[++tot]=b;
	next[tot]=head[a];
	head[a]=tot;
}
int main(){
	scanf("%d",&n);
	for(int a,b,i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		addedge(a,b);
		addedge(b,a);
	}
	dfs(1,0,0);ans=1;
	solve(1,0,ans_d);
	printf("%d\n",ans);
	return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=1000000,INF=0x3f3f3f3f;
int sz[MAXN+3],pa[MAXN+3],n;
LL opt[MAXN+3];
vector<int> g[MAXN+3];
void dfs(int x){
	sz[x]=1;
	for(int i=0,to;i<g[x].size();i++){
		to=g[x][i];
		if(to==pa[x])continue;
		pa[to]=x;
		dfs(to);
		sz[x]+=sz[to];
		opt[x]+=opt[to]+sz[to];
	}
}
void solve(int x){
	if(pa[x])opt[x]=opt[pa[x]]+n-2*sz[x];
	for(int i=0,to;i<g[x].size();i++){
		to=g[x][i];
		if(to==pa[x])continue;
		solve(to);
	}
}
int main(){
	scanf("%d",&n);
	for(int a,b,i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	solve(1);
	printf("%d\n",max_element(opt+1,opt+n+1)-opt);
	return 0;
}
*/ 
