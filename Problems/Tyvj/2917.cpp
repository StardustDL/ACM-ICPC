/*
¹ØÂ·µÆ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=50;
int opt[MAXN+3][MAXN+3][2],w[MAXN+3],d[MAXN+3],n,v,sum[MAXN+3][MAXN+3],c[MAXN+3][MAXN+3];
int main(){
	scanf("%d%d",&n,&v);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&d[i],&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum[i][j]=sum[i][j-1]+w[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[i][j]=sum[1][n]-sum[i][j];
		}
	}
	memset(opt,INF,sizeof(opt));
	opt[0][0][0]=opt[0][0][1]=0;
	for(int i=1;i<=v-1;i++){
		opt[i][0][0]=opt[i-1][0][0]+c[v-i+1][v]*(d[v-i+1]-d[v-i]);
		opt[i][0][1]=opt[i][0][0]+c[v-i][v]*(d[v]-d[v-i]);
	}
	for(int i=1;i<=n-v;i++){
		opt[0][i][1]=opt[0][i-1][1]+c[v][v+i-1]*(d[v+i]-d[v+i-1]);
		opt[0][i][0]=opt[0][i][1]+c[v][v+i]*(d[v+i]-d[v]);
	}
	for(int i=1;i<=v-1;i++){
		for(int j=1;j<=n-v;j++){
			opt[i][j][0]=
				min(opt[i-1][j][0]+c[v-i+1][v+j]*(d[v-i+1]-d[v-i]),
					opt[i-1][j][1]+c[v-i+1][v+j]*(d[v+j]-d[v-i]));
			opt[i][j][1]=
				min(opt[i][j-1][1]+c[v-i][v+j-1]*(d[v+j]-d[v+j-1]),
					opt[i][j-1][0]+c[v-i][v+j-1]*(d[v+j]-d[v-i]));
		}
	}
	printf("%d",min(opt[v-1][n-v][0],opt[v-1][n-v][1]));
	return 0;
}

