/*
Ä¾¹ÏµØ
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=50,INF=0x3f3f3f3f;
const int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int r,c,f[MAXN+3][MAXN+3],ans=0;
int main(){
	cin>>r>>c;
	for(int i=1;i<=r;i++)for(int j=1;j<=c;j++)cin>>f[i][j];
	ans+=f[1][1];f[1][1]=0;
	for(int nc=1,nr=1,p,t=0;nc<c||nr<r;ans+=t,nc+=dy[p],nr+=dx[p],f[nr][nc]=t=0)
		for(int j=0,e;j<4;j++)
			if((e=f[nr+dx[j]][nc+dy[j]])>t)t=e,p=j;
	cout<<ans<<endl;
	return 0;
}

