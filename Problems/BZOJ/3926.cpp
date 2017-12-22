/*
[Zjoi20150]诸神眷顾的幻想乡
分析： 
		首先题目中有一个关键条件是说叶子的数量不超过20个。我们不妨对每个叶子都以它为根建一个Trie。
		那么注意到整个树的任何一个子串，都是某个Trie上从一个点到它的一个子孙的路径。
		那么，我们可以把这20个Trie合并成一个大Trie，然后求这个大Trie的子串数量就可以了（Trie的子串指的是从Trie中一个点到它的一个子孙）。
		怎么求字串数量呢？
		两种方法：
		1.首先有Max(fa)=Min(x)-1，对于一个状态，其对答案的贡献是自己的right最长长度-parent树中的父亲的right最长长度。即ans[x]=x.len-x.fa.len。因为其取值的范围是Min(x)..Max(x)，ans[x]=Max(x)-Min(x)+1=Max(x)-(Max(fa)+1)+1=Max(x)-Max(fa)。 这样扫一遍所有状态即可。
		2.很显然，根到每个节点的路径条数总和即为答案。这个问题可以DP，对于自动机中的一个状态x，dp[x]表示根到x的路径数，则有dp[x->ch]+=dp[x]，将自动机拓扑排序然后依次计算即可（注意不能直接dfs，因为不是树QAQ）。
		其实并不用将20个Trie显式合并，每次搜一棵Trie，然后加到自动机中即可（怎么加？记录Trie树对应的last节点，然后从这个last建自动机即可。
		但这会有一个问题！
		有可能两个Trie有公共部分，这部分加到自动机中该怎么办？即重复添加。
		如果不管，用方法2求的答案就是错的（想一想，相当于同一个点在自动机中出现了多次），用方法1则不会有影响（因为正好p.len=p.fa.len（因为这两个节点相同），这样一减，就对答案没有影响了）。
		那么怎么调整？
		如果last已经有x转移，那么判断这个x转移后到达的状态，如果这个状态与将要加入的点的状态相同——last->ch[x].len==(np.len=last.len+1)，那么这个要加的点就和last->ch[x].len等价，不用加了。 否则，就要建立一个新的点nq，nq.len=last.len+1，要加的点和nq是等价的，而q是nq的子集。
*/ 
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;  
const int MAXN=100000,INF=0x3f3f3f3f;  
const int NS=10;  
typedef long long LL;  
struct SAM{  
    struct node{
        int ch[NS],pa,len;
    }ns[2*20*MAXN+103];
    int root,tot;
    int newnode(int l){
        tot++;
        ns[tot].len=l;
        ns[tot].pa=0;
        return tot;
    }
    void clear(){
        tot=0;root=newnode(0);
    }
    int append(int x,int last){
        int p=last,np=newnode(ns[p].len+1);
        for(;p && ns[p].ch[x]==0;p=ns[p].pa)ns[p].ch[x]=np;
        if(p==0)ns[np].pa=root;
        else{
            int q=ns[p].ch[x];
            if(ns[q].len==ns[p].len+1)ns[np].pa=q;
            else{
                int nq=newnode(ns[p].len+1);
                memcpy(ns[nq].ch,ns[q].ch,sizeof(ns[q].ch));
                ns[nq].pa=ns[q].pa;
                ns[q].pa=ns[np].pa=nq;
                for(;p && ns[p].ch[x]==q;p=ns[p].pa)ns[p].ch[x]=nq;
            }
        }
        return np;
    }
    LL solve(){
        LL ans=0;
        for(int i=1;i<=tot;i++)ans+=ns[i].len-ns[ns[i].pa].len;
        return ans;
    }
}sam;
vector<int> g[MAXN+3];  
int val[MAXN+3];  
void addedge(int u,int v){  
    g[u].push_back(v);
    g[v].push_back(u);
}
void dfs(int u,int fa,int last){  
    int t=sam.append(val[u],last);
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==fa)continue;
        dfs(g[u][i],u,t);
    }
}
/*int cnt[2*MAXN+3];
void solve(int u){  
    cnt[u]=1;
    for(int i=0;i<NS;i++){
        int v=sam.ns[u].ch[i];
        if(v==0)continue;
        solve(v);
        cnt[u]+=v;
    }
}*/
int n,c;  
int main(){  
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)scanf("%d",&val[i]);
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&u,&v);
        addedge(u,v);
    }
    sam.clear();
    for(int u=1;u<=n;u++){
        if(g[u].size()>1)continue;
        dfs(u,-1,sam.root);
    }
    //solve(sam.root);
    //printf("%d\n",cnt[sam.root]-1);
    printf("%lld\n",sam.solve());
    return 0;
}
/*方法2
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;  
const int MAXN=100000,INF=0x3f3f3f3f;  
const int NS=10;  
typedef long long LL;  
struct SAM{  
    struct node{
        int ch[NS],pa,len;
    }ns[2*20*MAXN+103];
    int root,tot;
    int newnode(int l){
        tot++;
        ns[tot].len=l;
        ns[tot].pa=0;
        return tot;
    }
    void clear(){
        tot=0;root=newnode(0);
    }
    int append(int x,int last){
        int p=last;
        if(ns[p].ch[x]){
            int q=ns[p].ch[x];
            if(ns[q].len==ns[p].len+1)return q;
            else{
                int nq=newnode(ns[p].len+1);
                memcpy(ns[nq].ch,ns[q].ch,sizeof(ns[q].ch));
                ns[nq].pa=ns[q].pa;
                ns[q].pa=nq;
                for(;p && ns[p].ch[x]==q;p=ns[p].pa)ns[p].ch[x]=nq;
                return nq;
            }
        }
        int np=newnode(ns[p].len+1);
        for(;p && ns[p].ch[x]==0;p=ns[p].pa)ns[p].ch[x]=np;
        if(p==0)ns[np].pa=root;
        else{
            int q=ns[p].ch[x];
            if(ns[q].len==ns[p].len+1)ns[np].pa=q;
            else{
                int nq=newnode(ns[p].len+1);
                memcpy(ns[nq].ch,ns[q].ch,sizeof(ns[q].ch));
                ns[nq].pa=ns[q].pa;
                ns[q].pa=ns[np].pa=nq;
                for(;p && ns[p].ch[x]==q;p=ns[p].pa)ns[p].ch[x]=nq;
            }
        }
        return np;
    }
    LL solve(){
        LL ans=0;
        for(int i=1;i<=tot;i++)ans+=ns[i].len-ns[ns[i].pa].len;
        return ans;
    }
}sam;
LL cnt[2*20*MAXN+3];  
int d[2*20*MAXN+3];  
queue<int> Q;  
LL getans(){  
    //cout<<"!!"<<endl;
    for(int i=1;i<=sam.tot;i++){
        for(int j=0;j<NS;j++){
            int v=sam.ns[i].ch[j];
            if(v==0)continue;
            d[v]++;
        }
    }
    Q.push(1);cnt[1]=1;
    //for(int i=1;i<=sam.tot;i++){if(d[i]==0){Q.push(i);cnt[i]=1;cout<<i<<endl;}}
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int j=0;j<NS;j++){
            int v=sam.ns[u].ch[j];
            if(v==0)continue;
            cnt[v]+=cnt[u];
            d[v]--;
            if(d[v]==0)Q.push(v);
        }
    }
    LL ans=0;
    for(int i=2;i<=sam.tot;i++)ans+=cnt[i];
    return ans;
}
vector<int> g[MAXN+3];  
int val[MAXN+3];  
void addedge(int u,int v){  
    g[u].push_back(v);
    g[v].push_back(u);
}
void dfs(int u,int fa,int last){  
    int t=sam.append(val[u],last);
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==fa)continue;
        dfs(g[u][i],u,t);
    }
}
int n,c;  
int main(){  
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)scanf("%d",&val[i]);
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&u,&v);
        addedge(u,v);
    }
    sam.clear();
    for(int u=1;u<=n;u++){
        if(g[u].size()>1)continue;
        dfs(u,-1,sam.root);
    }
    //printf("%lld\n",sam.solve());
    printf("%lld\n",getans());
    return 0;
}
*/
