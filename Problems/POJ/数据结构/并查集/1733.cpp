/*
Parity game
题意：一个由0,1组成的数字串~~，现在你问一个人，第i位到第j位的1的个数为奇数还是偶数。一共会告诉你几组这样的数，要你判断前k组这个人回答的都是正确的，到第k+1组，这个人说的是错的，要你输出这个k，要是这个人回答的都是正确的，则输出组数
分析：对于这种区间的，稍微转化一下。[l,r]中1个个数可以表示为sum[r]-sum[l-1]，而题目只要求是奇偶，也就确定了sum[r]与sum[l-1]奇偶是否相同
		权值并查集的写法要注意，并且要离散化 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5000,INF=0x3f3f3f3f;
struct uniset{
	int fa[2*MAXN+3];
	bool v[2*MAXN+3];
	void init(int n){for(int i=1;i<=n;i++)fa[i]=i,v[i]=0;}
	int find(int x){
		if(fa[x]!=x){
			int p=fa[x];
			fa[x]=find(fa[x]);
			v[x]=v[x]^v[p];
		}
		return fa[x];
	}
	bool same(int a,int b){return find(a)==find(b);}
	void unions(int a,int b,int d){//d=0表示这两个点相同，1表示不同 
		int pa=find(a),pb=find(b);
		if(pa!=pb)fa[pa]=pb,v[pa]=v[a]^v[b]^d;
	}
}S;
char temp[5];
struct query{
	int u,v;bool d;
	void input(){
		scanf("%d %d %s",&u,&v,temp);getchar();
		d=temp[0]=='o';u--;
	}
}qs[MAXN+3];
int n,q,a[2*MAXN+3],cnt=0,ans=0;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
		qs[i].input(),a[++cnt]=qs[i].u,a[++cnt]=qs[i].v;
	sort(a+1,a+cnt+1);cnt=unique(a+1,a+cnt+1)-a;
	S.init(cnt);
	for(int i=1;i<=q;i++){
		int u=lower_bound(a+1,a+cnt+1,qs[i].u)-a,v=lower_bound(a+1,a+cnt+1,qs[i].v)-a;
		if(S.same(u,v)&&S.v[u]^S.v[v]^qs[i].d)break; 
		else S.unions(u,v,qs[i].d);
		ans++;
	}
	printf("%d",ans);
	return 0;
}

