/*
Gopher II   
题意：有n只地鼠的坐标，m个洞的坐标，地鼠的移动速度为v,在s秒以后会飞来一只老鹰要吃地鼠，问有多少个地鼠可能被吃。
分析：二分图最大匹配 
*/
#include<iostream>
#include<cstdio>
#include<bitset>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#define sqr(x) ((x)*(x))
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
int link[MAXN+3],n,m,s,v;
double x[MAXN+3],y[MAXN+3];
vector<int> g[MAXN+3];
bitset<MAXN+3> vis;
inline double dist(double a,double b,int j){
	return sqr(a-x[j])+sqr(b-y[j]);
}
bool find(int u){
	for(int i=0;i<g[u].size();i++)
		if(!vis[g[u][i]]){
			vis[g[u][i]]=1;
			if(!link[g[u][i]] || find(link[g[u][i]])){
				link[g[u][i]]=u;return true;
			}
		}
	return false;
}
int maxpart(){
	memset(link,0,sizeof(link));int ans=0;
	for(int i=1;i<=n;i++)vis=0,ans+=find(i);
	return ans;
}
inline bool input(){
	if(scanf("%d%d%d%d",&n,&m,&s,&v)==EOF)return false;
	for(int i=1;i<=n;i++)scanf("%lf%lf",&x[i],&y[i]);
	for(int i=1;i<=n;i++)g[i].clear();
	double l=sqr(s*v),a,b;
	for(int j=1;j<=m;j++){
		scanf("%lf%lf",&a,&b);
		for(int i=1;i<=n;i++)
			if(dist(a,b,i)<=l)g[i].push_back(j);
	}
	return true;
}
int main(){
	while(input())printf("%d\n",n-maxpart());
	return 0;
}

