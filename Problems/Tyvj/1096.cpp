#include<iostream>
using namespace std;
const int MAXN=100,MAXM=10000;
int n,a[MAXN+3],m,opt[MAXM+3];
void read(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
}
int solve(){
	opt[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=a[i];j--){
			opt[j]+=opt[j-a[i]];
		}
	}
	return opt[m];
}
int main(){
	ios::sync_with_stdio(false);
	read();
	cout<<solve();
	return 0;
}

