/*
Ð¡³Ô
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXK=10000,MAXN=100;
int n,c,w[MAXN+3],v[MAXN+3],opt[MAXK+3];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>c;
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
		for(int j=c;j>=v[i];j--)
			opt[j]=max(opt[j],opt[j-v[i]]+w[i]);
	cout<<opt[c];
	return 0;
}
