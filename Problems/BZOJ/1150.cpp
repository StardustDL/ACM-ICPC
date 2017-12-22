/*
[CTSC2007]数据备份Backup
分析：首先，易知一定选的是相邻的，另外这K对点相异，不失一般性，设每个点和他前面的点配对，这样每个点有了一个权值d[i]-d[i-1] 
	  可以想到贪心，但如何维护呢？
	  刚开始一定是选权值最小的，但这样会使得这个点左右两个点不可选，这样可能导致结果不优
	  所以插入新点，将这三个点替换：权值是left[x]+right[x]-val[x]，这样选了这个点，就自然将x点抵消了
	  用优先队列或平衡树维护都可以
	  边界处理：val[1]=INF,val[n+1]=INF
	  因为选了第一个点，他左边没有点，这样选一定不优，
	  选了第n个点，为保证之后不会选择n+1这个不存在的点，设成INF
	  Ps:0x3f3f3f3f略大于106000000 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define P(x) (pre[x])
#define N(x) (nxt[x])
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
struct data{
	int pos,val;
	data(int p,int v):pos(p),val(v){}
	bool operator <(const data &t)const{
		return val<t.val||val==t.val&&pos<t.pos;
	}
};
int nxt[MAXN+3],pre[MAXN+3],val[MAXN+3],d[MAXN+3],n,k,ans;
set<data> S;
set<data>::iterator it;
int main(){
	scanf("%d%d",&n,&k);;
	for(int i=1;i<=n;i++){scanf("%d",&d[i]);val[i]=d[i]-d[i-1];}
	val[1]=INF;val[n+1]=INF;
	for(int i=2;i<=n;i++){
		nxt[i]=i+1;
		pre[i]=i-1;
		S.insert(data(i,val[i]));
	}
	for(int i=1,pos;i<=k;i++){
		it=S.begin();
		pos=(*it).pos;
		ans+=(*it).val;
		S.erase(data(pos,val[pos]));
		S.erase(data(P(pos),val[P(pos)]));
		S.erase(data(N(pos),val[N(pos)]));
		val[pos]=val[P(pos)]+val[N(pos)]-val[pos];
		S.insert(data(pos,val[pos]));
		P(pos)=P(P(pos));
		N(pos)=N(N(pos));
		if(P(pos))N(P(pos))=pos;
		if(N(pos))P(N(pos))=pos;
	}
	printf("%d\n",ans);
	return 0;
}

