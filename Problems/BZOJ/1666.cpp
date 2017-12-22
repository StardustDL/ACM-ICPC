/*
[Usaco2006 Oct]Another Cow Number Game 奶牛的数字游戏
分析：直接做，加个记忆化反而更慢 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
typedef long long LL;
int mem[MAXN+3];
int solve(LL x){//8ms
	if(x==1)return 1;
	if(x<=MAXN&&mem[x])return mem[x];
	int ans=0;
	if(x&1)ans=solve(x*3LL+1LL)+1;
	else ans=solve(x>>1)+1;
	if(x<=MAXN)mem[x]=ans;
	return ans;
}
int getans(LL x){//0ms
	int ans=0;
	while(x!=1){
		if(x&1)x=x*3LL+1LL;
		else x=x>>1;
		ans++;
	}
	return ans;
}
int main(){
	int n;scanf("%d",&n);
	printf("%d\n",getans(n));
	return 0;
}

