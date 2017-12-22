/*
Find them, Catch them
题意：两个集合，给出不在同一集合中的两者，判断两者是否在同一集合 
分析：并查集，可以拆点，也可以用边权,边权方法编伪了。。拆点倒是一遍AC 
*/
#include<cstdio>
using namespace std;
const int MAXN=100000;
int n,m,a,b;
char c;
/*struct uniset{
	int pa[MAXN+3],d[MAXN+3];
	void init(int n){
		for(int i=1;i<=n;i++){
			pa[i]=i;d[i]=0;
		}
	}
	int find(int x){
		if(pa[x]==x)return x;
		int t=find(pa[x]);
		d[x]=(d[pa[x]]+1)%2;
		pa[x]=t;
		return t;
	}
	int same(int a,int b){
		if(find(a)!=find(b))return -1;
		return d[a]==d[b];
	}
	void unions(int a,int b){
		int fa=find(a),fb=find(b);
		if(a==b)return;
		pa[fa]=fb;
		d[fa]=(d[fb]+1)%2;
	}
}S;*/
struct uniset{
	int pa[2*MAXN+3];
	void init(int n){
		for(int i=1;i<=2*n;i++)pa[i]=i;
	}
	int find(int x){return pa[x]==x?x:pa[x]=find(pa[x]);}
	bool same(int a,int b){
		return find(a)==find(b);
	}
	void unions(int a,int b){
		int fa=find(a),fb=find(b);
		if(a==b)return;
		pa[fa]=fb;
	}
}S;
int main(){
	int t;scanf("%d",&t);
	while(t-->0){
		scanf("\n%d %d",&n,&m);S.init(n);
		while(m-->0){
			scanf("\n%c %d %d",&c,&a,&b);
			if(c=='D'){
				S.unions(a,b+n);
				S.unions(a+n,b);
			}
			else{
				if(S.same(a,b))printf("In the same gang.\n");
				else if(S.same(a,b+n))printf("In different gangs.\n");
				else printf("Not sure yet.\n");
			} 
		}
	}
	return 0;
}
