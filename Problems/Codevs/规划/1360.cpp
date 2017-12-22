/*
xth 的玫瑰花
分析：题目很长但核心就是：道路不能交叉，这样便可以有一个简单的状态：
	  opt[i][j]表示到第i列，且该列上部j个点向上运输的最优值，这蕴含着第j+1..m个点向左运输，因为只能向这两个方向运输，不然不会最优
	  所以opt[i][j]=max(opt[i-1][k])k<=j 
	  但这样复杂度太高，考虑很多信息并没有充分利用，采用前缀和，并维护g[i][j]表示max(opt[i][k]|k<=j)，g可以在循环中O(1)维护：g[i][j]=max(opt[i][j],g[i][j-1])
	  进一步压缩空间：去掉第一维 
*/ 
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000;
int n,m,a[MAXN+3][MAXN+3],b[MAXN+3][MAXN+3],opt[MAXN+3],g[MAXN+3],s[MAXN+3];//s维护a数组第i列的后缀和 
void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j]; 
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>b[i][j]; 
}
int dp(){
	for(int i=1;i<=m;i++){
		int sum=0;
		for(int j=n;j>=1;j--)s[j]=s[j+1]+a[j][i];//维护a数组第i列后缀和 
		g[0]=opt[0]=g[0]+s[1];//初始化g和opt（全部向上运输） 
		for(int j=1;j<=n;j++){
			sum+=b[j][i];//维护b数组前缀和 
			opt[j]=g[j]+sum+s[j+1];//直接更新，因为g已是最优 
			g[j]=max(opt[j],g[j-1]);
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)ans=max(ans,opt[i]);//寻找最优解 
	return ans;
}
int main(){
	input();
	cout<<dp();
	return 0;
}
