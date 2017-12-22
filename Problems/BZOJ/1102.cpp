/*
[POI2007]山峰和山谷Grz
分析：BFS即可，注意这道题加输入优化可以提高800ms，可以说是很大的提升 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
const int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
int qx[MAXN*MAXN],qy[MAXN*MAXN+3],head,tail;
int n,h[MAXN+3][MAXN+3];
bool vis[MAXN+3][MAXN+3];
int curh,mx,mn;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void clear(){head=1;tail=0;}
inline void push(int x,int y){++tail;qx[tail]=x;qy[tail]=y;}
inline void pop(){++head;}
void bfs(int x,int y){
	clear();
	mx=mn=curh=h[x][y];
	push(x,y);
	while(head<=tail){
		int px=qx[head],py=qy[head];pop();
		for(int i=0;i<8;i++){
			int tx=px+dx[i],ty=py+dy[i];
			if(tx<1||ty<1||tx>n||ty>n)continue;
			mn=min(mn,h[tx][ty]);
			mx=max(mx,h[tx][ty]);
			if(h[tx][ty]==curh&&!vis[tx][ty]){
				vis[tx][ty]=1;
				push(tx,ty);
			}
		}
	}
}
int main(){
	n=read();
	//scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			h[i][j]=read();
			//scanf("%d",&h[i][j]);
		}
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!vis[i][j]){
				bfs(i,j);
				if(mn<=curh&&mx<=curh)ans1++;
				if(mn>=curh&&mx>=curh)ans2++;
			}
		}
	}
	printf("%d %d",ans1,ans2);
	return 0;
}

