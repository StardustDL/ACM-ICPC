/*
Pku3764 The xor-longest Path
�����������ÿ���㵽��·����Ȩֵ���ͣ����������·�����Ϳ����������㵽�������͵�����ʾ
	  Ȼ����Ǿ������⣺��һ��������������x��������ֵ������Trie��+̰�Ŀ���
	  ע�����鷶Χ���߿�������Trie���ڵ�*������λ����ע�ⲻҪά��valֵ�ˣ��ᱬ�ڴ棬����Ԥ����һ�£����ܺ����ױ���val����
	  һֱRE����ݴ�����poj��Ҳ��RE����BZOJ��AC 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
const int MAXN=100010,INF=0x3f3f3f3f;
int n,u[2*MAXN+3],v[2*MAXN+3],w[2*MAXN+3],tot,c[MAXN+3];
vector<int> g[MAXN+3];
int bit[35];
namespace Trie{
	int ch[32*MAXN+3][2],sz;
	void init(){memset(ch,0,sizeof(ch));sz=0;}
	void insert(int va){
		int cur=0;
		for(int i=30,t;i>=0;i--){
			t=(va&bit[i])>>i;
			if(!ch[cur][t])ch[cur][t]=++sz;
			cur=ch[cur][t];
		}
	}
	int query_MAX(int va){
		int cur=0,tmp=0;
		for(int i=30,t;i>=0;i--){
			t=(va&bit[i])>>i;
			if(ch[cur][t^1])cur=ch[cur][t^1],tmp+=bit[i];
			else cur=ch[cur][t];
		}
		return tmp;
	}
}
void addedge(int _u,int _v,int _w){
	//cout<<_u<<_v<<_w<<endl;
	w[tot]=_w;
	u[tot]=_u;
	v[tot]=_v;
	g[_u].push_back(tot++);
}
bool input(){
	//scanf("%d",&n);
	if(scanf("%d",&n)!=1)return false;
	for(int i=1;i<=n;i++)g[i].clear();
	memset(u,0,sizeof(u));
	memset(v,0,sizeof(v));
	memset(w,0,sizeof(w));
	tot=0;
	for(int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	return true;
}
void dfs(int u,int fa){
	//cout<<u<<" "<<c[u]<<endl;
	for(int i=0;i<g[u].size();i++){
		int to=g[u][i];
		if(v[to]==fa)continue;
		//cout<<v[to<<" "<<w[to]<<endl;
		c[v[to]]=c[u]^w[to];
		dfs(v[to],u);
	}
}
void calcc(){
	memset(c,0,sizeof(c));
	dfs(1,0);
}
int main(){
	bit[0]=1;for(int i=1;i<=30;i++)bit[i]=bit[i-1]<<1;
	int ans=0;
	while(input()){
		Trie::init();ans=0;
		calcc();
		for(int i=1;i<=n;i++){
			//cout<<i<<" "<<c[i]<<endl;
			Trie::insert(c[i]);
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,Trie::query_MAX(c[i]));
		}
		printf("%d\n",ans);
	}
	return 0;
}

