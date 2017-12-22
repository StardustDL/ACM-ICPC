/*
http://blog.csdn.net/popoqqq/article/details/46820313
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
const LL MOD=998244353LL;
LL n,m;
LL phi(LL x){
	LL ans=x,t=sqrt(x*1.0);
	for(LL i=2;i<=t;i++){
		if(x%i==0){
			ans=ans/i*(i-1);
			while(x%i==0)x/=i;
		}
	}
	if(x!=1)ans=ans/x*(x-1);
	return ans%MOD;
}
int main(){
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",phi(n)*phi(m)%MOD*(n%MOD)%MOD*(m%MOD)%MOD);//n,m need to mod
	return 0;
}

