/*
[SDOI2012]Longge的问题
分析：sigma(gcd(i,n))
	  =sigma(sigma(d|i&d|n,phi(d)))
	  =sigma(d|n,phi(d)*(n/d)) 
	  注意phi要用质因数分解的方法求（n太大） 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=1000,INF=0x3f3f3f3f;
LL phi(LL x){
	LL ans=x,m=(LL)sqrt(x);
	for(LL i=2;i<=m;i++){
		if(x%i!=0)continue;
		ans=ans/i*(i-1);
		while(x%i==0)x/=i;
	}
	if(x>1)ans=ans/x*(x-1);//注意这里，有可能会剩下一个质因子 
	return ans;
}
LL solve(LL n){
	LL ans=0,m=(LL)sqrt(n);
	for(LL i=1;i<=m;i++){
		if(n%i!=0)continue;
		ans+=(LL)(n/i)*phi(i);
		if(i*i<=n)ans+=(LL)i*phi(n/i);//讨论另一种情况 
	}
	return ans;
}
int main(){
	LL n;scanf("%lld",&n);
	printf("%lld\n",solve(n)); 
	return 0;
}

