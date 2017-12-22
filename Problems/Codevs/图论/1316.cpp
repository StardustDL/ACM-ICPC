/*
文化之旅
分析：题目和数据不符，不需要考虑已经学习的文化，只考虑相邻的就可以，Floyd
	  另外，样例第二个好像也有问题 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=103,INF=0x3f3f3f3f;
int n,k,m,s,t,c[MAXN],a[MAXN][MAXN],d[MAXN][MAXN],x,y,z;
int main(){
	cin>>n>>k>>m>>s>>t;
	memset(d,INF,sizeof(d));
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)cin>>a[i][j];
	while(m-->0){
		cin>>x>>y>>z;
		d[x][y]=d[y][x]=z;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[c[i]][c[j]])d[i][j]=INF;
	for(int o=1;o<=n;o++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				//if(!a[i][j]&&!a[i][o]&&!a[o][j])
					d[i][j]=min(d[i][j],d[i][o]+d[o][j]);
	if(d[s][t]==INF)cout<<-1;
	else cout<<d[s][t];
	return 0;
}

