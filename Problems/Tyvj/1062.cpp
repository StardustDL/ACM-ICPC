#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=300,INF=1<<30;
int n,w[MAXN+3],s[MAXN+3],f[MAXN+3][MAXN+3],i,j,k;
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>w[i];
		s[i]=s[i-1]+w[i];
	}
	for(int len=2;len<=n;len++){
		for(i=1;i<=n-len+1;i++){
			j=i+len-1;
			int m=INF;
			for(k=i;k<j;k++){
				m=min(m,f[i][k]+f[k+1][j]);
			}
			f[i][j]=m+s[j]-s[i-1];
		}
	}
	cout<<f[1][n];
	return 0;
}
