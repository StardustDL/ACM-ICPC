/*
[Usaco2006 Mar]Mooo 奶牛的歌声
分析：两遍单调栈 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
int sta[MAXN+3],top,n,h[MAXN+3],v[MAXN+3],sum[MAXN+3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&h[i],&v[i]);
	top=0;
	for(int i=1;i<=n;i++){
		while(top && h[sta[top]]<h[i])top--;
		sta[++top]=i;
		if(top>1)sum[sta[top-1]]+=v[i];
	}
	top=0;
	for(int i=n;i>=1;i--){
		while(top && h[sta[top]]<h[i])top--;
		sta[++top]=i;
		if(top>1)sum[sta[top-1]]+=v[i];
	}
	printf("%d\n",*max_element(sum+1,sum+n+1));
	return 0;
}

