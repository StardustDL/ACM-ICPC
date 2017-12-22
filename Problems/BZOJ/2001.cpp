/*
[Hnoi2010]City 城市建设
分析：动态最小生成树，CDQ分治，并不断缩小图的规模
	  两个关键的操作：
  		Reduction(删除无用边)：
  		把待修改的边标为INF，做一遍MST，把做完后不在MST中的非INF边删去（因为这些边在原图的情况下肯定更不可能选进MST的边集，即无用边）；
  		Contraction(缩必须边)：
  		把待修改的边标为-INF，做一遍MST，在MST中的非-INF边为必须边（因为这些边在原图的情况下也一定会被选进MST），缩点。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=20000,MAXQ=50000,MAXM=50000,INF=0x3f3f3f3f;
typedef long long LL;
struct query{int x,y;}q[MAXQ+3];
struct edge{
	int pos,u,v,w;
	bool operator <(const edge &e)const{
		return w<e.w;
	}
}e[25][MAXM+3],d[MAXM+3],t[MAXM+3];
int n,m,Q;
LL ans[MAXQ+3];
int pa[MAXN+3],sz[MAXN+3],cnt[25+3];//cnt维护每一层图的边数 
int epos[MAXM+3],val[MAXM+3];//val备份边的值，以便重构图，epos在整理图的时候被修改，在下一层递归时，被用于重构图 
void init_set(edge *es,int n){
	for(int i=1;i<=n;i++)pa[es[i].u]=es[i].u,sz[es[i].u]=1,pa[es[i].v]=es[i].v,sz[es[i].v]=1;
}
int find_pa(int x){
	return x==pa[x]?x:pa[x]=find_pa(pa[x]);
}
void unite(int x,int y){
	if(sz[x]>sz[y])swap(x,y);
	sz[y]+=sz[x];pa[x]=y;
}
void contraction(int &etot,LL &sum){//将要修改的边权值置为-INF，调用本函数，得到所有必须边，sum是所有必须边的权值和 ，目的：通过缩点使得图变小 
	int tmp=0;init_set(d,etot);//tmp维护剩余多少边，t存储剩下的边 
	sort(d+1,d+etot+1);
	for(int i=1;i<=etot;i++){//第一遍MST，将考虑-INF边 
		int a=find_pa(d[i].u),b=find_pa(d[i].v);
		if(a!=b){unite(a,b);t[++tmp]=d[i];} 
	}
	init_set(t,tmp);
	for(int i=1;i<=tmp;i++){//第二遍MST，不考虑-INF边，求权值和 ，注意这里是对t里的边做MST 
		int a=find_pa(t[i].u),b=find_pa(t[i].v);
		if(a!=b&&t[i].w!=-INF){unite(a,b);sum+=t[i].w;}
	}
	tmp=0;//对原图缩点
	for(int i=1;i<=etot;i++){
		int a=find_pa(d[i].u),b=find_pa(d[i].v);
		if(a!=b){
			t[(epos[d[i].pos]=++tmp)]=d[i];//存下这条边，并记录他的新位置epos 
			t[tmp].u=a,t[tmp].v=b;
		}
	}
	etot=tmp;
	for(int i=1;i<=etot;i++)d[i]=t[i];
}
void reduction(int &etot){//将要修改的边权值置为INF，调用本函数，去掉所有无用边 
	int tmp=0;init_set(d,etot);
	sort(d+1,d+etot+1);
	//如果把要改变的边都设为最大值，也用不到边i，那么边i为废边
	for(int i=1;i<=etot;i++){
		int a=find_pa(d[i].u),b=find_pa(d[i].v);
		if(a!=b){
			unite(a,b);
			t[epos[d[i].pos]=++tmp]=d[i];
		} 
		else if(d[i].w==INF)t[epos[d[i].pos]=++tmp]=d[i];//修改边的两点已经并为一个联通块，但是由于这里 修改边 的权值并不是真实值（而是INF）所以还要把他加上 
	}
	etot=tmp;
	for(int i=1;i<=etot;i++)d[i]=t[i];
}
void solve(int l,int r,int cur,LL sum){//cur：图的标号 
	int tot=cnt[cur];
	if(l==r)val[q[l].x]=q[l].y;
	for(int i=1;i<=tot;i++)e[cur][i].w=val[e[cur][i].pos];//重建这张图（修改权值）
	for(int i=1;i<=tot;i++){d[i]=e[cur][i];epos[d[i].pos]=i;}//将当前图复制，用于整理，整理后用于下层构图 
	if(l==r){
		init_set(d,tot);
		ans[l]=sum;sort(d+1,d+tot+1);
		for(int i=1;i<=tot;i++){
			int a=find_pa(d[i].u),b=find_pa(d[i].v);
			if(a!=b){
				unite(a,b);ans[l]+=d[i].w;
			}
		}
		return;
	}
	for(int i=l;i<=r;i++)d[epos[q[i].x]].w=-INF;
	contraction(tot,sum);
	for(int i=l;i<=r;i++)d[epos[q[i].x]].w=INF;
	reduction(tot);
	for(int i=1;i<=tot;i++)e[cur+1][i]=d[i];//存到下一层的图中，不过权值还没有改回 
	int mid=(l+r)>>1;
	cnt[cur+1]=tot;
	solve(l,mid,cur+1,sum); 
	solve(mid+1,r,cur+1,sum);
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&e[0][i].u,&e[0][i].v,&val[i]);
		e[0][i].w=val[i];
		e[0][i].pos=i;
	}
	for(int i=1;i<=Q;i++)scanf("%d%d",&q[i].x,&q[i].y);
	cnt[0]=m;
	solve(1,Q,0,0);
	for(int i=1;i<=Q;i++)printf("%lld\n",ans[i]);
	return 0;
}

