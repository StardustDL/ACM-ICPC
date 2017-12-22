/*
Blocks
题意：有一些带颜色的盒子，如果一些相邻的盒子都是相同的颜色,和两个盒子左(如果它存在的话)和其右(如果它存在的话)的其他颜色,我们称之为“盒段”。
	  每一次,可以单击一个盒子,然后整个段消失。如果这段由k个盒子组成,你会得到k * k点。求最优点数 
分析：区间DP，一目了然，但是状态并不太好理解：
	  opt[i][j][k]表示[i..j]然后把第j段和其后的k个格子合并的最优解
	  则转移为：
	  	1.直接消去:opt[i][j][k]=opt[i][j-1][0]+(len[j]+k)^2
		2.第j段连同k个一起和[i..j]中某一段一起合并：opt[i][j][k]=max{opt[i][p][len[j]+k]+opt[p+1][j-1][0]|i<=p<j&&color[p]==color[j]} 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#define sqr(x) ((x)*(x)) 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200;
int col[MAXN+3],len[MAXN+3],opt[MAXN+3][MAXN+3][MAXN+3],n,cntc,after[MAXN+3];
void input(){
	scanf("%d",&n);
	int x;scanf("%d",&x);
	cntc=1;col[1]=x;len[1]=1;
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		if(x==col[cntc])len[cntc]++;
		else {
			col[++cntc]=x;
			len[cntc]=1;
		}
	}
	n=cntc;
	for(int i=1;i<=n;i++){//统计i之后（不含i）的与i颜色相同的格子数 
		after[i]=0;
		for(int j=i+1;j<=n;j++)if(col[j]==col[i])after[i]+=len[j];
	}
}
int dp(){
	memset(opt,0,sizeof(opt));
	/*for(int i=1;i<=n;i++){
		for(int k=0;k<=after[i];k++){
			opt[i][i][k]=sqr(len[i]+k);
		}
	}*/
	for(int le=1;le<=n;le++){
		for(int i=1;i+le-1<=n;i++){
			int j=i+le-1;
			for(int k=0;k<=after[j];k++){
				opt[i][j][k]=opt[i][j-1][0]+sqr(len[j]+k);
				for(int p=i;p<j;p++){
					if(col[p]!=col[j])continue;
					opt[i][j][k]=max(opt[i][j][k],opt[i][p][len[j]+k]+opt[p+1][j-1][0]);
				}
			}
		}
	}
	return opt[1][n][0];
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		input();
		printf("Case %d: %d\n",i,dp());
	}
	return 0;
}

