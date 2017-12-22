//Î´Íê³É 
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2000;
int n,a[MAXN+3],s[MAXN+3],opt[MAXN+3][MAXN+3];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}

	for(int i=1;i<=n;i++){//rest:i
		for(int j=1;j<=n;j++){
			int &t=opt[i][j];
			for(int k=1;k<=2*j&&k<=i;k++){
				t=max(t,s[i]-opt[i-k][k]);
			}
		}
	}
	
	cout<<opt[n][1];
	return 0;
}
