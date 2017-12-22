/*
[NOI2005]维修数列
分析：Splay模板，然而就是WA= =，注释中是hzwer的代码，可以AC 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include "assert.h" 
using namespace std;
const int MAXN=1000000+1000,INF=0x3f3f3f3f;
struct Splay{
	struct node{
		node *f,*c[2];
		int cn,val,rev,sum,lmax,rmax,mxsum,tag,sz;
		void update(){
			sum=val+c[0]->sum+c[1]->sum;sz=1+c[0]->sz+c[1]->sz;
			lmax=max(c[0]->sum+val+c[1]->lmax,c[0]->lmax);
			rmax=max(c[1]->sum+val+c[0]->rmax,c[1]->rmax);
			mxsum=max(max(c[0]->mxsum,c[1]->mxsum),c[0]->rmax+val+c[1]->lmax);
		}
		void out(){
			cout<<val<<" "<<sum<<" "<<lmax<<" "<<rmax<<" "<<mxsum<<endl;
		}
		//bool isroot(){return cn==2;}
		void add_rev(){
			rev^=1;
			c[0]->cn=1;c[1]->cn=0;
			swap(c[0],c[1]);
		}
		void add_tag(int t){
			tag=1;
			val=t;
			sum=sz*t;
			if(t>0)lmax=rmax=mxsum=sum;
			else lmax=0,rmax=0,mxsum=t;
		}
		void link(node *fa,int _cn){
			f=fa;cn=_cn;
			f->c[cn]=this;
		}
	}ns[MAXN+3];
	node *nil,*root;
	node* sta[MAXN+3];
	int top;
	int tot;
	void down(node *t){
		if(t->rev){
			t->c[0]->add_rev();
			t->c[1]->add_rev();
			t->rev=0;
		}
		if(t->tag){
			if(t->c[0]!=nil)t->c[0]->add_tag(t->val);
			if(t->c[1]!=nil)t->c[1]->add_tag(t->val);
			t->tag=0;
		}
	}
	void init(){
		nil=ns;
		nil->f=nil->c[0]=nil->c[1]=nil;
		nil->cn=2;nil->sum=nil->lmax=nil->rmax=nil->tag=nil->rev=nil->val=nil->sz=0;
		nil->mxsum=-INF;//注意这里 
		tot=0;top=0;
	}
	node* newnode(int val){
		node* t=top>0?sta[top--]:(ns+(++tot));
		t->f=t->c[0]=t->c[1]=nil;
		t->cn=2;t->tag=t->rev=0;t->sum=t->val=val;t->sz=1;
		t->lmax=t->rmax=max(0,val);
		t->mxsum=val;
		return t;
	}
	void rotate(node *x){
		node *y=x->f,*z=y->f;int nx=x->cn,ny=y->cn;
		x->link(z,ny);x->c[!nx]->link(y,nx);y->link(x,!nx);
		y->update();
	}
	void relax(node *x){
		//cout<<((x->f)==nil)<<endl;
		if(x->f!=nil)relax(x->f);
		down(x);
	}
	void debug(node *x){
		if(x==nil)return;
		cout<<x->val<<":"<<x->c[0]->val<<" "<<x->c[1]->val<<endl;
		debug(x->c[0]);
		debug(x->c[1]); 
	}
	/*void output(node *x){
		cout<<x->val<<" "<<x->cn<<" "<<x->f->val<<endl;
	}*/ 
	void splay(node *x,node* tp){
		relax(x);
		while((x->f!=tp)){//注意判 
			//output(x);output(x->f);output(tp);
			//if(x->cn==2)cout<<"ERROR"<<endl;
			if(x->f->f!=tp)x->cn==x->f->cn?rotate(x->f):rotate(x);//注意判 祖父 
			rotate(x);
		}
		x->update();
		//cout<<"QWQ"<<endl;
		if(tp==nil){root=x;x->link(nil,2);}//注意更新根节点 
	}
	node* build(int* a,int l,int r){
		if(l>r)return nil;
		if(l==r)return newnode(a[l]);
		int mid=(l+r)>>1;
		node *t=newnode(a[mid]);
		node *L=build(a,l,mid-1),*R=build(a,mid+1,r);
		L->link(t,0);R->link(t,1);
		t->update();
		//t->out();
		return t;
	}
	void erase(node* x){
		if(x==nil)return;
		sta[++top]=x;
		erase(x->c[0]);
		erase(x->c[1]);
	}
	node* getnode(int pos){
		node *ans=root;
		while(ans!=nil){
			//output(ans);cout<<pos<<endl;
			down(ans);
			if(ans->c[0]->sz+1==pos)return ans;
			else if(ans->c[0]->sz>=pos)ans=ans->c[0];//注意是>=pos 
			else {pos-=ans->c[0]->sz+1;ans=ans->c[1];}
		}
		return ans;
	}
	void insert(int pos,int *a,int l,int r){
		node* nw=build(a,l,r);
		node* t=getnode(pos),*p=getnode(pos+1);
		splay(t,nil);splay(p,t); 
		nw->link(p,0);
		p->update();t->update();//注意更新 
		//splay(nw,nil);
	}
	void remove(int pos,int len){
		node* t=getnode(pos-1),*p=getnode(pos+len);
		splay(t,nil);splay(p,t);
		erase(p->c[0]);
		p->c[0]=nil;
		p->update();t->update();
		//splay(p,nil);
	}
	void modify(int pos,int len,int c){
		node* t=getnode(pos-1),*p=getnode(pos+len);//cout<<t->val<<" "<<p->val<<endl;
		splay(t,nil);splay(p,t);
		if(p->c[0]==nil)return;
		p->c[0]->add_tag(c);
		p->update();t->update();
		//splay(p->c[0],nil);
	}
	void reverse(int pos,int len){
		node* t=getnode(pos-1);//cout<<"GET2"<<endl;
		node *p=getnode(pos+len);
		splay(t,nil);
		//debug(root);
		splay(p,t);
		if(p->c[0]==nil)return;
		p->c[0]->add_rev();
		p->update();t->update();//cout<<"GET1"<<endl;
		//splay(p->c[0],nil);
	}
	int sum(int pos,int len){
		node* t=getnode(pos-1),*p=getnode(pos+len);
		splay(t,nil);
		splay(p,t);
		//debug(root);
		if(p->c[0]==nil)return 0;
		int ans=p->c[0]->sum;//cout<<ans<<endl;
		//splay(p->c[0],nil);
		return ans;
	}
	int maxsum(int pos,int len){
		node* t=getnode(pos-1),*p=getnode(pos+len);
		splay(t,nil);splay(p,t);
		if(p->c[0]==nil)return 0;
		int ans=p->c[0]->mxsum;
		//splay(p->c[0],nil);
		return ans;
	}
}S;
int a[MAXN+3],n,m;
char str[50];
int main(){
	S.init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[0]=-INF;a[n+1]=-INF;
	S.root=S.build(a,0,n+1);
	//cout<<S.root->val<<endl;
	int pos,tot;
	//S.debug(S.root);
	//for(int i=1;i<=S.tot;i++)S.ns[i].out();
	while(m--){
		scanf("%s",str);
		switch(str[2]){
			case 'S':
				scanf("%d%d",&pos,&tot);
				for(int i=1;i<=tot;i++)scanf("%d",&a[i]); 
				S.insert(pos+1,a,1,tot);
				break;
			case 'L':
				scanf("%d%d",&pos,&tot);
				S.remove(pos+1,tot);
				break;
			case 'K':
				int c;scanf("%d%d%d",&pos,&tot,&c);
				S.modify(pos+1,tot,c);
				break;
			case 'V':
				scanf("%d%d",&pos,&tot);
				S.reverse(pos+1,tot);
				break;
			case 'T':
				int pos,tot;scanf("%d%d",&pos,&tot);
				printf("%d\n",S.sum(pos+1,tot));
				break;
			case 'X':
				printf("%d\n",S.root->mxsum);
				break;
		}
	}
	return 0;
}
/*
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 1000000000
#define N 1000005
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,rt,cnt;
int a[N],id[N],fa[N],c[N][2];
int sum[N],size[N],v[N],mx[N],lx[N],rx[N];
bool tag[N],rev[N];
queue<int> q;
void update(int x){
	int l=c[x][0],r=c[x][1];
	sum[x]=sum[l]+sum[r]+v[x];
	size[x]=size[l]+size[r]+1;
	mx[x]=max(mx[l],mx[r]);
	mx[x]=max(mx[x],rx[l]+v[x]+lx[r]);
	lx[x]=max(lx[l],sum[l]+v[x]+lx[r]);
	rx[x]=max(rx[r],sum[r]+v[x]+rx[l]);
}
void pushdown(int x){
	int l=c[x][0],r=c[x][1];
	if(tag[x]){
		rev[x]=tag[x]=0;
		if(l)tag[l]=1,v[l]=v[x],sum[l]=v[x]*size[l];
		if(r)tag[r]=1,v[r]=v[x],sum[r]=v[x]*size[r];
		if(v[x]>=0){
			if(l)lx[l]=rx[l]=mx[l]=sum[l];
			if(r)lx[r]=rx[r]=mx[r]=sum[r];
		}
		else{
			if(l)lx[l]=rx[l]=0,mx[l]=v[x];
			if(r)lx[r]=rx[r]=0,mx[r]=v[x];
		}
	}
	if(rev[x]){
		rev[x]^=1;rev[l]^=1;rev[r]^=1;
		swap(lx[l],rx[l]);swap(lx[r],rx[r]);
		swap(c[l][0],c[l][1]);swap(c[r][0],c[r][1]);
	}
}
void rotate(int x,int &k){
	int y=fa[x],z=fa[y],l,r;
	l=(c[y][1]==x);r=l^1;
	if(y==k)k=x;
	else c[z][c[z][1]==y]=x;
	fa[c[x][r]]=y;fa[y]=x;fa[x]=z;
	c[y][l]=c[x][r];c[x][r]=y;
	update(y);update(x);
}
void splay(int x,int &k){
	while(x!=k){
		int y=fa[x],z=fa[y];
	    if(y!=k){
			if(c[y][0]==x^c[z][0]==y)rotate(x,k);
			else rotate(y,k);
		}
		rotate(x,k);
	}
}
int find(int x,int rk){
	pushdown(x);
	int l=c[x][0],r=c[x][1];
	if(size[l]+1==rk)return x;
	if(size[l]>=rk)return find(l,rk);
	return find(r,rk-size[l]-1);
}
void rec(int x){
	if(!x)return;
	int l=c[x][0],r=c[x][1];
	rec(l);rec(r);q.push(x);
	fa[x]=c[x][0]=c[x][1]=0;
	tag[x]=rev[x]=0;
}
int split(int k,int tot){
	int x=find(rt,k),y=find(rt,k+tot+1);
	splay(x,rt);splay(y,c[x][1]);
	return c[y][0];
}
void query(int k,int tot){
	int x=split(k,tot);
	printf("%d\n",sum[x]);
}
void modify(int k,int tot,int val){
	int x=split(k,tot),y=fa[x];
	v[x]=val;tag[x]=1;sum[x]=size[x]*val;
	if(val>=0)lx[x]=rx[x]=mx[x]=sum[x];
	else lx[x]=rx[x]=0,mx[x]=val;
	update(y);update(fa[y]);
}
void rever(int k,int tot){
	int x=split(k,tot),y=fa[x];
	if(!tag[x]){
		rev[x]^=1;
		swap(c[x][0],c[x][1]);
		swap(lx[x],rx[x]);
		update(y);update(fa[y]);
	}
}
void erase(int k,int tot){
	int x=split(k,tot),y=fa[x];
	rec(x);c[y][0]=0;
	update(y);update(fa[y]);
}
void build(int l,int r,int f){
	if(l>r)return;
	int mid=(l+r)>>1,now=id[mid],last=id[f];
	if(l==r){
		sum[now]=a[l];size[now]=1;
		tag[now]=rev[now]=0;
		if(a[l]>=0)lx[now]=rx[now]=mx[now]=a[l];
		else lx[now]=rx[now]=0,mx[now]=a[l];
	}
	else build(l,mid-1,mid),build(mid+1,r,mid);
	v[now]=a[mid];fa[now]=last;update(now);
	c[last][mid>=f]=now;
}
void insert(int k,int tot){
	for(int i=1;i<=tot;i++)a[i]=read();
	for(int i=1;i<=tot;i++)
		if(!q.empty())id[i]=q.front(),q.pop();
		else id[i]=++cnt;
	build(1,tot,0);int z=id[(1+tot)>>1];
	int x=find(rt,k+1),y=find(rt,k+2);
	splay(x,rt);splay(y,c[x][1]);
	fa[z]=y;c[y][0]=z;
	update(y);update(x);
}
int main(){
	n=read();m=read();
	mx[0]=a[1]=a[n+2]=-inf;
	for(int i=1;i<=n;i++)a[i+1]=read();
	for(int i=1;i<=n+2;i++)id[i]=i;
	build(1,n+2,0);
	rt=(n+3)>>1;cnt=n+2;
	int k,tot,val;
	char ch[10];
	while(m--){
		scanf("%s",ch);
		if(ch[0]!='M'||ch[2]!='X')k=read(),tot=read();
		if(ch[0]=='I')insert(k,tot);
		if(ch[0]=='D')erase(k,tot);
		if(ch[0]=='M'){
			if(ch[2]=='X')printf("%d\n",mx[rt]);
			else val=read(),modify(k,tot,val);
		}
		if(ch[0]=='R')rever(k,tot);
		if(ch[0]=='G')query(k,tot);
	}
	return 0;
}
*/
