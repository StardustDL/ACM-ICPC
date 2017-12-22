/*
上学路线（施工）
*/ 
#include<iostream>
using namespace std;
const int MAXN=16;
int d[MAXN+3][MAXN+3],a,b;
int main(){
	int n,x,y;
	cin>>a>>b>>n;
	while(n--){cin>>x>>y;d[x][y]=-1;}
	d[1][1]=1;
	for(int i=2;i<=b;i++)if(d[1][i]!=-1)d[1][i]=1;else break;
	for(int i=2;i<=a;i++)if(d[i][1]!=-1)d[i][1]=1;else break;
	for(int i=2;i<=a;i++){
		for(int j=2;j<=b;j++){
			if(d[i][j]==-1)continue;
			if(d[i-1][j]!=-1)d[i][j]+=d[i-1][j];
			if(d[i][j-1]!=-1)d[i][j]+=d[i][j-1];
		}
	}
	//for(int i=1;i<=a;i++){for(int j=1;j<=b;j++)cout<<d[i][j]<<" ";cout<<endl;}
	cout<<d[a][b];
	return 0;
}
