/*
纪念品分组
*/
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[30001],s,l,r;
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	l=1,r=n;
	while(r>=l){
		if(a[l]+a[r]<=m)l++;
		s++;r--;
	}
	cout<<s;
	return 0;
}
