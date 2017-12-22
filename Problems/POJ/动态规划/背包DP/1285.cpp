/*
Combinations, Once Again
题意：给n个数，和一些r，求出在这n个数中取r个能取出的不同方案有多少个 
分析：将选择的数目看成背包的空间，枚举放入某类数的个数，空间增加为当前枚举的个数，dp[j+x]+=dp[j](j为枚举的当前背包容量，x为枚举的当前某个类的个数)
		这个方法不太会证明 
	  另一种方法：
	  	b[i][j]表示从第i个元素开始（包括i）中抽取j个数的不同的种类数
		则b[i][j]=b[i+1][j-1]+b[x][j]
		b[i+1][j-1]:代表将第i个数取出，那么剩下的就是求从i+1个元素开始取j-1个数的不同种类数
		b[x][j]：代表第i个数没有取，因为数组中有数重复，而且数组又是排过序的，则x代表的是从第i个元素之后不等于第i个元素的第一个数 
		注意用long long 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=50;
typedef long long LL; 
int c[MAXN+3],a[MAXN+3],n,r,m,u,T=0;
LL cnt[MAXN+3];
int main(){
	while(scanf("%d%d",&n,&m),n+m){
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);u=0;
		for(int i=1;i<=n;i++)if(a[i]!=a[i-1])c[++u]=1;else c[u]++;
		memset(cnt,0,sizeof(cnt));cnt[0]=1;
		for(int i=1;i<=u;i++)
			for(int j=n;j>=0;j--)
				for(int k=1;k<=c[i]&&j+k<=n;k++)cnt[j+k]+=cnt[j];
		printf("Case %d:\n",++T);
		for(int x;m;m--){
			scanf("%d",&x);
			printf("%lld\n",cnt[x]);
		}
	}
	return 0;
}

