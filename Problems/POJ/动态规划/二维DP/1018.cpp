/*
Communication System
题意：N个格子，每个格子i可以选择Mi个不同物品，每种物品两个属性：bj,pj，设每个格子选ti号物品，
	  则要求最大化min{b[ti]}/sum{p[ti]}
分析：最大化这个值，可以理解为最小化sum，最大化min，利用DP转成枚举方案 
	  DP，状态：opt[i][j]表示填满前i个格子，min{b[ti]}=j时的最小sum{p[ti]} 
	  则有：opt[i][j]=min{opt[i-1][min(j,b[k])]+p[k]|1<=k<=mi} 
	  注意i=1时的边界处理，最后枚举opt[n][i]，注意有的状态是不可达的 
	  边读边处理，可以节省空间 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100,MAXV=100;
int opt[MAXN+3][MAXV+3],n,cnt,a[MAXN+3],b[MAXN+3];
/*double dp(){
	memset(opt,INF,sizeof(opt));
	for(int i=0;i<=MAXV;i++)opt[0][i]=0; 
	for(int i=1;i<=n;i++){
		for(int j=MAXV;j>=0;j--){
			//opt[i][j]=opt[i-1][j];
			for(int k=1;k<=cnt[i];k++){
				if(a[i][k]>j)continue;
				opt[i][j]=min(opt[i-1][j],opt[i-1][j-a[i][k]]+b[i][k]);
			}
		}
	}
	double ans=0;
	for(int i=MAXV;i>=0;i--){
		if(abs(opt[n][i]-INF)<1e-5)continue;
		ans=max(ans,i*1.0/opt[n][i]);
	}
	return ans;
}
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&cnt[i]);
		for(int j=1;j<=cnt[i];j++){
			scanf("%d%d",&a[i][j],&b[i][j]);
		}
	}
}*/
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(opt,-1,sizeof(opt));
		int maxa=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&cnt);
			for(int j=1;j<=cnt;j++){
				scanf("%d%d",&a[j],&b[j]);
				maxa=max(maxa,a[j]);
			}
			if(i==1){
				for(int j=1;j<=cnt;j++){
					opt[1][a[j]]=b[j];
				}
				continue;
			}
			for(int j=0;j<=maxa;j++){
				if(opt[i-1][j]==-1)continue;
				for(int k=1;k<=cnt;k++){
					int t=min(a[k],j);
					opt[i][t]=min(opt[i-1][j]+b[k],(opt[i][t]==-1?INF:opt[i][t]));
				}
			}
		}
		double ans=0;
		for(int i=1;i<=maxa;i++){
			if(opt[n][i]==-1)continue;
			ans=max(ans,i*1.0/opt[n][i]);
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}

