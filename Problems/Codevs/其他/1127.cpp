/*
接水问题
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
int a[103],t[10003],n,m; 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	for(int i=1;i<=m;i++)a[i]=t[i];
	for(int i=m+1;i<=n;i++){
		sort(a+1,a+m+1);
		a[1]+=t[i];
	}
	sort(a+1,a+m+1);
	printf("%d\n",a[m]);
	return 0;
}

