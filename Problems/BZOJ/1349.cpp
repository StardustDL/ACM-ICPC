/*
[Baltic2006]Squint
*/
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
LL n,ans;
int main(){
	cin>>n;
	ans=sqrt(n);
	if(ans*ans<n)ans++;
	cout<<ans<<endl;
	return 0;
}
