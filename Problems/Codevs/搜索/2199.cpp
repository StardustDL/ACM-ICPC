/*
派对
分析：类似于质数环，固定了第一个元素就不用判重 
*/
#include<iostream>
#include<cmath>
#include<bitset>
using namespace std;
const int MAXN=10;
int n,k,a[MAXN+3],s[MAXN+3],ans=0,mn=1<<30,p=0;
bitset<MAXN+3> used=0;
void dfs(int ind){
	if(ind>n){
		if(abs(s[n]-s[1])<=k)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]&&abs(a[i]-s[ind-1])<=k){
			s[ind]=a[i];used[i]=1;
			dfs(ind+1);
			used[i]=0;
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	s[1]=a[1];used[1]=1;//不必找最小值放在这里，因为只要有解，a[1]在这就是可行的（注意是环） 
	dfs(2);
	cout<<ans;
	return 0;
}
