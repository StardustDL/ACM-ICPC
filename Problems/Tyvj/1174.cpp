/*
»¥ËØ
·ÖÎö£ºÇóphiº¯Êý 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
const int MAXN=1000,INF=0x3f3f3f3f;
int phi(int n){
	int m=floor(sqrt(n+0.5)),ans=n;
	for(int i=2;i<=m;i++){
		if(n%i==0){
			(ans/=i)*=i-1;
			while(!(n%i))n/=i;
		}
	}
	if(n>1)(ans/=n)*=n-1;
	return ans; 
}
int main(){
	int n;
	cin>>n;
	cout<<phi(n)<<endl;
	return 0;
}


