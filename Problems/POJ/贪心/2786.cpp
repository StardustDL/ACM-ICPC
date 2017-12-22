/*
Keep the Customer Satisfied
题意：有一个公司有一条生产线，每单位时间只能生产一件产品，在开始的时候他会受到N个订单，每个订单有产品量q和截止日期d，过期无效，但是又一些订单会发生冲突，必须进行一定的调整，问最多能够保留多少订单使得这些订单都可以按时完成。
分析：先想的二分【一定是借教室的原因。。
	  其实贪心即可：按终止时间从小到大排序，因为一定要先选终止时间早的，这样维护前i个订单完成尽量多的最小结束时间time 
	  	对于一个新订单K，若其need[K]+time<=last[K]，则可以选这个订单（但这样不一定最优，所以之后要调整）
		若不满足上述条件，尝试去掉一个队列中的订单，使K可以选择（一换一，答案不变），这个交换要尽量使time更小，所以
		要比较已选订单中需要时间最长的E，若need[E]>need[K]，则将E变为K依然合法，且time减小
		最后的答案即为最终队列内的元素个数 
	  于是优先队列维护大根堆即可
	  注意队列为空的时候 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=800000;
priority_queue<int> q;
struct thing{
	int l,w;
	bool operator < (const thing &t)const{
		return l<t.l;
	}
}ts[MAXN+3];
int n;
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)scanf("%d%d",&ts[i].w,&ts[i].l);
		while(!q.empty())q.pop();
		sort(ts+1,ts+n+1);
		int cur=0;
		for(int i=1;i<=n;i++){
			if(cur+ts[i].w<=ts[i].l || (!q.empty()&&ts[i].w<q.top())){q.push(ts[i].w);cur+=ts[i].w;}
			if(cur>ts[i].l){cur-=q.top();q.pop();} 
		}
		printf("%d\n",q.size());
	}
	return 0;
}

