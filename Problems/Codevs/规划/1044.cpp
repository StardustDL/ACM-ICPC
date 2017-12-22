/*
拦截导弹
分析：第一问：最长不上升子序列
	  第二问：最长严格下降子序列 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=23;
int n=0,a[MAXN],opt[MAXN],ans1=0,ans2=0;
int main(){
	ios::sync_with_stdio(false);
	while(cin>>a[++n]);
	n--;//注意这里 
	memset(opt,0,sizeof(opt));
	for(int i=1;i<=n;i++){
		opt[i]=1;
		for(int j=1;j<i;j++){
			if(a[j]>=a[i])opt[i]=max(opt[i],opt[j]+1);
		}
		ans1=max(ans1,opt[i]);
	}
	memset(opt,0,sizeof(opt));
	for(int i=1;i<=n;i++){
		opt[i]=1;
		for(int j=1;j<i;j++){
			if(a[j]<a[i])opt[i]=max(opt[i],opt[j]+1);
		}
		ans2=max(ans2,opt[i]);
	}
	cout<<ans1<<endl<<ans2; 
	return 0;
} 
