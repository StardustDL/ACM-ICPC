/*
[HEOI2015]������ӣ��
������̰�ģ�����һ���ڵ㣬��������ӽڵ�󣬽��䰴��С��������һ����ѡС�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=2000000;
vector<int> g[MAXN+3];
int val[MAXN+3],n,m,ans=0;
struct cmp{
	bool operator ()(const int a,const int b)const{return val[a]>val[b];}
};
priority_queue<int,vector<int>,cmp> pq;
void dfs(int x){
	for(int i=0;i<g[x].size();i++)dfs(g[x][i]);
	for(int i=0;i<g[x].size();i++)pq.push(g[x][i]);//ע�����Ҫ������ͳһpush 
	while(!pq.empty()){
		int v=pq.top();pq.pop();
		if(val[x]+val[v]-1<=m)val[x]+=val[v]-1,ans++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	for(int i=1;i<=n;i++){
		int k,b;scanf("%d",&k);
		while(k--){
			scanf("%d",&b);
			g[i].push_back(++b);
			val[i]++;
		}
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}

