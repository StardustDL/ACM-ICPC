/*
[HNOI2008]神奇的国度
分析：所有的人构成的关系图是一个弦图（长度超过 3 的环中必有一条弦），求出它的完美性消除序列，根据完美消除序列逆序贪心的染色，最终所用的色数就是本题的答案
	  完美消除序列：所有点的一个排列，使得vi在{vi..n}产生的诱导子图中是一个单纯点（单纯点：{v}与v相邻的点，构成一个团）。 
	  求完美消除序列的 MCS 法是倒着解的，也就是先求序列的第 n 个再求序列的第 n-1 个
		每次选取图中具有最大标号的点作为完美消除序列中对应位置的点，并用这个点更新所有和他邻接的不在序列中的点的标号值
		对于一个弦图的染色，用完美消除序列可以很好的解决，按照完美消除序列中的点倒着给图中的点贪心的然尽可能小的颜色
		最终，一定能够用最小的颜色数量给图中的所有点染色
	  O(n+m):
	  	维护每个点的标号，维护标号0,1,2,...的链表，维护最大标号值
		初始时每个点势为0，都放在0号链表里。best=0。
		①更新操作：某结点u的势从x变为x+1时，只要把u插到x+1链表的头部，无需将其从x链表中删除（所以不用写双向链表）。然后更新best值。
		②取最大操作：取最大势结点时从best链表的头开始取，如果取到的是已被放入序列的结点就删除并继续往后取，仍取不到则--best，直到取到一个未被放入序列的点。
		操作①每次O(1)，总共执行O(m)次。best++也被执行O(m)次，那么操作②中--best也只有O(m)次。操作①每次插一个结点，则总共有O(n+m)个结点，而操作②中每往后取一个就删一个，所以也是O(n+m)。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue> 
#include<vector>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
vector<int> g[MAXN+3];
vector<int> sta[MAXN+3];
int head[MAXN+3];
bool vis[MAXN+3];
int top,v[MAXN+3];
int n,m;
vector<int> ans;
int getmax(){
	while(1){
		if(head[top]==sta[top].size())top--;
		int x=sta[top][head[top]];
		if(vis[x])head[top]++;
		else return x;
	}
}
void calc(){
	for(int i=1;i<=n;i++){sta[0].push_back(i);v[i]=0;head[i]=0;}
	top=0;
	for(int i=1;i<=n;i++){
		int t=getmax();
		vis[t]=1;ans.push_back(t);
		for(int j=0;j<g[t].size();j++){
			if(vis[g[t][j]])continue;
			sta[++v[g[t][j]]].push_back(g[t][j]);
			top=max(top,v[g[t][j]]);
		}
	}
}
int col[MAXN+3],tmp[MAXN+3],Ans=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	calc();
	memset(tmp,-1,sizeof(tmp));
	for(int i=0,k;i<n;i++){
		for(int j=0;j<g[ans[i]].size();j++)tmp[col[g[ans[i]][j]]]=i;
		for(k=1;tmp[k]==i;k++);
		col[ans[i]]=k;Ans=max(k,Ans);
	}
	printf("%d\n",Ans);
	return 0;
}

