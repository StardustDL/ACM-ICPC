/*
[2010Beijing wc]æÿ’Ûæ‡¿Î
∑÷Œˆ£∫BFS 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int n,m,d[1003][1003];
queue< pair<int,int> >q;
void bfs(){
	while(!q.empty()){
		pair<int,int> u=q.front();q.pop();int t=d[u.first][u.second];
		for(int k=0;k<4;k++){
			int x=u.first+dx[k],y=u.second+dy[k];
			if(x<1||y<1||x>n||y>m||d[x][y]!=-1)continue;
			d[x][y]=t+1;
			q.push(make_pair(x,y));
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);memset(d,-1,sizeof(d));
	for(int i=1;i<=n;i++){
		for(int j=1,t;j<=m;j++){
			scanf("%1d",&t);
			if(t)d[i][j]=0,q.push(make_pair(i,j));
		}
	}
	bfs();
	for(int i=1;i<=n;i++){
		for(int j=1,t;j<=m;j++)printf("%d ",d[i][j]);
		puts("");
	}
	return 0;
}

