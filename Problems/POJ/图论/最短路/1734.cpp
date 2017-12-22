/*
Sightseeing trip
题意：求无向图最小环
分析：Floyd的扩展：因为floyd的外层到k时，i->j的最短路上肯定没有k。所以我们可以先找环，再更新。如果存在的话，那么肯定是i->j  然后j->k->i。这样保证了i->j这条路不经过k。
	  包含点 i 和点 j 的最小环，我们可以看成是 i 到 j 之间的最短路和次短路的组合，通过 floyd 可求任意两点之间的最短距离，那么我们只要找到最短路径外的一条最短路来保证 i 和 j 之间可达即可。在做 floyd 循环的同时，我们以 环权值 最小（最短路权值+次短路权值=最小环权值）为标准，一直更新每个点的前驱，也就是记录 i 到 j 的最短路径，以及，能够松弛 i 和 j 的点 k （k 不在 i 到 j 的最短路径中）中代价最小的那个（也就是 i 到 j 之间的次短路），然后按环的自然顺序输出即可。
	  但自己的代码不知为什么WA。。意思都一样 
	  
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
int mp[MAXN+3][MAXN+3],dis[MAXN+3][MAXN+3],n,m,x,y,z,ans=INF,path[MAXN+3][MAXN+3],res[MAXN+3],tot=0;
void buildpath(int i,int j){
	int k=path[i][j];
	if(!k){res[tot++]=j;return;}
	buildpath(i,k);
	buildpath(k,j);
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		ans=INF;
		memset(mp,INF,sizeof(mp));
		memset(path,0,sizeof(path));
		for(int i=1;i<=n;i++)mp[i][i]=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			mp[y][x]=mp[x][y]=min(mp[x][y],z);
		}
		memcpy(dis,mp,sizeof(dis));
		for(int k=1;k<=n;k++){
			for(int i=1;i<k;i++){
				for(int j=i+1;j<k;j++){
					if((x=dis[i][j]+mp[i][k]+mp[k][j])<ans){
						ans=x;
						tot=0;
						res[tot++]=i;
						buildpath(i,j);
						res[tot++]=k;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if((x=dis[i][k]+dis[k][j])<dis[i][j]){
						dis[i][j]=x;path[i][j]=k;
					}
				}
			}
		}
		if(ans==INF)puts("No solution.");
		else{
			printf("%d",res[0]);
			for(int i=1;i<tot;i++)printf(" %d",res[i]);
			puts(""); 
		}
	}
	return 0;
}
/* 
#include<cstdio>
#include<cstring>
using namespace std;
const int inf = 100000000;
const int maxn = 110;
int n,m,num;
int dis[maxn][maxn];
int path[maxn][maxn];
int g[maxn][maxn];
int res[maxn];
void dfs(int i,int j){
    int k=path[i][j];
    if(k==0){res[num++]=j;return;}
    dfs(i,k);
    dfs(k,j);
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++)g[i][j]=g[j][i]=dis[i][j]=dis[j][i]=inf;
            g[i][i]=dis[i][i]=0;
        }
        for(int i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(z<g[x][y]){
                dis[x][y]=dis[y][x]=z;
                g[x][y]=g[y][x]=z;
            }
        }
        int ans=inf;
        memset(path,0,sizeof(path));
        for(int k=1;k<=n;k++){
            for(int i=1;i<k;i++)
                for(int j=i+1;j<k;j++)//求环
                    if(dis[i][j]+g[i][k]+g[k][j]<ans){
                        ans=dis[i][j]+g[i][k]+g[k][j];
                        num=0;
                        res[num++]=i;
                        dfs(i,j);
                        res[num++]=k;
                    }
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(dis[i][k]+dis[k][j]<dis[i][j]){//松弛
                        dis[i][j]=dis[i][k]+dis[k][j];
                        path[i][j]=k;
                    }
        }
        if(ans==inf)puts("No solution.");
        else{
            printf("%d",res[0]);
            for(int i=1;i<num;i++)printf(" %d",res[i]);
            printf("\n");
        }
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#define find_min(a,b) a<b?a:b

const int N = 101;
const int INF = 0x7ffffff;
int mat[N][N],dist[N][N],pre[N][N],path[N],n;

int main()
{
	int i,j,k,m,a,b,c;
	int num;
	
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				mat[i][j]=dist[i][j]=INF;
				pre[i][j]=i;
			}
		}
		while(m--){
			scanf("%d%d%d",&a,&b,&c);
			mat[a][b]=mat[b][a]=dist[a][b]=dist[b][a]=find_min(mat[a][b],c);
		}

		int min=INF;
		for(k=1;k<=n;k++){//最短路径外一点将最短路首尾链接,那么就得到一个最小环
			for(i=1;i<k;i++){
				for(j=i+1;j<k;j++){
					//求最小环不能用两点间最短路松弛,因为(i,k)之间的最短路,(k,j)之间的最短路可能有重合的部分
					//所以mat[][]其实是不更新的,这里和单纯的floyd最短路不一样
					//dist[i][j]保存的是 i 到 j 的最短路权值和
					int tmp=dist[i][j]+mat[i][k]+mat[k][j];//这里 k 分别和 i 还有 j 在mat中直接相连
					if(tmp<min){
						min=tmp;
						num=0;
						int p=j;
						while(p!=i){//回溯
							path[num++]=p;
							p=pre[i][p];//pre[i][j]表示 i 到 j 最短路径上 j 前面的一个点
						}
						path[num++]=i;
						path[num++]=k;
					}
				}
			}
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(dist[i][j]>dist[i][k]+dist[k][j]){
						dist[i][j]=dist[i][k]+dist[k][j];//dist[][]保存两点间最短距离
						pre[i][j]=pre[k][j];
					}
				}
			}
		}
		if(min==INF)puts("No solution.");
		else{
			printf("%d",path[0]);
			for(i=1;i<num;i++)
				printf(" %d",path[i]);
			puts("");
		}
	}
	return 0;
}
*/ 
