/*
排列
分析：直接调函数，注意是求第k个 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int a[MAXN+3];
int main(){
	int m,n,k;
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		while(k--)next_permutation(a+1,a+n+1);
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		puts("");
	}
	return 0;
}

