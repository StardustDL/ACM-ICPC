/*
��ʿ����
����������DP�����д���ÿ���ϵ�ÿ���㶼Ҫ���� 
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=50,R=4;
const int dx[4]={1,1,2,2},dy[4]={2,-2,1,-1};
struct point{
	int x,y;
};
long mp[R+MAXN+3][R+MAXN+3],n,m;
point s,t;
queue<point> q;
long dp(){
	memset(mp,0,sizeof(mp));
	mp[R+s.x][R+s.y]=1;
	for(int i=R+s.x;i<=R+t.x;i++){
		for(int j=R+1;j<=R+m;j++){
			if(mp[i][j]){
				for(int k=0;k<4;k++){
					mp[i+dx[k]][j+dy[k]]+=mp[i][j];
				}
			}
		}
	}
	return mp[R+t.x][R+t.y];
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>s.x>>s.y>>t.x>>t.y;
	cout<<dp();
	return 0;
}
