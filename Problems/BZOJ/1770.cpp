/*
[Usaco2009 Nov]lights 燈
分析：可以高斯消元，然后枚举自由元，也可以折半搜索 
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
typedef long long LL;
const int MAXN=35,INF=0x3f3f3f3f;
int n,m;
LL bin[MAXN+3],v[MAXN+3],to;
map<LL,int> mp;
int ans=INF,mxdep;
bool isfirst;
void dfs(int dep,LL cur,int used){
    if(dep==mxdep+1){
        if(cur==to)ans=min(ans,used);
        if(isfirst){
            int t=mp[cur];
            if(!t || t>used)mp[cur]=used;
        }
        else{
            int t=mp[to^cur];
            if(t!=0)ans=min(ans,t+used);
        }
    }
    else{
        dfs(dep+1,cur,used);
        dfs(dep+1,cur^v[dep],used+1);  
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n+1;i++)bin[i]=1LL<<(i-1);
    to=bin[n+1]-1;
    for(int i=1,a,b;i<=m;i++){
        scanf("%d%d",&a,&b);
        v[a]+=bin[b];v[b]+=bin[a];
    }
    for(int i=1;i<=n;i++)v[i]+=bin[i];
    isfirst=1;mxdep=n/2;
    dfs(1,0,0);
    isfirst=0;mxdep=n;
    dfs(n/2+1,0,0);
    printf("%d\n",ans);
    return 0;
}
