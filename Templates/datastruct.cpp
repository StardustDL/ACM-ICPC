/*

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
template<class T>
struct Queue {
	T q[MAXN+3];
	int h,t;
	void clear() {
		h=0;
		t=0;
	}
	void push(T val) {
		q[t++]=val;
		if(t==MAXN+1)t=0;
	}
	void pop() {
		h++;
		if(h==MAXN+1)h=0;
	}
	bool empty() {
		return h==t;
	}
	T front() {
		return q[h];
	}
};
template<class T>
struct Stack {
	T q[MAXN+3];
	int tp;
	void clear() {
		tp=0;
	}
	void push(T val) {
		q[tp++]=val;
	}
	void pop() {
		tp--;
	}
	bool empty() {
		return tp==0;
	}
	T top() {
		return q[tp-1];
	}
};
template<class T>
struct Monotone_Queue { //单调不降队列
	T q[MAXN+3];
	int h,t;
	void clear() {
		h=0;
		t=0;
	}
	void push(T val) {
		while(h<t && q[t-1]>val)t--;
		q[t++]=val;
	}
	void pop() {
		h++;
	}
	bool empty() {
		return h==t;
	}
	T front() {
		return q[h];
	}
};
struct Union_Set {
	int pa[MAXN+3],sz[MAXN+3];
	void init(int n) {
		for(int i=1; i<=n; i++) {
			pa[i]=i;
			sz[i]=1;
		}
	}
	int find(int x) {
		return pa[x]==x?x:pa[x]=find(pa[x]);
	}
	bool issame(int a,int b) {
		return find(a)==find(b);
	}
	void unite(int a,int b) {
		a=find(a),b=find(b);
		if(a==b)return;
		if(sz[a]>sz[b])swap(a,b);
		pa[a]=b,sz[b]+=sz[a];
	}
};
struct Segment_Tree {
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)
	struct node {
		int sum,tag,l,r;
	} ns[4*MAXN+3];
	void clear() {
		memset(ns,0,sizeof(ns));
	}
	void update(int x) {
		ns[x].sum=ns[LC(x)].sum+ns[RC(x)].sum;
	}
	void down(int x) {
		if(ns[x].tag==0)return;
		int t=ns[x].tag;
		ns[LC(x)].tag+=t;
		ns[LC(x)].sum+=t*(ns[LC(x)].r-ns[LC(x)].l+1);
		ns[RC(x)].tag+=t;
		ns[RC(x)].sum+=t*(ns[RC(x)].r-ns[RC(x)].l+1);
		ns[x].tag=0;
	}
	void build(int x,int l,int r,int *a) {
		ns[x].l=l;
		ns[x].r=r;
		if(l==r) {
			ns[x].sum=a[l];
			ns[x].tag=0;
			return;
		}
		int mid=(l+r)>>1;
		build(LC(x),l,mid,a);
		build(RC(x),mid+1,r,a);
		update(x);
	}
	void modify(int x,int L,int R,int ad) {
		if(L<=ns[x].l&&R>=ns[x].r) {
			ns[x].tag+=ad;
			ns[x].sum+=ad*(ns[x].r-ns[x].l+1);
			return;
		}
		down(x);
		int mid=(ns[x].l+ns[x].r)>>1;
		if(L<=mid)modify(LC(x),L,R,ad);
		if(R>mid)modify(RC(x),L,R,ad);
		update(x);
	}
	int query(int x,int L,int R) {
		if(L<=ns[x].l&&R>=ns[x].r) {
			return ns[x].sum;
		}
		down(x);
		int mid=(ns[x].l+ns[x].r)>>1,ans=0;
		if(L<=mid)ans+=query(LC(x),L,R);
		if(R>mid)ans+=query(RC(x),L,R);
		return ans;
	}
};
struct Splay {
	int ch[MAXN+3][2],val[MAXN+3],sum[MAXN+3],tag[MAXN+3],rev[MAXN+3],size[MAXN+3],pa[MAXN+3],root;
	int tot;
	int newnode(int v) {
		tot++;
		ch[tot][0]=ch[tot][1]=0;
		val[tot]=v;
		sum[tot]=v;
		tag[tot]=rev[tot]=0;
		size[tot]=1;
		pa[tot]=0;
	}
	void update(int k) {
		int l=ch[k][0],r=ch[k][1];
		size[k]=size[l]+size[r]+1;
		sum[k]=sum[l]+sum[r]+val[k];
	}
	void down(int k) {
		int l=ch[k][0],r=ch[k][1];
		if(rev[k]) {
			rev[k]^=1;
			rev[l]^=1;
			rev[r]^=1;
			swap(ch[k][0],ch[k][1]);
		}
		if(tag[k]) {
			tag[l]+=tag[k];
			tag[r]+=tag[k];
			sum[l]+=size[l]*tag[k];
			sum[r]+=size[r]*tag[k];
			tag[k]=0;
		}
	}
	void rotate(int x) {
		int y=pa[x],z=pa[y],l=ch[y][1]==x,r=l^1;
		if(pa[y]!=0)ch[z][ch[z][1]==y]=x;
		pa[x]=z;
		pa[y]=x;
		pa[ch[x][r]]=y;
		ch[y][l]=ch[x][r];
		ch[x][r]=y;
		update(y);
		update(x);
	}
	void splay(int x,int t) {
		static int st[MAXN+3],top;
		top=0;
		st[++top]=x;
		for(int i=x; pa[i]!=0; i=pa[i])st[++top]=pa[i];
		while(top)down(st[top--]);
		while(pa[x]!=t) {
			int y=pa[x],z=pa[y];
			if(pa[y]!=t) {
				if(ch[y][0]==x ^ ch[z][0]==y)rotate(x);
				else rotate(y);
			}
			rotate(x);
		}
		if(t==0)root=x;
	}

	void init() { //添加两边的INF和-INF
		tot=0;
		root=newnode(-INF);
		int t=newnode(INF);
		ch[root][1]=t;
		pa[t]=root;
		update(root);
	}
	int get_node(int rk) {
		int cur=root;
		while(1) {
			if(cur==0)return -1;
			int l=ch[cur][0],r=ch[cur][1];
			if(size[l]+1==rk)return cur;
			else if(rk<=size[l])cur=l;
			else rk-=size[l]+1,cur=r;
		}
	}
	int get_line(int l,int r) {
		l=get_node(l-1),r=get_node(r+1);
		splay(l,0);
		splay(r,l);
		return ch[r][0];
	}
	int insert(int pos,int val) {
		int l=get_node(pos),r=get_node(pos+1);
		splay(l,0);
		splay(r,l);
		int t=newnode(val);
		ch[r][0]=t;
		pa[t]=r;
		update(r);
		update(l);
		splay(t,0);
	}
	int count() {
		return size[root]-2;
	}
};
struct LCT {
	int c[MAXN+3][2],sum[MAXN+3],fa[MAXN+3],val[MAXN+3],rev[MAXN+3];
	void newnode(int id,int v) {
		c[id][0]=c[id][1]=0;
		sum[id]=val[id]=v;
		fa[id]=0;
		rev[id]=0;
	}
	void update(int x) {
		sum[x]=sum[c[x][0]]+sum[c[x][1]]+val[x];
	}
	void pushdown(int x) {
		int l=c[x][0],r=c[x][1];
		if(rev[x]) {
			rev[x]^=1;
			rev[l]^=1;
			rev[r]^=1;
			swap(c[x][0],c[x][1]);
		}
	}
	bool isroot(int x) {
		return !(c[fa[x]][0]==x||c[fa[x]][1]==x);
	}
	void rotate(int x) {
		int y=fa[x],z=fa[y],l=c[y][1]==x,r=l^1;
		if(!isroot(y))c[z][c[z][1]==y]=x;
		fa[x]=z;
		fa[y]=x;
		fa[c[x][r]]=y;
		c[y][l]=c[x][r];
		c[x][r]=y;
		update(y);
		update(x);
	}
	int st[MAXN+3],top;
	void splay(int x) {
		top=0;
		st[++top]=x;
		for(int i=x; !isroot(i); i=fa[i])st[++top]=fa[i];
		while(top)pushdown(st[top--]);
		while(!isroot(x)) {
			int y=fa[x],z=fa[y];
			if(!isroot(y)) {
				if(c[y][0]==x ^ c[z][0]==y)rotate(x);
				else rotate(y);
			}
			rotate(x);
		}
	}
	void access(int x) {
		for(int i=0; x; i=x,x=fa[x])
			splay(x),c[x][1]=i,update(x);
	}
	void makeroot(int x) {
		access(x);
		splay(x);
		rev[x]^=1;
	}
	void link(int x,int y) {
		makeroot(x);
		fa[x]=y;
	}
	void cut(int x,int y) {
		makeroot(x);
		access(y);
		splay(y);
		if(c[y][0]!=x)return;
		c[y][0]=0;
		fa[x]=0;
		update(y);
	}
	int getroot(int x) {
		access(x);
		splay(x);
		while(c[x][0])x=c[x][0];
		return x;
	}
	int get_path(int x,int y) {
		makeroot(x);
		access(y);
		splay(y);
		return y;
	}
	int query(int u,int v) {
		return sum[get_path(u,v)];
	}
};
namespace RMQ {
	const int POW=18;
	int mn[MAXN+3][POW];
	void pre(int *a,int n) {
		for(int i=1; i<=n; i++)mn[i][0]=a[i];
		for(int j=2; j<POW; j++) {
			for(int i=1; (i+(1<<j)-1)<=n; i++) {
				mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
			}
		}
	}
	int get_mn(int l,int r) {
		int k=0;
		while((1<<k+1)<(r-l+1))k++;
		return min(mn[l][k],mn[r-(1<<k)+1][k]);
	}
}
struct LeftistTree {
	struct node {
		node *l,*r;
		int key,dist;
	} ns[MAXN+3],*nil;
	int tot,tp;
	node* root,*bin[MAXN+3];
	void init() {
		nil=ns;
		tot=0;
		tp=0;
		root=nil;
	}
	node* newnode(int key) {
		node* t;
		if(tp==0)t=&ns[++tot];
		else t=bin[tp--];
		t->l=t->r=nil;
		t->key=key;
		t->dist=0;
		return t;
	}
	node* merge(node*a,node*b) {
		if(a==nil)return b;
		if(b==nil)return a;
		if(b->key<a->key)swap(a,b);
		a->r=merge(a->r,b);
		if(a->r->dist > a->l->dist)swap(a->l,a->r);
		if(a->r == nil)a->dist=0;
		else a->dist=a->r->dist+1;
		return a;
	}
	void push(int key) {
		root=merge(newnode(key),root);
	}
	void pop() {
		bin[++tp]=root;
		root=merge(root->l,root->r);
	}
	int top() {
		return root->key;
	}
	bool empty() {
		return root==nil;
	}
};
struct Persistent_Segment_Tree {
	struct node {
		int sum,l,r,ls,rs;
	} ns[4*MAXN+3];
	int root[MAXN+3],rt,tot;
	void update(int x) {
		int l=ns[x].ls,r=ns[x].rs;
		ns[x].sum=ns[l].sum+ns[r].sum;
	}
	void init() {
		tot=0;
		rt=0;
	}
	int newnode() {
		++tot;
		ns[tot].sum=ns[tot].l=ns[tot].r=ns[tot].ls=ns[tot].rs=0;
		return tot;
	}
	void modify(int pre,int &x,int pos,int ad) {
		if(x==0)x=newnode();
		ns[x]=ns[pre];
		ns[x].sum+=ad;
		if(ns[x].l==ns[x].r)return;
		int mid=(ns[x].l+ns[x].r)>>1;
		if(pos<=mid) {
			modify(ns[pre].ls,ns[x].ls,pos,ad);
		} else {
			modify(ns[pre].rs,ns[x].rs,pos,ad);
		}
	}
	int query(int pre,int x,int K) {
		if(K==1&&ns[x].l==ns[x].r)return ns[x].l;
		int t=ns[ns[x].ls].sum-ns[ns[pre].ls].sum;
		if(K<=t)return query(ns[pre].ls,ns[x].ls,K);
		else return query(ns[pre].rs,ns[x].rs,K-t);
	}
};
const int NS=26;
struct Persistent_Trie {

	int ch[MAXN+3][NS],tot,root[MAXN+3],sum[MAXN+3];
	void init() {
		tot=0;
		memset(ch,0,sizeof(ch));
		memset(sum,0,sizeof(sum));
	}
	int newnode() {
		return ++tot;
	}
	int insert(int base,int *val,int n) {
		int rt,cur;
		rt=cur=newnode();
		for(int i=0; i<n; i++) {
			int t=val[i];
			ch[cur][0]=ch[base][0];
			ch[cur][1]=ch[base][1];
			base=ch[base][t];
			cur=ch[cur][t]=newnode();
			sum[cur]=sum[base]+1;
		}
		return rt;
	}
	bool query(int l,int r,int *val,int n) {
		for(int i=0; i<n; i++) {
			int t=val[i];
			if(sum[ch[r][t]]-sum[ch[l][t]])l=ch[l][t],r=ch[r][t];
			else return false;
		}
		return true;
	}
};
namespace KDTree {
	typedef long long LL;
	int curD;
	struct Point {
		int mn[2],mx[2],p[2],l,r,val;
		LL sum;
		int& operator [](int ind) {
			return p[ind];
		}
		bool operator ==(const Point &x)const {
			return p[0]==x.p[0]&&p[1]==x.p[1];
		}
		bool operator <(const Point &x)const {
			return p[curD]<x.p[curD];
		}
	} tmp[MAXN+3];
	bool in(int x1,int y1,int x2,int y2,int X1,int Y1,int X2,int Y2) {
		return x1<=X1&&X2<=x2&&y1<=Y1&&Y2<=y2;
	}
	bool out(int x1,int y1,int x2,int y2,int X1,int Y1,int X2,int Y2) {
		return x1>X2||x2<X1||y1>Y2||y2<Y1;
	}
	struct kdtree {
		Point ps[MAXN+3],ins;
		int cnt,rt;
		int max_cnt;
		void init(){
			max_cnt=10000;cnt=0;
		}
		void update(int k) {
			int l=ps[k].l,r=ps[k].r;
			for(int i=0; i<2; i++) {
				ps[k].mn[i]=ps[k].mx[i]=ps[k][i];
				if(l) {
					ps[k].mn[i]=min(ps[k].mn[i],ps[l].mn[i]);
					ps[k].mx[i]=max(ps[k].mx[i],ps[l].mx[i]);
				}
				if(r) {
					ps[k].mn[i]=min(ps[k].mn[i],ps[r].mn[i]);
					ps[k].mx[i]=max(ps[k].mx[i],ps[r].mx[i]);
				}
			}
			ps[k].sum=ps[k].val+ps[l].sum+ps[r].sum;
		}
		void _insert(int &k,bool D) {
			if(k==0) {
				k=++cnt;
				ps[k].mn[0]=ps[k].mx[0]=ps[k][0]=ins[0];
				ps[k].mn[1]=ps[k].mx[1]=ps[k][1]=ins[1];
			}
			if(ps[k]==ins) {
				ps[k].val+=ins.val;
				ps[k].sum+=ins.val;
				return;
			}
			if(ins[D]<ps[k][D])_insert(ps[k].l,D^1);
			else _insert(ps[k].r,D^1);
			update(k);
		}
		void insert(int x,int y,int val){
			ins[0]=x;ins[1]=y;
			ins.val=ins.sum=val;
			_insert(rt,0);
			if(cnt==max_cnt){
				for(int i=1;i<=cnt;i++)tmp[i]=ps[i];
				rt=rebuild(1,cnt,0);max_cnt+=10000;
			}
		}
		int rebuild(int l,int r,bool D) {
			if(l>r)return 0;
			int mid=(l+r)>>1;
			curD=D;
			nth_element(tmp+l,tmp+mid,tmp+r+1);
			ps[mid]=tmp[mid];
			ps[mid].l=rebuild(l,mid-1,D^1);
			ps[mid].r=rebuild(mid+1,r,D^1);
			update(mid);
			return mid;
		}
		LL query(int k,int x1,int y1,int x2,int y2) {
			if(k==0)return 0;
			if(in(x1,y1,x2,y2,ps[k].mn[0],ps[k].mn[1],ps[k].mx[0],ps[k].mx[1]))return ps[k].sum;
			if(out(x1,y1,x2,y2,ps[k].mn[0],ps[k].mn[1],ps[k].mx[0],ps[k].mx[1]))return 0;
			LL tmp=0;
			if(in(x1,y1,x2,y2,ps[k][0],ps[k][1],ps[k][0],ps[k][1]))tmp+=ps[k].val;
			tmp+=query(ps[k].l,x1,y1,x2,y2)+query(ps[k].r,x1,y1,x2,y2);
			return tmp;
		}
	};
}
struct BIT{
	int c[MAXN+3],n;
	void init(int n){
		this->n=n;memset(c,0,sizeof(c));
	}
	#define lowbit(x) ((x)&-(x))
	void add(int x,int ad){
		for(;x<=n;x+=lowbit(x))c[x]+=ad;
	}
	int sum(int x){
		int ans=0;
		for(;x;x-=lowbit(x))ans+=c[x];
		return ans;
	}
};
struct BIT_Range{
	int c[2][MAXN+3],n;
	void init(int n){
		this->n=n+1;memset(c,0,sizeof(c));
	}
	#define lowbit(x) ((x)&-(x))
	void _add(int t,int x,int ad){
		for(;x<=n;x+=lowbit(x))c[t][x]+=ad;
	}
	int _sum(int t,int x){
		int ans=0;
		for(;x;x-=lowbit(x))ans+=c[t][x];
		return ans;
	}
	int query(int l,int r){
		return 
			(_sum(0,r)-_sum(0,l-1))*(r+1)-(_sum(1,r)-_sum(1,l-1))+_sum(0,l-1)*(r-l+1);
	}
	void modify(int l,int r,int v){
		_add(0,l,v);
		_add(0,r+1,-v);
		_add(1,l,l*v);
		_add(1,r+1,(r+1)*-v);
	}
};
BIT_Range T;
int n;
int main() {
	scanf("%d",&n);
	T.init(n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);T.modify(i,i,x); 
	}
	for(int i=1;i<=n;i++){
		int l,r,v;
		scanf("%d%d%d",&l,&r,&v);
		if(v)T.modify(l,r,v);
		else cout<<T.query(l,r)<<endl;
	}
	return 0;
}

