/*
冗余关系
分析：并查集 
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1000;
int fa[MAXN+3],m,n,a,b,ans=0;
int find(int x){
	return fa[x]==0?x:fa[x]=find(fa[x]);
}
bool same(int a,int b){
	return find(a)==find(b);
}
void unions(int a,int b){
	a=find(a),b=find(b);
	if(a!=b)fa[a]=b;
}
int main(){
	memset(fa,0,sizeof(fa));
	cin>>n>>m;
	while(n-->0){
		cin>>a>>b;
		if(same(a,b))ans++;
		else unions(a,b);
	}
	cout<<ans;
	return 0;
} 
