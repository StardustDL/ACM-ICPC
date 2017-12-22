/*
第K个数
分析：注意差值小于0的情况 
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=10000;
int n,a[MAXN+3],k,t;
bool isprime(int t){
	if(t<0)return false;
	for(int i=2;i<=sqrt(t);i++){
		if(t%i==0)return false;
	}
	return true;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(isprime(a[n-k+1]-a[k]))cout<<"YES";
	else cout<<"NO";
	cout<<endl<<a[n-k+1]-a[k];
	return 0;
}
