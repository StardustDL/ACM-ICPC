/*
守卫者的挑战 
分析：概率DP，opt[i][j][k]表示前i次挑战，成功j次，剩余容量为j的概率 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200,pos=200;
double opt[MAXN+3][MAXN+3][MAXN*2+3],p[MAXN+3];
int a[MAXN+3],n,l,k,mn,mx;
void input(){
	scanf("%d%d%d",&n,&l,&k);
	k=min(k,n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&p[i]);
		p[i]/=100;
	}
	for(int j=1;j<=n;j++)scanf("%d",&a[j]);
}
double dp(){
	mn=mx=k+pos;
	opt[0][0][k+pos]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int t=mn;t<=mx;t++){
				if(opt[i][j][t]==0)continue;//如果可能性为0，则不转移，这里只影响mx,mn的取值 
				opt[i+1][j+1][min(t+a[i+1],n+pos)]+=opt[i][j][t]*p[i+1];//成功 
				opt[i+1][j][t]+=opt[i][j][t]*(1-p[i+1]);//失败 
				mx=max(mx,min(t+a[i+1],n+pos));
				mn=min(mn,t+a[i+1]);
			}
		}
	}
	double ans=0;
	for(int i=l;i<=n;i++)
		for(int j=pos;j<=mx;j++)
			ans+=opt[n][i][j];
	return ans;
}
int main(){
	input();
	printf("%.6lf",dp());
	return 0;
}

