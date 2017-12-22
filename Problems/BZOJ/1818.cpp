/*
[Cqoi2010]内部白点
分析：首先证明不可能出现输出-1的情况：（其实黑点的增长只会发生在第一秒）
		反设白点i在第一秒时由于某个方向（设为上方）没有黑点，就没有变成黑点，而在后来又成为了黑点。
		此时在i点上方必有了黑点j，而j要成为黑点，j的上方必存在一个黑点，而那个黑点同时也在i的上方，
		所以i一开始将成为黑点，矛盾！
	  那么我们只需求出有多少个整点满足上下左右都存在黑点。
		离散化+树状数组
		x,y坐标分别排序，扫一遍，找出所有的横线和竖线，统计出横线、竖线上端点、竖线下端点。
		对统计出的数据进行排序，关键字为y，当y值相同时，上端点优先于横线优先于下端点。
		从下往上依次扫描，扫到横线时统计横线左右端点内（开区间）的竖线数量，扫到竖线下端点时竖线数量+1，扫到上端点时竖线数量-1（上边的优先级因此确立）。
		最后由于没有统计原先存在的黑点，再加上即可。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100000;
struct point{
	int x,y;
}a[MAXN+3];
struct line{
	int l,r,y,k;//k=0 横线,k=1 竖线下端点,k=-1 竖线上端点 
}s[MAXN*3+3];
int hash[MAXN+3],c[MAXN+3],n,cnt,ans;
inline int gethash(int x){
	return lower_bound(hash+1,hash+1+n,x)-hash;
}
bool cmp1(point a,point b){//横线统计 
	return a.y<b.y || a.y==b.y&&a.x<b.x;
}
bool cmp2(point a,point b){//竖线统计 
	return a.x<b.x || a.x==b.x&&a.y<b.y;
}
bool cmp3(line a,line b){
	return a.y<b.y || a.y==b.y&&a.k<b.k;
}
void pre(){
	sort(a+1,a+1+n,cmp1);
	for(int i=2;i<=n;i++)
		if(a[i].y==a[i-1].y){
			s[++cnt].l=gethash(a[i-1].x);
			s[cnt].r=gethash(a[i].x);
			s[cnt].y=a[i].y;
			s[cnt].k=0;
		}
	sort(a+1,a+1+n,cmp2);
	for(int i=2;i<=n;i++)
		if(a[i].x==a[i-1].x){
			int tmp=gethash(a[i].x);
			s[++cnt].y=a[i-1].y;
			s[cnt].l=tmp;
			s[cnt].k=1;
			s[++cnt].y=a[i].y;
			s[cnt].l=tmp;
			s[cnt].k=-1;
		}
}
#define lowbit(x) (x&-x) 
void add(int x,int v){
	for(;x<=n;x+=lowbit(x))c[x]+=v;
}
int sum(int x){
	int ret=0;
	for(;x>0;x-=lowbit(x))ret+=c[x];
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		hash[i]=a[i].x;
	}
	sort(hash+1,hash+1+n);
	pre();
	sort(s+1,s+1+cnt,cmp3);
	for(int i=1;i<=cnt;i++)
		if(s[i].k)add(s[i].l,s[i].k);
		else ans+=sum(s[i].r-1)-sum(s[i].l);//去掉两端点的部分 
	printf("%d\n",ans+n);
	return 0;
}
