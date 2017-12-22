/*
����������Ӿ���
������ת�ƺܺ��룬��Ҫע��������ת�Ʒ��� 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1003;
bool mp[MAXN][MAXN];
int opt[MAXN][MAXN],n,m;
void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>mp[i][j];
	}
}
//�ж�һ���Ƿ�����Ҫ��len�������Ҫ�������䳤�ȣ�������ǰ�㣬���Բ��á�1 
bool check(int x,int y,int len,bool isright){ 
	for(int i=x-1;i>=x-len/*+1*/;i--){
		if(mp[i][y])return false;
	}
	if(isright){
		for(int i=y+1;i<=y+len/*-1*/;i++)if(mp[x][i])return false;
	}
	else{
		for(int i=y-1;i>=y-len/*+1*/;i--)if(mp[x][i])return false;
	}
	return true;
}
int dpleft(){//DP���ϽǾ���
	int ans=0;
	memset(opt,0,sizeof(opt));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!mp[i][j])continue;
			if(check(i,j,opt[i-1][j-1],false)){
				ans=max(opt[i][j]=opt[i-1][j-1]+1,ans);
			}
			else opt[i][j]=0;
		}
	}
	return ans;
}
int dpright(){//DP���ϽǾ��� 
	int ans=0;
	memset(opt,0,sizeof(opt));
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(!mp[i][j])continue;
			if(check(i,j,opt[i-1][j+1],true)){
				ans=max(opt[i][j]=opt[i-1][j+1]+1,ans);
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	input();
	cout<<max(dpleft(),dpright());
	return 0;
}
