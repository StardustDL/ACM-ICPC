/*
[HEOI2013]SAO  
���⣺��n���¼���n-1��Լ������ʾΪ��i���¼������ڵ�j��֮ǰ���󣩷���������ܵ��¼����У���ģ109+7���� 
		������Լ����Ϊ����ߣ�����n���¼���һ����ͨ���ڡ� 
		1��n��1000 
����������DP����f[i][j]��ʾi�ڵ�λ���������е�jλ�õķ�������pre[i][j]=sigma{f[i][1..j]},suf[i][j]=sigma{f[i][j..n]}
		����dfs������һ����(u,v)���ȵݹ鴦��v������Ȼ��ϲ���u�� 
		���Ҫ��u��vǰ����u��u�������е�λ��Ϊi��v��v�������е�λ��Ϊj��Ҫ��v�е�ǰj-1��Ҫ��uǰ
			��ô������ΪC( i-1 + j-1,i-1)*f[u][i] * C( size[u]-i + size[v]-(j-1),size[u]-i)*suf[v][j] , ת�Ƶ�f'[u][i+j-1] 
		���Ҫ��v��uǰ����u��u�������е�λ��Ϊi��v��v�������е�λ��Ϊj��Ҫ��v�е�ǰj��Ҫ��uǰ
			��ô������ΪC( i-1 + j,i-1)*f[u][i] * C( size[u]-i + size[v]-j,size[u]-i)*pre[v][j] , ת�Ƶ�f'[u][i+j] 
		ans=pre[root][n] 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=1000,INF=0x3f3f3f3f;
const LL MOD=1000000007;
LL fact[MAXN+3],inv[MAXN+3];
LL qpow(LL a,LL n){
	LL ans=1;
	while(n){if(n&1)(ans*=a)%=MOD;(a*=a)%=MOD;n>>=1;}
	return ans;
}
void init(){
	fact[0]=1;
	for(int i=1;i<=MAXN;i++)fact[i]=fact[i-1]*i%MOD;
	inv[MAXN]=qpow(fact[MAXN],MOD-2);
	for(int i=MAXN-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
LL C(int n,int m){
	return fact[n]*inv[m]%MOD*inv[n-m]%MOD;
}
struct edge{
	int u,v;bool b;
	edge(int u,int v,bool b):u(u),v(v),b(b){}
};
vector<edge> es;
vector<int> g[MAXN+3];
void addedge(int u,int v,int d){
	es.push_back(edge(u,v,d));
	g[u].push_back(es.size()-1);
	es.push_back(edge(v,u,!d));
	g[v].push_back(es.size()-1);
}
int n;
LL pre[MAXN+3][MAXN+3],suf[MAXN+3][MAXN+3],f[MAXN+3][MAXN+3],h[MAXN+3],sz[MAXN+3];
void dfs(int u,int fa){
	sz[u]=1;
	memset(f[u],0,sizeof(f[u]));f[u][1]=1;
	for(int p=0;p<g[u].size();p++){
		edge &e=es[g[u][p]];
		if(e.v==fa)continue;
		dfs(e.v,u);
		memset(h,0,sizeof(h));
		for(int i=1;i<=sz[u];i++){
			/*Ҳ���Էֿ�������u��vǰ��ö��j=0..sz[e.v]-1������u��v��ö��j=1..sz[e.v]
				���̱�ɣ�h[i+j]+=C(i+j-1,i-1)*C(sz[u]-i+sz[e.v]-j,sz[u]-i)*f[u][i]*suf[e.v][j+1];
						  h[i+j]+=C(i+j-1,i-1)*C(sz[u]-i+sz[e.v]-j,sz[u]-i)*f[u][i]*pre[e.v][j];*/
			for(int j=1;j<=sz[e.v];j++){ 
				if(e.b)//u->v 
					(h[i+j-1]+=C(i+j-2,i-1)*C(sz[u]-i+sz[e.v]-(j-1),sz[u]-i)%MOD*f[u][i]%MOD*suf[e.v][j]%MOD)%=MOD;//ע����+= 
				else
					(h[i+j]+=C(i+j-1,i-1)*C(sz[u]-i+sz[e.v]-j,sz[u]-i)%MOD*f[u][i]%MOD*pre[e.v][j]%MOD)%=MOD;
			}
		}
		sz[u]+=sz[e.v];
		for(int i=1;i<=sz[u];i++)f[u][i]=h[i];
	}
	pre[u][1]=f[u][1];
	for(int i=2;i<=n;i++)
    	pre[u][i]=(pre[u][i-1]+f[u][i])%MOD;
    suf[u][n]=f[u][n];
    for(int i=n-1;i>=1;i--)
        suf[u][i]=(suf[u][i+1]+f[u][i])%MOD;
}
void clear(int n){
	es.clear();
	for(int i=1;i<=n;i++)g[i].clear();
}
int main(){
	init();
	int T;scanf("%d",&T);
	for(;T;T--){
		scanf("%d",&n);
		clear(n);
		for(int i=1,x,y;i<n;i++){
			scanf("%d",&x);
			char c=getchar();
            while (c!='<'&&c!='>')c=getchar();
            scanf("%d",&y);
			addedge(++x,++y,c=='<');
		}
		dfs(1,0);
		printf("%lld\n",pre[1][n]);
	}
	return 0;
}

