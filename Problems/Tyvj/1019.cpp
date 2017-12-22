/*
≈‰∂‘
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=10000;
int n,a[MAXN+3],b[MAXN+3],ans=0;
bool cmp(int i,int j){return i>j;}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=n;j++)cin>>b[j];
	sort(a+1,a+n+1);sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)ans+=abs(a[i]-b[i]);
	cout<<ans;
	return 0;
}
