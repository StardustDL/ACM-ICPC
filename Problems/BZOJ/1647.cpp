/*
[Usaco2007 Open]Fliptile 翻格子游戏
分析：枚举第一行每个格子按或不按，这样后面行的操作就唯一了（因为要使全部为0） 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m,mn=INF;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
bool a[16][16],t[16][16],op[16][16],ans[16][16];
void rev(int x,int y){
	op[x][y]=1;t[x][y]^=1;
	for(int k=0;k<4;k++){
		int tx=x+dx[k],ty=y+dy[k];
		if(tx<1||ty<1||tx>n||ty>m)continue;
		t[tx][ty]^=1;
	}
}
void solve(int x){
	memset(op,0,sizeof(op));
	int tot=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)t[i][j]=a[i][j];
	for(int i=1;i<=m;i++)
		if((1<<(i-1))&x){
			tot++;if(tot>=mn)return;
			rev(1,i);
		}
	for(int i=2;i<=n;i++)
	    for(int j=1;j<=m;j++){
			if(t[i-1][j]){
				tot++;if(tot>=mn)return;
				rev(i,j);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(t[i][j])return;
	mn=tot;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans[i][j]=op[i][j];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<=(1<<m)-1;i++)solve(i);
	if(mn!=INF){
		for(int i=1;i<=n;i++){
			for(int j=1;j<m;j++)
				printf("%d ",ans[i][j]);
			printf("%d\n",ans[i][m]);
		}
	}
	else puts("IMPOSSIBLE");
	return 0;
}
