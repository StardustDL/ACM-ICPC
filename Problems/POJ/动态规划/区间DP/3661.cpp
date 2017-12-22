/*
Running
题意：奶牛Bessie有N分钟时间跑步，每分钟她可以跑步或者休息。若她在第i分钟跑步，可以跑出D_i米，同时疲倦程度增加1（初始为0）。若她在第i分钟休息，则疲倦程度减少1。无论何时，疲倦程度都不能超过M。另外，一旦她开始休息，只有当疲惫程度减为0时才能重新开始跑步。在第N分钟后，她的疲倦程度必须为0。 
分析：状态设为opt[i][j]表示第i分钟，疲劳值为j时的最远距离，
	  转移有点多，要好好想：
	  	1.0<j<=m时，继续前进：opt[i-1][j-1]+d[i]
	  	2.j=0时，
			a)由上次休息前进：opt[i-j][j]，这个状态正好是到opt[i][j]的下一秒就可以前进了 
	  		b)继续休息：opt[i-1][0]
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10000,MAXM=500;
int n,m,d[MAXN+3],opt[MAXN+3][MAXM+3];
void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>d[i];
	memset(opt,0,sizeof(opt));
}
int dp(){
	for(int i=1;i<=n;i++){
		opt[i][0]=max(opt[i][0],opt[i-1][0]);
		for(int j=1;j<=m;j++){
			opt[i][j]=max(opt[i][j],opt[i-1][j-1]+d[i]);
			if(i>=j)opt[i][0]=max(opt[i][0],opt[i-j][j]);
		}
	}
	return opt[n][0];
}
int main(){
	ios::sync_with_stdio(false);
	input();
	cout<<dp()<<endl;
	return 0;
} 
