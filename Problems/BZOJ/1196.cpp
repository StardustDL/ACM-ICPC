/*
[HNOI2006]公路修建问题
分析：二分答案，做MST，先添一级公路，由于不要求总费用，所以能添就添，然后考虑二级，可行条件是一级>=k，整个图连通(|T|=n-1) 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){} 
	bool operator <(const edge &t)const{
		return w<t.w;
	}
};
vector<edge> e1,e2;
int pa[MAXN+3];
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
bool unite(int a,int b){
	a=find(a),b=find(b);
	if(a==b)return false;
	pa[a]=b;
	return true;
}
int n,m,K;
bool check(int x){
	memset(pa,0,sizeof(pa));
	int cnt=0;
	for(int i=0;i<e1.size();i++){
		if(e1[i].w>x)break;
		if(unite(e1[i].u,e1[i].v))cnt++;
	}
	if(cnt<K)return false;
	for(int i=0;i<e2.size();i++){
		if(e2[i].w>x)break;
		if(unite(e2[i].u,e2[i].v))cnt++;
	}
	return cnt==n-1;
}
int main(){
	scanf("%d%d%d",&n,&K,&m);
	for(int i=1,a,b,c,d;i<m;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		e1.push_back(edge(a,b,c));
		e2.push_back(edge(a,b,d));
	}
	sort(e1.begin(),e1.end());
	sort(e2.begin(),e2.end());
	int l=0,r=INF,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}

