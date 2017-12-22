/*
四个国王
*/
#include<iostream>
using namespace std;
const int MAXN=5,MAXM=100;
int n,m,k,opt[MAXN+3][MAXM+3][MAXM*MAXN+3];
int get(int x,int y,int t){
	int ans=0;
	if(x-2>0)ans+=opt[x-2][y][t-1];
	if(x-2>0&&y-1>0)ans+=opt[x-2][y-1][t-1];
	if(y-2>0)ans+=opt[x][y-2][t-1];
	if(y-2>0&&x-1>0)ans+=opt[x-1][y-2][t-1];
	if(x-2>0&&y-2>0)ans+=opt[x-2][y-2][t-1];
	return ans;
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)opt[i][j][0]=1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int t=1;t<=m;t++){
				opt[j][t][i]+=get(j,t,i);
			}
		}
	}
	cout<<opt[n][m][k];
	return 0;
} 
