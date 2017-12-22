/*
[Usaco2007 Mar]Cow Traffic ��ţ��ͨ
����������һ����(a,b)��ԭͼ�����Ϊ0�ĵ㵽a��·������F��ԭͼ��b��N��·������G����ô�����ߵľ�������ΪF*G
	  Ȼ������˵���رߣ��ѵ��������ô0.0 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector> 
using namespace std;
const int MAXN=5000,INF=0x3f3f3f3f;
vector<int> g[2][MAXN+3];
int n,m,d[2][MAXN+3],cnt[2][MAXN+3],a[10*MAXN+3],b[10*MAXN+3];
queue<int> q;
void work(int P){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)if(cnt[P][i]==0){q.push(i);d[P][i]=1;}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<g[P][u].size();i++){
			int v=g[P][u][i];
			d[P][v]+=d[P][u];
			if(--cnt[P][v] == 0)q.push(v);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i],&b[i]);
		g[0][a[i]].push_back(b[i]);
		cnt[0][b[i]]++;
		g[1][b[i]].push_back(a[i]);
		cnt[1][a[i]]++;
	}
	work(0);work(1);
	int ans=0;
	for(int i=1;i<=m;i++)ans=max(ans,d[0][a[i]]*d[1][b[i]]);
	printf("%d\n",ans);
	return 0;
}

