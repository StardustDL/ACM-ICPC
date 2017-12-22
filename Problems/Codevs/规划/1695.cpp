/*
windows 2013
分析：opt[i][0]表示第i个菜用勺子吃，opt[i][1]表示第i个菜用筷子吃
	  注意初始化，不能将第一件菜放入循环，因为那样会缩小答案 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100;
int n,a[MAXN+3],b[MAXN+3],c[MAXN+3],opt[MAXN+3][2];
void input(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
} 
int dp(){
	opt[1][0]=c[1]+a[1];
	opt[1][1]=b[1];
	for(int i=2;i<=n;i++){
		opt[i][0]=min(opt[i-1][0]+a[i],opt[i-1][1]+a[i]+c[i]);
		opt[i][1]=min(opt[i-1][1]+b[i],opt[i-1][0]+b[i]+c[i]);
	}
	return min(opt[n][0],opt[n][1]);
}
int main(){
	input();
	cout<<dp();
	return 0;
}
