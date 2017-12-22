/*
The dog task
���⣺���˴���ȥɢ����������n���㣬����ÿ���㶼����������ͷ��������ʱ���Ǹ���������֮�⣬������ȥ��һЩ��Ȥ�ĵط�����m������ÿ���뿪���˹����ȥһ����Ȥ�ĵط��������ٶ�������˵���������ʹ�ù����������Ȥ��ķ�����
�����������˴ӵ�i���㵽��i+1���㣬����·��Ϊ�����ε�һ��c��Ȼ����������㣬��j������������ɵı߼�Ϊa,b���a+b<=2*c��g[i][j]=true��Ȼ��������ͼ���ƥ�䣬���ǹ�����ܵ��ĵ㡣
	  ע������������㷨ʱ��������¼N->M��ƥ��ߣ���Ҫ��¼M->N�����Ӧ��ƥ��ߣ���ΪҪ����������ɴ����� 
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

