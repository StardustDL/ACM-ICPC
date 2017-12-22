/*
[Usaco2005 qua]Bank Interest
·ÖÎö£º¸´Àû¼ÆËã= = 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k;
int main(){
	cin>>n>>m>>k;
	printf("%d",int(m*1.0*pow(1.0+n*1.0/100.0,k*1.0)));
	return 0;
}
