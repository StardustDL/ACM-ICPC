/*
老鼠的旅行
分析：经典棋盘DP，先处理出不可达点，再处理上边界和左边界，然后dp即可 
*/
#include<iostream>
using namespace std;
int a[26][26],n,m,p,q,k;
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)a[i][j]=0;
	for(int i=1;i<=k;i++){
		cin>>p>>q;
		a[p][q]=-1;
	}
	for(int i=1;i<=25;i++){
		a[i][1]=(a[i-1][1]==-1)?-1:a[i][1];
		a[1][i]=(a[1][i-1]==-1)?-1:a[1][i];
	}
	for(int i=1;i<=25;i++){
		a[1][i]=(a[1][i]!=-1)?1:a[1][i];
		a[i][1]=(a[i][1]!=-1)?1:a[i][1];
	}
	for(int i=2;i<=n;i++)
		for(int j=2;j<=m;j++){
			if(a[i][j]==-1)continue;
			a[i][j]+=(a[i][j-1]!=-1)?a[i][j-1]:0;
			a[i][j]+=(a[i-1][j]!=-1)?a[i-1][j]:0;
		}
	cout<<a[n][m];
	return 0;
}
