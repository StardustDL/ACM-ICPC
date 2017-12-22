/*
Rightmost Digit
题意：求N^N的个位数
分析：快速幂，还可以找规律，发现20个一循环 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef long long LL; 
LL ksm(LL a,LL n){
	LL ans=1;
	while(n){
		if(n&1)ans=(ans*a)%10;
		a=(a*a)%10;
		n>>=1;
	}
	return ans;
}
int main(){
	int T;LL n,ans;
	cin>>T;
	while(T--){
		cin>>n;
		cout<<ksm(n,n)<<endl;
	}
	return 0;
}

