/*
[Baltic2004]sequence
分析：先考虑只要求z1<=z2<=...<=zn：两个特殊情况：
		t[1]<=t[2]<=...<=t[n]，此时z[i] = t[i].
		t[1]>=t[2]>=...>=t[n]，此时z[i]=x，x为序列t的中位数.
		于是可以将原数列划分成m个区间，每一段的解为该区间的中位数。
	  实现：
		假设已经求出了前k个数的最优解，被划分成了m个区间，每段区间的最优解为w[i](w[1]<=w[2]<=...<=w[m])，现在考虑第k + 1个数，先将t[k + 1]单独看作一个区间，最优解为w[m+1]，此时假如w[m]>w[m+1]，则合并区间m，m + 1，然后找出新区间的解（中位数），重复上述过程直到w[m]<=w[m+1].
		如何维护中位数：当堆的大小大于区间长度的一半时删除堆顶元素，则堆中的元素一定是该区间内较小的一半元素，堆顶元素即为该区间的中位数。
		这只是z1<=z2<=...<=zn的情况。
		然而要求递增只需要将原本的t[i]改成t[i] - i，再按照上述做法做就行了orz。 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
int v[MAXN+3],ch[MAXN+3][2],dist[MAXN+3],sz[MAXN+3],rt[MAXN+3],tot=0,l[MAXN+3],r[MAXN+3];
int merge(int x,int y){
	if(!x || !y)return x^y;
	if(v[x]<v[y])swap(x,y);
	ch[x][1]=merge(ch[x][1],y);
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
	if(dist[ch[x][0]]<dist[ch[x][1]])swap(ch[x][0],ch[x][1]);
	dist[x]=dist[ch[x][1]]+1;
	return x;
}
void pop(int &x){x=merge(ch[x][0],ch[x][1]);}
int newnode(int x){
	v[++tot]=x;sz[tot]=1;
	ch[tot][1]=ch[tot][1]=dist[tot]=0;
	return tot;
}
int n,a[MAXN+3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);a[i]-=i;}
	int cnt=0;
	for(int i=1;i<=n;i++){
		rt[++cnt]=newnode(a[i]);
		l[cnt]=r[cnt]=i;
		while(cnt>1 && v[rt[cnt]]<v[rt[cnt-1]]){//注意是cnt>1 
			cnt--;
			rt[cnt]=merge(rt[cnt],rt[cnt+1]);
			r[cnt]=r[cnt+1];
			while(sz[rt[cnt]]*2>(r[cnt]-l[cnt]+2))pop(rt[cnt]);
		}
	}
	long long ans=0;
	for(int i=1;i<=cnt;i++){
		int t=v[rt[i]];
		for(int j=l[i];j<=r[i];j++)ans+=abs(t-a[j]);
	}
	printf("%lld\n",ans);
	return 0;
}

