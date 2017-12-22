/*
Max Sum
题意：最大连续子序列和，输出起始点和结束点（第一个） 
分析：贪心：维护当前的最大和，若<0，就置0，否则尝试更新答案，同时记录端点
	  DP思路：f[i]表示一定选第i个的前i个数的最大值，f[i]=max(f[i-1]+a[i],0)，但记录区间并不方便（尤其是第一个区间）
	  注意输出不要有多余的行 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
int n,a[MAXN+3],opt[MAXN+3];
int main(){
	int T;
	scanf("%d",&T);
	for(int k=1;k<=T;k++){
		scanf("%d",&n);
		//memset(opt,0,sizeof(opt));
		int ans=-INF,l,r,t=0,p=1;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			t+=a[i];
			if(t>ans){
				ans=t;
				l=p;r=i;
			}
			if(t<0){
				p=i+1;t=0;
			}
		}
		printf("Case %d:\n%d %d %d\n",k,ans,l,r);
		if(k<T)puts("");
	}
	return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
int n,a[MAXN+3],opt[MAXN+3];
int main(){
	int T;
	scanf("%d",&T);
	for(int k=1;k<=T;k++){
		scanf("%d",&n);
		//memset(opt,0,sizeof(opt));
		int ans=-INF,l,r,t;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=n;i>=1;i--){
			opt[i]=max(opt[i+1]+a[i],0);
			if(opt[i]>=ans){
				ans=opt[i];l=i;
			}
		}
		r=l-1;t=0;
		while(t!=ans){
			t+=a[++r];
		}
		printf("Case %d:\n%d %d %d\n\n",k,ans,l,r);
	}
	return 0;
}
*/
