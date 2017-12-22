/*
One-way Traffic
题意：给一个混合图，把尽可能多的无向边定向使得最终图保持强连通的性质（任意两点可达），答案保证有解。输出所有无向边最终的情况 
分析：1、tarjan：由于图中既有有向边，又有无向边，那么先把有向边视为无向，用双连通求桥，直接输出桥然后删掉该边即可（因为题目保证有解，所以桥一定是无向边）
	  2、那么图中就只剩下一个个连通块，对于任意连通块（当前是当作边全为无向）我们必然能把所有无向边定向。因为要使得定向后依旧强连通，所以对于任意点u的low[u]值一定<=dfn[u].
	  	1、当前遍历的是树边->若当前边是无向边：假如不满足该等式，则将边反向，若满足则无向边方向正确（定向后直接输出并删边）
	  	2、当前遍历的是后向边-> 容易确定若为无向边就让这边成为后向边。
	  这里我们可以把有向边看成无向边，然后求边双连通分量，对于那些桥，必须加边，对于同一个连通分量，在访问的同时定向，对于有向边，如果访问的方向相反，那么就不予以访问，这样在每条边(假设是now -> v)进行完low的函数计算的时候（其实是计算low[v]），我们都会判一次是否会有low[v] > low[now]，如果上述关系式成立，那就说明按照现在的定向方法，v是不能访问到它的前驱的，所以对于当前边，就对它取反向，这样当前的v节点就可以访问到前驱节点了，因为这个连通分支原来就是双联通的（将边全部看成无向边），所以对当前边的改变，不会影响v的前驱节点到v的连通性，这样就图就成强连通了。
	  具体实现可以在边上记录一些信息，这样方便操作 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2000; 
struct edge{
    int u,v,next;
    bool isbridge,flag,isprint;
}es[MAXN*MAXN+3];
int n,m,tot,head[MAXN+3];
void insert(int u,int v,int flag){
    es[tot].u=u;
    es[tot].v=v;
    es[tot].isbridge=false;
    es[tot].flag=flag;
    es[tot].next=head[u];
    if(flag==2)es[tot].isprint=true;
    else es[tot].isprint=false;
    head[u]=tot++;
}
int low[MAXN+3],dfn[MAXN+3],cnt,_count;
bool mark[MAXN+3];
void tarjan(int u,int father){
    int flag=0;
    low[u]=dfn[u]=++cnt;
    mark[u]=true;
    for(int i=head[u];i!=-1;i=es[i].next){
        int v=es[i].v;
        if(v==father&&!flag){flag=1;continue; }
        if(dfn[v]==0){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){//桥
                es[i].isbridge=true;
                es[i^1].isbridge=true;
            }
        }
		else if(mark[v])low[u]=min(low[u],dfn[v]);
    }
}
void dfs(int u,int father){
    int flag=0;
    low[u]=dfn[u]=++cnt;
    mark[u]=true;
    for(int i=head[u];i!=-1;i=es[i].next){
        int v=es[i].v;
        if(v==father||es[i].flag==0)continue;
        es[i].flag=1;
        es[i^1].flag=0;
        if(dfn[v]==0){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                es[i].flag=0;
                es[i^1].flag=1;
            }
        }
		else if(mark[v])low[u]=min(low[u],dfn[v]);
    }
}
void solve(){
    for(int i=0;i<tot;i+=2){
        if(es[i].isprint){
            if(es[i].isbridge)printf("%d %d 2\n",es[i].u,es[i].v);
            else if(es[i].flag)printf("%d %d 1\n",es[i].u,es[i].v);
            else printf("%d %d 1\n",es[i].v,es[i].u);
        }
    }
}
int main(){
    int u,v,flag;
    while(~scanf("%d%d",&n,&m)){
        tot=0;
        memset(head,-1,sizeof(head));
        while(m--){
            scanf("%d%d%d",&u,&v,&flag);
            if(flag==2){
                insert(u,v,2);
                insert(v,u,2);
            }else{//为了能把有向边当成无向边，必须加两条 
                insert(u,v,1);
                insert(v,u,0);
            }
        }
        cnt=0;
        memset(dfn,0,sizeof(dfn));
        memset(mark,false,sizeof(mark));
        tarjan(1,-1);
        cnt=0;
        memset(dfn,0,sizeof(dfn));
        memset(mark,false,sizeof(mark));
        dfs(1,-1);
        solve();
    }
    return 0;
}
