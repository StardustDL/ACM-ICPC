/*
取物品
分析：对每种物品计数，枚举每种物品，枚举其个数，借此累计数量，边界opt[0]=1 
*/
#include<iostream>
using namespace std;
const int MAXN=30,MAXD=1000;
int opt[MAXN+3],n,k,t,cnt[MAXD+3];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>t;cnt[t]++;
	}
	opt[0]=1;
	for(int i=1;i<=MAXD;i++){
		if(!cnt[i])continue;
		for(int j=k;j>=1;j--)
			for(int e=1;e<=cnt[i];e++)
				if(j-e>=0)opt[j]+=opt[j-e];
	}
	cout<<opt[k];
	return 0;
}
