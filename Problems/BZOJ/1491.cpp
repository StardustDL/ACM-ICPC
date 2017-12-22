/*
[NOI2007]社交网络
分析：Floyd+暴力 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
typedef long long LL;
LL mp[MAXN+3][MAXN+3],cnt[MAXN+3][MAXN+3];
double ans[MAXN+3];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)mp[i][j]=(i==j)?0:1LL<<60;
	for(int i=1,a,b,c;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		mp[a][b]=mp[b][a]=c;
		cnt[a][b]=cnt[b][a]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mp[i][j]>mp[i][k]+mp[k][j])mp[i][j]=mp[i][k]+mp[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
				else if(mp[i][j]==mp[i][k]+mp[k][j])cnt[i][j]+=cnt[i][k]*cnt[k][j]; 
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mp[i][j]==mp[i][k]+mp[k][j] && cnt[i][j]>0)
					ans[k]+=(double)cnt[i][k]*cnt[k][j]/cnt[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%.3lf\n",ans[i]);
	return 0;
}

