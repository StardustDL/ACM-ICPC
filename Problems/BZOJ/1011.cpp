/*
[HNOI2008]遥远的行星
分析：对于小的i暴力算，对于大的i，分母的变化可以忽略，全当成分母中间值 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
const int MAXN=100000,INF=0x3f3f3f3f;
const LL SIZE=500;
LL m[MAXN+3],sum[MAXN+3],n;
double ans[MAXN+3],a;
int main(){
	scanf("%lld%lf",&n,&a);
	for(int i=1;i<=n;i++){scanf("%lld",&m[i]);sum[i]=sum[i-1]+m[i];}
	for(int i=1;i<=min(n,SIZE);i++){
		int l=floor(i*a);
		for(int j=1;j<=l;j++){
			ans[i]+=m[j]*1.0/((i-j)*1.0);
		}
		ans[i]*=m[i];
	}
	for(int i=SIZE+1;i<=n;i++){
		int l=floor(i*a);
		ans[i]=m[i]*1.0*sum[l]/(((i-1)+(i-l))/2.0);
	}
	for(int i=1;i<=n;i++)printf("%lf\n",ans[i]);
	return 0;
}

