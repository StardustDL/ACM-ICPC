/*
[SHOI2008]cactus������ͼ
������������dfs����ͼ���ܵõ�һ��dfs������������dp��F[i]��ʾdfs���ϣ���iΪ������������iΪ���������
		������(u,v)����F[v]+F[u]+1����ans�����ʱ��F[u]��δ���£���Ȼ����F[v]+1����F[u]
		���ڻ�������ע�⵽������ͼ��������ͼ�����Գ�����ߵ�����ĵ㣬���ǵ�Fֵֻ��Ӱ�쵽���ϵĵ��Fֵ��������Ӱ�쵽�������ĵ��Fֵ�����ָ���ǰ��ſ���֮��ͼʣ�µ����ɸ���ͨ�飩����������ֻҪ����ansֵ����ߵ�Fֵ���ɡ���Ҳ���������潲���Ǿ����ӵĻ�����˼��
		Fֵ����O(���ĸ���)ɨһ����ã���һ������ʱ�临�Ӷ���O(n)��
		����ansֵ�����Ƿ���ö�ٵ�i��ʱ��ans=max(ans,max{F[j]+dist(i,j))��Ϳ����þ���ĵ�������ά���ˡ������ǻ��Σ����Կ��԰��������� 
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
