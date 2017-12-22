/*
一塔湖图
分析：好恶心的一道题。。。不打算A了。。有时间再说吧 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10,MX=MAXN*MAXN,INF=1<<30;
int n,m,d[MX][MX],a[MAXN+3],b[MAXN+3],x1,x2,y1,y2;
int to(int x,int y){
	return (x-1)*n+(y);
}
void input(){
	int t,k,x1,x2,y1,y2,temp;
	cin>>n>>m>>t>>k;
	for(int i=0;i<MX;i++)for(int j=0;j<MX;j++)d[i][j]=INF;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			d[to(i,j)][to(i,j-1)]=b[j]-b[j-1];
			d[to(i,j)][to(i-1,j)]=a[i]-a[i-1];
			if(j<m)d[to(i,j)][to(i,j+1)]=b[j+1]-b[j];
			if(i<n)d[to(i,j)][to(i+1,j)]=a[i+1]-a[i];
		}
	}
	for(int i=1;i<=t;i++){
		cin>>x1>>y1>>x2>>y2;
		d[to(x1,y1)][to(x2,y2)]=d[to(x2,y2)][to(x1,y1)]=INF;
	}
	for(int e=1;e<=k;e++){
		cin>>x1>>y1>>x2>>y2;
		for(int i=x1+1;i<x2;i++){
			for(int j=y1+1;j<y2;j++){
				for(int k=x1+1;k<x2;k++){
					for(int l=y1+1;l<y2;l++){
						int t1=to(i,j),t2=to(k,l);
						if(t1==t2)continue;
						d[t1][t2]=INF;
					}
				}
			}
		}
		for(int i=x1;i<=x2;i++){
			d[to(i,y1)][to(i,y1+1)]=d[to(i,y1+1)][to(i,y1)]=INF;
			d[to(i,y2-1)][to(i,y2)]=d[to(i,y2)][to(i,y2-1)]=INF;
		}
		for(int i=y1;i<=y2;i++){
			d[to(x1,i)][to(x1,i+1)]=d[to(x1,i+1)][to(x1,i)]=INF;
			d[to(x2-1,i)][to(x2,i)]=d[to(x2,i)][to(x2-1,i)]=INF;
		}
	}
	cin>>x1>>y1>>x2>>y2;
}
void floyd(){
	for(int k=0;k<n*m;k++){
		for(int i=0;i<n*m;i++){
			for(int j=0;j<n*m;j++){
				if(i==j||j==k)continue;
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int main(){
	input();
	floyd();
	cout<<d[to(x1,y1)][to(x2,y2)];
	return 0;
}
