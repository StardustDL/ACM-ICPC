/*
isn
分析：设f[i]表示长度为i的不下降子序列的个数。得到一个长度为i的序列的方法就有f[i]*(n-i)!（被删除元素的全排列） 
		考虑容斥，对于长度为i的子序列，如果操作不合法，那么之前一定是一个长度为i+1的子序列
		所以Ans=sigma{1<=i<=n|f[i]*(n-i)!-f[i+1]*(n-(i+1))!*(i+1)[这是最后一位的删除位置]} 
		时间复杂度O(n^2logn)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f,MOD=1000000007;
int n,a[MAXN+3],b[MAXN+3],f[MAXN+3],bit[MAXN+3][MAXN+3];//bit[i][j]维护子序列长度为i的最后一位为j的子序列数的树状数组 
int fac[MAXN+3]; 
#define lowbit(x) ((x)&-(x))
void add(int l,int x,int ad){
	for(;x<=n;x+=lowbit(x))(bit[l][x]+=ad)%=MOD;//注意这里也要取模 
}
int sum(int l,int x){
	int ans=0;
	for(;x;x-=lowbit(x))(ans+=bit[l][x])%=MOD;
	return ans;
}
int main(){
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1;i<=n;i++){scanf("%d",&a[i]),b[i]=a[i];fac[i]=(1LL*fac[i-1]*i)%MOD;}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	add(0,1,1);
	for(int i=1;i<=n;i++){//枚举最后一位，求以a[i]结尾的长度分别为[1..i]的子序列的数量 
		for(int j=i;j;j--){
			int t=sum(j-1,a[i]);
			f[j]=(f[j]+t)%MOD;
			add(j,a[i],t);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+1LL*f[i]*fac[n-i]%MOD)%MOD;
		if(i<n)ans=(ans-1LL*f[i+1]*fac[n-(i+1)]%MOD*(i+1)%MOD+MOD)%MOD; 
	}
	printf("%d\n",ans);
	return 0;
}

