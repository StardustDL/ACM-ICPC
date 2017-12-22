/*
数的计算
题意：题意没说清楚，就理解成每次可以最多加上次所加数的一半就行
分析：DFS计数，实际上没必要，递推也可以 
*/ 
#include<iostream>
using namespace std;
int n,ans=0;
void dfs(int n){
	ans++;
	for(int i=1;i<=n/2;i++)dfs(i);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	dfs(n);
	cout<<ans;
	return 0;
}
