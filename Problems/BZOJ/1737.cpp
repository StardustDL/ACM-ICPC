/*
[Usaco2005 jan]Naptime 午睡时间
题意：有头牛喜欢睡觉，一天被其分成了n(3<=n<=3830)份，它可以选择至多m份(2<=m<n)进行睡觉。每个时间段睡觉所得的收益不同，且它每次睡觉都必须花一份时间来入睡（算在m中，但是却没有收益），每天被视为一个环，即如果第n份没有在入睡或者熟睡状态，第一份时间就不能是熟睡状态，求最大收益。
分析：环形DP，设计状态时，用f[i,j,1]表示第i段时间为止，已睡去j个时间段，且第i段时间睡觉获得的最大效用。
	  反之，f[i,j,0]表示上述状态下[i]第i段时间不睡觉能获得的最大效用值。
	  状态转移方程如下：
	  f[i,j,0]:=Max{f[i-1,j,0]，f[i-1,j,1]}
	  f[i,j,1]:=Max{f[i-1,j-1,0],f[i-1,j-1,1]+u[i]}
 	  上述方程从i=1开始顺推，推出的只能是第一段时间开始睡或者第一段时间没有睡的最大效用值，换句话说，就是无论如何没有把u[1]加入这个最大值中，
	   但是题目要求有可能让我们把u[1]加入进去，所以只需考虑一下u[i]一定被加入的情况。
	   处理的方法就是，之前的初态为f[1,1,1]:=0;和f[1,0,0]:=0;其余f值均为不可行(即将第一秒睡不睡的值都记为0)，
	   那么现在，我们只需把初态记为f[1,1,1]:=0;其余值均记为不可行，然后再将f[n,b,1]+u[1]与原来更新出来的的ans值作比较即可
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3830,INF=0x3f3f3f3f;
int opt[2][MAXN+3][2],n,m,w[MAXN+3];
int dp(bool sleep){
	memset(opt,-1,sizeof(opt));
	int cur=0;
	opt[0][1][1]=0;
	if(!sleep)opt[0][0][0]=0;
	for(int i=2;i<=n;i++,cur^=1){
		memset(opt[cur^1],-1,sizeof(opt[cur^1]));
		for(int j=0;j<=m;j++){
			opt[cur^1][j][0]=max(opt[cur][j][0],opt[cur][j][1]);
			if(j)opt[cur^1][j][1]=max(opt[cur][j-1][1]!=-1?(opt[cur][j-1][1]+w[i]):-1,opt[cur][j-1][0]);
		}
	}
	return max(opt[cur][m][0],opt[cur][m][1]!=-1?(opt[cur][m][1]+(sleep?w[1]:0)):-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	printf("%d\n",max(dp(1),dp(0)));
	return 0;
}

