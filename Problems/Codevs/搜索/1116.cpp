/*
四色问题
*/
#include<iostream>
using namespace std;
const int MAXN=8;
int n,a[MAXN+1][MAXN+1],s[MAXN+3],ans=0;
bool check(int d){
	for(int i=1;i<=d;i++){
		for(int j=i+1;j<=d;j++){
			if(a[i][j]&&s[i]==s[j])return false;
		}
	}
	return true;
}
void dfs(int ind){
	if(ind>n){
		ans++;return;
	}
	for(int i=1;i<=4;i++){
		s[ind]=i;
		if(check(ind))dfs(ind+1);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
	dfs(1);
	cout<<ans;
	return 0;
}
