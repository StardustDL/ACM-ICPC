/*
Yogurt factory
题意：有n周，第i周：需要向外供货yi，生产1单位成本ci。若非本周生产的货物不在本周销售，需要贮藏，1单位贮藏一周需要花费s，注意不会变质。问n周供货供需花费多少钱（成本和贮藏费）。
分析：由于不会变质，问题简单得多，贪心，我们用mn记录当前的最小单价，然后以最小单价买入，这个最小单价，要么是现在的单价，要么是之前的最小单价＋贮藏费。mn中被替换掉的值是不可能是以后的最小单价的。因为现在被替换，同时＋上若干个s之后它还是会比现在替换它的那个值大。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef long long LL; 
int n,c,y,s,mn=INF;
LL ans=0; 
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c,&y);
		mn=min(mn,c);
		ans+=((LL)mn*y);
		mn+=s;
	}
	printf("%lld",ans);
	return 0;
}

