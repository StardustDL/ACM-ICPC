/*
过河卒
分析：典型棋盘DP，注意几点：边界处理，马的控制点可能出界，先预留出空
注意：A点在(0,0)，马可以控制9个点，预留时不要出现漏算 
*/
#include<iostream>
using namespace std;
const int D=2,MAXN=15,dx[8]={1,1,-1,-1,2,2,-2,-2},dy[8]={2,-2,2,-2,1,-1,1,-1};
int mp[MAXN+2*D+3][MAXN+2*D+3],n,m,x,y;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>x>>y;
	mp[D+x][D+y]=-1;
	for(int i=0;i<8;i++){
		mp[D+x+dx[i]][D+y+dy[i]]=-1;
	}
	mp[D][D]=1;
	for(int i=1;i<=n;i++){
		if(mp[D+i][D]==-1)break;
		mp[D+i][D]=1;
	}
	for(int i=1;i<=m;i++){
		if(mp[D][D+i]==-1)break;
		mp[D][D+i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[D+i][D+j]==-1)continue;
			mp[D+i][D+j]=(mp[D+i-1][D+j]!=-1?mp[D+i-1][D+j]:0)
						+(mp[D+i][D+j-1]!=-1?mp[D+i][D+j-1]:0);
		}
	}
	/*for(int i=1;i<=n+D;i++){
		for(int j=1;j<=m+D;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<mp[D+n][D+m];
	return 0; 
} 
