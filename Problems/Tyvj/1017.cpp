/*
ศ฿ำเนุฯต
*/ 
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1000;
struct uniset{
	int pa[MAXN+3];
	void init(){memset(pa,0,sizeof(pa));}
	int find(int x){return pa[x]==0?x:pa[x]=find(pa[x]);}
	bool same(int x,int y){return find(x)==find(y);}
	void unions(int x,int y){x=find(x);y=find(y);if(x==y)return;pa[x]=y;}
}S;
int n,m,ans=0,a,b;
int main(){
	cin>>n>>m;S.init();
	while(n--){
		cin>>a>>b;
		if(S.same(a,b))ans++;
		else S.unions(a,b);
	}
	cout<<ans;
	return 0;
}
