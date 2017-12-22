/*
Least Common Multiple
题意：求多个数的LCM 
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
	int T,ans,m,a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&m);
		ans=1;
		while(m--){
			scanf("%d",&b);
			ans=ans/gcd(ans,b)*b;
		}
		printf("%d\n",ans);	 
	}
	return 0;
}

