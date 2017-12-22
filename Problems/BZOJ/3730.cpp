/*
��
��������̬������
	  ����ν�ͼ������һ��㻮�֣���֤��һ���㣬��������������logn�����
	  Ȼ���߶���ά�������Ϣ��������£� 
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
bool ok[N];//��������߿ɲ������ߣ�����Ѿ��߹�x��������x^1�� 
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
void find(int x,int fat) {//������cur 
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
/*�߶���ά����head[x]: ��xΪ���ĵ����о���<=k��Ȩֵ��  root[x]ά����xΪ������ʱx��һ�����ĵĶ��ӣ��������������У�����fa[x]<=k �ĵ��Ȩֵ�ͣ�
	������һ�����ѯ��=head[x][1..k]
	+sigma{each higher center cx,x is in the tx child-tree of cx,head[cx][1..(k-len(cx,x))]-root[tx][1..(k-len(cx,x))]}
	ע��Ҫȥ��������ͬһ�������еģ���Ϊ�����ĵ㣬�Ѿ���head[x][1..k]ͳ�ƹ��ˣ�
	ͬʱ��len(x,y)<=k&&path(x,y)��Խcx�ĵ� ���ں�x����ͬһ������������head[x]����ȥά������ֵ��
	�����������ʽ��ǡ��ͳ�������д𰸡� 
*/
void dfs(int x,int fat,int dep) {//�����������ӵ�segment_tree�� 
	//v[x]�洢x�����ڵ��·���ϵ����ģ�u[x]:x��������ĵ��ĸ������ϵģ��������Ӧÿ����ά�����߶�����ֱ�����������ڵĵ��ϻ�ά����������ڵ����е㣨�����������ڵ㣩���߶�������w[x]:x����������ж�Զ ,w[x][i]��ʾx��v[x][i]�ľ��� 
    v[x].pb(cur); u[x].pb(num); w[x].pb(dep);
    ins(head[cur],1,n,dep,val[x]); ins(root[num],1,n,dep,val[x]);
    for (int k=g[x];k;k=nxt[k]) if (to[k]!=fat&&ok[k]) dfs(to[k],x,dep+1);
}
void solve(int x) {//����� 
    int i,j,k;
    for (k=g[x];k;k=nxt[k]) if (ok[k]) num++,dfs(to[k],x,1);
    for (k=g[x];k;k=nxt[k]) if (ok[k]) {
        ok[k^1]=0; f[0]=sz=size[to[k]];
        find(to[k],cur=0); solve(cur);
    }
}
LL query(int x,int k) {
    LL ans=ask(head[x],1,n,1,k)+val[x];//��xΪ���ĵ����о���<=k��Ȩֵ�� 
    int i,sz=v[x].size();
    for (i=0;i<sz;i++) {//ö��x��������������(logn) 
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
