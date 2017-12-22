/*
��ļ���
�����������ڿ�Ҫ�������ڵ㣩����֤��������ȷ���Ŀ�Ĵ�Сk�����ַ�����Ψһ�ġ�����ʾ��ÿ�ο�����������Ǹ��飩��
		������Եȼ����ж��ж��������Ĵ�СΪk�ı�����Ԥ����Ȼ���жϾ���O(NlogN)�ˡ� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
int head[2*MAXN+3],next[2*MAXN+3],to[2*MAXN+3],cnt=1,sz[MAXN+3],n,a[MAXN+3],ans=0;
void addedge(int u,int v){
	to[cnt]=v;next[cnt]=head[u];head[u]=cnt++;
}
void dfs(int u,int fa){
	sz[u]=1;
	for(int i=head[u];i;i=next[i]){
		if(to[i]==fa)continue;
		dfs(to[i],u);
		sz[u]+=sz[to[i]];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){scanf("%d%d",&u,&v);addedge(u,v);addedge(v,u);}
	dfs(1,0);
	for(int i=1;i<=n;i++)a[sz[i]]++;
	for(int k=1,cnt=0;k<=n;k++,cnt=0){
		if(n%k)continue;
		for(int j=k;j<=n;j+=k)cnt+=a[j];
		ans+=cnt==n/k;
	}
	printf("%d\n",ans); 
	return 0;
}

