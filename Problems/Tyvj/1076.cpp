#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=25;
int mp[MAXN+3][MAXN+3],n,ans=0;
void dfs(int x,int y,int t){
	if(x==n+1){
		ans=max(ans,t);return;
	}
	t=(t+mp[x][y])%100;
	dfs(x+1,y,t);
	dfs(x+1,y+1,t);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)cin>>mp[i][j];
	}
	dfs(1,1,0);
	cout<<ans;
	return 0;
}
