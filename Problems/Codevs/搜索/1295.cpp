/*
N皇后问题
分析：按行设置，列比较好判断，对角线有一个比较好的方法：
	  对于(x,y)，之前的皇后(i,t)在其对角线上的条件是： 
	   t+i==x+y || i-t==x-y
*/
#include<iostream>
using namespace std;
const int MAXN=13;
int n,d[MAXN+3],ans=0;
bool check(int x,int y){
	for(int i=1;i<x;i++){
		int t=d[i];
		if(t==y || t+i==x+y || i-t==x-y)return false;
	}
	return true;
}
void dfs(int ind){
	if(ind>n){
		ans++;return;
	}
	for(int i=1;i<=n;i++){
		if(check(ind,i)){
			d[ind]=i;
			dfs(ind+1);
		}
	}
}
int main(){
	cin>>n;
	dfs(1);
	cout<<ans;
	return 0;
}
