/*
[Usaco2005 oct]Skiing 奶牛滑雪
分析：注意这个速度的定义，其实保证了到每个点的速度是一定的。跑最短路即可 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN=100+5,INF=0x3f3f3f3f;
bool vis[MAXN+3][MAXN+3];
int h[MAXN+3][MAXN+3],V,r,c;
double d[MAXN+3][MAXN+3],v[MAXN+3][MAXN+3];
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct P{
	int x,y;double l;
	P(int x,int y,double l):x(x),y(y),l(l){}
	bool operator <(const P &t)const {
		return l>t.l;
	}
};
double calc(int t){
	double ans=1;
	if(t>0)while(t--)ans=ans/2.0;
	else if(t<0)while(t++)ans=ans*2.0;
	return ans;
}
priority_queue<P>q;
int main(){
	scanf("%d%d%d",&V,&r,&c);
	double v2=1.0/V;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			scanf("%d",&h[i][j]);d[i][j]=1e60;v[i][j]=v2*calc(h[1][1]-h[i][j]);
		}
	}
	q.push(P(1,1,0));d[1][1]=0;
	while(!q.empty()){
		P t=q.top();q.pop();
		if(vis[t.x][t.y])continue;
		vis[t.x][t.y]=1;double l=d[t.x][t.y]+v[t.x][t.y];
		for(int i=0;i<4;i++){
			int tx=t.x+dx[i],ty=t.y+dy[i];
			if(tx<0||ty<0||tx>r||ty>c||vis[tx][ty])continue;
			if(d[tx][ty]>l){d[tx][ty]=l;q.push(P(tx,ty,d[tx][ty]));}
		}
		if(vis[r][c])break;
	}
	printf("%.2lf\n",d[r][c]);
	return 0;
}

