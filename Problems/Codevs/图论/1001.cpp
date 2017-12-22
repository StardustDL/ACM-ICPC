/*
舒适的路线 
题意：在一个无向图上寻找一条s-t路径，最小化这条路径上的边最大权值与边最小权值之比
分析：先把所有边从小到大排序，然后枚举每条边作为最小权值边，
		在所有比它权值大的边中找出一条路径，使得s-t连通（这里使用并查集实现）。
		与最优解比较，更新。 
注意：可能有重边，最优解初值的设定不能爆范围，int/int=int，要转成double
备注：一个多月没刷题，这道题坑了好几次，sort，cmp，并查集，变量名，各种低级错误。。
2015.2.20 2h 
*/ 
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=503,MAXM=5003,INF=1<<30;
struct edge{
	int u,v;
	double s;
}es[MAXM];
int n,m,S,T,pa[MAXN],ansa=0,ansb=0,r[MAXM];
double rate=INF*1.0;
bool isi = false;

bool cmp(const int i,const int j){
	return es[i].s<es[j].s;
}
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
void sunion(int x,int y){
	x=find(x);y=find(y);
	if(x!=y)pa[x]=y;
}
int gcd(int x,int y){
	return (x%y==0)?y:gcd(y,x%y);
}
void solve(int k){
	memset(pa,0,sizeof(pa));
	int j=k;
	for(;j<=m;j++){
		sunion(es[r[j]].u,es[r[j]].v);
		if(find(S)==find(T))break;
	}
	if(j>m)return;
	isi=true;
	if(es[r[j]].s/es[r[k]].s < rate){
		rate=es[r[j]].s/es[r[k]].s;
		ansa=(int)es[r[j]].s;
		ansb=(int)es[r[k]].s;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>es[i].u>>es[i].v>>es[i].s;
		r[i]=i;
	}
	cin>>S>>T;
	
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;i++){
		solve(i);
	}
	if(!isi){
		cout<<"IMPOSSIBLE";return 0;
	} 
	int x=gcd(ansa,ansb);
	ansa/=x,ansb/=x;
	if(ansb!=1)cout<<ansa<<"/"<<ansb;
	else cout<<ansa;
	return 0;
} 
