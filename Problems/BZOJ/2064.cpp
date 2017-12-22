/*
分裂
分析：很不错的状压DP
		最优方案中出现的所有数一定是一开始两个数列中出现过的数，首先找一个操作数的上界，那一定是n+m，显然只要把第一个数列n次加起来加成一个数，然后再m次分割分成数列2即可
		如果已经有a数列里的一坨数的和等于b数列里一坨数的和的话，那先把这两坨数搞成相同的，就可以在上界的基础上减少两次操作，也就是将这两坨数的和合到总和里去，和从总和里分出来的那两次操作省去了，然后再看这两坨数里面最大的和相等的部分，这就是最优子结构了，就可以用DP愉快地搞定了
		DP[S][T]表示a数列选中的方案为S,b数列中选中方案为T，两坨数相同的最大值，由上所述，每个相同能减少两次操作，因此答案就是n+m-dp[(1<<(n))-1][(1<<(m))-1] 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[10+3],b[10+3],dp[1<<10+1][1<<10+1],sa[1<<10+2],sb[1<<10+2];
void init(int ind,int mxd,int st,int *a,int sum,int *out){
	if(ind==mxd+1)return;
	out[st<<(mxd-ind)]=sum;//给后面的留着空 
	init(ind+1,mxd,st<<1|1,a,sum+a[ind+1],out);
	init(ind+1,mxd,st<<1,a,sum,out);
}
int solve(){
	for(int i=1;i<1<<n;i++){
		for(int j=1;j<1<<m;j++){
			int &t=dp[i][j];
			for(int k=0;k<n;k++)
				if(i&(1<<k))t=max(t,dp[i^(1<<k)][j]);
			for(int k=0;k<m;k++)
				if(j&(1<<k))t=max(t,dp[i][j^(1<<k)]);
			if(sa[i]==sb[j])t++;
		}
	}
	return dp[(1<<n)-1][(1<<m)-1];
}
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	init(0,n,0,a,0,sa);
	init(0,m,0,b,0,sb);
	printf("%d\n",n+m-2*solve());
	return 0;
}

