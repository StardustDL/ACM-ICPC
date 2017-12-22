/*
二叉树最大宽度和高度
分析：高度即深度（DFS），宽度即同一层最多节点数（BFS） 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=16;
int n,a[MAXN][2],h=0,w=0,W[MAXN];
void dfs(int x,int xh){
	if(x==0)return;
	h=max(xh,h);
	W[xh]++;
	dfs(a[x][0],xh+1);
	dfs(a[x][1],xh+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	dfs(1,1);
	for(int i=1;i<=h;i++)w=max(w,W[i]);
	cout<<w<<" "<<h; 
	return 0;
}
