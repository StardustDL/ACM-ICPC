/*
[HNOI2004]打鼹鼠
分析：最长上升子序列 
	  f[i]=max(f[j]+1) (abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])
	  O(m^2)可以过数据 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
int n,m,t[MAXN+3],opt[MAXN+3],x[MAXN+3],y[MAXN+3]; 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&t[i],&x[i],&y[i]);
	fill(opt+1,opt+m+1,1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<i;j++)
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])opt[i]=max(opt[j]+1,opt[i]);
		opt[0]=max(opt[0],opt[i]);
	}
	printf("%d",opt[0]);
	return 0;
}

