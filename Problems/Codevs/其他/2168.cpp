/*
生物入侵者
分析：fillfeed，题目本身不难，就是细节颇多 
*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=100,dx[8]={0,0,1,1,1,-1,-1,-1},dy[8]={-1,1,-1,0,1,-1,0,1};
int rest,x,y,x0,y0,ans=0,mp[MAXN+3][MAXN+3];
struct point{
	int x,y,t;
};
queue<point> q;
int main(){
	cin>>y>>x>>y0>>x0;
	char c;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			cin>>c;
			switch(c){
				case '.':mp[i][j]=0;rest++;break;
				case '*':mp[i][j]=-1;break;
			}
		}
	}
	x0=x-x0+1;
	q.push((point){x0,y0,1});mp[x0][y0]=1;rest--;
	while(!q.empty()){
		point p=q.front();q.pop();
		for(int i=0;i<8;i++){
			int a=p.x+dx[i],b=p.y+dy[i];
			if(a>0&&b>0&&a<=x&&b<=y&&mp[a][b]==0){
				mp[a][b]=mp[p.x][p.y]+1;rest--;
				if(rest==0){
					ans=mp[a][b]-1;break;
				}
				q.push((point){a,b,mp[a][b]});
			}
		}
		if(ans!=0)break;
	}
	cout<<ans;
	return 0;
}
