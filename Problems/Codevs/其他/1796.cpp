/*
社交网络
分析：Floyd，其中加入最短路条数的记录，然后模拟计算那个式子即可 
*/ 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
typedef long long LL;
int n,d[MAXN+3][MAXN+3];
LL c[MAXN+3][MAXN+3];
double ans[MAXN+3];
void input(){
	int x,y,z,m;
	cin>>n>>m;
	memset(d,INF,sizeof(d));
	//for(int i=1;i<=n;i++)d[i][i]=0;
	while(m--){
		cin>>x>>y>>z;
		d[x][y]=d[y][x]=z;
		c[x][y]=c[y][x]=1;
	}
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i)continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k)continue;
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					c[i][j]=c[i][k]*c[k][j];
				}
				else if(d[i][j]==d[i][k]+d[k][j]){
					c[i][j]+=c[i][k]*c[k][j];
				}
			}
		}
	}
}
int main(){
	input();
	floyd();
	for(int k=1;k<=n;k++){
		ans[k]=0;
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(i==j||k==j)continue;
				if(d[i][j]==d[i][k]+d[k][j])ans[k]+=(c[i][k]*c[k][j]*1.0)/c[i][j];
			}
		}
		printf("%.3lf\n",ans[k]);
	}
	return 0;
}
