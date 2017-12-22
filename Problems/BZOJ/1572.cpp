/*
[Usaco2009 Open]工作安排Job
分析：贪心：按截至时间从小到大，每次push进去，如果发现任务数量>当前时间，那么pop掉最小的。最后所有queue中剩下的数的和就是答案 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
struct data{
	int p,d;
	bool operator <(const data &t)const{
		return p>t.p;
	}
}ds[MAXN+3];
bool cmp(data a,data b){
	return a.d<b.d;
}
priority_queue<data> q;
long long ans=0;
int rest=0,n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&ds[i].d,&ds[i].p);
	sort(ds+1,ds+n+1,cmp);
	for(int i=1;i<=n;i++){
		q.push(ds[i]);rest++;ans+=ds[i].p;
		if(rest>ds[i].d){
			rest--;
			ans-=q.top().p;q.pop();
		}
	}
	printf("%lld\n",ans);
	return 0;
}

