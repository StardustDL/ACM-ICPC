/*
比赛
分析：数据有点大，不然用Floyd又好编有简单。。只能DFS，懒得打 
*/
#include<iostream>
#include<bitset>
#include<vector>
#include<cstdio>
using namespace std;
const int MAXN=1000;
struct Ans{
	int k,t;
};
bitset<MAXN+3> d[MAXN+3];
vector<Ans> ans;
int n;
void input(){
	int m,x,y;
	scanf("%d %d",&n,&m);
	while(m-->0){
		scanf("%d %d",&x,&y);d[x][y]=1;
	}
} 
void floyd(){
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j&&j!=k&&d[i][j]==0)d[i][j]=d[i][k]&d[k][j];
}
void solve(){
	for(int i=1;i<=n;i++){
		int up=0,down=0;
		for(int j=1;j<=n;j++){
			//cout<<d[i][j]<<" ";
			if(i==j)continue;
			if(d[i][j])down++;
			if(d[j][i])up++;
		}
		//cout<<endl;
		//cout<<up<<" "<<down<<endl;
		if(up+down==n-1){
			ans.push_back((Ans){i,up+1});
		}
	}
}
void output(){
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].k,ans[i].t);
	}
}
int main(){
	input();floyd();solve();output();
	return 0;
} 
