/*
¹í¹È×ÓµÄÇ®´ü
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
typedef long long LL;
LL m;
int ans;
int main(){
	scanf("%lld",&m);
	ans=0;
	while((1LL<<ans)<m)ans++;
	printf("%d\n",ans);
	return 0;
}

