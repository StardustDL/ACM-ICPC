/*
[SCOI2009]最长距离
分析：求出从每个点开始，到每个点的最少需要清除多少障碍物，然后用题目给的障碍判断是否可行，暴力计算所有点对即可 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
const int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
int mp[35][35],dist[35][35],n,m,T;
struct P{int x,y,d;P(int x,int y,int d):x(x),y(y),d(d){}bool operator <(const P &t)const{return d>t.d;}};
priority_queue<P> q;
#define d(u) (dist[(u).x][(u).y])
#define sqr(x) ((x)*(x))
void dijkstra(int sx,int sy){
	while(!q.empty())q.pop();
	memset(dist,INF,sizeof(dist));
	dist[sx][sy]=mp[sx][sy];
	q.push(P(sx,sy,dist[sx][sy]));
	while(!q.empty()){
		P u=q.top();q.pop();
		if(d(u)<u.d)continue;
		for(int i=0;i<4;i++){
			int tx=u.x+dx[i],ty=u.y+dy[i];
			if(tx<1||ty<1||tx>n||ty>m)continue;
			P t=P(tx,ty,0);
			if(d(t)>d(u)+mp[t.x][t.y]){
				d(t)=d(u)+mp[t.x][t.y];t.d=d(t);
				q.push(t);
			}
		}
	}
	
}
char str[35];
int main(){
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n;i++){
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)mp[i][j]=str[j]-'0';
	}
	//for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)cout<<mp[i][j]<<" ";cout<<endl;} 
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		dijkstra(i,j);//cout<<endl;
		for(int x=1;x<=n;x++)for(int y=1;y<=n;y++){
			if(dist[x][y]<=T){
				//if(ans<sqr(x-i)+sqr(y-j))cout<<i<<" "<<j<<endl<<x<<" "<<y<<endl; 
				ans=max(ans,sqr(x-i)+sqr(y-j));
			}
		}
	}
	printf("%.6lf",sqrt(ans*1.0));
	return 0;
}

