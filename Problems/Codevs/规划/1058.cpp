/*
合唱队形
分析：先求最长上升最长下降子序列，然后枚举每个位置作为最高点时的解 
*/ 
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=103;
int n,a[MAXN],opt1[MAXN],opt2[MAXN];
void read(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
}
void LIS(){
	for(int i=1;i<=n;i++){
		opt1[i]=1;
		for(int j=1;j<i;j++){
			if(a[j]<a[i]&&opt1[j]+1>opt1[i]){
				opt1[i]=opt1[j]+1;
			}
		}
	}
	for(int i=n;i>=1;i--){
		opt2[i]=1;
		for(int j=n;j>i;j--){
			if(a[j]<a[i]&&opt2[j]+1>opt2[i]){
				opt2[i]=opt2[j]+1;
			}
		}
	}
}
int solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,opt1[i]+opt2[i]);
	}
	return n-ans+1;
}
int main(){
	ios::sync_with_stdio(false);
	read();
	LIS();
	cout<<solve();
	return 0;
} 
