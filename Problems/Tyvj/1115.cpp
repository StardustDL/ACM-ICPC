#include<iostream>
using namespace std;
int n,a[103],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(ans=1000000;ans>=1;ans--){
		int t=a[1]%ans;
		for(int i=2;i<=n;i++){
			if(a[i]%ans!=t){
				t=-1;break;
			}
		}
		if(t!=-1){
			cout<<ans;
			break;
		}
	}
	return 0;
}
