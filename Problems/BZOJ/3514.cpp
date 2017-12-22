/*
Codechef MARCH14 GERALD07��ǿ��
���������Ȱѱ����μӵ�ͼ�У�����ǰ��������ͼ�еı��γ��˻�����ô�������������ӽ����ıߵ���ȥ
		����ÿ���߰������ߵ��˳�ȥ��¼������ntr[i] = j���ر�أ�Ҫ��û�е����ߣ�ntr[i] = 0;
		�����Ȼ�ǿ�����LCT��Ū�Ķ԰ɡ��������ӣ���ô�½�һ���㣬ȨֵΪi��u->i,v->i 
		Ȼ�����ÿ��ѯ�ʣ����ǵĴ𰸾��Ƕ�l~r��ntrС��l�ı���ͣ�����n��ȥ���ֵ
		��ȷ�Կ���YYһ�£�
			���һ���ߵ�ntr >= l,��ô��Ȼ���������l ~ r�еı��γɻ�����ô���Դ�û�й���
			��֮���һ���ߵ�ntr < l��ô�����l ~ r�еı��ǲ����γɻ��ģ���ô���Դ𰸵Ĺ���Ϊ-1
			���ڲ�ѯ��l ~ r���ж��ٱߵ�ntrС��l������ʽ�߶���
	  �������������� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200000,MAXM=200000,INF=0x3f3f3f3f;
struct LCT{
	struct node{
		node *f,*c[2],*mn;
		int cn,val,rev;
		void update(){
			mn=this;
			if(c[0]->mn->val < mn->val)mn=c[0]->mn;
			if(c[1]->mn->val < mn->val)mn=c[1]->mn;
		}
		void add_rev(){
			rev^=1;
			c[0]->cn=1;c[1]->cn=0;swap(c[0],c[1]);
		}
		bool isroot(){return cn==2;}
		void setroot(){cn=2;}
		void down(){
			if(rev){
				rev=0;
				c[0]->add_rev();c[1]->add_rev();
			}
		}
		void link(node *fa,int _cn){
			f=fa;cn=_cn;
			if(!isroot())f->c[cn]=this;
		}
	}ns[MAXN+MAXM+3],*nil;
	node *s[MAXN+3];
	int tot,tp;
	void clear(){
		tot=0;nil=ns;nil->val=INF;
		nil->c[0]=nil->c[1]=nil->mn=nil;//һ��Ҫ��nil->mn��ֵ 
	}
	node* newnode(int val){
		node *x=ns+(++tot);
		x->val=val;x->mn=x;
		x->c[0]=x->c[1]=x->f=nil;x->cn=2;x->rev=0;
		return x;
	}
	void rotate(node *x){
		node *y=x->f,*z=y->f;int nx=x->cn,ny=y->cn;
		x->link(z,ny);x->c[!nx]->link(y,nx);y->link(x,!nx);
		y->update();
	}
	void relax(node *x){
		tp=0;s[++tp]=x;
		while(!x->isroot()){s[++tp]=x->f;x=x->f;}
		for(int i=tp;i;i--)s[i]->down();
	}
	void splay(node *x){
		relax(x);
		while(!x->isroot()){
			x->cn==x->f->cn ? rotate(x->f) : rotate(x);
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
		access(x);splay(x);x->add_rev(); 
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
		make_root(x);x->f=y;
	}
	void cut(node *x,node *y){
		make_root(x);access(y);splay(y);
		if(y->c[0] !=x )return;
		y->c[0]=nil;x->link(nil,2);y->update();
	}
	node* get_path(node *x,node *y){
		make_root(x);access(y);splay(y);return y;
	}
	node* query_min(int u,int v){
		return get_path(ns+u,ns+v)->mn;
	}
}lct;
#define id(x) (lct.ns+(x))
int ntr[MAXM+3],u[MAXM+3],v[MAXM+3],n,m,type,Q;
struct PersistentSeg{
	int root[MAXN+3];
	struct node{
		int l,r,sum;
	}ns[20*MAXM+3];
	int tot;
	void clear(){tot=0;}
	void insert(int l,int r,int x,int &y,int val){
		y=++tot;
		ns[y]=ns[x];
		ns[y].sum=ns[x].sum+1;
		if(l==r)return;
		int mid=(l+r)>>1;
		if(val<=mid)insert(l,mid,ns[x].l,ns[y].l,val);
		else insert(mid+1,r,ns[x].r,ns[y].r,val);
	}
	int query(int l,int r,int x,int y,int val){
		//cout<<l<<" "<<r<<endl;
		if(l==r&&l==val)return ns[y].sum-ns[x].sum;
		int mid=(l+r)>>1;
		if(val<=mid)return query(l,mid,ns[x].l,ns[y].l,val);
		else return (ns[ns[y].l].sum-ns[ns[x].l].sum)+query(mid+1,r,ns[x].r,ns[y].r,val);
	}
}pst;
void prep(){
	lct.clear();
	for(int i=1;i<=n;i++)lct.newnode(INF);
	for(int i=1;i<=m;i++){
		if(u[i]==v[i]){ntr[i]=i;continue;}
		if(lct.get_root(id(u[i]))==lct.get_root(id(v[i]))){
			LCT::node *t=lct.query_min(u[i],v[i]);
			ntr[i]=t->val;
			
			lct.cut(id(u[i]),t);
			lct.cut(id(v[i]),t);
		}//cout<<"!!"<<endl;
		LCT::node *t=lct.newnode(i);
		lct.link(id(u[i]),t);
		lct.link(id(v[i]),t);
	}
	
	pst.clear();
	for(int i=1;i<=m;i++){
		pst.insert(0,m,pst.root[i-1],pst.root[i],ntr[i]);
	}
}
void solve(){
	int lst=0;
	for(int i=1,l,r;i<=Q;i++){
		scanf("%d%d",&l,&r);
		if(type)l^=lst,r^=lst;
		lst=n-pst.query(0,m,pst.root[l-1],pst.root[r],l-1);
		printf("%d\n",lst);
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&Q,&type);
	for(int i=1;i<=m;i++)scanf("%d%d",&u[i],&v[i]);
	prep();
	solve();
	return 0;
}

