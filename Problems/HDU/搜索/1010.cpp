/*
Tempter of the Bone
题意：网格图，要恰好t时间到达T，并不是在t时间内到达 
分析：DFS+可行性判断
	  可行性判断：当剩下的步数大于剩下的时间的时候，狗是不能走到的；
	  	对图01染色，发现从0走一步一定走到1，从1走一步一定走到0。
		如果当前的狗所在的坐标与D的坐标奇偶性不一样，那么狗需要走奇数步。
		同理，如果狗所在坐标与D的坐标奇偶性一样，那么狗需要走偶数步数。
	  保证这个奇偶性相同 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,t,sx,sy,tx,ty;
int mp[MAXN+3][MAXN+3];
bool vis[MAXN+3][MAXN+3];
bool input(){
	scanf("%d%d%d",&n,&m,&t);
	if(n+m+t==0)return false;
	char c;
	for(int i=1;i<=n;i++){
		scanf("\n");
		for(int j=1;j<=m;j++){
			scanf("%c",&c);
			switch(c){
				case 'S':mp[i][j]=2;sx=i,sy=j;break;
				case 'D':mp[i][j]=3;tx=i,ty=j;break;
				case 'X':mp[i][j]=0;break;
				case '.':mp[i][j]=1;break;
			}
		}
	}
	return true;
}
bool dfs(int x,int y,int ct){
	if(mp[x][y]==3&&ct==t)return true;
	if(ct>=t)return false;
	if(abs(tx-x)+abs(ty-y)>t-ct)return false;
	for(int i=0;i<4;i++){
		int p=x+dx[i],q=y+dy[i];
		if(p>0&&q>0&&p<=n&&q<=m&&mp[p][q]!=0&&vis[p][q]==0){
			vis[p][q]=1;
			if(dfs(p,q,ct+1)){
				vis[p][q]=0;
				return true;
			}
			vis[p][q]=0;
		}
	}
	return false;
}
int main(){
	while(input()){
		if(abs(tx-sx)+abs(ty-sy)>t||(tx+sx+ty+sy+t)%2==1){puts("NO");continue;}
        memset(vis,0,sizeof(vis));
        vis[sx][sy]=1;//注意这里，WA*2 
		if(dfs(sx,sy,0))puts("YES");
		else puts("NO");
	}
	return 0;
}

