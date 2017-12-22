#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=10000;
map<int,int> ans;
int bt[MAXN+3],n,m=0;
int main(){
	cin>>n;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(ans.count(t)==0){
			bt[++m]=t;
			ans[t]=1;
		}
		else ans[t]++;
	}
	sort(bt+1,bt+m+1);
	for(int i=1;i<=m;i++){
		cout<<bt[i]<<' '<<ans[bt[i]]<<endl;
	}
	return 0;
}
