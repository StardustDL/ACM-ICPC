#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200000;
int fa[MAXN+3],fw[MAXN+3],u[MAXN+3],v[MAXN+3],w[MAXN+3],r[MAXN+3],n,m,k;
long long ans=0;
int find(int x){
	return fa[x]==0?x:fa[x]=find(fa[x]);
}
bool cmp(const int i,const int j){
	return w[i]<w[j];
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		r[i]=i;
	}
	for(int i=1;i<=n;i++)fw[i]=1;
	sort(r+1,r+m+1,cmp);
	int cur=0;
	for(int i=1;i<=m;i++){
		int a=find(u[r[i]]),b=find(v[r[i]]);
		if(a!=b){
			fa[a]=b;
			fw[b]+=fw[a];
			ans+=w[r[i]];
			if(++cur==n-1)break;
		}
	}
	int t=find(k);
	if(fw[t]==n)cout<<ans;
	else cout<<n-fw[t];
	return 0;
}
