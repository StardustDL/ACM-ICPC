/*
Team Them Up!
题意：分成两组，使得每组中的人互相认识，且两组人数尽量接近 
分析：非常明显，如果存在两个人A和B，A不认识B，或B不认识A，那么A和B一定不能分在同一组。因此，我们以人为结点重新构造一个图G。假如A和B不能分在同一组，那么就在G中增加一条无向边(A,B)。这样，我们就得到了一个较为“单纯”的模型。下面我们对这个模型进行简单分析。
	  我们先研究G的一个连通分量K1。对于这个连通分量，可以先求出K1的生成树T1。对于K1中的任意结点a，假如a在T1中的深度为奇数，我们就把a加入点集S1；否则我们把a加入点集S2（S1,S2最初为空集）。显然最后S1,S2的交集为空。
      不难证明，如果存在不同结点p和q，p和q同属于S1或S2，而且G中存在边(p,q)，那么要做到满足题目要求的分组是不可能的，应输出No solution。否则，我们就得到了连通分量K1的唯一分组方案：分为S1,S2两组。
      对于G中的每个连通分量Ki，我们可以求出相应的S1i,S2i。最后，我们的目的是把全部人分为2组。也就是说，对于i=1,2,3,...,m，我们必须决定把S1i中的人分到第1组，S2i中的人分到第2组，还是做刚好相反的处理。由于题目要求最后两组的总人数差最小，我们可以用动态规划的办法来确定究竟选取上面的哪种决策。
      不妨假设G中共有m个连通分量，记|S1i|=xi,|S2i|=yi(i=1,2,3,...,m)。我们用f[i,j]表示把前i个连同分量分为2组，且这两组总人数差的绝对值恰好为j是否可能。如果可能，f[i,j]=true；否则f[i,j]=false。初始条件是f[0,0]=true, f[0,x]=false(x=1,2,3,...)。然后我们可以按照如下方法确定f[i,j](0<i<=m, j>=0)：
      f[i,j]= f[i-1, j-Abs(xi-yi)] or f[i-1, j+Abs(xi-yi)];
      当然，在求解的同时，我们可以记录路径。最后，res=min{i: f[m, i]=true}即为最佳分组的人数差，而它对应的路径就是我们要求的分组方案。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
int n,sccn;
vector<int> scc[MAXN+3][2];
vector<int> g[MAXN+3];
bitset<MAXN+3> col;
bitset<MAXN+3> vis;
int opt[MAXN+3][MAXN+3],pre[MAXN+3][MAXN+3];
void input(){
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){
		vis=0;vis[i]=1;
		do{
			scanf("%d",&x);
			vis[x]=1;
		}while(x!=0);
		for(int j=1;j<=n;j++){
			//cout<<vis[j]<<" ";
			if(!vis[j]){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		//cout<<endl;
	}
}
bool dfs(int u){
	vis[u]=1;
	scc[sccn][col[u]].push_back(u);
	for(int i=0;i<g[u].size();i++){
		int t=g[u][i];
		if(!vis[t]){
			col[t]=!col[u];
			if(!dfs(t))return false;
		}
		else if(t!=u&&col[t]==col[u])return false;
	}
	return true;
}
bool findscc(){
	vis=0;col=0;sccn=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			sccn++;
			if(!dfs(i))return false;
		}
	}
	return true;
}
void output(){
	int k=(n>>1);
	while(--k>0){
		//cout<<k<<endl;
		if(opt[sccn][k])break;
	}
	if(k==0){
		printf("No solution");return;
	}
	int cur=k;
	vis=0;
	for(int i=sccn;i>=1;i--){
		int t=pre[i][cur];cur-=scc[i][t].size();
		for(int j=0;j<scc[i][t].size();j++){
			vis[scc[i][t][j]]=1;
		}
	}
	printf("%d",n-k);
	for(int i=1;i<=n;i++)if(vis[i])printf(" %d",i);
	printf("\n%d",k);
	for(int i=1;i<=n;i++)if(!vis[i])printf(" %d",i);
}
void dp(){
	memset(opt,0,sizeof(opt));
	memset(pre,0,sizeof(pre));
	opt[0][0]=1;
	for(int i=1;i<=sccn;i++){
		for(int j=0;j<=(n>>1)+1;j++){
			int t=j-scc[i][0].size();
			if(t>=0&&opt[i-1][t]){
				opt[i][j]=pre[i][j]=1;
			}
			t=j-scc[i][1].size();
			if(t>=0&&opt[i-1][t]){
				opt[i][j]=pre[i][j]=1;
			}
		}
	}
}
int main(){
	input();
	if(!findscc()){
		printf("No solution");
		return 0;
	}
	dp();
	output();
	puts("");
	/*for(int i=1;i<=sccn;i++){
		cout<<i<<":"<<endl;
		for(int j=0;j<scc[i][0].size();j++){
			cout<<scc[i][0][j]<<" ";
		}
		cout<<endl;
		for(int j=0;j<scc[i][1].size();j++){
			cout<<scc[i][1][j]<<" ";
		}
		cout<<endl;
	}*/
	return 0;
}
/*
代码
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
 #define MM 20010
 #define NN 105

typedef struct node{
       int v;
       struct node *nxt;
}NODE;
NODE edg[MM], *Link[NN];

 int idx, N, time, scc;
char map[NN][NN];
char col[NN];
int dfn[NN];
int cnt[NN][2];
int ans[NN][2][NN];// 记录连通分支 
char dp[NN][NN];
char pre[NN][NN];//记录dp路径 
char flag[NN];

void Add(int u, int v){//建边 
     edg[idx].v = v;
     edg[idx].nxt = Link[u];
     Link[u] = edg + idx++;
     edg[idx].v = u;
     edg[idx].nxt = Link[v];
     Link[v] = edg + idx++;
}

int dfs(int u){//着色过程 
    int v;
    dfn[u] = ++time;
    ans[scc][col[u]][++cnt[scc][col[u]]] = u;
    for(NODE *p = Link[u]; p; p = p->nxt){
             v = p->v;
             if(dfn[v] == 0){
                       col[v] = !col[u];
                       if (dfs(v) == 0) return 0;//
             }else{
                   if (v != u && col[v] == col[u]) return 0;
             }
    }
    return 1;
}

void Dp(){
     int i, j, t;
     dp[0][0] = 1;
     for(i = 1; i <= N; i++) dp[0][i] = 0;
     
     for(i = 1; i <= scc; i++){
           for(j = 0; j <= N / 2; j++){// j从0开始 
                 dp[i][j] = 0;
                 t = j - cnt[i][0];
                 if(t >= 0 && dp[i - 1][t]){
                      dp[i][j] = 1;
                      pre[i][j] = 0;
                 }
                 t = j - cnt[i][1];
                 if(t >= 0 && dp[i - 1][t]){
                      dp[i][j] = 1;
                      pre[i][j] = 1;
                 }
           }
     }
}

void Print(){//输出 
     int t, tmp, i, j, k;
     for (k = N / 2; k >= 1; k--){
         if(dp[scc][k]) break;
     }
     if(k == 0) puts("No solution");
     else{
          int tmp = k;
          memset(flag, 0, sizeof(flag));
          for (i = scc; i >= 1; i--){
              t = pre[i][tmp];
              tmp = tmp - cnt[i][t];
              for(j = 1; j <= cnt[i][t]; j++){
                    flag[ans[i][t][j]] = 1;
              }
          }
          printf("%d", N - k);
          for(i = 1; i <= N; i++){
                if(flag[i] == 0) printf(" %d", i);
          }
          puts("");
          printf("%d", k);
          for(i = 1; i <= N; i++){
                if(flag[i]) printf(" %d", i);
          }
          puts("");
     }
}
void Solve(){
     int i;
     memset(dfn, 0, sizeof(dfn));//发现标号 
     memset(col, 0, sizeof(col));
     memset(cnt, 0, sizeof(cnt));
     time = scc = 0;
     for (i = 1; i <= N; i++){
         if(dfn[i] == 0){
             ++scc;
             if(dfs(i) == 0) break;
         }
     }
     if(i <= N) puts("No solution");
     else{
          Dp();
          Print();
     }
}
int main()
{
    int i, a, j;
    scanf("%d", &N);
    
    idx = 0; memset(Link, 0, sizeof(Link));
    memset(map, 0, sizeof(map));
    for (i = 1; i <= N; i++){
        while(scanf("%d", &a), a){
           map[i][a] = 1;
        }
    }
    for(i = 1; i <= N; i++){
          for(j = i + 1; j <= N; j++){
                if(map[i][j] == 0 || map[j][i] == 0) Add(i, j);
          }
    }
    Solve();
    return 0;
}
*/

