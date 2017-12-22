/*
I Love this Game!
题意：给n个数，并给一个区间[a,b],第一次选的数要在这个区间内，然后每次选n个数中的某个数，使得这个数减去对手所选的数得到的差值在[a,b]区间内。b>a>0，求第一个选手所选的数的和减去第二个人所选的数的和的最大差值。A要使sum1-sum2最大，B则尽量让sum1-sum2小。而他们都会取最佳的数。 
分析：博弈+Dp，a>0，所以取得顺序一定是递增的，排序，这样就不存在后效性了，考虑DP，opt[i]表示选择i位置的数所能得到的最大差值，则有opt[i]=val[i]-max{opt[j]|val[j]-val[i]∈[a,b] && n>=j>i} 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
int v[MAXN+3],opt[MAXN+3],a,b,n;
void input(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	sort(v+1,v+n+1);
}
int dp(){
	int ans=INT_MIN;
	memset(opt,0,sizeof(opt));
	for(int i=n;i>=1;i--){
		int mx=INT_MIN;
		for(int j=i+1;j<=n;j++){
			int c=v[j]-v[i];
			if(c>b)break;
			if(c>=a)mx=max(mx,opt[j]);
		}
		if(mx==INT_MIN)mx=0;
		opt[i]=v[i]-mx;
	}
	for(int i=1;i<=n;i++){
		if(v[i]>b)break;
		if(v[i]>=a)ans=max(ans,opt[i]);
	}
	return ans==INT_MIN ? 0:ans;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		input();
		printf("%d\n",dp());
	}
	return 0;
}

