/*
孪生蜘蛛
分析：求每两点最短路，枚举蜘蛛和蛾子的位置，注意这里是最大距离的最小值 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100,INF=1<<30;
int dis[MAXN+3][MAXN+3],n,a,b,c,x1,x2,mn=INF;
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	memset(dis,0x3f,sizeof(dis));
	while(cin>>a>>b>>c)
		dis[a][b]=dis[b][a]=c;
	floyd();
	for(a=1;a<=n;a++){
		for(b=a+1;b<=n;b++){
			int an=0;
			for(int i=1;i<=n;i++){
				if(i!=a&&i!=b){
					an=max(an,min(dis[a][i],dis[b][i]));
				}
			}
			if(an<mn){
				mn=an;
				x1=a;x2=b;
			}
		}
	}
	cout<<x1<<" "<<x2;
	return 0;
}
