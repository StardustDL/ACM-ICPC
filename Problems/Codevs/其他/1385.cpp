/*
挤牛奶
分析：统计一下即可，注意区间的边界 
*/
#include<iostream>
#include<algorithm>
using namespace std;
int f[5003],e[5003],r[5003],n,ll=0,kk=0;
bool cmp(const int i,const int j){
	return (f[i]<f[j])||(f[i]==f[j]&&e[i]>e[j]);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i]>>e[i];
		r[i]=i;
	}
	sort(r+1,r+n+1,cmp);
	int fr=0,en=0;
	if(n==1){
		cout<<e[1]-f[1]<<" "<<0;
		return 0;
	}
	fr=f[r[1]];
	en=e[r[1]];
	ll=en-fr;
	for(int i=2;i<=n;i++){
		int t=r[i];
		if(f[t]>=fr&&e[t]<=en){
			continue;
		}
		if(f[t]<=en){
			en=e[t];
		}
		else{
			ll=max(ll,en-fr);
			kk=max(kk,f[t]-en);
			fr=f[t];en=e[t];
		}
	}
	cout<<ll<<" "<<kk;
	return 0;
}
