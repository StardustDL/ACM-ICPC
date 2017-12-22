/*
≈≈∂”Œ Ã‚
*/
#include<iostream>
using namespace std;
const int MAXN=150; 
long long opt[MAXN+3],n;
int main(){
	cin>>n;
	opt[1]=0;opt[2]=1;opt[3]=1;
	for(int i=4;i<=n;i++)opt[i]=opt[i-2]+opt[i-3];
	cout<<opt[n];
	return 0;
}
