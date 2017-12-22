#include<iostream>
using namespace std;
const int MAXN=100;
bool mp[MAXN+3][MAXN+3];
int m,n;
bool read(){
	ios::sync_with_stdio(false);
	cin>>m>>n;
	if(m==0)return false;
	char c;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>c;
			switch(c){
				case '*':mp[i][j]=0;break;
				case '@':mp[i][j]=1;break;
			}
		}
	}
	return true;
}
void dfs(int i,int j){
	if(i<1||j<1||i>m||j>n||!mp[i][j])return;
	mp[i][j]=0;
	dfs(i+1,j);dfs(i-1,j);dfs(i,j+1);dfs(i,j-1);
	dfs(i+1,j+1);dfs(i-1,j-1);dfs(i+1,j-1);dfs(i-1,j+1);
}
int solve(){
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]){
				ans++;
				dfs(i,j);
			}
		}
	}
	return ans;
}
int main(){
	while(read()){
		cout<<solve()<<endl;
	}
	return 0;
}
