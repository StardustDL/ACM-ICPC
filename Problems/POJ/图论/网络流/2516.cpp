/*
Minimum Cost
���⣺��N�������̣�M��������K����Ʒ��ÿ�������̶�ÿ����Ʒ�ĵĹ�������֪��ÿ��������ÿ����Ʒ������������֪���Ӳ�ͬ�Ĺ��������Ͳ�ͬ�Ļ��ﵽ��ͬ�Ĺ���������Ҫ��ͬ�Ļ��ѣ�����֪�ӹ�����Mj�͵�kind�ֻ���ĵ�λ����������Ni��������ĵ�λ���ѡ�
      �ʣ������Ƿ����������������㣬��С�˷��Ƕ��٣� 
������1�������Ƿ���������
    	��������Ҫ�������Ƿ���������Ҫ����С���ã����������㹩�����ڵ�������ſ��ԡ����Ǳ��������k�ֻ�����ܹ����������������������һ�ֻ�������������ڹ���������ôֱ�����-1��������סҪ�Ƚ���Ŀ��������꣬����wa������Ȼ��ֻ�й����������󣬲����ҳ���Сֵ��Ҳһ�����ҵ���Сֵ��
      2�� ��С���������
    	����Ŀ���Կ���������n���ˣ���������Դ��������С�����������������ʵ��Ŀ�Ѿ���������ʾ��������k��N*M�ľ�����ʵ�������������ȼ���ÿһ�ֻ������С���ã�Ȼ����ͼ��ɡ�ͨ�����������׷��֣���k�л������С���ú�����ɣ������໥Ӱ�졣
      3�� ��ô��ν�ͼ��
    	Դ��s�ͻ��t��������������£�Դ��s���Ϊ0�������̱�Ŵ�1��M��������Ŵ�M+1��M+N�����t���ΪM+N+1���ܽ����nmax=M+N+2������ÿ���ߵġ����ѡ��ռ�map[nMax][ nMax]�͡��������ռ�cap[nMax][ nMax]������ʼ��Ϊȫ0��Դ��s�����й�����M���ߣ�����Ϊ0������Ϊ������j�Ĺ�������
   		ÿ�������̶���ÿ���������ߣ����򻡷���Ϊ�������ݵĵ�k����������Ϊ������j�Ĺ����������򻡷���Ϊ���򻡷��õĸ���������Ϊ0��
    	���й�������t���ߣ�����Ϊ0������Ϊ����i����������
      4���㷨ʵ��
    	��ÿ����Ʒ������⣬���ڵ�k����Ʒ��ͼ����spfa�㷨�����С����·����������������������·���������������Сֵ����ʵҲ������������Ȼ����·���������ȥ��������������ϴ�����������Ϊ���۳��Դ������� 
      �Լ��Ĵ�����spfaͣ��ס [DEBUG] 
*/
/*#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
struct edge{
	int u,v,w,c,f;
	edge(int u,int v,int w,int c):u(u),v(v),w(w),c(c),f(0){}
};
vector<edge> es;
vector<int> g[MAXN+3];
void addedge(int u,int v,int w,int c){
	es.push_back(edge(u,v,w,c));
	es.push_back(edge(v,u,-w,c));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
vector<int> minipaths;
int dis[MAXN+3],l[MAXN+3];
queue<int> q;
bitset<MAXN+3> inq;
int n,m,k,nd[MAXN+3][MAXN+3],has[MAXN+3][MAXN+3],cost[MAXN+3][MAXN+3],ndk[MAXN+3],hask[MAXN+3];
int spfa(int u,int v,int n){
	minipaths.clear();
	while(!q.empty())q.pop();
	memset(l,0,sizeof(l));
	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[u]=0;
	inq=0;
	inq[u]=1;
	q.push(u);
	while(!q.empty()){
		int t=q.front();q.pop();inq[t]=0;
		for(int i=0;i<g[t].size();i++){
			edge &e=es[g[t][i]];
			if(dis[t]+e.w<dis[e.v]&&e.c-e.f>0){
				dis[e.v]=dis[t]+e.w;
				l[e.v]=g[t][i];
				if(!inq[e.v]){
					inq[e.v]=1;q.push(e.v);
				}
			}
		}
	}
	int rel=INF;
	if(dis[v]!=INF)
		for(int i=v;i!=u;i=es[l[i]].u){
			minipaths.push_back(l[i]);
			rel=min(rel,es[l[i]].c-es[l[i]].f);
		}
	return dis[v]==INF?-1:rel;
}
void augment(int s,int t,int n){
	int mn=0;
	while((mn=spfa(s,t,n))!=-1){
		for(int i=0;i<minipaths.size();i++){
			edge &a=es[minipaths[i]];
			edge &b=es[minipaths[i]^1];
			a.f+=mn;
			b.f-=mn;
		}
	}
}
int Ans(){
	int ans=0;
	for(int i=0;i<es.size();i++){
		edge &e=es[i];
		if(e.f!=0)ans+=e.f*e.w;
	}
	//cout<<ans<<endl;
	return ans;
}
void init(int n){
	es.clear();
	for(int i=1;i<=n;i++)g[i].clear();
}
int main(){
	while(scanf("%d%d%d",&n,&m,&k),n+m+k>0){
		int s=n+m+2,t=s+1,ans=0;
		memset(hask,0,sizeof(hask));
		memset(ndk,0,sizeof(ndk));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				scanf("%d",&nd[i][j]);
				ndk[j]+=nd[i][j];
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=k;j++){
				scanf("%d",&has[i][j]);
				hask[j]+=has[i][j];
			}
		}
		bool flg=1;
		for(int i=1;i<=k;i++){if(ndk[i]>hask[i]){flg=0;break;}}
		for(int tk=1;tk<=k;tk++){
			init(t+1);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					scanf("%d",&cost[i][j]);
				}
			}
			if(!flg)continue;
			for(int i=1;i<=n;i++)addedge(i,t,0,nd[i][tk]);
			for(int i=1;i<=m;i++)addedge(s,n+i,0,has[i][tk]);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					addedge(n+j,i,cost[i][j],INF);
				}
			}
			augment(s,t,t+1);
			
			ans+=Ans();
		}
		if(flg)printf("%d\n",ans);
		else puts("-1");
	}
	return 0;
}*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
#define N 130
#define inf 100000000
int need[N][N];
int offer[N][N];
int map[N][N],cost[N][N];
int sum_need[N],sum_offer[N];
int n,m,K;
int pre[N];
int s,t;//Դ��ͽ�����
int spfa(){
	int dis[N];
	bool vis[N];
	int i;
	queue<int>q;
	for(i=0; i<=t; i++){
		vis[i]=false;
		dis[i]=inf;
	}
	vis[s]=true;
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int k=q.front();
		vis[k]=false;
		q.pop();
		for(i=0; i<=t; i++){
			if(map[k][i] && dis[i]>dis[k]+cost[k][i]){
				dis[i]=dis[k]+cost[k][i];
				pre[i]=k;
				if(vis[i]==false){
					vis[i]=true;
					q.push(i);
				}
			}
		}
	}
	if(dis[t]!=inf)return 1;
	else return 0;
}
int fond(){
	int i,j;
	int Min=INT_MAX;
	j=0;
	while(spfa()){
		for(i=t;i!=s; i=pre[i])Min=min(Min,map[pre[i]][i]);
		for(i=t; i!=s; i=pre[i]){
			map[pre[i]][i]-=Min;
			map[i][pre[i]]+=Min;
			j+=cost[pre[i]][i]*Min;
		}
	}
	return j;
}
int main(){
	int i,j,k,sum,sign;
	while(scanf("%d%d%d",&n,&m,&K)){
		if(n==0 && m==0 && K==0)break;
		sum=0;
		memset(sum_need,0,sizeof(sum_need));
		memset(sum_offer,0,sizeof(sum_offer));
		for(i=1; i<=n; i++)
			for(j=1; j<=K; j++){
				scanf("%d",&need[i][j]);
                sum_need[j]+=need[i][j];
			}
        for(i=1; i<=m; i++)
		   	for(j=1; j<=K; j++){
				scanf("%d",&offer[i][j]);
				sum_offer[j]+=offer[i][j];
			}
		sign=0;
		for(i=1; i<=K; i++)
			if(sum_offer[i]<sum_need[i]){sign=1;break;} 
		s=0;t=m+n+1; 
		for(k=1; k<=K; k++){
			for(i=0; i<=t; i++)
				for(j=0; j<=t; j++)
					map[i][j]=cost[i][j]=0;
			for(i=1+m; i<=n+m; i++)
				for(j=1; j<=m; j++){
					scanf("%d",&cost[j][i]);
					cost[i][j]=-cost[j][i];
				} 
		    if(sign==1)continue;  
		    for(i=1; i<=m; i++)
			   map[s][i]=offer[i][k];
	    	for(i=1; i<=m; i++)
			   for(j=1+m; j<=n+m; j++)
				 map[i][j]=offer[i][k];  
		   for(i=m+1; i<=m+n; i++)map[i][t]=need[i-m][k];
		  sum+=fond();
		}
		if(sign==1)printf("-1\n");
		else printf("%d\n",sum);
	}
    return 0;
}
