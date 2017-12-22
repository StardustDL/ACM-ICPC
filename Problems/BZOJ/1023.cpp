/*
[SHOI2008]cactus仙人掌图
分析：我们用dfs遍历图，能得到一棵dfs树。进行树形dp，F[i]表示dfs树上，以i为根的子树上以i为起点的最长链。
		对于桥(u,v)，用F[v]+F[u]+1更新ans（这个时候F[u]还未更新），然后用F[v]+1更新F[u]
		对于环：首先注意到，由于图是仙人掌图，所以除了最高点以外的点，它们的F值只会影响到环上的点的F值，而不会影响到其他块块的点的F值（块块指的是把桥砍掉之后图剩下的若干个联通块），所以我们只要更新ans值和最高点F值即可。这也正是我上面讲的那句冗杂的话的意思。
		F值可以O(环的个数)扫一边求得，这一部分总时间复杂度是O(n)的
		更新ans值，我们发现枚举到i的时候，ans=max(ans,max{F[j]+dist(i,j))这就可以用经典的单调队列维护了。由于是环形，所以可以把链翻倍。 
*/
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#include<vector> 
#define MAXN 50010 
#define pb push_back 
using namespace std; 
int n,m,sum[MAXN],num,ans,F[MAXN],father[MAXN]; 
int dfn[MAXN],low[MAXN]; 
int a[MAXN*2],b[MAXN*2],queue[MAXN*2]; 
vector<int>edge[MAXN]; 
void read(){ 
    scanf("%d %d",&n,&m); 
    for(int i=1,k;i<=m;i++) { 
        scanf("%d",&k); 
        for(int j=1;j<=k;j++) scanf("%d",&a[j]); 
        for(int j=1;j<k;j++) edge[a[j]].pb(a[j+1]),edge[a[j+1]].pb(a[j]); 
    } 
} 
void Dp(int root,int p){ 
    int n=sum[p]-sum[root]+1,front=1,rear=1; 
    for(int i=p;i!=root;i=father[i]) 
        a[n--]=F[i]; 
    a[n]=F[root],n=sum[p]-sum[root]+1; 
    for(int i=n+1;i<=n+n;i++) 
        a[i]=a[i-n]; 
    queue[front]=1; 
    for(int i=2;i<=n+n/2;i++) 
    { 
        while(front<=rear&&queue[front]<i-n/2)  front++; 
        ans=max(ans,a[front[queue]]+a[i]+i-queue[front]); 
        while(front<=rear&&a[queue[rear]]-queue[rear]<=a[i]-i)  rear--; 
        queue[++rear]=i; 
    } 
    for(int i=2;i<=n;i++) 
        F[root]=max(F[root],a[i]+min(i-1,n-i+1)); 
} 
void Tarjan(int p){ 
    dfn[p]=low[p]=++num; 
    for(int i=0;i<edge[p].size();i++) 
        if(edge[p][i]!=father[p]){ 
            int q=edge[p][i]; 
            if(dfn[q]==0)father[q]=p,sum[q]=sum[p]+1,Tarjan(q); 
            low[p]=min(low[p],low[q]); 
            if(dfn[p]<low[q])ans=max(ans,F[p]+F[q]+1),F[p]=max(F[p],F[q]+1); 
        } 
    for(int i=0;i<edge[p].size();i++) 
        if(father[edge[p][i]]!=p&&dfn[p]<dfn[edge[p][i]]) Dp(p,edge[p][i]); 
} 
int main(){ 
    read();
    Tarjan(1);
    printf("%d\n",ans); 
    return 0; 
}
