/*
尼克的任务
分析：opt[i]表示从i到n的闲暇时间，
	  opt[i]=opt[i+1]+1 (没有从i开始的工作)
	  opt[i]=max{opt[i+T-1+1]} (T:每个从i开始的工作的持续时间) 
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=10000;
vector<int> g[MAXN+3];
int n,opt[MAXN+3];
void add(int s,int t){
	g[s].push_back(t);
}
void input(){
	int k,s,t;
	cin>>n>>k;
	while(k-->0){
		cin>>s>>t;add(s,t);
	}
}
int dp(){
	for(int i=n;i>=0;i--){
		if(g[i].size()==0)opt[i]=opt[i+1]+1;
		else for(int j=0;j<g[i].size();j++)
				opt[i]=max(opt[i],opt[i+g[i][j]]);
	} 
	return opt[1];
}
int main(){
	ios::sync_with_stdio(false);
	input();
	cout<<dp();
	return 0;
} 
