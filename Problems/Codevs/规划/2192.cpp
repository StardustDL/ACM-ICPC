/*
删数
分析：最后一步，只剩下一次能删除的数字组，
	  对于已经删过的数字组，就是一个子问题了，
	  又可以分为最后一次删的和之前删的两部分。 
	  所以可以依次遍历最后一次删除的位置
	  f[i][j]表示从i到j，删数的最大值,
	  sum[i][j]表示直接删除从i到j的操作值
	  f[i][j]=max{max{f[i][k]+f[k+1][j]|i<=k<j},sum[i][j]} 
*/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100;
int n,a[MAXN+3],opt[MAXN+3][MAXN+3];
int dp(){
	for(int i=1;i<=n;i++)opt[i][i]=a[i];//注意边界 
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			int &t=opt[i][j];
			for(int k=i;k<j;k++){
				t=max(t,opt[i][k]+opt[k+1][j]);
			}
			t=max(t,abs(a[j]-a[i])*(j-i+1));
		}
	}
	return opt[1][n];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<dp();
	return 0;
}
