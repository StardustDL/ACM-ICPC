/*
多源最短路
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=101;
int d[MAXN][MAXN],n,q,a,b;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>d[i][j];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	cin>>q;
	while(q-->0){
		cin>>a>>b;
		cout<<d[a][b]<<endl;
	}
	return 0;
} 
