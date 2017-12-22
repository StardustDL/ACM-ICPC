/*
Bribing FIPA
题意：现在有n个村子，你想要用收买m个村子为你投票，其中收买第i个村子的代价是val[i]。但是有些村子存在从属关系，如果B从属于A国，则收买了A也意味着买通了B，而且这些关系是传递的。问你最小要付出的代价是多少？
分析：经典树形DP，配合背包，dp[i][j]表示以第i节点为根的子树，如果要收买j个国家的最小代价。
	  dp[u][j+k] = min(dp[u][j+k], val[u], dp[v][k]+dp[u][j])。
	  这里要很注意一点，就是在把子树k当为背包的时候，子数j表示的所有背包不能有相互影响。所以需要先预处理一下。即将之前的结果存到另一个数组
	  也可以通过逆向着背包避免这个问题（子问题重叠），但是理解有点麻烦，并且要先处理出总子树节点数 
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm> 
#include<map>
#include<string>
#include<bitset>
using namespace std;
const int MAXN=200,INF=0x3f3f3f3f;
vector<int> g[MAXN+3];
int opt[MAXN+3][MAXN+3],tmp[MAXN+3],num[MAXN+3],val[MAXN+3],n,m;
bitset<MAXN+3> isroot;
void addedge(int u,int v){
	g[u].push_back(v);
}
void dfs(int u){
	//printf("%d:\n",u);
    num[u]=1;
    memset(opt[u],INF,sizeof(opt[u]));
    opt[u][0]=0;
    opt[u][1]=val[u];
    for(int i=0,v;i<g[u].size();i++){
        v=g[u][i];
        //printf("%d,",v);
        dfs(v);
        num[u]+=num[v];
        memcpy(tmp,opt[u],(num[u]+1)*sizeof(int));//预处理opt[u][j]
        for(int j=0;j<=num[u]-num[v];j++)
            for(int k=1;k<=num[v];k++)
                opt[u][j+k]=min(opt[u][j+k],min(val[u],opt[v][k]+tmp[j]));
    }
    //puts("");
}
map<string,int> mp;
string t;
char str[105];
int main(){
    while(gets(str)&&str[0] != '#'){//sscanf()函数应用在这里很适合：把str当为输入流。
        sscanf(str,"%d%d",&n,&m);
        mp.clear();isroot=0;
        for(int i=0;i<=n;i++)g[i].clear();
        for(int i=1,v,p,q,cnt=0;i<=n;i++){
            cin>>t>>v;
            if(mp.count(t)>0)p=mp[t];
            else p=mp[t]=++cnt;
            val[p]=v;
            while(getchar()!='\n'){
                cin>>t;
                if(mp.count(t)>0)q=mp[t];
            	else q=mp[t]=++cnt;
            	isroot[q]=1;
            	addedge(p,q);
            }
        }
        val[0]=INF;
        for(int i=1;i<=n;i++)if(!isroot[i])addedge(0, i);
        dfs(0);
        printf("%d\n", opt[0][m]);
    }
    return 0;
}
