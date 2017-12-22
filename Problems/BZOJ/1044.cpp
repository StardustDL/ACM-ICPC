/*
[HAOI2008]木棍分割
分析：第一问二分，注意下界要取最长木棍长度，不然判断函数要加特判
	  第二问，设f[i][j]表示前i根，切j次的方案数，f[i][j]=sigma{f[k][j-1]|sum[i]-sum[k]<=len} 
	  注意sum是递增的，所以维护一下sum即可，类似单调队列。注意不要MLE，要滚动数组。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f,MAXM=1000,MOD=10007;
int ans1,ans2,n,m,sum[MAXN+3],f[MAXN+3][2],mx=0;
bool check(int x){
	int lst=0,cnt=0;
	for(int i=1;i<=n;i++)
		if(sum[i]-sum[lst]>x)lst=i-1,cnt++;
	return cnt<=m;
}
void solve1(){
	int l=mx,r=sum[n];ans1=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans1=mid,r=mid-1;
		else l=mid+1;
	}
}
void solve2(){
	for(int i=1;i<=n;i++)if(sum[i]<=ans1)f[i][0]=1;else break;
	ans2=(ans2+f[n][0])%MOD;
	for(int j=1,cur=1,l,tsum;j<=m;j++,cur^=1){
		l=1;tsum=0;
		for(int i=1;i<=n;i++){
			while(sum[i]-sum[l]>ans1)((tsum-=f[l++][cur^1])+=MOD)%=MOD;
			f[i][cur]=tsum;
			tsum=(tsum+f[i][cur^1])%MOD;
		}
		ans2=(ans2+f[n][cur])%MOD;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%d",&sum[i]);mx=max(sum[i],mx);sum[i]+=sum[i-1];}
	solve1();solve2();
	printf("%d %d\n",ans1,ans2);
	return 0;
}

