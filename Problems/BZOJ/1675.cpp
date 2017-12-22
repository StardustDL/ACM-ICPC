/*
[Usaco2005 Feb]Rigging the Bovine Election ¾ºÑ¡»®Çø
*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int n,ans;
char mp[15][15];
bool mark[15][15],b[15][15];
void dfs(int x,int y){
	b[x][y]=0;
	for(int k=0;k<4;k++){
		int nx=x+dx[k],ny=y+dy[k];
		if(b[nx][ny])dfs(nx,ny);
	}
}
bool cal(){
	for(int i=1;i<=5;i++)for(int j=1;j<=5;j++)b[i][j]=mark[i][j];
	bool flag=0;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5&&(!flag);j++)
			if(b[i][j]&&!flag){
				dfs(i,j);
				flag=1;break;
			}
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			if(b[i][j])return 0;
	return 1;
}
void dfs(int x,int y,int a,int b){
	if(a+b==7){
		if(a>b)ans+=cal();
		return;
	}
	if(y==6)x++,y=1;
	if(x==6)return;
	mark[x][y]=1;
	if(mp[x][y]=='J')dfs(x,y+1,a+1,b);
	else dfs(x,y+1,a,b+1);
	mark[x][y]=0;
	dfs(x,y+1,a,b);
}
int main(){
	for(int i=1;i<=5;i++)scanf("%s",mp[i]+1);
	dfs(1,1,0,0);
	printf("%d\n",ans);
	return 0;
}
