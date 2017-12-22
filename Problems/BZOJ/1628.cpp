/*
[Usaco2007 Demo]City skyline
分析：答案置成n，维护单调递增栈，如果有相同高度的，那么答案可以-1。(注意题中给的是高度的变化过程，所以不可能有相邻两个相同） 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
int sta[MAXN+3],top=0,ans,n,tmp; 
int main(){
	scanf("%d%d",&n,&tmp);
	ans=n;
	for(int i=1,h;i<=n;i++){
		scanf("%d%d",&tmp,&h);
		while(top && sta[top]>h)top--;
		if(sta[top]==h)ans--;
		sta[++top]=h;
	}
	printf("%d\n",ans);
	return 0;
}

