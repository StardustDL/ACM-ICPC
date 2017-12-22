/*
最小公倍数
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}
int main(){
	int a,b;
	while(cin>>a>>b)cout<<a/gcd(a,b)*b<<endl; 
	return 0;
}

