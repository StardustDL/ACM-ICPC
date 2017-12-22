/*
选学霸 
分析：并查集维护大小，然后做零一背包 
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
	void init(int n){//这里是1..n 
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
	cin>>n>>m>>k;
	S.init(n);
	for(int i=1;i<=k;i++){
		cin>>a>>b;
		S.unions(a,b);
	}
	//for(int i=1;i<=n;i++)cout<<S.cnt[i]<<" ";
	for(int i=1;i<=n;i++){
		if(i==S.find(i)){
			//cout<<S.cnt[i]<<endl;
			v.push_back(S.cnt[i]);
		}
	}
	for(int i=1;i<=v.size();i++){
		for(int j=2*m+1;j>=v[i-1];j--){
			opt[j]=max(opt[j-v[i-1]]+v[i-1],opt[j]);
		}
	}
	//cout<<opt[m]<<endl;
	int ans=0;
	for(int i=0;i<=m;i++){
		if(opt[m-i]==m-i){
			ans=m-i;break;
		}
		if(opt[m+i]==m+i){
			ans=m+i;break;
		}
	}
	cout<<ans;
	return 0;
}

