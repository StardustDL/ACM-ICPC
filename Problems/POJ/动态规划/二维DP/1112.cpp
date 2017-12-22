/*
Team Them Up!
���⣺�ֳ����飬ʹ��ÿ���е��˻�����ʶ�����������������ӽ� 
�������ǳ����ԣ��������������A��B��A����ʶB����B����ʶA����ôA��Bһ�����ܷ���ͬһ�顣��ˣ���������Ϊ������¹���һ��ͼG������A��B���ܷ���ͬһ�飬��ô����G������һ�������(A,B)�����������Ǿ͵õ���һ����Ϊ����������ģ�͡��������Ƕ����ģ�ͽ��м򵥷�����
	  �������о�G��һ����ͨ����K1�����������ͨ���������������K1��������T1������K1�е�������a������a��T1�е����Ϊ���������ǾͰ�a����㼯S1���������ǰ�a����㼯S2��S1,S2���Ϊ�ռ�������Ȼ���S1,S2�Ľ���Ϊ�ա�
      ����֤����������ڲ�ͬ���p��q��p��qͬ����S1��S2������G�д��ڱ�(p,q)����ôҪ����������ĿҪ��ķ����ǲ����ܵģ�Ӧ���No solution���������Ǿ͵õ�����ͨ����K1��Ψһ���鷽������ΪS1,S2���顣
      ����G�е�ÿ����ͨ����Ki�����ǿ��������Ӧ��S1i,S2i��������ǵ�Ŀ���ǰ�ȫ���˷�Ϊ2�顣Ҳ����˵������i=1,2,3,...,m�����Ǳ��������S1i�е��˷ֵ���1�飬S2i�е��˷ֵ���2�飬�������պ��෴�Ĵ���������ĿҪ��������������������С�����ǿ����ö�̬�滮�İ취��ȷ������ѡȡ��������־��ߡ�
      ��������G�й���m����ͨ��������|S1i|=xi,|S2i|=yi(i=1,2,3,...,m)��������f[i,j]��ʾ��ǰi����ͬ������Ϊ2�飬����������������ľ���ֵǡ��Ϊj�Ƿ���ܡ�������ܣ�f[i,j]=true������f[i,j]=false����ʼ������f[0,0]=true, f[0,x]=false(x=1,2,3,...)��Ȼ�����ǿ��԰������·���ȷ��f[i,j](0<i<=m, j>=0)��
      f[i,j]= f[i-1, j-Abs(xi-yi)] or f[i-1, j+Abs(xi-yi)];
      ��Ȼ��������ͬʱ�����ǿ��Լ�¼·�������res=min{i: f[m, i]=true}��Ϊ��ѷ���������������Ӧ��·����������Ҫ��ķ��鷽����
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
����
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
int ans[NN][2][NN];// ��¼��ͨ��֧ 
char dp[NN][NN];
char pre[NN][NN];//��¼dp·�� 
char flag[NN];

void Add(int u, int v){//���� 
     edg[idx].v = v;
     edg[idx].nxt = Link[u];
     Link[u] = edg + idx++;
     edg[idx].v = u;
     edg[idx].nxt = Link[v];
     Link[v] = edg + idx++;
}

int dfs(int u){//��ɫ���� 
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
           for(j = 0; j <= N / 2; j++){// j��0��ʼ 
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

void Print(){//��� 
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
     memset(dfn, 0, sizeof(dfn));//���ֱ�� 
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

