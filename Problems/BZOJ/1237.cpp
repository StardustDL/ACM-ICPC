/*
[SCOI2008]配对
分析：本以为是二分图最大权匹配，但实际上不用
	  首先排序，若无配对元素不能相等这一 限制，则排序后一一匹配即可。
	  有了这个限制，那么对于相等的元素就要在其前后进行调整，显然，与距离较远的调整不如与距离近的调整优。
	  那么，需要在多大的范围内调整才能保证最优呢？大牛给出的结论是最多在上下三个元素内调整即可。怎么证明呢？
	  两个肯定是不行的，比如n=3，三个元素均对应相等，此时必须要三个元素之间调整。那么，若4个连续元素对应相等呢？此时前两个调整后两个调整即可得到最优。因此用不着四个调整。
	  这样的话 DP即可。opt[i]表示前i个元素匹配完的最优值。opt[i]由opt[i-1],opt[i-2],opt[i-3]转移
	  但long long 很烦人：最大值不要设成1LL<<62，这样加和时会爆，要用 0x7ffffffffffll（10个f），更大的数： 0x7ffffffffffffffll，若f更多，其二倍就会爆掉 
	  	然后-1要用-1LL，一切longlong数字均有后缀LL 
	  	long long 最长10^20 
*/ 
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const LL MAXN=100000,INF=0x7ffffffffffll;
int a[MAXN+3],b[MAXN+3],n;
LL opt[MAXN+3];
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d %d",&a[i],&b[i]);
	sort(a+1,a+n+1);sort(b+1,b+n+1);
}
LL G(LL a,LL b){return a==b?INF:abs(a-b);}//这样方便计算，但可能会因为INF+INF爆掉 
LL dp(){
	opt[1]=G(a[1],b[1]);
	opt[2]=min(opt[1]+G(a[2],b[2]),G(a[1],b[2])+G(a[2],b[1]));
	for(int i=3;i<=n;i++){
		opt[i]=opt[i-1]+G(a[i],b[i]);//可能会因为INF+INF爆掉
		opt[i]=min(opt[i],opt[i-2]+G(a[i-1],b[i])+G(a[i],b[i-1]));
		opt[i]=min(opt[i],opt[i-3]+
			min(G(a[i],b[i-1])+G(a[i-1],b[i-2])+G(a[i-2],b[i]),
				G(a[i],b[i-2])+G(a[i-1],b[i])+G(a[i-2],b[i-1])));
	}
	return opt[n]<INF?opt[n]:-1LL;//注意LL 
}
int main(){
	 printf("%lld",INF+INF);
	input();
	printf("%lld",dp());
	return 0;
}
