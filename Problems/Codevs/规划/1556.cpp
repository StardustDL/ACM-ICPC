/*
数字游戏 2
分析：可以想到，要使减数大的先被减，这样才不会翻倍
	  然而重点在于方程的书写：
	  第一次先写了个
	  opt[i][j]=max(opt[i-1][j],opt[i-1][j-1]+a[i]-b[i]*(m-j))
	  但这是错的，这里使用(m-j)相当于给以后的所有数值先减了b[i]
	  但这不符合状态的无后效性，状态要由之前的信息得到。
	  为什么呢？注意要取max，这样可能为正解的后一项因为减了一个值（虽然之后的状态会加上a[i]），
	  而使得决策不选择这个解，这样会导致错解，而样例并没有体现
	  只好转换方程：后减b[i]，即。
	  opt[i][j]=max(opt[i-1][j],opt[i-1][j-1]+a[i]-b[i]*(j-1));
	  实际上第一个方程相当于当前状态最后选不选a[i]的问题
	  而后一个方程为是不是第一个选a[i] 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200;
struct data{
	int a,b;
	bool operator < (const data &d)const{
		return b>d.b;
	}
}da[MAXN+3];
int n,m,opt[MAXN+3][MAXN+3];
int dp(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			opt[i][j]=max(opt[i-1][j],opt[i-1][j-1]+da[i].a-da[i].b*(j-1));
		}
	}
	return opt[n][m];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>da[i].a;
	for(int i=1;i<=n;i++)cin>>da[i].b;
	sort(da+1,da+n+1);
	cout<<dp();
	return 0;
}
