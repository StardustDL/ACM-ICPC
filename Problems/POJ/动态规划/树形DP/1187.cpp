/*
陨石的秘密
题意：给定()[]{}的数量分别为l1，l2，l3（0<=l1，l2，l3<=10），规定()不能套在[]和{}的外面，[]不能套在{}的外面，即{} [] ()优先级递减，现在想最大组成嵌套深度为d
         （0<=d<=30）的串，问一共有多少种方法。
分析：首先很容易想到记忆化dfs，dp[a][b][c][d]表示{}[]()分别有a b c个形成最大嵌套深度为d的方法数，然后找到子状态，但是麻烦的是d是多个子问题求max得到的，这样
          在dfs的过程中没办法控制哪一个是最大的，看了下提示瞬间石化。
          dp[a][b][c][d]表示{}[]()分别有a b c个形成最大嵌套深度小于等于d的方法数，这样能得到子状态，由于优先级的问题改变遍历{}[]()的顺序即可，枚举当前在左边套在最
          外面的是{}[]或()，最后得到答案为dp[a][b][c][d] – dp[a][b][c][d-1]（d == 0时候答案为dp[a][b][c][d]）。因为dfs时分开的两个串是独立的，所以不会有重复计数。 
		PS：网上有一个想法说的很好：把括号的嵌套看成是一棵树就简单些，这棵树的最大深度为 D，()节点下面不能有{}[]节点，[]节点下面不能有{}节点，然后从上往下
        依次摆放节点。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10,MAXM=30,MOD=11380,INF=0x3f3f3f3f;
int opt[MAXN+3][MAXN+3][MAXN+3][MAXM+3];
int l1,l2,l3,d;
int dp(int l1,int l2,int l3,int d){
	if(l1+l2+l3==0)return opt[l1][l2][l3][d]=1;
	if(d==0)return opt[l1][l2][l3][d]=0;
	int &ans=opt[l1][l2][l3][d];
	if(ans!=-1)return ans;
	ans=0;
	for(int i=0;i<=l3;i++){
		if(i)(ans+=dp(0,0,i-1,d-1)*dp(l1,l2,l3-i,d)%MOD)%=MOD;
		for(int j=0;j<=l2;j++){
			if(j)(ans+=dp(0,j-1,i,d-1)*dp(l1,l2-j,l3-i,d)%MOD)%=MOD;
			for(int k=0;k<=l1;k++)
				if(k)(ans+=dp(k-1,j,i,d-1)*dp(l1-k,l2-j,l3-i,d)%MOD)%=MOD;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d%d%d",&l1,&l2,&l3,&d);
	memset(opt,-1,sizeof(opt));
	int t1=dp(l1,l2,l3,d),t2=0;
	if(d)t2=dp(l1,l2,l3,d-1);
	printf("%d\n",(((t1-t2)%MOD)+MOD)%MOD);
	return 0;
}

