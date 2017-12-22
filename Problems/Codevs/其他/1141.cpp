/*
数列
分析：看题目描述，很容易想到进制转换，将n转为2进制，然后将其当做k进制转成10进制 
*/
#include<iostream>
using namespace std;
long long n,k,ans=0,t=1;
int main(){
	cin>>k>>n;
	for(int i=0;(1<<i)<=n;i++){
		if(n&(1<<i))ans+=t;
		t*=k;
	}
	cout<<ans;
	return 0;
}
