/*
*/
#include<iostream>
#include<bitset>
using namespace std;
typedef bitset<5> map[5];
map mp,vis;
int md,cnt,base=0,x1=-1,y1;
//int zc[5];
void input(){
	char t;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>t;
			mp[i][j]=t-'0';
			if(t=='0')base++;
			if(t=='1'&&x1==-1){
				x1=i;y1=j;
			}
		}
	}
}
void clear(map &t){
	for(int i=0;i<5;i++)t[i]=0;
}
void fillfeed(int x,int y){
	if(x<0||y<0||x>4||y>4)return;
	if(mp[x][y]&&vis[x][y]==0){
		vis[x][y]=1;
		cnt++;
		fillfeed(x+1,y);
		fillfeed(x,y+1);
		fillfeed(x-1,y);
		fillfeed(x,y-1);
	}
}
bool dfs(int d,int x,int y){
	if(d==md){
		clear(vis);
		cnt=0;fillfeed(x1,y1);
		if(cnt==25-base+d)return true;
		else return false;
	}
	mp[x][y]=1;
	bool flag=false;
	if(!mp[x+1][y])flag=flag||dfs(d+1,x+1,y);
	if(!mp[x][y+1] && !flag)dfs(d+1,x,y+1);
	mp[x][y]=0;
	return flag;
}
int solve(){
	md=0;
	while(1){
		for(int 
	}
	return md;
}
int main(){
	input();
	cout<<solve();
	return 0;
}
