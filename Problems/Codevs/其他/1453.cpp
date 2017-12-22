/*
统计素数个数 2
*/ 
#include<iostream>
#include<bitset>
using namespace std;
const int MAXN=5000000;
bitset<MAXN+3> isp=0;
int a,b,s=0;
int main(){
	cin>>a>>b;
	isp[1]=1;
	for(int i=2;i<=b;i++){
		if(isp[i])continue;
		for(int j=i<<1;j<=b;j+=i)isp[j]=1;
	}
	for(int i=a;i<=b;i++)s+=!isp[i];
	cout<<s;
	return 0;
}
