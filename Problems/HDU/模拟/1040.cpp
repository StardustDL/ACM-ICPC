/*
As Easy As A+B
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int a[MAXN+3],n; 
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		printf("%d",a[1]);
		for(int i=2;i<=n;i++)printf(" %d",a[i]);
		puts("");
	}
	return 0;
}

