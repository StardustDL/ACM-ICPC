/*
[wc2013]糖果公园
分析：带修改树上莫队
	  1.对树分块：
	  	两种：一种是普通块状树的分块，按照dfs序按遍历的顺序，往块里一个个加结点，到达block之后开新块。这样子的话会分出严格block的块和树的枝叶上不到block的块。但是相邻的块在树上的位置不一定连续。
		另一种方法是bzoj1086的分块方式。题目已经说得很清楚了。分块的结果是可以分出[block,3*block]的块。这些块内的结点可能并不连通，但是在最坏情况下他们可以仅通过一个公共父亲连通。 这样子分块的话保证相邻的块在树上的位置是挨着的。 
	  2. 如果没有修改，则令B = sqrt(n)，对于询问(v, u)，按照v、u所在块的编号排序。v所在块的编号为第一关键字，u所在块的编号为第二关键字排个序，然后搞莫队算法，按顺序扫询问，在树上爬一爬。这样是O(n * sqrt(n))。（n、q是同阶的）
	  3.现在有了修改，引入时间这一维度，
	  	变成：(v, u, ti)，ti是询问时的时间，即这次询问是第几次操作。
		然后v所在块的编号为第一关键字，u所在块的编号为第二关键字，ti为第三关键字。
		然后搞莫队算法，按顺序扫询问，在树上爬一爬，时间有时向前有时倒流。这样令B = n ^ (2 / 3)，则时间复杂度是O(n ^ (5 / 3))。（n、q是同阶的） 
	  4.考虑如何从一个(v,u,ti)转移到(v',u',t')
	  5.先转移t，预处理出对于每个修改 ，它修改前应是什么颜色，这样就可以撤销修改了。
	  	改变的方式：如果这个点被统计到答案中了，那么就排除，修改，重新统计到答案中。如果没有，就直接改
	  6.转移节点：
	  	用S(v, u)代表 v到u的路径上的结点的集合。用root来代表根结点，用lca(v, u)来代表v、u的最近公共祖先。
		那么S(v, u) = S(root, v) xor S(root, u) xor lca(v, u)
		其中xor是集合的对称差。简单来说就是节点出现两次消掉。
		这个有什么用呢= = ，先不考虑lca（因为它就是一个点，可以单独处理）
		定义T(v, u) = S(root, v) xor S(root, u)
		观察将curV移动到targetV前后T(curV, curU)变化：
		T(curV, curU) = S(root, curV) xor S(root, curU)
		T(targetV, curU) = S(root, targetV) xor S(root, curU)
		取对称差：
		T(curV, curU) xor T(targetV, curU)= (S(root, curV) xor S(root, curU)) xor (S(root, targetV) xor S(root, curU))
		由于对称差的交换律、结合律：
		T(curV, curU) xor T(targetV, curU)= S(root, curV) xor S(root, targetV)
		两边同时xor T(curV, curU)：
		T(targetV, curU)= T(curV, curU) xor S(root, curV) xor S(root, targetV)
		发现最后两项就是T(curV, targetV)
		T(targetV, curU)= T(curV, curU) xor T(curV, targetV)
		其实就是对curV到targetV路径(除开lca(curV, targetV))上的结点，将它们的存在性取反即可。
		所以我们要有一个将存在性取反的操作（reverse） 
	  7.有了这两个操作，就能实现转移了，并且转移复杂度是三维的曼哈顿距离，用莫队搞一下就好了 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath> 
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
typedef long long LL;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
LL ans,res[MAXN+3];
int bin[21];
int n,m,Q,cnt;
int blo,blonum;
LL V[MAXN+3],W[MAXN+3],C[MAXN+3],pre[MAXN+3];
int pa[MAXN+3][17];
int q[MAXN+3],top,dep[MAXN+3],belong[MAXN+3],dfn[MAXN+3],tme;
int num[MAXN+3];
bool vis[MAXN+3];
struct edge{int to,next;}e[MAXN*2+3];
int last[MAXN+3];
struct query{int x,y,t,id;}qs[MAXN+3];
struct change{int x,y,t,pre;}cs[MAXN+3];
bool operator <(query a,query b){
	if(belong[a.x]==belong[b.x]&&belong[a.y]==belong[b.y])return a.t<b.t;
	else if(belong[a.x]==belong[b.x])return belong[a.y]<belong[b.y];
	else return belong[a.x]<belong[b.x];
}
void addedge(int u,int v){
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}
int dfs(int u,int fa){
	int sz=0;dfn[u]=++tme;
	pa[u][0]=fa;dep[u]=dep[fa]+1;
	for(int i=1;i<17;i++)if(dep[u]>=bin[i])pa[u][i]=pa[pa[u][i-1]][i-1];else break;
	for(int i=last[u];i;i=e[i].next){
		if(e[i].to==fa)continue;
		sz+=dfs(e[i].to,u);
		if(sz>=blo){
			blonum++;
			for(int j=1;j<=sz;j++)belong[q[top--]]=blonum;
			sz=0;
		}
	}
	q[++top]=u;
	return sz+1;
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int t=dep[x]-dep[y];
	for(int i=0;t>=bin[i];i++)if(bin[i]&t)x=pa[x][i];
	for(int i=16;i>=0;i--)if(pa[x][i]!=pa[y][i])x=pa[x][i],y=pa[y][i];
	return x==y?x:pa[x][0];
}
void reverse(int x){
	if(vis[x])ans-=W[num[C[x]]]*V[C[x]],num[C[x]]--;
	else num[C[x]]++,ans+=W[num[C[x]]]*V[C[x]];
	vis[x]^=1;
}
void change(int x,int val){
	if(vis[x]){reverse(x);C[x]=val;reverse(x);}
	else C[x]=val;
}
void moveto(int x,int y){
	while(x!=y){
		if(dep[x]>dep[y])reverse(x),x=pa[x][0];
		else reverse(y),y=pa[y][0];
	}
}
int main(){
	bin[0]=1;for(int i=1;i<20;i++)bin[i]=bin[i-1]<<1;
	n=read();m=read();Q=read();blo=pow(n,2.0/3)*0.5;
	for(int i=1;i<=m;i++)V[i]=read();
	for(int i=1;i<=n;i++)W[i]=read();
	for(int i=1;i<n;i++)addedge(read(),read());
	for(int i=1;i<=n;i++)pre[i]=C[i]=read();
	dfs(1,0);
	while(top)belong[q[top--]]=blonum;
	int c1=0,c2=0;
	for(int i=1,type,x,y;i<=Q;i++){
		type=read(),x=read(),y=read();
		if(!type){//change
			c1++;
			cs[c1].x=x,cs[c1].y=y,cs[c1].pre=pre[x];pre[x]=y;
		}
		else{//query
			c2++;
			if(dfn[x]>dfn[y])swap(x,y);
			qs[c2].x=x;qs[c2].y=y;qs[c2].id=c2;qs[c2].t=c1;
		}
	}
	sort(qs+1,qs+c2+1);ans=0;
	for(int i=1;i<=qs[1].t;i++)change(cs[i].x,cs[i].y);
	
	moveto(qs[1].x,qs[1].y);
	int t=lca(qs[1].x,qs[1].y);
	reverse(t);res[qs[1].id]=ans;reverse(t);
	for(int i=2;i<=c2;i++){
		for(int j=qs[i-1].t+1;j<=qs[i].t;j++)change(cs[j].x,cs[j].y);
		for(int j=qs[i-1].t;j>qs[i].t;j--)change(cs[j].x,cs[j].pre);
		moveto(qs[i-1].x,qs[i].x);
		moveto(qs[i-1].y,qs[i].y);
		int t=lca(qs[i].x,qs[i].y);
		reverse(t);res[qs[i].id]=ans;reverse(t);
	}
	for(int i=1;i<=c2;i++)printf("%lld\n",res[i]);
	return 0;
}

