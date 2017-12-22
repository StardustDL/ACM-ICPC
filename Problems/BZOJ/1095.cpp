/*
[ZJOI2007]Hide 捉迷藏
分析：动态树分治大法好，
		把每次分治的重心连成一棵树，树的深度是logn，每次修改一个结点只影响它到树根的一条链
		这题具体实现的时候要维护三层堆
		C.每个重心存所有子树到其距离
		B.每个重心存各个子树最大值，即子结点堆C的最大值
		A.全局一个堆，维护答案最大值，存每个堆B的最大值和次大值之和 
	  括号序列做法【Tag 未懂】
		http://www.shuizilong.com/house/archives/bzoj-1095-zjoi2007hide-%E6%8D%89%E8%BF%B7%E8%97%8F/
*/
#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f; 
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int bin[20],Log[200005];
int n,m,G,cnt,dfn,sum,tot;
int size[100005],f[100005],deep[100005],last[100005];
int mn[18][200005],pos[100005],fa[100005];
bool vis[100005],clo[100005];
struct edge {
	int to,next;
} e[200005];
void insert(int u,int v) {
	e[++cnt]=(edge) {
		v,last[u]
	};
	last[u]=cnt;
	e[++cnt]=(edge) {
		u,last[v]
	};
	last[v]=cnt;
}
struct heap {
	priority_queue<int> A,B;
	void push(int x) {
		A.push(x);
	}
	void erase(int x) {
		B.push(x);
	}
	void pop() {
		while(B.size()&&A.top()==B.top())
			A.pop(),B.pop();
		A.pop();
	}
	int top() {
		while(B.size()&&A.top()==B.top())
			A.pop(),B.pop();
		if(!A.size())return 0;
		return A.top();
	}
	int size() {
		return A.size()-B.size();
	}
	int stop() {
		if(size()<2)return 0;
		int x=top();
		pop();
		int y=top();
		push(x);
		return y;
	}
} A,B[100005],C[100005];
void dfs(int x,int fa) {
	mn[0][++dfn]=deep[x];
	pos[x]=dfn;
	for(int i=last[x]; i; i=e[i].next)
		if(e[i].to!=fa) {
			deep[e[i].to]=deep[x]+1;
			dfs(e[i].to,x);
			mn[0][++dfn]=deep[x];
		}
}
void getrt(int x,int fa) {
	size[x]=1;
	f[x]=0;
	for(int i=last[x]; i; i=e[i].next)
		if(e[i].to!=fa&&!vis[e[i].to]) {
			getrt(e[i].to,x);
			size[x]+=size[e[i].to];
			f[x]=max(f[x],size[e[i].to]);
		}
	f[x]=max(f[x],sum-size[x]);
	if(f[x]<f[G])G=x;
}
void divi(int x,int f) {
	fa[x]=f;
	vis[x]=1;
	for(int i=last[x]; i; i=e[i].next)
		if(!vis[e[i].to]) {
			sum=size[e[i].to];
			G=0;
			getrt(e[i].to,x);
			divi(G,x);
		}
}
int rmq(int x,int y) {
	x=pos[x];
	y=pos[y];
	if(y<x)swap(x,y);
	int t=Log[y-x+1];
	return min(mn[t][x],mn[t][y-bin[t]+1]);
}
int dis(int x,int y) {
	return deep[x]+deep[y]-2*rmq(x,y);
}
void turn_off(int u,int v) {
	if(u==v) {
		B[u].push(0);
		if(B[u].size()==2)A.push(B[u].top());
	}
	if(!fa[u])return;
	int f=fa[u],D=dis(f,v),tmp=C[u].top();
	C[u].push(D);
	if(D>tmp) {
		int mx=B[f].top()+B[f].stop(),size=B[f].size();
		if(tmp)B[f].erase(tmp);
		B[f].push(D);
		int now=B[f].top()+B[f].stop();
		if(now>mx) {
			if(size>=2)A.erase(mx);
			if(B[f].size()>=2)A.push(now);
		}
	}
	turn_off(f,v);
}
void turn_on(int u,int v) {
	if(u==v) {
		if(B[u].size()==2)A.erase(B[u].top());
		B[u].erase(0);
	}
	if(!fa[u])return;
	int f=fa[u],D=dis(f,v),tmp=C[u].top();
	C[u].erase(D);
	if(D==tmp) {
		int mx=B[f].top()+B[f].stop(),size=B[f].size();
		B[f].erase(D);
		if(C[u].top())B[f].push(C[u].top());
		int now=B[f].top()+B[f].stop();
		if(now<mx) {
			if(size>=2)A.erase(mx);
			if(B[f].size()>=2)A.push(now);
		}
	}
	turn_on(f,v);
}
int main() {
	bin[0]=1;
	for(int i=1; i<20; i++)bin[i]=bin[i-1]<<1;
	Log[0]=-1;
	for(int i=1; i<=200000; i++)Log[i]=Log[i>>1]+1;
	n=read();
	for(int i=1; i<n; i++) {
		int u=read(),v=read();
		insert(u,v);
	}
	dfs(1,0);
	for(int i=1; i<=Log[dfn]; i++)
		for(int j=1; j<=dfn; j++)
			if(j+bin[i]-1<=dfn)
				mn[i][j]=min(mn[i-1][j],mn[i-1][j+bin[i-1]]);
	G=0;
	f[0]=INF;
	sum=n;
	getrt(1,0);
	divi(G,0);
	for(int i=1; i<=n; i++)C[i].push(0);
	for(int i=1; i<=n; i++)clo[i]=1;
	for(int i=1; i<=n; i++) {
		turn_off(i,i);
		tot++;
	}
	char ch[2];
	m=read();
	while(m--) {
		scanf("%s",ch+1);
		if(ch[1]=='G') {
			if(tot<=1)printf("%d\n",tot-1);
			else printf("%d\n",A.top());
		} else {
			int x=read();
			if(clo[x])turn_on(x,x),tot--;
			else turn_off(x,x),tot++;
			clo[x]^=1;
		}
	}
	return 0;
}
