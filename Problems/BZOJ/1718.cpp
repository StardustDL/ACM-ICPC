/*
[Usaco2006 Jan] Redundant Paths 分离的路径
分析：新建最少的边,使得整个图只有一个边双联通分量. 
	  把图用双联通分量缩点后会形成一个DAG,其中这个DAG上的叶子节点可以两两互相配对连边. 是最优情况. 
	  所以ans=ceil(leaf/2)=(leaf+1)/2 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=5000;
int H[MAXN+3],X[20005],P[20005],tot,_tot,num[20005],fa[20005];
inline void add(int x,int y){
    P[++tot]=y;X[tot]=H[x];H[x]=tot;num[tot]=++_tot;
    P[++tot]=x;X[tot]=H[y];H[y]=tot;num[tot]=_tot;
}
int x,y,n,m;
int low[MAXN+3],dfn[MAXN+3],cnt,point[MAXN+3],tim,stk[MAXN+3],top;
void tarjan(int u){
    low[u]=dfn[u]=++tim;stk[top++]=u;
    for(int i=H[u];i;i=X[i]){
        if(num[i]==fa[u]) continue;//沿着反向边回去了 
        if(!dfn[P[i]]){
            fa[P[i]]=num[i];
            tarjan(P[i]);
            low[u]=min(low[P[i]],low[u]);
        }else low[u]=min(dfn[P[i]],low[u]);
    }
    if(low[u]==dfn[u]){
        int k;++cnt;
        do{
            k=stk[--top];
            point[k]=cnt;
        }while(k!=u);
    }
}
bool vis[20005];int in[MAXN+3];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    tarjan(1);
    for(int i=1;i<=n;i++){
        for(int j=H[i];j;j=X[j]){
            if(vis[j]) continue;
            if(point[i]==point[P[j]]) continue;
            in[point[i]]++;
            vis[j]=1; 
        }
    }
    int leaf=0;
    for(int i=1;i<=cnt;i++)
        if(in[i]==1)leaf++;
    printf("%d",(leaf+1)>>1);
    return 0;
}

