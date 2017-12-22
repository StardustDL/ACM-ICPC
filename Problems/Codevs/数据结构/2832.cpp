/*
6个朋友 
分析：并查集维护大小 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=30000;
struct Uniset{
	int pa[MAXN+3],n,cnt[MAXN+3];
	void init(int n){
		this->n=n;
		for(int i=1;i<=n;i++){
			pa[i]=i;cnt[i]=1; 
		}
	}
	int find(int x){
		return pa[x]==x?x:pa[x]=find(pa[x]);
	}
	bool unions(int x,int y){
		x=find(x),y=find(y);
		if(x==y)return false;
		pa[x]=y;
		cnt[y]+=cnt[x];
		return true;
	}
}S;
int n,m,k,a,b,opt[MAXN*2+3];
vector<int> v;
int main(){
	cin>>n>>m;
	S.init(n);
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		S.unions(a,b);
	}
	for(int i=1;i<=n;i++){
		if(i==S.find(i)){
			v.push_back(S.cnt[i]);
		}
	}
	if(v.size()<=6)cout<<"^_^";
	else {
		int t=v.size();
		sort(v.begin(),v.end());
		cout<<"T_T"<<endl<<v[t-1]+v[t-2]+v[t-3]+v[t-4]+v[t-5]+v[t-6];
	}
	return 0;
}
