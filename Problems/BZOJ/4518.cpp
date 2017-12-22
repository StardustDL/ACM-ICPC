/*
[Sdoi2016]征途
分析：感觉是*m，而不是*m^2
		ans=m*sigma{xi^2}+m*sum^2-2m*sum^2
		最小化 sigma{xi^2}
		DP+斜率优化 j<k 且k优于j：((dp[j]+sum[j]^2)-(dp[k]+sum[k]^2))/sum[j]-sum[k]<2s[i]
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=3000,INF=0x3f3f3f3f;
#define sqr(x) ((x)*(x)) 
typedef long long LL;
struct data{
	LL x,y;
	data(LL x,LL y):x(x),y(y){}
	data(){}
};
LL dp[MAXN+3],s[MAXN+3];
data q[MAXN+3];
int h,t,n,m;
double calc(data &a,data &b){
	return (a.y-b.y)*1.0/(a.x-b.x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%lld",&s[i]);s[i]+=s[i-1];}
	for(int i=1;i<=n;i++)dp[i]=sqr(s[i]);
	for(int i=2;i<=m;i++){
		h=0,t=0;
		for(int j=1;j<=n;j++){
			data c=data(s[j],dp[j]+sqr(s[j]));
			while(h<t-1 && calc(c,q[t-1])<calc(q[t-1],q[t-2]))t--;
			q[t++]=c;
			while(h<t-1 && calc(q[h],q[h+1])<2*s[j])h++;
			dp[j]=sqr(s[j])+q[h].y-2*q[h].x*s[j];
		}
	}
	printf("%lld\n",(dp[n]*m-sqr(s[n])));
	return 0;
}
