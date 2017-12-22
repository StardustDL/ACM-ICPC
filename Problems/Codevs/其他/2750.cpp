/*
心系南方灾区
*/
#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>m>>n;
	cout<<(m%n==0?m/n:m/n+1);
	return 0;
}
