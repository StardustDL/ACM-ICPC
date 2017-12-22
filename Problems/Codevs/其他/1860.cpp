/*
最大数
分析：通过巧妙设计字符串比较，sort一遍即可 
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a[23];
int n;
bool cmp(const string &a,const string &b){
	/*方法1，此方法过不了1649，说明此方法有问题 
	int mi=min(a.length(),b.length());
	for(int i=0;i<mi;i++){
		if(a[i]>b[i])return true;
		else if(a[i]<b[i])return false;
	}
	if(mi==a.length())return b[mi]<=a[0];
	else{
		//cout<<a[mi]<<" "<<b[0]<<endl;
		return a[mi]>b[0];
	}*/
	return a+b>b+a;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<a[i];
	return 0;
}
