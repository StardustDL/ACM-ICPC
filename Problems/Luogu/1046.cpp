#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int a[10],t,n=0;
int main(){
	for(int i=0;i<10;i++)cin>>a[i];
	cin>>t;t+=30;
	for(int i=0;i<10;i++)if(t>=a[i])n++;
	cout<<n;
	return 0;
}


