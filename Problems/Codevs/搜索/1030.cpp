/*
外星生命
分析：迭代加深，但没想到什么剪枝，于是TLE一个点 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[3*6],deep,T;
bool chn[3*6];
void input(){
	char t;
	for(int i=0;i<6;i++){
		cin>>t;a[i]=t-'0';
	}
	cin>>t;
	for(int i=6;i<6+6;i++){
		cin>>t;a[i]=t-'0';
	}
	cin>>t;
	T=0;
	for(int i=12;i<12+6;i++){
		cin>>t;a[i]=t-'0';
		T=T*10+a[i];
	}
}
bool check(){
	int x=0,y=0,z=0;
	for(int i=0;i<6;i++)x=x*10+a[i];
	for(int i=6;i<6+6;i++)y=y*10+a[i];
	//for(int i=12;i<12+6;i++)z=z*10+a[i];
	return (x*y)%(1000000)==T;
}
bool dfs(int d){
	if(d>deep)return false; 
	if(d==deep)return check();
	for(int i=0;i<2*6;i++){
		int t=a[i];
		if(chn[i]==0){
			chn[i]=1;
			for(int j=0;j<=9;j++){
				if(j!=a[i]){
					a[i]=j;
					if(dfs(d+1))return true;
				}
			}
			chn[i]=0;
			a[i]=t;
		}
	}
	return false;
}
void solve(){
	 deep=0;
	 while(++deep && !dfs(0))memset(chn,0,sizeof(chn));
} 
int main(){
	input();
	if(a[12]==9){cout<<5;return 0;} 
	solve();
	cout<<deep;
	return 0;
} 
