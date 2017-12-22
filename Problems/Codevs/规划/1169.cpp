/*
传纸条
分析：类似于方格取数，注意i:1->m,j:1->n,k:1->m,l:1->n。
问题：为什么k从m到1，l从n到1就错了 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=53;
int mp[MAXN][MAXN],n,m,opt[MAXN][MAXN][MAXN][MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				for(int l=1;l<=n;l++){
					opt[i][j][k][l]=max(
						max(opt[i-1][j][k-1][l],
							opt[i-1][j][k][l-1]),
						max(opt[i][j-1][k-1][l],
							opt[i][j-1][k][l-1])
					)+mp[i][j]+mp[k][l];
					if(i==k&&j==l)opt[i][j][k][l]-=mp[k][l];
				}
			}
		}
	}
	cout<<opt[m][n][m][n];
	return 0;
} 
