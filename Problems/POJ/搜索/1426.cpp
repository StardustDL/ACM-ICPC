/*
Find The Multiple
题意：给你一个数n，让你找到一个它的倍数只由1和0组成。 
分析：从小到大暴力试，注意选一个上界 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef long long LL;
bool flg;
int n; 
void dfs(LL p,int dep){
	if(dep==20||flg)return;//深度为20就停止（估计） 
	if(p%n==0){
		printf("%lld\n",p);
		flg=true;return;
	}
	dfs(p*10,dep+1); 
	dfs(p*10+1,dep+1);
} 
int main(){
	while(scanf("%d",&n),n){
		flg=false;
		dfs(1,1);
	}
	return 0;
}

