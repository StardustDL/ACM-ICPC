/*
奶牛的锻炼 
分析：状态设为opt[i][j]表示第i分钟，疲劳值为j时的最远距离，
	  转移有点多，要好好想：
	  	1.0<j<=m时，继续前进：opt[i-1][j-1]+d[i]
	  	2.j=0时，
			a)由上次休息前进：opt[i-j][j]，这个状态正好是到opt[i][j]的下一秒就可以前进了 
	  		b)继续休息：opt[i-1][0]
	  数据范围有问题：N<=10000 
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
	cout<<dp();
	return 0;
} 
