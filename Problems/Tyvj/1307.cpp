#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000,MAXM=10000;
int n,m,u[MAXM+3],v[MAXM+3],w[MAXM+3],r[MAXM+3],cm=0,pa[MAXN+3],ans=0;
void init(){
	memset(pa,-1,sizeof(pa));
}
int find(int x){
	return pa[x]==-1?x:pa[x]=find(pa[x]); 
}
bool unio(int a,int b){
	a=find(a);b=find(b);
	if(a!=b)pa[a]=b;
	return a!=b;
}
void read(){
	cin>>n>>m;
	int p,a,b,c;
	for(int i=1;i<=m;i++){
		cin>>p>>a>>b>>c;
		if(p==1){
			ans+=c;
			unio(a,b);
		}
		else{
			cm++;
			u[cm]=a;v[cm]=b;w[cm]=c;r[cm]=cm;
		}
	}
}
bool cmp(const int i,const int j){
	return w[i]<w[j];
}
void kruskal(){
	sort(r+1,r+cm+1,cmp);
	for(int i=1;i<=cm;i++){
		if(unio(u[r[i]],v[r[i]])){
			ans+=w[r[i]];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	init();
	read();
	kruskal();
	cout<<ans;
	return 0;
}
