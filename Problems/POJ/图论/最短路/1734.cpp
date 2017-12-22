/*
Sightseeing trip
���⣺������ͼ��С��
������Floyd����չ����Ϊfloyd����㵽kʱ��i->j�����·�Ͽ϶�û��k���������ǿ������һ����ٸ��¡�������ڵĻ�����ô�϶���i->j  Ȼ��j->k->i��������֤��i->j����·������k��
	  ������ i �͵� j ����С�������ǿ��Կ����� i �� j ֮������·�ʹζ�·����ϣ�ͨ�� floyd ������������֮�����̾��룬��ô����ֻҪ�ҵ����·�����һ�����·����֤ i �� j ֮��ɴＴ�ɡ����� floyd ѭ����ͬʱ�������� ��Ȩֵ ��С�����·Ȩֵ+�ζ�·Ȩֵ=��С��Ȩֵ��Ϊ��׼��һֱ����ÿ�����ǰ����Ҳ���Ǽ�¼ i �� j �����·�����Լ����ܹ��ɳ� i �� j �ĵ� k ��k ���� i �� j �����·���У��д�����С���Ǹ���Ҳ���� i �� j ֮��Ĵζ�·����Ȼ�󰴻�����Ȼ˳��������ɡ�
	  ���Լ��Ĵ��벻֪ΪʲôWA������˼��һ�� 
	  
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
                for(int j=i+1;j<k;j++)//��
                    if(dis[i][j]+g[i][k]+g[k][j]<ans){
                        ans=dis[i][j]+g[i][k]+g[k][j];
                        num=0;
                        res[num++]=i;
                        dfs(i,j);
                        res[num++]=k;
                    }
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(dis[i][k]+dis[k][j]<dis[i][j]){//�ɳ�
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
		for(k=1;k<=n;k++){//���·����һ�㽫���·��β����,��ô�͵õ�һ����С��
			for(i=1;i<k;i++){
				for(j=i+1;j<k;j++){
					//����С����������������·�ɳ�,��Ϊ(i,k)֮������·,(k,j)֮������·�������غϵĲ���
					//����mat[][]��ʵ�ǲ����µ�,����͵�����floyd���·��һ��
					//dist[i][j]������� i �� j �����·Ȩֵ��
					int tmp=dist[i][j]+mat[i][k]+mat[k][j];//���� k �ֱ�� i ���� j ��mat��ֱ������
					if(tmp<min){
						min=tmp;
						num=0;
						int p=j;
						while(p!=i){//����
							path[num++]=p;
							p=pre[i][p];//pre[i][j]��ʾ i �� j ���·���� j ǰ���һ����
						}
						path[num++]=i;
						path[num++]=k;
					}
				}
			}
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(dist[i][j]>dist[i][k]+dist[k][j]){
						dist[i][j]=dist[i][k]+dist[k][j];//dist[][]�����������̾���
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
