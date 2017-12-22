/*
倒水问题
分析：对每种状态转移进行DFS，注意记忆化最小步数 
*/
#include<iostream>
using namespace std;
int a,b,aim;
int f[101][101];
void dfs(int x,int y,int cur){
	if(f[x][y]&&cur>=f[x][y])return;
	f[x][y]=cur;
	dfs(x,0,cur+1);dfs(0,y,cur+1);
	dfs(x,b,cur+1);dfs(a,y,cur+1);
	if(x+y<=a)dfs(x+y,0,cur+1);
		else  dfs(a,x+y-a,cur+1);
	if(x+y<=b)dfs(0,x+y,cur+1);
		else  dfs(x+y-b,b,cur+1);
}
int main(){
	cin>>a>>b>>aim;
	dfs(0,0,0);
	int ans=100000;
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			if((i==aim||j==aim)&&f[i][j])
				ans=min(ans,f[i][j]);
	if(ans>=10000)cout<<"impossible";
	else cout<<ans;
	return 0;
}
