/*
ZOJ1649
采用记忆化搜索，注意边界判断，并不是传统的BFS 
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN=200,INF=1<<20;
const int d[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
int mp[MAXN+3][MAXN+3],n,m,xf,yf,xt,yt,dis[MAXN+3][MAXN+3];
struct poi{
	int x,y,dis;
};
bool read(){
	if(!(cin>>n))return false;
	cin>>m;
	char c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c;
			switch(c){
				case '#':mp[i][j]=0;break;
				case '.':mp[i][j]=1;break;
				case 'a':mp[i][j]=1;xt=i,yt=j;break;
				case 'r':mp[i][j]=1;xf=i,yf=j;break;
				case 'x':mp[i][j]=2;break;
			}
		}
	}
	return true;
}
queue<poi> q;
int a,b,e;
int solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)dis[i][j]=INF;
	}
	q.push((poi){xf,yf,0});
	while(!q.empty()){
		poi t=q.front();q.pop();
		for(int i=0;i<4;i++){
			poi p={t.x+d[i][0],t.y+d[i][1],t.dis};
			if(p.x<1||p.y<1||p.x>n||p.y>m||mp[p.x][p.y]==0)continue;
			p.dis+=mp[p.x][p.y];
			if(p.dis<dis[p.x][p.y]){
				dis[p.x][p.y]=p.dis;
				q.push(p);
			}
		}
	}
	return dis[xt][yt];
}
int main(){
	ios::sync_with_stdio(false);
	int ans;
	while(read()){
		if((ans=solve()) < INF)cout<<ans<<endl;
		else cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
	}
	return 0;
}
