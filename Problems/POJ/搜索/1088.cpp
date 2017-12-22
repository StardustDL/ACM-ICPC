/*
»¬Ñ©
*/
#include<iostream>
#include<algorithm>
using namespace std;
int m[101][101],r,c,tans=0,ans=0,f[101][101];
void dfs(int x,int y,int step){
	if(x>r||x<1||y>c||y<1)return;
	if(f[x][y]!=0){
		step+=f[x][y]-1;
		if(step>tans)tans=step;
		return;
	}
	if(step>tans)tans=step;
	int &t=m[x][y];
	if(m[x+1][y]<t)dfs(x+1,y,step+1);
	if(m[x-1][y]<t)dfs(x-1,y,step+1);
	if(m[x][y+1]<t)dfs(x,y+1,step+1);
	if(m[x][y-1]<t)dfs(x,y-1,step+1);
}
int main(){
	cin>>r>>c;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			cin>>m[i][j];
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			tans=0;
			dfs(i,j,1);
			f[i][j]=tans;
			ans=max(tans,ans);
		}
	}
	cout<<ans;
	return 0;
}
