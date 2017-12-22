/*
»Ø¼Ò
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAXN 60
#define INF 10000000
using namespace std;
int dist[MAXN][MAXN],n,m;
void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)dist[i][j]=i==j?0:INF;
}
int hash(char c){
	if(c>='a')return 1+(c-'a');	
	else if(c>='A')return 27+(c-'A');
}
int main(){
	n=52;
	scanf("%d\n",&m);
	char x,y;int z;
	init();
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		int p=hash(x),q=hash(y);
		dist[p][q]=min(dist[p][q],z);
		dist[q][p]=dist[p][q];
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(!((i==j)||(j==k)||(i==k)))
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	int ma=INF,mp=0;
	for(int i=27;i<52;i++)
		if(dist[i][52]!=INF && dist[i][52]<ma)
			ma=dist[i][52],mp=i;
	if(mp>=27)x=mp-27+'A';
	else x=mp-1+'a';
	cout<<x<<' '<<ma;
	return 0;
} 
