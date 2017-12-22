/*
题意：给定一个网格图，每次从左上角出发，只能往右或往下走，最后到达右下角，每个格子有最低经过次数，问最少走几次 
分析：Dilworth定理：DAG的最小链覆盖=最大点独立集 
		最小链覆盖指选出最少的链(可以重复)使得每个点都在至少一条链中 
		最大点独立集指最大的集合使集合中任意两点不可达 
		此题中最大点独立集显然是一个集合满足集合中任意两点都是左下-右上的关系 
		DP一遍就能出解 复杂度O(Tmn) 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
int a[1005][1005];
long long f[1005][1005];
int main(){
	for(int T=read();T;T--){
		n=read();m=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)a[i][j]=read();
		for(int i=1;i<=n;i++)
			for(int j=m;j;j--)
				f[i][j]=max(f[i-1][j+1]+a[i][j],max(f[i-1][j],f[i][j+1]));
		printf("%lld\n",f[n][1]);
	}
	return 0;
}
