/*
[Usaco2005 Open] Muddy roads 泥泞的路
分析：按左端点排序，然后直接做 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
struct segment{
	int l,r;
	bool operator <(const segment &s)const{
		return l<s.l;
	}
}s[MAXN+3];
int n,l,ans=0;
int main(){
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)scanf("%d%d",&s[i].l,&s[i].r);
	sort(s+1,s+n+1);
	for(int i=1,now=0,cnt;i<=n;i++){
		if(now>=s[i].r)continue;
		now=max(s[i].l,now);
		cnt=(s[i].r-now)/l+((s[i].r-now)%l!=0);//注意余下的部分 
		ans+=cnt;
		now+=cnt*l;
	}
	printf("%d\n",ans);
	return 0;
}

