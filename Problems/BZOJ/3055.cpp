/*
礼物运送
分析：f[i][j]，表示当前走过的集合为j，现在在i点的最短路。
		令g[j]=min(f[i][j])  1<=i<=n
		再令 d[j]=min(d[k])  j&k=j
		则 ans=min(max(d[j],d[!j]))   0<=j< 1<<n
		d[j]的求法可以记忆化搜索。
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=20,INF=0x3f3f3f3f;
int opt[MAXN][1<<MAXN],n,mp[MAXN][MAXN],m,d[1<<MAXN],f[1<<MAXN];
bitset<(1<<MAXN)> vis;
void calcd(int state){
	if(vis[state])return;
	d[state]=f[state];
	vis[state]=1;
	for(int i=1;i<=n;i++){
		if(!(state&(1<<i-1))){
			int nx=state|(1<<i-1);
			calcd(nx);
			d[state]=min(d[state],d[nx]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	memset(mp,INF,sizeof(mp));
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		mp[x][y]=mp[y][x]=min(mp[x][y],z);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	memset(opt,INF,sizeof(opt));
	opt[1][1]=0;
	for(int state=1;state<(1<<n);state++){
		for(int i=1;i<=n;i++){
			if((state>>i-1)&1==0)continue;
			for(int j=1;j<=n;j++){
				if((state>>j-1)&1==1)continue;
				if(opt[j][state|(1<<j-1)]>opt[i][state]+mp[i][j]){
					opt[j][state|(1<<j-1)]=opt[i][state]+mp[i][j];
				}
			}
		}
	}
	memset(f,INF,sizeof(f));
	for(int state=1;state<(1<<n);state++){
		for(int i=1;i<=n;i++){
			f[state]=min(f[state],opt[i][state]);
		}
	}
	calcd(0);
	int ans=INF;
	for(int state=1;state<(1<<n);state++){
		ans=min(ans,max(d[state],d[(1<<n)-1-state]));
	}
	printf("%d\n",ans);
	return 0;
}

