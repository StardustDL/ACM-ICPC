/*
[Usaco2007 Dec]´©Ô½ÄàµØ
·ÖÎö£ºBFS 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int R=505;
struct point{
	int x,y,v;
	point(int x,int y,int v):x(x),y(y),v(v){}
};
queue<point> q;
int mp[2*R+3][2*R+3],x,y,n;
const int dx[4]={0,0,1,-1},dy[4]={-1,1,0,0};
int bfs(int x,int y,int tox,int toy){
	while(!q.empty())q.pop();
	q.push(point(x,y,0));
	mp[x][y]=0;
	while(!q.empty()){
		point u=q.front();q.pop();
		for(int i=0;i<4;i++){
			int nx=u.x+dx[i],ny=u.y+dy[i];
			if(mp[nx][ny]!=-1)continue;
			mp[nx][ny]=u.v+1;
			if(nx==tox&&ny==toy)return mp[nx][ny];
			q.push(point(nx,ny,u.v+1));
		}
	}
}
int main(){
	scanf("%d%d%d",&x,&y,&n);x+=R;y+=R;
	memset(mp,-1,sizeof(mp));
	for(int i=1,a,b;i<=n;i++){
		scanf("%d%d",&a,&b);
		mp[R+a][R+b]=-2;
	}
	printf("%d\n",bfs(R,R,x,y));
	return 0;
}

