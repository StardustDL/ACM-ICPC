/*
FibonacciÊıÁĞ 3
*/
#include<iostream>
using namespace std;
int f1=1,f2=1,n,t;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	if(n==1||n==2){cout<<1;return 0;}
	n-=2;
	while(n-->0){
		t=f1+f2;
		f1=f2;
		f2=t;
	}
	cout<<f2;
	return 0;
}
