/*
[Usaco2008 Mar]Cow Travelling游荡的奶牛
分析：DP，f[i][j][k]表示第i秒到达(j,k)的方案 
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,t,k,f[16][101][101];
const int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
int fx,fy,ex,ey;
bool mp[101][101];
char ch[101];
int main(){
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++){
		scanf("%s",ch);
		for(int j=1;j<=m;j++)if(ch[j-1]=='.')mp[i][j]=1;
	}
	scanf("%d%d%d%d",&fx,&fy,&ex,&ey);
	f[0][fx][fy]=1;
	for(int i=1;i<=t;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				if(mp[j][k])
	    			for(int l=0;l<4;l++){
	        			int nowx=j+dx[l],nowy=k+dy[l];
						if(nowx<1||nowy<1||nowx>n||nowy>m||!mp[nowx][nowy])continue;	
	        			f[i][j][k]+=f[i-1][nowx][nowy];
					}
	printf("%d",f[t][ex][ey]);      
	return 0;
}

