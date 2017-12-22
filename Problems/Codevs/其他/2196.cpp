/*
找朋友
分析：数据范围有问题 
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN=200000;
int n,a[MAXN+3];
string s[MAXN+3];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(s+1,s+n+1);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cout<<s[i]<<" "<<a[i]<<endl;
	}
	return 0;
}
