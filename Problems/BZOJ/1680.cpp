/*
[Usaco2005 Mar]Yogurt factory
分析：贪心，和之前的最小值比较，选更优的 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=1000,INF=0x3f3f3f3f;
int n,c,y,s;
LL ans,l;
int main(){
	scanf("%d%d",&n,&s);
	l=INF-s;
	while(n--){
		scanf("%d%d",&c,&y);
		l=min(l+s,(LL)c);//这样支持加多个s 
		ans+=(LL)l*y;
	}
	printf("%lld\n",ans); 
	return 0;
}

