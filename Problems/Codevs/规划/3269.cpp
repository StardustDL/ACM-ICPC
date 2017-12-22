/*
单调队列优化多重背包 
*/ 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXV=200000;
typedef long long LL;
int que[MAXV+3],opt[MAXV+3],n,V,g[MAXV+3];
void solve(int v,int w,int m){
	int t=v*m;
	for(int i=0;i<v;i++){
		int l=1,r=0;
		for(int j=i;j<=V;j+=v){
			int k=j/v*w;
			while(l<=r&&g[r]<opt[j]-k)r--;
			que[++r]=j;
			g[r]=opt[j]-k;
			while(que[l]<j-t)l++;
			opt[j]=g[l]+k;
		}
	}
}
int main(){
	scanf("%d%d",&n,&V);
	/*int v,w,m;
	while(n--){
		scanf("%d%d%d",&v,&w,&m);
		if(m==-1)m=V/v;
		solve(v,w,m);
	}*/
	int v[203],w[203],m[203];
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&v[i],&w[i],&m[i]);
		if(m[i]==-1)m[i]=V/v[i];
	}
	for(int i=1;i<=n;i++)solve(v[i],w[i],m[i]);
	printf("%d",opt[V]);
	return 0;
}

