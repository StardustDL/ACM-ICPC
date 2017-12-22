/*
[Zjoi20150]�����˵Ļ�����
������ 
		������Ŀ����һ���ؼ�������˵Ҷ�ӵ�����������20�������ǲ�����ÿ��Ҷ�Ӷ�����Ϊ����һ��Trie��
		��ôע�⵽���������κ�һ���Ӵ�������ĳ��Trie�ϴ�һ���㵽����һ�������·����
		��ô�����ǿ��԰���20��Trie�ϲ���һ����Trie��Ȼ���������Trie���Ӵ������Ϳ����ˣ�Trie���Ӵ�ָ���Ǵ�Trie��һ���㵽����һ�������
		��ô���ִ������أ�
		���ַ�����
		1.������Max(fa)=Min(x)-1������һ��״̬����Դ𰸵Ĺ������Լ���right�����-parent���еĸ��׵�right����ȡ���ans[x]=x.len-x.fa.len����Ϊ��ȡֵ�ķ�Χ��Min(x)..Max(x)��ans[x]=Max(x)-Min(x)+1=Max(x)-(Max(fa)+1)+1=Max(x)-Max(fa)�� ����ɨһ������״̬���ɡ�
		2.����Ȼ������ÿ���ڵ��·�������ܺͼ�Ϊ�𰸡�����������DP�������Զ����е�һ��״̬x��dp[x]��ʾ����x��·����������dp[x->ch]+=dp[x]�����Զ�����������Ȼ�����μ��㼴�ɣ�ע�ⲻ��ֱ��dfs����Ϊ������QAQ����
		��ʵ�����ý�20��Trie��ʽ�ϲ���ÿ����һ��Trie��Ȼ��ӵ��Զ����м��ɣ���ô�ӣ���¼Trie����Ӧ��last�ڵ㣬Ȼ������last���Զ������ɡ�
		�������һ�����⣡
		�п�������Trie�й������֣��ⲿ�ּӵ��Զ����и���ô�죿���ظ���ӡ�
		������ܣ��÷���2��Ĵ𰸾��Ǵ�ģ���һ�룬�൱��ͬһ�������Զ����г����˶�Σ����÷���1�򲻻���Ӱ�죨��Ϊ����p.len=p.fa.len����Ϊ�������ڵ���ͬ��������һ�����ͶԴ�û��Ӱ���ˣ���
		��ô��ô������
		���last�Ѿ���xת�ƣ���ô�ж����xת�ƺ󵽴��״̬��������״̬�뽫Ҫ����ĵ��״̬��ͬ����last->ch[x].len==(np.len=last.len+1)����ô���Ҫ�ӵĵ�ͺ�last->ch[x].len�ȼۣ����ü��ˡ� ���򣬾�Ҫ����һ���µĵ�nq��nq.len=last.len+1��Ҫ�ӵĵ��nq�ǵȼ۵ģ���q��nq���Ӽ���
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
/*����2
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
