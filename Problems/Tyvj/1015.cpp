#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100,MAXM=10,INF=1<<30;
int n,a[MAXM+3],opt[MAXN+3];
int solve(){
	for(int i=1;i<=n;i++)opt[i]=INF;
	opt[0]=0;
	for(int i=1;i<=MAXM;i++){
		for(int j=i;j<=n;j++){
			opt[j]=min(opt[j],opt[j-i]+a[i]);
		}
	}
	return opt[n];
}
int main(){
	ios::sync_with_stdio(false);
	for(int i=1;i<=MAXM;i++)cin>>a[i];
	cin>>n;
	cout<<solve();
	return 0; 
}
