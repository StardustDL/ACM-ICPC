/*
¶ÑµÄÅÐ¶Ï
*/
#include<iostream>
using namespace std;
const int MAXN=100;
int n,a[MAXN+3];
bool dfs(int i){
	int l=i<<1,r=l+1;
	if(l<=n){
		if(a[l]>=a[i])return false;
		if(!dfs(l))return false;
	}
	if(r<=n){
		if(a[r]>=a[i])return false;
		if(!dfs(r))return false;
	}
	return true;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(dfs(1))cout<<"Yes";
	else cout<<"No";
	return 0;
} 
