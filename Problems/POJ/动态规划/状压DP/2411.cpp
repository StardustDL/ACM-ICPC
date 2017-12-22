/*
Mondriaan's Dream
题意：用1*2的砖去恰好铺满n*m的空间，求方案数
分析：只有横着填和数竖着填两种，可以枚举两行状态，判断能否转移
	  但这样很浪费，dfs求能到达状态i的状态j,就不需要枚举所有状态j 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define INF 99999999
typedef long long LL;
using namespace std;
const int MAXN=(1<<11)+10;
int n,m;
LL temp[MAXN],cnt[MAXN];
bool check(int i){
	while(i){
		if(i&1){
			i>>=1;
			if(!(i&1))return false;//第i列是1则第i+1列必须是1 
			i>>=1;//继续判断下一列 
		}else i>>=1;//继续判断下一列 
	}
	return true;
}
void dfs(int k,int i,int j){//求出i能由那些状态转移到 
	if(k==m){cnt[i]+=temp[j];return;}
	if(k>m)return;
	if((i>>k)&1){
		dfs(k+1,i,j);
		if((i>>(k+1))&1)dfs(k+2,i,j|(1<<k)|(1<<(k+1)));
	}
	else dfs(k+1,i,j|(1<<k));
}
LL dp(){
	memset(temp,0,sizeof(temp));//初始化第一行
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<(1<<m);++i)if(check(i))cnt[i]=1;
	for(int k=2;k<=n;++k){
		memcpy(temp,cnt,sizeof(temp));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<(1<<m);++i)dfs(0,i,0);
	}
	return cnt[(1<<m)-1];
}
int main(){
	while(~scanf("%d%d",&n,&m),n+m){
		if(n<m)swap(n,m);//始终保持m<n,提高效率 
		printf("%lld\n",dp());//输出最后一行到达时的状态必须全部是1 
	}
	return 0;
}
