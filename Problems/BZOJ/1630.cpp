/*
[Usaco2007 Demo]Ant Counting
·ÖÎö£ºÍ¬2023 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f,MOD=1000000;
int cnt[MAXN+3],opt[2][MAXN*100+3],t,a,s,b,cur,sum[2][MAXN*100+3]; 
int main(){
	scanf("%d%d%d%d",&t,&a,&s,&b);
	for(int i=1,x;i<=a;i++){scanf("%d",&x);cnt[x]++;}
	opt[0][0]=1;
	for(int i=0;i<=a+1;i++)sum[0][i]=1;
	for(int i=1,cur=1;i<=t;i++,cur^=1){
		for(int j=0;j<=a;j++){
			opt[cur][j]=sum[cur^1][j];
			if(j-cnt[i]>0)opt[cur][j]-=sum[cur^1][j-cnt[i]-1];
			(opt[cur][j]+=MOD)%=MOD;
			sum[cur][j]=(sum[cur][j-1]+opt[cur][j])%MOD;
		}
	}
	int ans=(sum[t&1][b]-sum[t&1][s-1]+MOD)%MOD;
	printf("%d\n",ans);
	return 0;
}

