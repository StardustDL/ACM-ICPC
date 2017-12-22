/*
Supermarket
题意：有N件商品，分别给出商品的价值和销售的最后期限，只要在最后日期之前销售处，就能得到相应的利润，并且销售该商品需要1天时间。问销售的最大利润。
分析：这是并查集专题中的一道题， 但是我怎么看都长得像是贪心题，于是顺着贪心的思路AC了.
		因为每卖一个产品要占用一个时间单位，所以，我们可以一个单位一个单位时间地依次决定，每个时间要卖哪个产品，并且保证每个单位时间卖出的产品都是利润最大的，这样便能保证最终结果是最大的。
		如果枚举时间从小到大的话，那么比较麻烦，更好的办法是从最后一个截至时间开始往前枚举， 这样的话，只要把截止时间大于这个时间段的产品都放入优先队列，其中利润最大的便是这时间所要的。 这个方法用排序+优先队列实现， 复杂度是 n log n， 在poj上用了 63ms
		但毕竟是并查集专题，于是又想了并查集的方法做。想了很久，发现实在是很难想到。于是偷偷地看了下用了并查集的题解，发现无法理解。。。
		时间一点一点地过去，突然我又发现好像可以用另一种贪心的方法来做，先把所有产品按照利润从大到小排序，然后这个把这个放在截止日期那天卖出，并做好标记，如果截至日期那天已经有其他产品占用了，那么可以把这个产品卖出的时间往前推，直到找到可以卖的那一天并标记好。 按照这种思路提交，AC了，不过却用了141 ms。
		用了这个方法之后，再回想了下并查集方法的代码， 瞬间恍然大悟， 所谓的用并查集做，实际上是对上面那种方法的优化！
		用并查集的关键之处是，我们知道按照上面那个方法，假设一个产品a占用了一个日期后，那么如果下次又有一个产品b和产品a的截止日期是相同的，但是那个日期以被占用了，所以就要往前移动1天，那么就可以用并查集进行标记，在a占用了那个日期后，把a的截止日期指向前一个日期，这样的话，可以直接查找到他要占用到哪一个时间。  用了并查集优化后，时间为47MS。
		下面的代码是不用并查集的。有时间码一下并查集方法 
*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=10000;
struct thing{
	int r,w;
	bool operator < (const thing &t)const{
		return w<t.w;
	}
}ts[MAXN+3];
priority_queue<thing>pq;
int n;
bool cmp(const thing &a,const thing &b){return a.r>b.r;}
bool input(){
	if(!(cin>>n))return false;
	for(int i=1;i<=n;i++)cin>>ts[i].w>>ts[i].r;
	return true;
}
int solve(){
	while(!pq.empty())pq.pop();
	int ans=0,cur=1;
	sort(ts+1,ts+n+1,cmp);
	for(int i=ts[1].r;i>=1;i--){
		while(cur<=n&&ts[cur].r>=i)pq.push(ts[cur++]);
		if(!pq.empty()){
			ans+=pq.top().w;pq.pop();
		}
	}
	return ans;
}
int main(){
	while(input())cout<<solve()<<endl;
	return 0;
}
