/*
LITTLE SHOP OF FLOWERS
题意：F束花插入V个瓶子里面，花要按编号插，不同花插入不同的花瓶有不同的美观程度，要求最大的美观程度。
分析：opt[i][j]表示第i束花插入前j个瓶子里面。则状态转移函数为opt[i][j]=max(opt[i-1][j-1]+a[i][j],opt[i][j-1])
	  因为有两种插法，一：第i束花插入第j个瓶子里面，则为opt[i][j]=opt[i-1][j-1]+a[i][j].二：第i束花不插入第j个瓶子里面，则opt[i][j]=opt[i][j-1]。
	  初始化也很重要：对于opt[i][i]只能依次插 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100;
int f,v,a[MAXN+3][MAXN+3],opt[MAXN+3][MAXN+3];
int main(){
	cin>>f>>v;
	for(int i=1;i<=f;i++)
		for(int j=1;j<=v;j++)cin>>a[i][j];
	for(int i=1;i<=v;i++)opt[i][i]=opt[i-1][i-1]+a[i][i];
	for(int i=1;i<=f;i++)
		for(int j=i+1;j<=v;j++)
			opt[i][j]=max(opt[i][j-1],opt[i-1][j-1]+a[i][j]);
	cout<<opt[f][v];
	return 0;
} 
