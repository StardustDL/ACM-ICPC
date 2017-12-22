/*
总数统计
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10000;
int n,a[MAXN+3],m,t,ans=0,x;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cin>>m;
	while(m-->0){
		cin>>t;ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]>t)break;
			for(int j=i+1;j<=n;j++){
				if(a[i]+a[j]>t)break;
				ans++;
			}
		}
		cout<<ans<<endl; 
	} 
	return 0;
}
