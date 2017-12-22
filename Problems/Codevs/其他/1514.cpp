/*
×î¼òµ¥ÅÅÐò
*/
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[13];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)cout<<a[i]<<endl;
	return 0;
}
