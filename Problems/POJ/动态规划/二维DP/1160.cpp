/*
Post Office
·ÖÎö£º¼ò»¯°æµÄ1485 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=300;
int ds[MAXN+3][MAXN+3],opt[MAXN+3][MAXN+3],pre[MAXN+3][MAXN+3],n,k,d[MAXN+3];
void input(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	d[n+1]=INF;d[0]=-INF;
	//memset(ds,0,sizeof(ds));
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int t=d[(i+j)>>1],l=i,r=j,&a=ds[i][j];
			while(l<=r)a+=abs(t-d[l++]);
		}
	}
}
int dp(){
	memset(opt,INF,sizeof(opt));
	for(int i=1;i<=n;i++)opt[i][1]=ds[1][i];
	for(int i=2;i<=n;i++)
		for(int j=2;j<=k;j++)
			for(int e=1;e<i;e++)
				opt[i][j]=min(opt[i][j],opt[e][j-1]+ds[e+1][i]);
	return opt[n][k];
}
int main(){
	input(); 
	printf("%d",dp());
	return 0;
}

