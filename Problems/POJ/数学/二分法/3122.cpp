/*
Pie
题意：生日，买了n个pie，找来f个朋友，那么总人数共f+1人
	  每个pie都是高为1的圆柱体，输入这n个pie的每一个尺寸（半径），如果要公平地把pie分给每一个人（就是所有人得到的pie尺寸一致，但是形状可以不同），而且每个人得到的那份pie必须是从同一个pie上得到的
分析：二分答案，注意精度，这道题精度要求高 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
const double PI=3.14159265359;
double p[MAXN+3];
int n,f,T;
inline bool check(double val){
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=(int)(p[i]/val);
	return cnt>=f;
}
inline double erfen(double l,double r,double eps){
	double mid,ans=l;
	while(r-l>eps){
		mid=(l+r)/2.0;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	return ans;
}
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d%d",&n,&f);f++;
		for(int i=1,r;i<=n;i++){
			scanf("%d",&r);
			p[i]=r*r;
		}
		printf("%.4lf\n",erfen(0,*max_element(p+1,p+n+1),1e-6)*PI); 
	}
	return 0;
}

