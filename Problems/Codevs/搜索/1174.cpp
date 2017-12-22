/*
靶形数独
分析：先预处理好，然后做好可放置的标记，然后DFS即可
	  感觉不用启发式搜索。。。 
*/
#include<iostream>
#include<cstring>
using namespace std;
const int sc[10][10]={
{ 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0},
{ 0, 6, 6, 6, 6, 6 , 6, 6, 6, 6},
{ 0, 6, 7, 7, 7, 7 , 7, 7, 7, 6},
{ 0, 6, 7, 8, 8, 8 , 8, 8, 7, 6},
{ 0, 6, 7, 8, 9, 9 , 9, 8, 7, 6},
{ 0, 6, 7, 8, 9, 10, 9, 8, 7, 6},
{ 0, 6, 7, 8, 9, 9 , 9, 8, 7, 6},
{ 0, 6, 7, 8, 8, 8 , 8, 8, 7, 6},
{ 0, 6, 7, 7, 7, 7 , 7, 7, 7, 6},
{ 0, 6, 6, 6, 6, 6 , 6, 6, 6, 6}};
const int bn[10][10] = {
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,1,1,1,2,2,2,3,3,3 },
{ 0,1,1,1,2,2,2,3,3,3 },
{ 0,1,1,1,2,2,2,3,3,3 },
{ 0,4,4,4,5,5,5,6,6,6 },
{ 0,4,4,4,5,5,5,6,6,6 },
{ 0,4,4,4,5,5,5,6,6,6 },
{ 0,7,7,7,8,8,8,9,9,9 },
{ 0,7,7,7,8,8,8,9,9,9 },
{ 0,7,7,7,8,8,8,9,9,9 }};
struct poi{
	int x,y;
};
int mp[10][10],block[10][10],row[10][10],col[10][10],len;
poi ps[9*9+3];
int ans;
int read(){
	len=0;ans=0;
	int r=0;
	memset(mp,0,sizeof(mp));
	memset(block,0,sizeof(block));
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cin>>mp[i][j];
			r+=mp[i][j]*sc[i][j];
			if(mp[i][j]==0){
				ps[++len]=(poi){i,j};
			}
			else{
				row[i][mp[i][j]]=1;
				col[j][mp[i][j]]=1;
				block[bn[i][j]][mp[i][j]]=1;
			}
		}
	}
	return r;
}
void dfs(poi p,int sco,int d){
	if(d==0){
		if(sco>ans)ans=sco;
		return;
	}
	for(int i=1;i<=9;i++){
		if(row[p.x][i]+col[p.y][i]+block[bn[p.x][p.y]][i]==0){
			row[p.x][i]=col[p.y][i]=block[bn[p.x][p.y]][i]=1;
			dfs(ps[d-1],sco+sc[p.x][p.y]*i,d-1);
			row[p.x][i]=col[p.y][i]=block[bn[p.x][p.y]][i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	int t=read();
	dfs(ps[len],t,len);
	if(ans!=0)cout<<ans;
	else cout<<-1;
	return 0;
}
