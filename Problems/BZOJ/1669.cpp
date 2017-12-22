/*
[Usaco2006 Oct]Hungry Cows¼¢¶öµÄÄÌÅ£
·ÖÎö£ºLIS 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5000,INF=0x3f3f3f3f;
int n,st[MAXN+3],tp=1;
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		int p=lower_bound(st,st+tp+1,x)-st;
		if(p==tp+1)st[++tp]=x;
		else st[p]=x;
	}
	printf("%d\n",tp-1);
	return 0;
}

