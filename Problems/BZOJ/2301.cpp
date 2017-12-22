/*
[HAOI2011]Problem b
分析：这道题是ZAP(bzoj1101)的强化版，用一下容斥原理，利用原来的求解方式即可
	  注意取值含a,b,c,d，所以容斥时要(a-1)/k,(c-1)/k 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
int mindiv[MAXN+3],primes[MAXN+3],pcnt=0,miu[MAXN+3],sum[MAXN+3];
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
int calc(int a,int b,int c,int d,int k){
	int ans=solve(b/k,d/k);
	ans-=solve((a-1)/k,d/k);
	ans-=solve(b/k,(c-1)/k);
	ans+=solve((a-1)/k,(c-1)/k);
	return ans;
}
int n,a,b,c,d,k;
int main(){
	init(50000);
	for(scanf("%d",&n);n;n--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		printf("%d\n",calc(a,b,c,d,k));
	}
	return 0;
}

