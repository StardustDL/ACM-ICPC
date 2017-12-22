/*
Monster
题意：一个人，攻击力M，有N个敌人，每个敌人HPi,ATKi,每一秒人可以选择一个敌人攻击，同时所有活着的敌人会攻击他，问这个人需要的最少HP，使得能消灭所有敌人
分析：贪心。设打第i只怪兽的耗时为ti，怪兽攻击力为ci，解法是按ci/ti的值由大到小的顺序消灭怪兽。
	  证明：考虑如果在被消灭的序列里存在相邻的两个怪兽他们的ci/ti是小的在大的前面，则交换他俩的位置，对于除了他俩之外的其他怪兽的花费没有影响，但是他俩的花费之和减少了，所以在最优解里不存在这样的相邻项。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
int n,m,ts[MAXN+3],atk[MAXN+3],r[MAXN+3];
typedef long long LL;
bool cmp(int i,int j){
	return atk[i]*ts[j]>atk[j]*ts[i];
}
void input(){
	scanf("%d%d",&n,&m);
	int t;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&t,&atk[i]);
		ts[i]=(t+m-1)/m;//这里保证了向上进一 
		r[i]=i;
	}
}
LL solve(){
	sort(r+1,r+n+1,cmp);
	LL ans=0,tme=0;
	for(int i=1;i<=n;i++){
		tme+=ts[r[i]];//记录时间 
		ans+=tme*atk[r[i]];
	}
	return ans;
}
int main(){
	int T;scanf("%d",&T);
	for(int i=1;i<=T;i++){
		input();
		printf("Case #%d: %lld\n",i,solve());
	}
	return 0;
}

