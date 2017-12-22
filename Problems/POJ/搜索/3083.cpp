/*
Children of the Candy Corn
题意：给一张方格图，求从起点一直向左走，一直向右走，和最短路
分析：定义方向，0(上),1(左),2(下),3(右)，先处理出每种转向的方式，然后DFS即可，此题综合考察DFS，BFS 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<queue> 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
const int dl[4][4]={{1,0,3,2},{2,1,0,3},{3,2,1,0},{0,3,2,1}};
const int dr[4][4]={{3,0,1,2},{0,1,2,3},{1,2,3,0},{2,3,0,1}};
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int stepl,stepr,n,m,sx,sy,tx,ty,direction;
bitset<MAXN+3> mp[MAXN+3];
inline bool checkpoint(int p,int q){
	return p>0&&q>0&&p<=n&&q<=m&&mp[p][q];
}
void dfsl(int x,int y,int d){
	stepl++;
	if(x==tx&&y==ty)return;
	for(int i=0;i<4;i++){
		int t=dl[d][i],p=x+dx[t],q=y+dy[t];
		if(checkpoint(p,q)){
			dfsl(p,q,t);
			return;
		}
	}
}
void dfsr(int x,int y,int d){
	stepr++;
	//cout<<x<<" "<<y<<" "<<d<<endl;
	//cin>>direction;
	if(x==tx&&y==ty)return;
	for(int i=0;i<4;i++){
		int t=dr[d][i],p=x+dx[t],q=y+dy[t];
		if(checkpoint(p,q)){
			dfsr(p,q,t);
			return;
		}
	}
}
struct point{
	int x,y,d;
	point(int x,int y,int d):x(x),y(y),d(d){};
};
queue<point>q; 
int bfs(int x,int y){
	while(!q.empty())q.pop();
	q.push(point(x,y,1));
	while(!q.empty()){
		point t=q.front();q.pop();
		if(t.x==tx&&t.y==ty)return t.d;
		mp[t.x][t.y]=0;
		for(int i=0;i<4;i++){
			int px=t.x+dx[i],py=t.y+dy[i];
			if(checkpoint(px,py)){
				mp[px][py]=0;
				q.push(point(px,py,t.d+1));
			}
		}
	}
}
void input(){
	scanf("%d%d",&m,&n);
	char c;
	for(int i=1;i<=n;i++){
		scanf("\n");
		for(int j=1;j<=m;j++){
			scanf("%c",&c);
			switch(c){
				case '#':mp[i][j]=0;break;
				case '.':mp[i][j]=1;break;
				case 'S':mp[i][j]=1;sx=i;sy=j;
					if(i==n)  
                        direction=0;  
                    else if(j==m)  
                        direction=1;  
                    else if(i==1)  
                        direction=2;  
                    else if(j==1)  
                        direction=3;break;
				case 'E':mp[i][j]=1;tx=i;ty=j;break;
			}
		}
	}
	stepl=stepr=0;
}
int main(){
	int T=0;
	scanf("%d",&T);
	while(T--){
		input();
		//cout<<direction<<endl;
		dfsl(sx,sy,direction);
		//cout<<"！！！"<<endl; 
		dfsr(sx,sy,direction);
		printf("%d %d %d\n",stepl,stepr,bfs(sx,sy));
	}
	return 0;
}

