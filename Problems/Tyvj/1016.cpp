#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=30,MAXV=20000;
int f[MAXV+3],v,n,m;
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>v;
		for(int j=m;j>=v;j--){
			f[j]=max(f[j],f[j-v]+v);
		}
	}
	cout<<m-f[m];
	return 0;
}
