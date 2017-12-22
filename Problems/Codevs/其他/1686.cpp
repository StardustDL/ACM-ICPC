/*
图书分配
分析：和抄书问题一样，二分答案，贪心的验证答案 
*/
#include<iostream>
using namespace std;
const int MAXM=100000;
int m,k,page[MAXM+3],s=0;
bool check(int ans){
	int t=page[1],cnt=0;
	for(int i=2;i<=m;i++){
		if(page[i]>ans)return false;
		if(t+page[i]<=ans)t+=page[i];
		else cnt++,t=page[i];
	}
	return ++cnt<=k;
}
int dichotomy(int l,int r){
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>page[i];
		s+=page[i];
	}
	cout<<dichotomy(0,s);
	return 0;
}
