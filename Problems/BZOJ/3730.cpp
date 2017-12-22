/*
震波
分析：动态树分治
	  点分治将图按重心一层层划分，保证了一个点，沿重心树向上是logn级别的
	  然后线段树维护点的信息（具体见下） 
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#define pb push_back
using namespace std;
typedef long long LL;
const int N=200010;
const int M=5000100;
vector<int> v[N],u[N],w[N];
int n,m,val[N];
int g[N],to[N],nxt[N],tot=1;
int f[N],size[N],sz,cur,num;
int son[M][2],len;
int head[N],root[N];
LL sum[M],lastans;
bool ok[N];//标记这条边可不可以走（如果已经走过x，则不能走x^1） 
void Max(int &x,int y){if (x<y) x=y;}
void read(int &a){
    char ch; while (!((ch=getchar())>='0'&&ch<='9'));
    a=ch-'0'; while ((ch=getchar())>='0'&&ch<='9') (a*=10)+=ch-'0';
}
void addedge(int x,int y) {
    to[++tot]=y; nxt[tot]=g[x]; g[x]=tot; ok[tot]=1;
    to[++tot]=x; nxt[tot]=g[y]; g[y]=tot; ok[tot]=1;
}
void ins(int &i,int l,int r,int x,int y) {
    if (!i) i=++len;sum[i]+=y;
    if (l==r) return;
    int mid=(l+r)>>1;
    if (x<=mid) ins(son[i][0],l,mid,x,y);
    else ins(son[i][1],mid+1,r,x,y);
}
LL ask(int i,int l,int r,int x,int y) {
    if (!i||x>y) return 0;
    if (x<=l&&y>=r) return sum[i];
    int mid=(l+r)>>1;LL ans=0;
    if (x<=mid) ans+=ask(son[i][0],l,mid,x,y);
    if (y>mid) ans+=ask(son[i][1],mid+1,r,x,y);
    return ans;
}
void find(int x,int fat) {//找重心cur 
    int k; size[x]=1; f[x]=0;
    for (k=g[x];k;k=nxt[k]) {
        if (to[k]==fat) continue;
        if (!ok[k]) continue;
        find(to[k],x);
        size[x]+=size[to[k]];
        Max(f[x],size[to[k]]);
    }
    Max(f[x],sz-size[x]);
    if (f[x]<f[cur]) cur=x;
}
/*线段树维护：head[x]: 以x为重心的树中距离<=k的权值和  root[x]维护以x为根（此时x是一个重心的儿子），在他的子树中，距离fa[x]<=k 的点的权值和，
	这样对一个点的询问=head[x][1..k]
	+sigma{each higher center cx,x is in the tx child-tree of cx,head[cx][1..(k-len(cx,x))]-root[tx][1..(k-len(cx,x))]}
	注意要去掉和他在同一个子树中的，因为这样的点，已经被head[x][1..k]统计过了，
	同时，len(x,y)<=k&&path(x,y)跨越cx的点 由于和x不在同一棵子树，所以head[x]不会去维护他的值。
	所以上面这个式子恰好统计了所有答案。 
*/
void dfs(int x,int fat,int dep) {//处理子树，加到segment_tree中 
	//v[x]存储x到根节点的路径上的重心，u[x]:x是这个重心的哪个子树上的（这个将对应每个点维护的线段树，直接与重心相邻的点上会维护这棵子树内的所有点（包括子树根节点）的线段树），w[x]:x距这个重心有多远 ,w[x][i]表示x到v[x][i]的距离 
    v[x].pb(cur); u[x].pb(num); w[x].pb(dep);
    ins(head[cur],1,n,dep,val[x]); ins(root[num],1,n,dep,val[x]);
    for (int k=g[x];k;k=nxt[k]) if (to[k]!=fat&&ok[k]) dfs(to[k],x,dep+1);
}
void solve(int x) {//点分治 
    int i,j,k;
    for (k=g[x];k;k=nxt[k]) if (ok[k]) num++,dfs(to[k],x,1);
    for (k=g[x];k;k=nxt[k]) if (ok[k]) {
        ok[k^1]=0; f[0]=sz=size[to[k]];
        find(to[k],cur=0); solve(cur);
    }
}
LL query(int x,int k) {
    LL ans=ask(head[x],1,n,1,k)+val[x];//以x为重心的树中距离<=k的权值和 
    int i,sz=v[x].size();
    for (i=0;i<sz;i++) {//枚举x的所有祖先重心(logn) 
        if (w[x][i]<=k) ans+=val[v[x][i]];
        ans+=ask(head[v[x][i]],1,n,1,k-w[x][i])-ask(root[u[x][i]],1,n,1,k-w[x][i]);
    }
    return ans;
}
void modify(int x,int y) {
    int i,sz=v[x].size(),t=y-val[x]; val[x]=y;
    for (i=0;i<sz;i++) {
        ins(head[v[x][i]],1,n,w[x][i],t);
        ins(root[u[x][i]],1,n,w[x][i],t);
    }
}
int main() {
    int i,k,x,y;
    read(n); read(m);
    for (i=1;i<=n;i++) read(val[i]);
    for (i=1;i<n;i++) {
        read(x); read(y);
        addedge(x,y);
    }
    f[0]=sz=n; find(1,cur=0); solve(cur);
    for (i=1;i<=m;i++) {
        read(k); read(x); read(y);
        x^=lastans; y^=lastans;
        if (k==0) printf("%lld\n",lastans=query(x,y));
        else if (k==1) modify(x,y);
    }
    return 0;
}
