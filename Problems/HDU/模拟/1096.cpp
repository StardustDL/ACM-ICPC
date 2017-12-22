/*
A+B for Input-Output Practice (VIII)
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int n,m,sum=0,t;
int main(){
	int T;scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&m);sum=0;
		while(m--){scanf("%d",&t);sum+=t;}
		printf("%d\n",sum);
		if(i<T)puts("");
	}
	return 0;
}

