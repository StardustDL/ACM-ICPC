/*
¹ã²¥²ÙµÄ·³ÄÕ
*/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a[50001],ans1,ans2;
void read(){
	cin>>m;
	for(int i=1;i<=m;i++)cin>>a[i];
}
void solve(){
	sort(a+1,a+m+1);
	ans1=a[m>>1];
	ans2=0;
	for(int i=1;i<=m;i++){
		ans2+=abs(a[i]-ans1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	while(n-->0){
		read();
		solve();
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
