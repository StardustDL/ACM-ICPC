/*
武士风度的牛
分析：BFS，坑。。 
*/
#include<iostream>
#include<queue>
using namespace std;
const int MAXN=150,dx[8]={1,1,-1,-1,2,-2,2,-2},dy[8]={2,-2,2,-2,1,1,-1,-1};
struct point{
	int x,y,st;
};
int r,c,si,sj,ei,ej;
bool mp[MAXN+3][MAXN+3];
queue<point> q;
void input(){
	cin>>c>>r;
	char t;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>t;
			switch(t){
				case '.':break;
				case '*':mp[i][j]=1;break;
				case 'K':si=i;sj=j;break;
				case 'H':ei=i;ej=j;break;
			} 
		}
	}
}
int bfs(){
	q.push((point){si,sj,0});
	while(!q.empty()){
		point e=q.front();q.pop();
		if(e.x==ei&&e.y==ej){cout<<e.st;return 0;}
		for(int i=0;i<8;i++){
			int a=e.x+dx[i],b=e.y+dy[i];
			if(!mp[a][b]&&a>0&&b>0&&a<=r&&b<=c){
				mp[a][b]=1;
				q.push((point){a,b,e.st+1});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	input();
	bfs();
	return 0;
}
