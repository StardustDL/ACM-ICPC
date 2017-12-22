/*
逃跑的拉尔夫
分析：先码的BFS，先是爆内存，又是超时间，于是DFS+判重AC 
*/
#include<iostream>
#include<queue>
#include<cstdio>
//#include<iomanip>
#include<cstring>
using namespace std;
const int MAXC=50,MAXN=1000;;
struct point{
	int x,y,b;
};
int mp[MAXC+3][MAXC+3],r,c,n,a[MAXN+3],used[MAXC+3][MAXC+3];
point s;
void input(){
	cin>>r>>c;
	memset(mp,0,sizeof(mp));
	char t;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>t;
			switch(t){
				case 'X':mp[i][j]=-1;break;
				case '*':s.x=i;s.y=j;break;
			}
		}
	}
	s.b=0;
	cin>>n;
	char ts[7];
	for(int i=1;i<=n;i++){
		cin>>ts;
		switch(ts[0]){
			case 'E' :a[i]=1;break;
			case 'W' :a[i]=2;break;
			case 'S':a[i]=3;break;
			case 'N':a[i]=4;break;
		}
	}
}
void output(){
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			//cout<<setw(2)<<mp[i][j];continue;
			switch(mp[i][j]){
				case -1:cout<<'X';break;
				case  0:cout<<'.';break; 
				case  1:cout<<'*';break;
			}
		}
		cout<<endl;
	}
}
queue<point> q;
void bfs(){
	q.push(s);
	while(!q.empty()){
		point t=q.front();q.pop();
		if(t.b==n){//很重要
			mp[t.x][t.y]=1;
			continue;
		}
		memset(used,0,sizeof(used));//不要扩展多余节点 
		if(t.b+1>n)continue; 
		switch(a[t.b+1]){
			case 1:
				for(int i=t.y+1;i<=c&&mp[t.x][i]!=-1;i++){
					if(used[t.x][i]==1)continue;
					used[t.x][i]=1;
					q.push((point){t.x,i,t.b+1});
				}
				break;
			case 2:
				for(int i=t.y-1;i>0&&mp[t.x][i]!=-1;i--){
					if(used[t.x][i]==1)continue;
					used[t.x][i]=1;
					q.push((point){t.x,i,t.b+1});
				}
				break;
			case 3:
				for(int i=t.x+1;i<=r&&mp[i][t.y]!=-1;i++){
					if(used[i][t.y]==1)continue;
					used[i][t.y]=1;
					q.push((point){i,t.y,t.b+1});
				}
				break;
			case 4:
				for(int i=t.x-1;i>0&&mp[i][t.y]!=-1;i--){
					if(used[i][t.y]==1)continue;
					used[i][t.y]=1;
					q.push((point){i,t.y,t.b+1});
				}
				break;
		}
	}
}
bool vis[MAXC+3][MAXC+3][MAXN+3];
void dfs(int x,int y,int d){
	if(vis[x][y][d])return;
	vis[x][y][d]=true;
	if(d==n){mp[x][y]=1;return;}
	switch(a[d+1]){
		case 1:
			for(int i=y+1;i<=c&&mp[x][i]!=-1;i++){
				dfs(x,i,d+1);
			}
			break;
		case 2:
			for(int i=y-1;i>0&&mp[x][i]!=-1;i--){
				dfs(x,i,d+1);
			}
			break;
		case 3:
			for(int i=x+1;i<=r&&mp[i][y]!=-1;i++){
				dfs(i,y,d+1);
			}
			break;
		case 4:
			for(int i=x-1;i>0&&mp[i][y]!=-1;i--){
				dfs(i,y,d+1);
			}
			break;
	}
}
int main(){
	ios::sync_with_stdio(false);
	input();
	dfs(s.x,s.y,s.b);
	output();
	return 0;
}
