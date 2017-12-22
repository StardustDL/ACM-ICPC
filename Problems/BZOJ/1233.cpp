/*
分析：刚开始想的贪心，后来发现不行，不过还是发现了一个性质 ：
		在多种可行的堆叠方案中，至少有一种能使层数最高的方案同时使得底边最短。即底边最短的，层数一定最高。 
		证明（网上）：任意取出一个能使层数最高的方案，设有CA层，把其中从下往上每一层最大的块编号记为Ai；任取一个能使底边最短的方案，设有CB层，把其中从下往上每一层最大的块编号记为Bi。显然A1>=B1,ACB<=BCB，这说明至少存在一个k属于(1,CB)，满足Ak-1>=Bk-1且Ak<=Bk。也就是说，方案 A 第K 层完全被方案 B 第K 层包含。构造一个新方案，第K 层往上按方案 A，往下按方案 B，两边都不要的块放中间当第K 层。新方案的层数与 A 相同，而底边长度与 B 相同。证毕。
	     知道这个结论后，贪心就明显不可行了。比如a + b> c+ d,b + c < d,贪心的结果是a,b,c||d,而a,b||c,d则更优。
     设f[i]为第i..N个干草包所叠成的塔底层最短边的值,同时用g[i]记下此时的层数。
	  DP:
		f[i]=min(sum[j-1]-sum[i-1]),(j>i,f[j]<=sum[j-1]-sum[i-1])
		显然f[i]从较小的j转移过来结果会更优(如果符合转移条件的话)
		而对于转移条件 f[j]<=sum[j-1]-sum[i-1] 我们把式子移项得到 sum[i-1]<=sum[j-1]-f[j]
		这样的话 对于决策j 显然sum[j-1]-f[j]越大 可以作为决策的情况就越多 而同时，j越小越好
		因此如果存在决策k>j 满足 sum[k-1]-f[k]<=sum[j-1]-f[j] 那么决策k便一定不能用上
		于是这个问题就转变为了用单调队列来维护单调性DP的经典模型了 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
int n,w[MAXN+3];
int f[MAXN+3],g[MAXN+3],q[MAXN+3],l,r;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&w[i]);w[i]+=w[i-1];}
	l=r=1;q[1]=n+1;
	for(int i=n;i;i--){
		while(l<r && w[q[l+1]-1]-w[i-1]>=f[q[l+1]])l++;//保证解可行的最小的q[l] 
		f[i]=w[q[l]-1]-w[i-1];
		g[i]=g[q[l]]+1;
		while(l<r && w[q[r]-1]-f[q[r]]<w[i-1]-f[i])r--;//按上面的分析得到的优化，解i一定优于q[r] 
		q[++r]=i;
	}
	printf("%d\n",g[1]);
	return 0;
}

