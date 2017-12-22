/*
花神的秒题计划Ⅰ
分析：记忆化搜索，大暴力——其中Q、S、B操作总和<=100; 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=700,INF=0x3f3f3f3f;
int n,m;
int mp[MAXN+3][MAXN+3];
int f[MAXN+3][MAXN+3];
bool mrk[MAXN+3][MAXN+3];
void protect(int a,int b,int x,int y,int v){
	for(int i=a;i<=x;i++)for(int j=b;j<=y;j++)mrk[i][j]=v;
}
#define work(a,b) if((x+a)>0&&(y+b)>0&&(x+a)<=n&&(y+b)<=n&&mp[x][y]>mp[x+a][y+b])f[x][y]=max(f[x][y],dp(x+a,y+b)+1)
int dp(int x,int y){
	if(mrk[x][y])return 0;
	if(f[x][y]!=-1)return f[x][y];
	f[x][y]=1;
	work(0,1);work(0,-1);work(1,0);work(-1,0);
	return f[x][y];
}
char ch[5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&mp[i][j]);
	scanf("%d",&m);
	int ans=0;
	for(int a,b,c,d;m;m--){
		scanf("%s",ch);
		switch(ch[0]){
			case 'Q':
				memset(f,-1,sizeof(f));
				ans=0;
				for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans=max(ans,dp(i,j));
				printf("%d\n",ans);
				break;
			case 'C':
				scanf("%d%d%d",&a,&b,&c);
				mp[a][b]=c;
				break;
			case 'S':
				scanf("%d%d%d%d",&a,&b,&c,&d);
				protect(a,b,c,d,1);
				break;
			case 'B':
				scanf("%d%d%d%d",&a,&b,&c,&d);
				protect(a,b,c,d,0);
				break;
		}
	}
	return 0;
}

