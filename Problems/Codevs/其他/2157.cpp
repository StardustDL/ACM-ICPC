/*
配对
分析：排个序就好了 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10000;
int n,a[MAXN+3],b[MAXN+3],ans=0; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];b[i]*=-1;
	}
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)ans+=abs(a[i]+b[i]);
	cout<<ans;
	return 0;
}
