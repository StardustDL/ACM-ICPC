/*
[Usaco2008 Nov]Guarding the Farm 保卫牧场
分析：坑人的题目描述，中文数据范围是错的，另外，邻接有八个点，相等也可以继续dfs- -，不是严格小于 
		 从大到小，每个点dfs，只能走<=自己的 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int dx[8]={0,0,1,-1,-1,-1,1,1},dy[8]={1,-1,0,0,1,-1,1,-1};
struct P{
	int x,y,h;
	bool operator <(const P &t)const{
		return h<t.h;
	}
}ps[700*700+3];
int tot=0,n,m,h[700+3][700+3],id[700+3][700+3],cnt=0;
void dfs(int x,int y){
	for(int i=0;i<8;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx<1||ty<1||tx>n||ty>m||id[tx][ty]||h[tx][ty]>h[x][y])continue;
		id[tx][ty]=cnt;
		dfs(tx,ty);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&h[i][j]);
			ps[++tot].h=h[i][j];ps[tot].x=i;ps[tot].y=j;
		}
	}
	sort(ps+1,ps+tot+1);
	for(int i=tot;i>=1;i--){
		if(id[ps[i].x][ps[i].y])continue;
		//cout<<ps[i].x<<" "<<ps[i].y<<endl;
		cnt++;
		dfs(ps[i].x,ps[i].y);
	}
	printf("%d\n",cnt);
	return 0;
}

