/*
小明学数数
*/
#include<iostream>
using namespace std;
int main(){
	int n,ans,t;
	cin>>n>>ans;
	for(int i=2;i<=n;i++){
		cin>>t;
		ans^=t;
	}
	cout<<ans;
	return 0;
}
