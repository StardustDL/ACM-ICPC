/*
Best Cow Fences
题意：给你n个数，要你在这n个数里面找到一些连续的数，这些数的数量大于等于m，并且他们的平均值在这n个数里面是最大的
分析：先把n个数的最大最小值确定，然后二分枚举平均值，对于每一个连续数，只要他们减去平均值大于0，就调制上限制，不然调整下限制，
	  似乎还可以DP，和类似斜率优化的思想 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
const double eps=1e-6;
double a[MAXN+3],s[MAXN+3];
int n,m;
bool check(double val){
	double t=s[m-1]-val*(m-1);
	for(int i=m;i<=n;i++){
		t=max(t+a[i]-val,s[i]-s[i-m]-val*m);
		if(t>-eps)return true;
	}
	return false;
}
double ef(double l,double r){
	double mid=0;
	while(r-l>eps){
		mid=(l+r)/2.0;
		if(check(mid))l=mid;
		else r=mid;
	}
	return r;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]),s[i]=s[i-1]+a[i];
	printf("%d\n",(int)(ef(*min_element(a+1,a+n+1),*max_element(a+1,a+n+1))*1000));
	return 0;
}

