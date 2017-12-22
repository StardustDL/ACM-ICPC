/*
[POI2008]BLO
����������ͼ��ͨ��
	  ע��ɾȥһ����X���������������㶼����ͨ�����Ծ���n-1������ˣ�Ȼ�����X�Ǹ�㣬�ͻ��и���ĵ�ԣ�
	  ɾȥ��㣬��õ�һЩ��ͨ�飺A,B,C��ע�������������� 
	  ans[X]=2*(n-1)+A*(B+C)+B*(A+C)+C*(A+B)
	  		=(n-1+A*B+(A+B)*C)*2
	  	���ֱ��ν�n^2������n 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=100000,INF=0x3f3f3f3f;
vector<int> g[MAXN+3];
int low[MAXN+3],dfn[MAXN+3],tme=0,sz[MAXN+3],n,m;
LL ans[MAXN+3];
void tarjan(int x){
	dfn[x]=low[x]=++tme;sz[x]=1;int sum=0;
	for(int i=0,to;i<g[x].size();i++){
		to=g[x][i];
		if(dfn[to])low[x]=min(low[x],dfn[to]);
		else{
			tarjan(to);
			sz[x]+=sz[to];
			low[x]=min(low[x],low[to]);
			if(low[to]>=dfn[x]){
				ans[x]+=(LL)sum*sz[to];
				sum+=sz[to];
			}
		}
	}
	ans[x]+=(LL)sum*(n-sum-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int a,b;m;m--){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	tarjan(1);
	for(int i=1;i<=n;i++)printf("%lld\n",(ans[i]+n-1)<<1);
	return 0;
}

