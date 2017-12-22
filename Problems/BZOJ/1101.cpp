/*
[POI2007]Zap
分析：练习数论写的第一题，小错误不断，
	  题目等价于x<=N/d，y<=M/d，互质的x，y的对数。
	  即sigma(x<=n',y<=m',e(gcd(x,y)))
	  将e用莫比乌斯函数展开：
	  e(gcd(x,y))=sigma(d|x&d|y,miu[d])
	  转换求和顺序：
	  sigma(d<=n',miu[d]*(n'/d)*(m'/d))
	  因为n'个数中，有n'/d个数满足t|n'，注意这里相当于是计算d的倍数二元组(x,y)的个数
	  只做到这里还不够，一次求解是O(n)的，需要注意： (n'/d)*(m'/d)最多有O(sqrt(n)) 个，
	  前缀和+分段枚举 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
int mindiv[MAXN+3],primes[MAXN+3],pcnt=0,miu[MAXN+3],a,b,d,n,sum[MAXN+3];
inline void init(int size){
	miu[1]=1;
	for(int i=2;i<=size;i++){
		if(mindiv[i]==0){mindiv[i]=i;miu[i]=-1;primes[++pcnt]=i;}
		for(int j=1,k;j<=pcnt&&(k=i*primes[j])<=size;j++){
			mindiv[k]=primes[j];
			if(mindiv[i]==primes[j]){miu[k]=0;break;}
			miu[k]=-miu[i];
		}
	}
	for(int i=1;i<=size;i++)sum[i]=sum[i-1]+miu[i];
}
int solve(int n,int m){
	if(n>m)swap(n,m);
	int ans=0,pos;
	for(int i=1;i<=n;i=pos+1){
		pos=min(n/(n/i),m/(m/i));//注意这里的求法 
		ans+=(sum[pos]-sum[i-1])*(n/i)*(m/i);
	}
	return ans;
}
int main(){
	init(50000);
	for(scanf("%d",&n);n;n--){
		scanf("%d%d%d",&a,&b,&d);
		printf("%d\n",solve(a/d,b/d));
	}
	return 0;
}

