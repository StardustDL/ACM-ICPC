/*
[Usaco2007 Dec]挑剔的美食家
分析：贪心，按美味度从大到小排序，先满足要求高的牛，插入multiset中，找价值大于要求价值的最小的 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
struct data{
	int a,b;
	bool operator <(const data &d)const{
		return b<d.b;
	}
};
data d1[MAXN+3],d2[MAXN+3];
int n,m;
long long ans=0;
multiset<int> S;
typedef multiset<int>::iterator IIT;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&d1[i].a,&d1[i].b);
	for(int j=1;j<=m;j++)scanf("%d%d",&d2[j].a,&d2[j].b);
	sort(d1+1,d1+n+1);
	sort(d2+1,d2+m+1);
	for(int i=n,j=m;i>=1;i--){
		while(d1[i].b<=d2[j].b){S.insert(d2[j].a);j--;}
		IIT it=S.lower_bound(d1[i].a);
		if(it==S.end()){puts("-1");return 0;}
		ans+=*it;
		S.erase(it);
	}
	printf("%lld\n",ans);
	return 0;
}

