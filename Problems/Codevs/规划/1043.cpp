/*
方格取数
分析：四维DP，opt[i][j][k][l]表示第一轮走到(i,j)，第二轮走到(k,l)的最优解
	  那么转移为
	  	opt[i][j][k][l]
		  =max{opt[i-1][j][k-1][l],opt[i-1][j][k][l-1]
		  	   opt[i][j-1][k-1][l],opt[i][j-1][k][l-1]}
		   +map[i][j]+map[k][l];
		注意如果(i,j),(k,l)位置相同，要删除一个 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=21;
int n,opt[MAXN][MAXN][MAXN][MAXN],map[MAXN][MAXN];
int dp(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					opt[i][j][k][l]=max(
						max(
							opt[i-1][j][k-1][l],
							opt[i-1][j][k][l-1]),
						max(
							opt[i][j-1][k-1][l],
							opt[i][j-1][k][l-1]))
						+map[i][j]+map[k][l];
					if(i==k&&j==l)//位置相同 
						opt[i][j][k][l]-=map[i][j];
				}
			}
		}
	}
	return opt[n][n][n][n]; 
} 
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	int a,b,c;
	while(cin>>a>>b>>c){
		map[a][b]=c;
	}
	cout<<dp();
	return 0;
}
