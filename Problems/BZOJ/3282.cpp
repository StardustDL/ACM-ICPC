/*
Tree
·ÖÎö£º¶¯Ì¬Ê÷ 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=300000,INF=0x3f3f3f3f;
struct LCT{
	struct node{
		node *c[2],*f;
		int val,ans,rev,cn;
		void update(){
			ans=c[0]->ans^c[1]->ans^val;
		}
		void add_rev(){
			rev^=1;
			c[0]->cn=1;c[1]->cn=0;
			swap(c[0],c[1]);
		}
		void down(){
			if(rev){
				c[0]->add_rev();
				c[1]->add_rev();
				rev=0;
			}
		}
		inline bool isroot(){
			return cn==2;
		}
		void setroot(){
			cn=2;
		}
		void link(node *fa,int _cn){
			f=fa;cn=_cn;
			if(!isroot())f->c[cn]=this;
		}
	}ns[MAXN+105],*nil;
	int tot;
	void init(){
		nil=ns;tot=0;nil->ans=0;
		nil->c[0]=nil;nil->c[1]=nil;
	}
	void newnode(int v){
		node *t=ns+(++tot);
		t->cn=2;t->ans=t->val=v;
		t->c[0]=t->c[1]=t->f=nil;t->rev=0;
	}
	void rotate(node *x){
		node *y=x->f,*z=y->f;int nx=x->cn,ny=y->cn;
		x->link(z,ny);x->c[!nx]->link(y,nx);y->link(x,!nx);
		y->update();
	}
	void relax(node *x){
		if(!x->isroot())relax(x->f);
		x->down();
	}
	void splay(node *x){
		relax(x);
		while(!x->isroot()){
			x->cn==x->f->cn?rotate(x->f):rotate(x);
			if(!x->isroot())rotate(x);
		}
		x->update();
	}
	node* access(node *x){
		node *y=nil;
		while(x!=nil){
			splay(x);
			x->c[1]->setroot();y->link(x,1);x->update();
			y=x;x=x->f;
		}
		return y;
	}
	void make_root(node *x){
		access(x);
		splay(x);
		x->add_rev();
	}
	node* get_root(node *x){
		access(x);splay(x);x->down();
		while(x->c[0]!=nil){
			x=x->c[0];x->down();
		}
		return x;
	}
	void link(node *x,node *y){
		if(get_root(x)==get_root(y))return;
		make_root(x);
		x->f=y;
	}
	void cut(node *x,node *y){
		make_root(x);access(y);splay(y);
		if(y->c[0]!=x)return;
		y->c[0]=nil;
		x->link(nil,2);
		y->update();
	}
	void modify(node *x,int v){
		make_root(x);splay(x);
		x->val=v;x->update();
	}
	node* get_path(node *x,node *y){
		make_root(x);
		access(y);
		splay(y);
		return y;
	}
	int query(int u,int v){
		return get_path(ns+u,ns+v)->ans;
	}
	void link(int u,int v){link(ns+u,ns+v);}
	void cut(int u,int v){cut(ns+u,ns+v);}
	void modify(int u,int v){modify(ns+u,v);}
}lct;
int main(){
	int n,m;scanf("%d%d",&n,&m);
	lct.init();
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);lct.newnode(x);
	}
	for(int i=1,x,u,v;i<=m;i++){
		scanf("%d%d%d",&x,&u,&v);
		switch(x){
			case 0:printf("%d\n",lct.query(u,v));break;
			case 1:lct.link(u,v);break;
			case 2:lct.cut(u,v);break;
			case 3:lct.modify(u,v);break;
		}
	}
	return 0;
}

