/*
[Usaco2008 Jan]Cow ContestÄÌÅ£µÄ±ÈÈü
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
bool mp[MAXN+3][MAXN+3];
int n,m,ans=0; 
int main(){
	scanf("%d%d",&n,&m);
	for(int a,b;m;m--){
		scanf("%d%d",&a,&b);
		mp[a][b]=1;
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)mp[i][j]=mp[i][j]||mp[i][k]&&mp[k][j];
	for(int i=1,j,cnt;i<=n;ans+=(cnt==n-1),i++)
		for(j=1,cnt=0;j<=n;j++)cnt+=mp[i][j]||mp[j][i];
	printf("%d\n",ans);
	return 0;
}

