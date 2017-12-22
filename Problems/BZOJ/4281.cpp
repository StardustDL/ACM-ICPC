/*
[ONTAK2015]Zwi?zek Harcerstwa Bajtockiego
分析：求lca= =，然后判一下就好了 
*/
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN=1000000; 
int n,k,cur;
vector<int> g[MAXN+3];
int dep[MAXN+3],fa[MAXN][23];
void dfs(int u,int f){
	fa[u][0]=f;dep[u]=dep[f]+1;
    for(int i=1;i<=20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=0;i<g[u].size();i++){
    	if(g[u][i]==f)continue;
    	dfs(g[u][i],u);
	}
}
int skip(int x,int t){
    for(int i=0;(1<<i)<=t;i++)
        if((1<<i)&t)x=fa[x][i];
    return x;
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    x=skip(x,dep[x]-dep[y]);
    for(int i=20;~i;i--)
        if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    return x==y?x:fa[x][0];
}
int main(){
    scanf("%d%d%d",&n,&cur,&k);
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&u,&v);
        g[u].push_back(v);g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1,d,t;i<=k;i++){
    	scanf("%d%d",&d,&t);
    	int lc=lca(d,cur);
        int d1=dep[cur]-dep[lc],d2=dep[d]-dep[lc];
        if(t>=d1+d2)cur=d;
        else if(t==d1)cur=lc;
        else if(t<d1)cur=skip(cur,t);
        else cur=skip(d,d2-(t-d1));
        printf("%d ",cur);
    }
    return 0;
}   
