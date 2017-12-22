/*
没有人的算术
分析：用平衡树维护这些数，给每个数一个实数值表示其大小
		生成一个数(a,b)的时候，由于a,b都是之前出现过的数，所以我们可以直接在平衡树上插入，返回代表它的实数值
		用线段树求区间最大值 
	  http://pan.baidu.com/s/1B0JNo
	  
	  第一份代码超时TAT，不知道为什么 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=100000;
double a[5*MAXN+3];
int n,m,pos[MAXN+3];
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
struct data{
	int l,r;
	data(int l,int r):l(l),r(r){}
	data(){}
	bool operator >(const data &t)const{
		return a[l]>a[t.l] || (a[l]==a[t.l]&&a[r]>a[t.r]); 
	}
	bool operator ==(const data &t)const{
		return a[l]==a[t.l]&&a[r]==a[t.r];
	}
};
struct sct{
	data v[5*MAXN+3];
	int sz[5*MAXN+3],ls[5*MAXN+3],rs[5*MAXN+3],cnt,id[5*MAXN+3],tp,R,root;
	void dfs(int x){
		if(!x)return;
		dfs(ls[x]);
		id[++tp]=x;
		dfs(rs[x]);
	}
	void build(int &x,int l,int r,double lv,double rv){
		if(l>r){x=0;return;}
		double mv=(lv+rv)*0.5;
		int mid=(l+r)>>1;
		x=id[mid];a[x]=mv;
		build(ls[x],l,mid-1,lv,mv);
		build(rs[x],mid+1,r,mv,rv);
		sz[x]=sz[ls[x]]+sz[rs[x]]+1;
	}
	void rebuild(int &x,double lv,double rv){
		tp=0;dfs(x);
		build(x,1,tp,lv,rv);
	}
	int _insert(int &x,double lv,double rv,data val){
		double mv=(lv+rv)*0.5;
		if(x==0){
			x=++cnt;a[x]=mv;v[x]=val;sz[x]=1;return x;
		}
		int res;
		if(val==v[x])return x;//已经添加
		else{
			sz[x]++;
			if(val>v[x])res=insert(rs[x],mv,rv,val);
			else res=insert(ls[x],lv,mv,val); 
		}
		if(sz[x]*0.75<=max(sz[ls[x]],sz[rs[x]]))R=x;
		else{
			if(R){
				if(ls[x]==R)rebuild(ls[x],lv,mv);
				else rebuild(rs[x],mv,rv);
				R=0;
			}
		}
		return res;
	}
	int insert(int &x,double lv,double rv,data val){
		int t=_insert(x,lv,rv,val);
		if(R){rebuild(root,0,1);R=0;}
		return t;
	}
}S;
int mx[5*MAXN+3];
void update(int x,int l,int r,int po){
	int mid=(l+r)>>1;
	if(l==r){mx[x]=l;return;}
	if(po<=mid)update(x<<1,l,mid,po);
	else update(x<<1|1,mid+1,r,po);
	int p=mx[x<<1],q=mx[x<<1|1];
	if(a[pos[p]]>=a[pos[q]])mx[x]=p;
	else mx[x]=q;
}
int query(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R)return mx[x];
	int mid=(l+r)>>1,res=0,t=0;
	//cout<<x<<endl;
	if(L<=mid){
		t=query(x<<1,l,mid,L,R);
		if(a[pos[t]]>a[pos[res]])res=t;
	}
	if(R>mid){
		t=query(x<<1|1,mid+1,r,L,R);
		if(a[pos[t]]>a[pos[res]])res=t;
	}
	return res;
}
char s[10];
int main(){
	n=read();m=read();a[0]=-1;
	int fir=S.insert(S.root,0,1,data(0,0));
	for(int i=1;i<=n;i++)pos[i]=fir;
	for(int i=1;i<=n;i++)update(1,1,n,i);
	int l,r,k;
	for(int i=1;i<=m;i++){
		scanf("%s",s);l=read(),r=read();
		if(s[0]=='C'){
			k=read();
			pos[k]=S.insert(S.root,0,1,data(pos[l],pos[r]));
			update(1,1,n,k);
		}
		else printf("%d\n",query(1,1,n,l,r)); 
	}
	return 0;
}

/*
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,rt,R,top;
double a[500005];
int mx[500005],pos[100005],id[500005];
char ch[5];
struct data{
	int l,r;
	friend bool operator>(data x,data y){
		if(a[x.l]>a[y.l])return 1;
		if(a[x.l]==a[y.l]&&a[x.r]>a[y.r])return 1;
		return 0;
	}
	friend bool operator==(data x,data y){
		if(x.l!=y.l||x.r!=y.r)return 0;
		return 1;
	}
};
struct sctree{
	int cnt;
	data v[500005];
	int size[500005],ls[500005],rs[500005];
	void dfs(int k){
		if(!k)return;
		dfs(ls[k]);
		id[++top]=k;
		dfs(rs[k]);
	}
	void build(int &k,int l,int r,double lv,double rv){
		if(l>r){k=0;return;}
		double mv=(lv+rv)/2.0;
		int mid=(l+r)/2;
		k=id[mid];a[k]=mv;
		build(ls[k],l,mid-1,lv,mv);
		build(rs[k],mid+1,r,mv,rv);
		size[k]=size[ls[k]]+size[rs[k]]+1;
	}
	void rebuild(int &k,double lv,double rv){
	    top=0;
		dfs(k);
		build(k,1,top,lv,rv);
	}
	int insert(int &k,double lv,double rv,data val){
		double mv=(lv+rv)/2.0;
		if(!k){
			k=++cnt;a[k]=mv;v[k]=val;size[k]=1;
			return k;
		}
		int p;
		if(val==v[k])return k;
		else {
			size[k]++;	
			if(val>v[k])p=insert(rs[k],mv,rv,val);
			else p=insert(ls[k],lv,mv,val);
		}
		if(size[k]*0.75>max(size[ls[k]],size[rs[k]])){
			if(R){
				if(ls[k]==R)rebuild(ls[k],lv,mv);
				else rebuild(rs[k],mv,rv);
				R=0;
			}
		}
		else R=k;
		return p;
	}
}sc;
void modify(int k,int l,int r,int v){
	int mid=(l+r)>>1;
	if(l==r){mx[k]=l;return;}
	if(v<=mid)modify(k<<1,l,mid,v);
	else modify(k<<1|1,mid+1,r,v);
	int x=mx[k<<1],y=mx[k<<1|1];
	if(a[pos[x]]>=a[pos[y]])mx[k]=x;
	else mx[k]=y;
}
int query(int k,int l,int r,int x,int y){
	int mid=(l+r)>>1;
	if(l==x&&y==r)return mx[k];
	int t=0,p=0;
	if(x<=mid){
		p=query(k<<1,l,mid,x,min(mid,y));
		if(a[pos[p]]>a[pos[t]])t=p;
	}
	if(y>mid){	
	p=query(k<<1|1,mid+1,r,max(x,mid+1),y);
		if(a[pos[p]]>a[pos[t]])t=p;
	}
	return t;
}
int main(){
	n=read();m=read();
	a[0]=-1;
    sc.insert(rt,0,1,(data){0,0});
	for(int i=1;i<=n;i++)pos[i]=1;
	for(int i=1;i<=n;i++)modify(1,1,n,i);
	int l,r,K;
	for(int i=1;i<=m;i++){
		scanf("%s",ch+1);l=read();r=read();
		if(ch[1]=='C'){
			K=read();
			pos[K]=sc.insert(rt,0,1,(data){pos[l],pos[r]});
			if(R)sc.rebuild(rt,0,1);R=0;
			modify(1,1,n,K);
		}
		else printf("%d\n",query(1,1,n,l,r));
	}
	return 0;
}
*/
