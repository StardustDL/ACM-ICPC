/*
Charm Bracelet
·ÖÎö£º01±³°ü 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=3500,MAXV=13000;
int opt[MAXV+3],n,m,w[MAXN+3],v[MAXN+3];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&w[i],&v[i]);
	for(int i=1;i<=n;i++)
		for(int j=m;j>=w[i];j--)opt[j]=max(opt[j-w[i]]+v[i],opt[j]);
	printf("%d\n",opt[m]);
	return 0;
}

