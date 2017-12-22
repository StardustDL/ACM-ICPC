#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=6000;
int r[MAXN+3],n,fa[MAXN+3],rt,dp[MAXN+3][2];
vector<int> ch[MAXN+3];
void dfs(int e){
	for(int i=0;i<ch[e].size();i++){
		int t=ch[e][i];
		dfs(t);
		dp[e][0]+=max(dp[t][1],dp[t][0]);
		dp[e][1]+=dp[t][0];
	}
	dp[e][1]+=r[e];
}
int main(){
	int l,k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	for(int i=1;i<=n-1;i++){
		cin>>l>>k;
		fa[l]=k;
		ch[k].push_back(l);
	}
	for(int i=1;i<=n;i++)if(fa[i]==0){
		rt=i;break;
	}
	dfs(rt);
	cout<<max(dp[rt][0],dp[rt][1]);
	return 0;
}
