#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=7;
int n,m,tm,x,y,tx,ty;
bool mp[MAXN+3][MAXN+3];
bool read(){
	cin>>n>>m>>tm;
	if(n==0)return false;
	char c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c;
			switch(c){
				case 'X':mp[i][j]=0;break;
				case 'D':tx=i;ty=j;mp[i][j]=1;break;
				case '.':mp[i][j]=1;break;
				case 'S':x=i;y=j;mp[i][j]=1;break;
			}
		}
	}
	return true;
}
bool dfs(int i,int j,int t){
	if(i<1||j<1||i>n||j>m||t>tm||!mp[i][j])return false;
	if(i==tx&&j==ty&&t==tm)return true;
	mp[i][j]=0;
	if(dfs(i+1,j,t+1)||dfs(i,j+1,t+1)||dfs(i-1,j,t+1)||dfs(i,j-1,t+1)){
		return true;
	}
	mp[i][j]=1;
	return false;
}
int main(){
	while(read()){
		if(dfs(x,y,0))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
