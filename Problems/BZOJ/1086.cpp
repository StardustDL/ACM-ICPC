/*
[SCOI2005]��������
������ÿ��ʡ����Ҫ��B�����У�Ϊ������Ч�Ĺ���ÿ��ʡ���ֻ��3B�����С�ÿ��ʡ������һ��ʡ�ᣬ���ʡ�����λ��ʡ�ڣ�Ҳ�����ڸ�ʡ�⡣���Ǹ�ʡ������һ�����е���ʡ���������ĵ�·�ϵĳ��У��������һ�����У�����ʡʡ�ᣩ���������ڸ�ʡ��һ�����п�����Ϊ���ʡ��ʡ�ᡣ
	  ��ϸ�����ͻᷢ����ʵʲô���ƶ�û�У�ֻҪ>=B�Ͱ�һ����������һ��ʡ��һ����Ķ������Ҳ������һ��ʡ 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
vector<int> g[MAXN+3];
int belong[MAXN+3],cap[MAXN+3],sz[MAXN+3],K,n,B,sta[MAXN+3],top; 
void dfs(int u,int fa){
	sta[++top]=u;
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==fa)continue;
		dfs(g[u][i],u);
		sz[u]+=sz[g[u][i]];
		if(sz[u]>=B){
			cap[++K]=u;sz[u]=0;
			while(sta[top]!=u)belong[sta[top--]]=K;
		}
	}
	sz[u]++;//ע��Ҫ��������������������ֵ� 
}
void reset(int u,int fa,int c){//��û��������ַ֣����ڵ�ʡ�� 
	if(belong[u])c=belong[u];
	else belong[u]=c;
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==fa)continue;
		reset(g[u][i],u,c);
	}
}
int main(){
	scanf("%d%d",&n,&B);
	if(n<B){puts("0");return 0;}
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	if(K==0)cap[++K]=1;
	reset(1,0,K);//1�ŵ�һ���ǰ������һ��ʡ��
	printf("%d\n",K);
	for(int i=1;i<=n;i++)printf("%d ",belong[i]);
	printf("\n");
	for(int i=1;i<=K;i++)printf("%d ",cap[i]);
	printf("\n"); 
	return 0;
}

