/*
[Usaco2008 Feb]Meteor Shower流星雨
分析：处理好每个位置坏掉的时间，BFS，注意有可能起点一开始就是坏的QAQ 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue> 
using namespace std;
const int MAXN=400,INF=0x3f3f3f3f;
int mp[MAXN+3][MAXN+3];
int vis[MAXN+3][MAXN+3];
typedef pair<int,int> pi;
queue<pi> q;
#define get(s,p) s[p.first][p.second]
#define go(p,i,j) tmp=make_pair(p.first+i,p.second+j);if(check(tmp,tme+1)){q.push(tmp);get(vis,tmp)=tme+1;}
inline bool check(pi p,int t){
	return p.first>=0&&p.second>=0&&get(mp,p)>t&&get(vis,p)==-1;
}
int bfs(pi s){
	while(!q.empty())q.pop();
	memset(vis,-1,sizeof(vis));
	int ans=-1;
	if(check(s,0))q.push(s);
	get(vis,s)=0;
	pi tmp;
	while(!q.empty()){
		pi t=q.front();q.pop();int tme=get(vis,t);
		if(get(mp,t)==INF){
			ans=get(vis,t);
			break;
		}
		go(t,1,0);
		go(t,-1,0);
		go(t,0,1);
		go(t,0,-1);
	}
	return ans;
}
int m;
int main(){
	scanf("%d",&m);
	memset(mp,INF,sizeof(mp));
	for(int i=1,x,y,t;i<=m;i++){
		scanf("%d%d%d",&x,&y,&t);
		mp[x][y]=min(mp[x][y],t);
		mp[x+1][y]=min(mp[x+1][y],t);
		if(x>0)mp[x-1][y]=min(mp[x-1][y],t);
		mp[x][y+1]=min(mp[x][y+1],t);
		if(y>0)mp[x][y-1]=min(mp[x][y-1],t);
	}
	printf("%d\n",bfs(make_pair(0,0)));
	return 0;
}

