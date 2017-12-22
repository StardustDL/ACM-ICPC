/*
The dog task
题意：主人带狗去散步，主人走n个点，狗在每个点都会与主人碰头，但其余时候都是各自溜达，除此之外，狗还会去找一些有趣的地方（共m个），每次离开主人狗最多去一个有趣的地方。狗的速度最快是人的两倍，求使得狗到达最多有趣点的方法。
分析：对于人从第i个点到第i+1个点，这条路作为三角形的一边c，然后遍历其他点，若j与这两个点组成的边即为a,b如果a+b<=2*c则g[i][j]=true，然后做二分图最大匹配，就是狗最多能到的点。
	  注意进行匈牙利算法时，不仅记录N->M的匹配边，还要记录M->N的相对应的匹配边，因为要根据这个生成答案序列 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<bitset>
#define cal(A,B) sqrt((double)((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)))
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
const double eps=1e-8;
struct point{
	int x,y;
}ps[MAXN+3],ds[MAXN+3]; 
int match[MAXN+3],link[MAXN+3],N,M;
bool g[MAXN+3][MAXN+3],vis[MAXN+3];
bool findpath(int u){
	for(int i=1;i<=M;i++){
		if(g[u][i] && !vis[i]){
			vis[i]=1;
			if(match[i]==-1 || findpath(match[i])){
				match[i]=u;
				link[u]=i;
				return true;
			}
		}
	}
	return false;
}
int Maxpart(){
	memset(match,-1,sizeof(match));
	memset(link,-1,sizeof(link));
	int ans=0;
	for(int i=1;i<=N;i++){
		memset(vis,0,sizeof(vis)); 
		ans+=findpath(i); 
	}
	return ans;
}
inline bool check(int i,int j,int k){
	double a=cal(ps[i],ds[k]),b=cal(ps[j],ds[k]),c=cal(ps[i],ps[j]);
	return (a+b<2.0*c+eps);
}
void buildgraph(){
	memset(g,0,sizeof(g));
	for(int i=1;i<N;i++)
		for(int j=1;j<=M;j++)
			g[i][j]=check(i,i+1,j);
}
void input(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)scanf("%d%d",&ps[i].x,&ps[i].y);
	for(int i=1;i<=M;i++)scanf("%d%d",&ds[i].x,&ds[i].y);
}
int main(){
	input();
	buildgraph();
	printf("%d\n",N+Maxpart());
	for(int i=1;i<N;i++){
		printf("%d %d ",ps[i].x,ps[i].y);
		if(link[i]!=-1)printf("%d %d ",ds[link[i]].x,ds[link[i]].y);
	}
	printf("%d %d\n",ps[N].x,ps[N].y);
	return 0;
}

