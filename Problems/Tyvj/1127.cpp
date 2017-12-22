#include<iostream>
using namespace std;
const int MAXN=80;
int mp[MAXN+3][MAXN+3],m,n,ans=0;
void dfs(int x,int y){
	if(x>m||y>n||x<1||y<1)return;
	if(mp[x][y]){
		mp[x][y]=0;
		dfs(x+1,y);dfs(x,y+1);dfs(x-1,y);dfs(x,y-1);
	}
}
void read(){
	cin>>m>>n;
	char c;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>c;
			mp[i][j]=c-'0';
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	read();
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]){
				ans++;dfs(i,j);
			}
		}
	}
	cout<<ans;
	return 0;
}


