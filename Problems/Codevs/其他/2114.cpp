/*
撕邮票
分析：好像是斐波那契数列，但数据与题意不符，AC不了 
*/
#include<iostream>
using namespace std;
int n,a1=1,a2=1,t;
int main(){
	cin>>n;
	n-=2;
	while(n-->0){
		t=a1+a2;
		a2=a1;
		a1=t;
	}
	cout<<a1;
	return 0;
}
