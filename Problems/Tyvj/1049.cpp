#include<iostream>
using namespace std;
const int MAXN=5000;
int n,a[MAXN+3],f[MAXN+3],ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int ma=0;
		for(int j=1;j<i;j++){
			if(f[j]>ma&&a[j]<=a[i]){
				ma=f[j];
			}
		}
		f[i]=ma+1;
		if(f[i]>ans)ans=f[i];
	}
	cout<<ans;
	return 0;
}
