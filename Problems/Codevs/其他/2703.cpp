/*
длеё╢ЗюМил XII 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
int n,a[MAXN+3],ans=INF;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-3;i++){
		ans=min(ans,max(a[i+1]-a[i],max(a[i+2]-a[i+1],a[i+3]-a[i+2])));
	}
	cout<<ans;
	return 0;
}
