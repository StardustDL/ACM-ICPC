/*
ÀçÌï»úÆ÷ÈË
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int MAXN=240,INF=0x3f3f3f3f;
int x,y,n,a,b,c,d;
bitset<MAXN+3> g[MAXN+3]; 
int main(){
	cin>>x>>y>>n;
	while(n--){
		cin>>a>>b>>c>>d;
		for(int i=a;i<=c;i++){
			for(int j=b;j<=d;j++){
				g[i][j]=1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++)ans+=g[i][j];
	}
	cout<<ans;
	return 0;
}

