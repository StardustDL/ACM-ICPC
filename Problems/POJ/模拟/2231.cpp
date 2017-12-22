/*
Moo Volume
题意：给定n个数字。问任意两数之间的差的总和是多少。 
分析：排序后，扫一遍，找找规律，注意这题求“噪音”，要乘2 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
typedef long long LL; 
int n,a[MAXN+3];
LL ans=0,t=0; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		t+=(i-1)*(LL(a[i]-a[i-1]));
		ans+=t;
	}
	printf("%lld",ans<<1); 
	return 0;
}

