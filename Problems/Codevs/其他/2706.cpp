/*
计算应交税款
*/
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n<=1000)cout<<0;
	else if(n<=5000)cout<<(n-1000)*0.1;
	else if(n<=10000)cout<<(n-1000)*0.1+(n-5000)*0.09;
	else cout<<(n-1000)*0.1+(n-5000)*0.09+(n-10000)*0.08;
	return 0;
}
