/*
�ۻ�
�������������ܴ�K�㵽�ĵ�������K������· 
*/ 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int d[MAXN+3][MAXN+3],n,K;
void input(){
	int m,a,b,c;
	cin>>n>>m>>K;
	memset(d,INF,sizeof(d));
	while(m-->0){
		cin>>a>>b>>c;
		d[a][b]=min(d[a][b],c);
	}
	for(int i=1;i<=n;i++)d[i][i]=0;
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(d[K][i]==INF||d[i][K]==INF)continue;
		ans=max(ans,d[i][K]+d[K][i]);
	}
	return ans;
}
int main(){
	input();
	floyd();
	cout<<solve();
	return 0;
}
