/*
Piggy-Bank
题意：给你一个储蓄罐空的，和满的重量，然后给出各种硬币的价值和对应的重量，要你估计出储蓄罐里面硬币价值和最小为多少，注意要保证重量和恰好为给出满的重量
分析：完全背包，注意要装满 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=500,MAXV=10000;
int V,v,w,opt[MAXV+3],T,n; 
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d%d%d",&w,&V,&n);V-=w;
		memset(opt,INF,sizeof(opt));opt[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&w,&v);
			for(int j=v;j<=V;j++)
				if(opt[j-v]!=INF)opt[j]=min(opt[j],opt[j-v]+w);
		}
		if(opt[V]==INF)puts("This is impossible.");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",opt[V]);
	}
	return 0;
}

