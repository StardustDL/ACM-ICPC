/*
[Usaco2008 Open]Cow Neighborhoods 奶牛的邻居
分析：一个非常巧妙的方法求曼哈顿距离：
	  如果原来坐标是(x, y)，令新的坐标为(X, Y), 其中X = x + y, Y = x - y
	  那么：曼哈顿距离 = |x1 - x2| + |y1 - y2| = max(|X1 - X2|, |Y1 - Y2|)
	  于是我们先进行坐标变换，按X排序。
	  然后用一个队列来做，满足队尾X - 队首X < c。
	  对这个队列中每个点的Y维护一棵平衡树，如果新加入元素的前驱后继与它的Y值差值不超过c，则用并查集将他们连在一起。
	  （其实就是类似kruskal的改进版本）
	  使用了STL的multiset
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long LL;
const int MAXN=100000;
const LL INF=1LL<<56;
struct point{
	LL x,y;int p;
	bool operator <(const point &p)const{
		return y<p.y;
	}
	point(){}
	point(LL x,LL y,int p):x(x),y(y),p(p){}
}ps[MAXN+3];
set<point>::iterator it;
int n,c,pa[MAXN+3],cur,cnt[MAXN+3],ans;
multiset<point> S;
bool cmp(const point &a,const point &b){
	return a.x<b.x;
}
int find(int x){
	return pa[x]==x?x:pa[x]=find(pa[x]);
}
void unite(int a,int b){
	if(find(a)!=find(b)){
		pa[find(a)]=find(b);
		ans--;
	}
}
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)pa[i]=i;
	for(int i=1,a,b;i<=n;i++){
		scanf("%d%d",&a,&b);
		ps[i].x=a+b,ps[i].y=a-b;ps[i].p=i;
	}
	ans=n;
	sort(ps+1,ps+n+1,cmp);
	S.insert(point(0,-INF,0));
	S.insert(point(0,INF,0));
	S.insert(ps[1]);
	cur=1;
	point l,r;
	for(int i=2;i<=n;i++){
		while(ps[i].x-ps[cur].x>c){
			S.erase(S.find(ps[cur++]));
		}
		//cout<<ps[i].p<<" "<<i<<endl;
		it=S.lower_bound(ps[i]);
		r=*it;l=*--it;
		if(ps[i].y-l.y<=c)unite(ps[i].p,l.p);
		if(r.y-ps[i].y<=c)unite(ps[i].p,r.p);
		S.insert(ps[i]);
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)++cnt[find(i)];
	printf("%d %d\n",ans,*max_element(cnt+1,cnt+n+1));
	return 0;
}

