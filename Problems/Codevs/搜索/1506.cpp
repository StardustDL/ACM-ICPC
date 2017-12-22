/*
´«»°
*/
#include<iostream>
using namespace std;
int rs[1001][1001],n,m,start=0;
bool vis[1001],iss=false;
bool dfs(int ind){
	if(iss)iss=false;
	else if(ind==start)return true;
	if(vis[ind])return false;
	vis[ind]=true;
	bool ans=false;
	for(int i=1;i<=n;i++){
		if(rs[ind][i]){
			ans=ans||dfs(i);
			if(ans)break;
		}
	}
	return ans;
}
int main(){
	cin>>n>>m;
	int p,q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)rs[i][j]=0;
	for(int i=1;i<=m;i++){
		cin>>p>>q;
		rs[p][q]=1;
	}
	for(int i=1;i<=n;i++){
		start=i;
		iss=true;
		for(int i=1;i<=n;i++)vis[i]=false;
		if(dfs(i))cout<<"T"<<endl;
		else cout<<"F"<<endl;
	}
	return 0;
}
