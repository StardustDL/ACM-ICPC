/*
题意：给定一组不同长度的木棍,有可能加入他们的端到端形成一个正方形吗? 
分析：类似1011，是其减弱版。直接调用dfs判断sum/4是否可行即可 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=20;
int T,n,a[MAXN+3],sum;
bool vis[MAXN+3];
bool dfs(int* stick,bool* vist,int len,int InitLen,int s,int num){//len:当前正在组合的棒长  InitLen:目标棒长  s:stick[]的搜索起点  num:已用的棒子数量 
	if(num==n)return true;
	int sample=-1;
	for(int i=s;i<n;i++){
		if(vist[i] || stick[i]==sample)continue;//剪枝3,等长的木棒只搜索一次
		vist[i]=true;
		if(len+stick[i]<InitLen){
			if(dfs(stick,vist,len+stick[i],InitLen,i,num+1))return true;
			else sample=stick[i];//不要直接和i-1比较，有可能i-1并不合法（如已用） 
		}
		else if(len+stick[i]==InitLen){
			if(dfs(stick,vist,0,InitLen,0,num+1))return true;
			else sample=stick[i];
		}
		vist[i]=false;
		if(len==0)break;//剪枝4，构建新棒时，对于新棒的第一根棒子，在搜索完所有棒子后都无法组合，则说明该棒子无法在当前组合方式下组合，不用往下搜索(往下搜索会令该棒子被舍弃)，直接返回上一层 
	}
	return false;
}
bool cmp(int a,int b){return a>b;} 
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);sum=0;
		for(int i=0;i<n;i++){scanf("%d",&a[i]);sum+=a[i];}
		sort(a,a+n,cmp);
		memset(vis,0,sizeof(vis));
		if(sum%4==0&&dfs(a,vis,0,sum/4,0,0))puts("yes");
		else puts("no");
	}
	return 0;
}

