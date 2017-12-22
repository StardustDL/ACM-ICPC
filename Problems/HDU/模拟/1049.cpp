/*
Climbing Worm
题意：一个虫子掉在了一个n长度深的井中，然后它每分钟可以爬u长度，然后要休息一分钟，在此期间它会掉下d长度，问最终爬出井需要多久。
分析：模拟 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int n,u,d;
int main(){
	while(cin>>n>>u>>d,n+u+d>0){
		int tme=0;
		while(n>0){
			if(tme&1)n+=d;
			else n-=u;
			tme++;
		}
		cout<<tme<<endl; 
	}
	return 0;
}

