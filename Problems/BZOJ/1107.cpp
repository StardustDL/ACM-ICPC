/*
[POI2007]驾驶考试egz
分析：首先有一个结论：一个出发点能到达所有的出路的充要条件是能够到达最左边和最右边的路。
		于是将所有边反向，统计最左边和最右边的上面开始，同时能够到达的出发点数目，就是原来的可行出发点数。
		然后加边怎么办呢？ 
		我们把每条路反向后左右两个方向分开处理，例如从左向右，把边按照m[i]从上到下排序。
		然后以n[i]为关键字做最长单调子序列，使用二分优化、
		对于第i条路，i-1-(n[i]小于i的路组成的最长单调子序列长度)就是至少加的边数。
		把这个记为lt[i],类似计算出rt[i]，显然lt,rt都是单调的。
		于是我们只要满足lt[i]+rt[j]<=k(i>=j)那么用i-j+1跟新答案即可，发现i增加时，j的最大值也增加，O(n)两个指针扫一遍即可。	
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=100000;
struct data{
	int pos,val;//pos是在东西上的位置， val是南北上的位置 
	data() {}
	data(int p,int v):pos(p),val(v) {}
}a1[MAXN+3],a2[MAXN+3];//a1维护反向后，从左到右的边 ，a2 维护反向后，从右到左的边
int tot1,tot2;
int n,m,p,k,ans;
int l[MAXN+3],r[MAXN+3];
bool cmp1(const data &x,const data &y){
	return x.pos < y.pos || x.pos == y.pos && x.val < y.val;//按东西位置排序，其次按南北从小到大，因为是反向了，南北方向上，大的可以到小的 
}
bool cmp2(const data &x,const data &y){
	return x.pos > y.pos || x.pos == y.pos && x.val < y.val;
}
int c[MAXN+3];
void add(int x,int y){
	for(;x;x-=x&-x)c[x]=max(c[x],y);
}
int getmax(int x){
	int re=0;
	for(;x<=m;x+=x&-x)re=max(re,c[x]);
	return re;
}
int main(){
	int i,j,x,y,z;
	cin>>n>>m>>p>>k;++m;
	for(i=1;i<=p;i++){
		scanf("%d%d%d",&x,&y,&z);++y;
		if(z)a1[++tot1]=data(x+1,y);
		else a2[++tot2]=data(x,y);
	}
	sort(a1+1,a1+tot1+1,cmp1);
	sort(a2+1,a2+tot2+1,cmp2);
	l[0]=r[n+1]=-1;
	memset(c,0,sizeof(c));
	for(j=1,i=1;i<=n;i++){
		l[i]=l[i-1]+1;
		for(;j<=tot1&&a1[j].pos==i;j++){
			int temp=getmax(a1[j].val)+1;
			l[i]=min(l[i],(i-1)-temp);
			add(a1[j].val,temp);
		}
	}
	memset(c,0,sizeof(c));
	for(j=1,i=n;i;i--){
		r[i]=r[i+1]+1;
		for(;j<=tot2&&a2[j].pos==i;j++){
			int temp=getmax(a2[j].val)+1;
			r[i]=min(r[i],(n-i)-temp);
			add(a2[j].val,temp);
		}
	}
	for(j=1,i=1;i<=n;i++){
		for(;i-j+1&&l[i]+r[j]>k;j++);
		ans=max(ans,i-j+1);
	}
	for(i=1;i<=n;i++)
		if(!l[i]&&!r[i])--ans;//把以前就可行的（两边都不需要加边）去掉 
	cout<<ans<<endl;
	return 0;
}


