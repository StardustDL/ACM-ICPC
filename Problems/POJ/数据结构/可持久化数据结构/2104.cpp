/*
K-th Number
题意：静态查找区间第K小 
分析：若不是区间的，可以离散化后使用计数线段树，在线段树上找k大数时就像平衡树询问k大数一样根据结点上的信息往左或者往右走。【或者直接排个序= =】
	  由于是区间，所以可以想到维护每个前缀的计数线段树，然后利用区间前缀和的思想求第K小，这就是简易可持久化线段树 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
struct node{
	int lc,rc,sum;//lc表示这个节点的左子节点的下标，注意不能像普通线段树直接按堆的方式存 
}ns[20*MAXN+3];
int T[MAXN+3],tot;//tot维护结点内存池的大小，T存放每个线段树根节点 
void init(int l,int r,int &curt){//初始化curt这棵树，区间长度l..r，这一步和一般的线段树差不多，但节点上什么信息也没有 
	node &X=ns[(curt=++tot)];
	X.sum=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	init(l,mid,X.lc);
	init(mid+1,r,X.rc);
}
void change(int last,int val,int l,int r,int &curt){//修改结点last（其实是一棵子线段树）的val值计数+1，操作区间为l..r（这样不用在node中记录区间范围信息），由于要持久化，新节点为curt 
	node &X=ns[curt=++tot];
	X=ns[last];X.sum++;//复制信息，计数+1 
	if(l==r)return;
	int mid=(l+r)>>1;//求出此区间中点，若val在左边就递归左子树，注意这里和查询的区别 
	if(val<=mid)change(ns[last].lc,val,l,mid,X.lc);
	else change(ns[last].rc,val,mid+1,r,X.rc);
}
int query(int s,int t,int l,int r,int k){//查询两颗线段树s,t的差（对应题目中的区间），查询第K小 
	if(l==r)return l;
	int mid=(l+r)>>1,cnt=ns[ns[t].lc].sum-ns[ns[s].lc].sum;//求出左子树差=cnt,这要和k进行比较，同时要计算区间中点，这要保证递归有终止 
	if(k<=cnt)return query(ns[s].lc,ns[t].lc,l,mid,k);//在左子树内 
	else return query(ns[s].rc,ns[t].rc,mid+1,r,k-cnt);//在右子树内，求第k-cnt小 
}
int rank[MAXN+3],a[MAXN+3],n,m;
void solve(){
	int l,r,k;tot=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memcpy(rank,a,sizeof(a));
	sort(a+1,a+n+1);
	int cnt=unique(a+1,a+n+1)-a-1;//去重 
	init(1,cnt,T[0]);//初始化T[0] 
	for(int i=1;i<=n;i++)rank[i]=lower_bound(a+1,a+cnt+1,rank[i])-a;//离散化 
	for(int i=1;i<=n;i++)change(T[i-1],rank[i],1,cnt,T[i]);//修改 
	while(m--){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",a[query(T[l-1],T[r],1,cnt,k)]);//查询 
	}
}
int main(){
	solve();
	return 0;
}

