#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100;
int n,k,fu[MAXN+3],fd[MAXN+3],dat[MAXN+3],ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>dat[i];
	
	for(int i=1;i<=n;i++){
		fu[i]=1;
		for(int j=1;j<i;j++){
			if(dat[j]<dat[i]&&fu[i]<fu[j]+1)fu[i]=fu[j]+1;
		}
	}
	for(int i=n;i>=1;i--){
		fd[i]=1;
		for(int j=n;j>i;j--){
			if(dat[j]<dat[i]&&fd[i]<fd[j]+1)fd[i]=fd[j]+1;
		}
	}
	
	for(int i=1;i<=n;i++){
		ans=max(fu[i]+fd[i]-1,ans);
	}
	cout<<n-ans;
	return 0;
}
