/*
数字积木
分析：其实就是“最大数”的升级版，但是改下范围就A了 
	  通过巧妙设计字符串比较，sort一遍即可 
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a[1003];
int n;
bool cmp(const string &a,const string &b){
	return a+b>b+a;
}
int main(){
	ios::sync_with_stdio(false); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<a[i];
	return 0;
}
