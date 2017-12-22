/*
[BeijingWc2008]雷涛的小猫
分析：DP，但是数据范围是什么鬼= = 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5000,INF=0x3f3f3f3f;
int mp[MAXN+3][MAXN+3];
int dp[MAXN+3],c[MAXN+3],n,h,d; //高度为i最大值，当前高度在第i棵上最大值 
int main(){
	scanf("%d%d%d",&n,&h,&d);
	for(int i=1;i<=n;i++){
		int t,x;scanf("%d",&t);
		for(;t;t--){
			scanf("%d",&x);
			mp[i][x]++;
		}
	}
	for(int i=h;i;i--){
		int up=(i+d<=h)?dp[i+d]:0;//从上方跳下来 
		for(int j=1;j<=n;j++){
			c[j]=max(c[j],up)+mp[j][i]; 
		}
		dp[i]=max(dp[i],*max_element(c+1,c+n+1));
	}
	printf("%d\n",dp[1]);
	return 0;
}

