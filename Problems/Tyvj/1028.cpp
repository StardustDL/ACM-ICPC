/*
Bessie的体重问题
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=45000;
int n,w,h,opt[MAXN+3];
int main(){
	cin>>h>>n;
	while(n-->0){
		cin>>w;
		for(int i=h;i>=w;i--)opt[i]=max(opt[i],opt[i-w]+w);
	}
	cout<<opt[h];
	return 0;
}
