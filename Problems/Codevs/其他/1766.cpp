/*
装果子
分析：二分法，构建方式类似抄书问题 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100000;
int n,m,v[MAXN+3];
bool judge(long ans){
	long use=1,cur=0;
	for(int i=1;i<=n;i++){
		if(cur+v[i]>ans){
			cur=v[i];
			if(++use>m)return false;
			continue;
		}
		cur+=v[i];
	}
	return true;
}
long dichotomy(long l,long r){
	while(l<r){
		long mid=(l+r)>>1;
		if(judge(mid)){
			r=mid;
		}
		else l=mid+1;
	}
	return l;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	long mx=0;
	for(int i=1;i<=n;i++){
		cin>>v[i];mx=max(mx,v[i]);
	}
	cout<<dichotomy(mx,n/m*mx);
	return 0;
}
