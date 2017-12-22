/*
Stockbroker Grapevine
题意：一张有向图，从某一点出发，使得到达其他点的最大距离最小
分析：Floyd，扫一遍点 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int mp[MAXN+3][MAXN+3],n;
bool input(){
	scanf("%d",&n);
	if(!n)return false;
	int m,x,y;
	memset(mp,INF,sizeof(mp));
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		while(m--){
			scanf("%d%d",&x,&y);
			mp[i][x]=y;
		}
	}
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
}
void solve(){
	int ans1=0,ans2=INF;
	for(int i=1;i<=n;i++){
		int t=0,k=0;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			t+=mp[i][j];
			k=max(k,mp[i][j]);
		}
		if(k<ans2){
			ans1=i;ans2=k;
		}
	}
	printf("%d %d\n",ans1,ans2);
}
int main(){
	while(input()){
		floyd();
		solve(); 
	}
	return 0;
}

