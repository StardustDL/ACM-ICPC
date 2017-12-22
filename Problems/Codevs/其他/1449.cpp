/*
Çó½×³Ë
*/ 
#include<iostream>
using namespace std;
long ans=1;
int n;
int main(){
	cin>>n;
	for(int i=2;i<=n;i++)ans*=i;
	cout<<ans;
	return 0;
} 
