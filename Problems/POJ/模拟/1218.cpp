/*
THE DRUNK JAILER
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int main(){
	int T,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&x);
		printf("%d\n",(int)sqrt((double)x));
	}
	return 0;
}

