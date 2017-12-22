/*
Balanced Lineup
题意：一群牛，多次区间查询，问最高的和最矮的差。
分析：RMQ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000,MAXE=100;
int h[MAXN+3],mx[MAXN+3][MAXE+3],mn[MAXN+3][MAXE+3];
int N,Q,L,R;
void rmqinit(){
	for(int i=1;i<=N;i++)
		mx[i][0]=mn[i][0]=h[i];
	int end_j=log(N+0.0)/log(2.0),end_i;
	for(int j=1;j<=end_j;j++){
		end_i=N+1-(1<<j);
		for(int i=1;i<=end_i;i++){
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
		}
	}
}
int queryMax(int L,int R){
	int k=log(R-L+1.0)/log(2.0);
	return max(mx[L][k],mx[R-(1<<k)+1][k]);
}
int queryMin(int L,int R){
	int k=log(R-L+1.0)/log(2.0);
	return min(mn[L][k],mn[R-(1<<k)+1][k]);
}
int main(){
	while(scanf("%d%d",&N,&Q)!=EOF){
		for(int i=1;i<=N;i++)scanf("%d",&h[i]);
		rmqinit();
		for(int i=0;i<Q;i++){
			scanf("%d%d",&L,&R);
			printf("%d\n",queryMax(L,R)-queryMin(L,R));
		}
	}
	return 0;
}

