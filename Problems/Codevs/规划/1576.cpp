/*
最长严格上升子序列
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5003;
int n,a[MAXN],opt[MAXN],ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(opt,0,sizeof(opt));
	for(int i=1;i<=n;i++){
		opt[i]=1;
		for(int j=1;j<i;j++){
			if(a[j]<=a[i])opt[i]=max(opt[i],opt[j]+1);
		}
		ans=max(ans,opt[i]);
	}
	cout<<ans; 
	return 0;
} 
