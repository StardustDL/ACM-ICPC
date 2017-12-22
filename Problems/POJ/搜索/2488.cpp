/*
A Knight's Journey
题意：骑士游历，一张n*m棋盘，第1行1列用A1表示，2行1列用A2表示，问能否每个点只经过一次走完整张棋盘，输出字典序最小的走法
分析：DFS即可，注意输出时行列顺序相反，字典序最小：则一定要求从(1,1)点开始搜（只要有可行解一定经过(1,1)，就能转为(1,1)开始）
	  搜索顺序也要注意保持字典序最小，一个小技巧，记录每个点被访问的时间，这样方便最后生成答案 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=26;
const int dx[8]={-1,1,-2,2,-2,2,-1,1},dy[8]={-2,-2,-1,-1,1,1,2,2};//保持字典序 
int mp[MAXN+3][MAXN+3];
int n,m,ans[MAXN*MAXN+3],ans2[MAXN*MAXN+3];
void loadans(){
	for(int i=1;i<=n;i++){ 
		for(int j=1;j<=m;j++){ 
			ans[mp[i][j]]=char('A'-1+j);//小技巧 
			ans2[mp[i][j]]=i;
		}
	} 
}
bool dfs(int x,int y,int cnt){
	if(cnt==n*m)return true;
	for(int i=0;i<8;i++){
		int p=x+dx[i],q=y+dy[i];
		if(p>0&&q>0&&p<=n&&q<=m&&!mp[p][q]){
			mp[p][q]=cnt+1;
			if(dfs(p,q,cnt+1))return true;
			mp[p][q]=0;//注意清零 
		}
	}
	return false;
}
int main(){
	int T=0;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d %d",&n,&m);
		printf("Scenario #%d:\n",i);
		memset(mp,0,sizeof(mp));
		mp[1][1]=1;
		if(dfs(1,1,1)){
			loadans();
			for(int i=1;i<=n*m;i++)
				printf("%c%d",ans[i],ans2[i]);
			puts("");
		}
		else puts("impossible");
		puts("");
	}
	return 0;
}

