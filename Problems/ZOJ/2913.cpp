#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=10000,INF=1<<20;
struct node{
	int x,dis;
};
int t,nz,nr;
int g[MAXN+3][11],ans[MAXN+3],xl[11][23];
bitset<MAXN+3> us=0;
void read(){
	cin>>nz>>nr;
	int a=0;
	us=0;
	for(int i=1;i<=nz;i++){
		cin>>a;
		us[a]=1;
		int &t=g[a][0];
		cin>>t;
		for(int j=1;j<=t;j++)cin>>g[i][j];
	}
	for(int i=1;i<=nr;i++){
		int &t=xl[i][0];
		cin>>t;
		for(int j=1;j<=t;j++)cin>>xl[i][j];
	}
	for(int i=1;i<=MAXN;i++)ans[i]=INF;
}
queue<node> q;
void bfs(int from){
	
}
int main(){
	return 0;
} 
