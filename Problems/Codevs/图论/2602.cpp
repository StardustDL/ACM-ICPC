/*
最短路径问题
分析：Floyd 
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
const int MAXN=100,INF=1<<20;
double dis[MAXN+3][MAXN+3];
int n,s,t,x[MAXN+3],y[MAXN+3];
double getdis(int i,int j){
	return sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
}
void input(){
	int a,b,m;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=(i==j?0:INF);
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		dis[a][b]=dis[b][a]=getdis(a,b);
	}
	cin>>s>>t;
}
void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]); 
}
int main(){
	ios::sync_with_stdio(false);
	input();
	floyd();
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<dis[s][t];
	return 0;
}
