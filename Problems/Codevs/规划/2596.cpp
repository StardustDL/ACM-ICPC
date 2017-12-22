/*
售货员的难题
分析：又是一道状压DP，要注意的是位运算符优先级很低，
	  第一次交写了个 i&(1<<(k-1))!=1 就错了，要去掉!=1，因为不一定是1，可能是1000 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=15,INF=0x3f3f3f3f;
int mp[MAXN+3][MAXN+3],n,opt[1<<MAXN][MAXN+3];
int dp(){
	memset(opt,INF,sizeof(opt));
	opt[1][1]=0;
	for(int i=1;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			if((i&(1<<(j-1))==0))continue;
			for(int k=1;k<=n;k++){
				if(k==j)continue;
				if(i&(1<<(k-1))/*!=1*/)continue;
				opt[i|(1<<(k-1))][k]=min(opt[i|(1<<(k-1))][k],opt[i][j]+mp[j][k]);
			}
		}
	}
	int ans=INF;
	for(int i=1;i<=n;i++){
		ans=min(ans,opt[(1<<n)-1][i]+mp[i][1]);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)cin>>mp[i][j];
	cout<<dp();
	return 0;
}
