/*
[Usaco2007 Demo]Cow Acrobats
分析：贪心。
		首先，对于一个排列，交换相邻两项，对其他项没有影响。
		假设现在a under b，则有两个危险值为 w[b]+sum-s[a](1),sum-s[b](2)
			如果b under a，则有两个危险值为 w[a]+sum-s[b](3),sum-s[a](4)
		注意(2)<(3),(4)<(1)，所以最终是比较前两个，交换ab的条件就是 w[a]+sum-s[b]<w[b]+sum-s[a]
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
struct data{
	int w,s;
	bool operator <(const data &t)const{
		return t.w-s<w-t.s;//cur在t下面的条件 
	}
}ds[MAXN+3];
int n,sum=0,ans=-INF;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&ds[i].w,&ds[i].s);
	sort(ds+1,ds+n+1);
	for(int i=n;i>=1;i--){
		ans=max(ans,sum-ds[i].s);
		sum+=ds[i].w;
	}
	printf("%d\n",ans);
	return 0;
}

