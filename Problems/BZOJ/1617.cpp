/*
[Usaco2008 Mar]River Crossing渡河问题
分析：DP，注意是w的前缀和 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2500,INF=0x3f3f3f3f;
int n,m,w[MAXN+3],opt[MAXN+3]; 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%d",&w[i]);w[i]+=w[i-1];}
	memset(opt,INF,sizeof(opt));
	opt[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			opt[i]=min(opt[i],opt[i-j]+w[j]+2*m);
		}
	}
	printf("%d\n",opt[n]-m);
	return 0;
}

