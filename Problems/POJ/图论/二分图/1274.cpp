/*
The Perfect Stall
���⣺��nͷţ��m��ţ�����ÿͷţԸ��ȥ���̵�ţ���ţ�ÿͷţֻ�ɲ�һ���̣�ÿ��ţ��Ҳֻ����һֻţ���̡�������ж���ţ 
����������ͼ���ƥ�� 
*/
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXV=205; 
int n,m,mp[MAXV][MAXV];
int link[MAXV],use[MAXV];
int dfs(int u){
	for(int i=1;i<=m;i++)
		if(mp[u][i]&&!use[i]){
			use[i]=1;
			if(link[i]==-1||dfs(link[i])){link[i]=u;return true;}
		}
	return false;
}
int hungary(){
	int ans=0;
	memset(link,-1,sizeof(link));
	for(int i=1;i<=n;i++){
		memset(use,0,sizeof(use));
		if(dfs(i))ans++;
	}
	return ans;
}
int main(){
	int cnt,t;
	while(~scanf("%d%d",&n,&m)){
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++){
			scanf("%d",&cnt);
			for(int j=1;j<=cnt;j++){
				scanf("%d",&t);
				mp[i][t]=1;
			}
		}
		printf("%d\n",hungary());
	}
	return 0;
}
