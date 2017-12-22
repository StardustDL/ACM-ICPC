/*
Grazing on the Run
题意：有n块草坪，知道每块草坪的位置（我们可以看做是x轴上的一点），Bessie位于L位置，他可以向左右两个方向去吃草坪，假设吃草坪的时间不计，路上的时间是每走一个单位，时间+1，每块草坪都有一个staleness值，这个值恰好等于Bessie到达的时间，现在要求的是Bessie将所有草坪吃完，所有草坪的staleness值最小是多少
分析：最优解一定是区间扩大而不会是跳跃式的
	  所以：
	  	用dp[i][j][0]表示从i-j区间都吃完，最后停留在i位置，所有草坪的最小的staleness值
		dp[i][j][1]表示i-j区间都吃完，最后停留在j位置上的最小值
		那么这两个状态的转移方程就是
        	dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(a[i+1]-a[i])*(delay));
        	dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(a[j]-a[i])*(delay));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(a[j]-a[j-1])*(delay));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(a[j]-a[i])*(delay));
        delay表示之后还有多少操作会延长时间，相当于提前计算出来，delay=n-(j-i+1)+1=n-j+i 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int opt[MAXN+3][MAXN+3][2],l,a[MAXN+3],n;
int dp(int start){
	memset(opt,INF,sizeof(opt));
	opt[start][start][0]=opt[start][start][1]=0;
	for(int i=start;i>=1;i--){
		for(int j=start;j<=n;j++){
			if(i==j)continue;
			int l=(j-i);
			opt[i][j][0]=min(min(opt[i+1][j][0]+(a[i+1]-a[i])*(n-l),opt[i+1][j][1]+(a[j]-a[i])*(n-l)),opt[i][j][0]);
			opt[i][j][1]=min(min(opt[i][j-1][1]+(a[j]-a[j-1])*(n-l),opt[i][j-1][0]+(a[j]-a[i])*(n-l)),opt[i][j][1]);
		}
	}
	return min(opt[1][n][0],opt[1][n][1]);
}
int main(){
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[++n]=l;
	sort(a+1,a+n+1);
	printf("%d\n",dp(lower_bound(a+1,a+n+1,l)-a)); 
	return 0;
}

