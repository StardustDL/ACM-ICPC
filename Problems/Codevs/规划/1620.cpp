/*
轮船问题
分析：先按x排序，然后找y的LIS 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5000;
struct node{
	int a,b;
	bool operator < (const node &t)const{
		return a<t.a || (a==t.a&&b<t.b);
	}
}ns[MAXN+3];
int n,opt[MAXN+3],ans=0;
int main(){
	cin>>n>>n>>n;
	for(int i=1;i<=n;i++){
		cin>>ns[i].a>>ns[i].b;
	}
	sort(ns+1,ns+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(ns[j].b<ns[i].b)opt[i]=max(opt[i],opt[j]);
		}
		opt[i]+=1;
		ans=max(ans,opt[i]);
	}
	cout<<ans;
	return 0;
}
