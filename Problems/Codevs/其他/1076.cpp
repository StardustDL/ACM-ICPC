/*
еепР 
*/ 
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100003;
int n,a[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
} 
