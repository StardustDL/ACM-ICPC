/*
n个数的最小公倍数
*/
#include<iostream>
using namespace std;
int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}
int lcm(int a,int b){return a/gcd(a,b)*b;}
int a,b,n,ans=0;
int main(){
	cin>>n;
	cin>>a;
	if(n==1){cout<<a;return 0;}
	cin>>b;
	a=lcm(a,b);
	n-=2;
	while(n-->0){
		cin>>b;
		a=lcm(a,b);
	}
	cout<<a;
	return 0;
}
