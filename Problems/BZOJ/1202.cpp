/*
[HNOI2005]狡猾的商人
分析：并查集+边权 
*/
#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;
int fa[105],v[105],w,n,m;
void init(){
	memset(v,0,sizeof(v));
	for(int i=0;i<=100;i++)fa[i]=i;
}
int find(int x){
	if(fa[x]==x)return x;
	int f=find(fa[x]);
	v[x]+=v[fa[x]];
	return fa[x]=f;
}
bool unite(int a,int b,int w){
	int p=find(a),q=find(b);
	if(p==q)return v[b]-v[a]==w;
	else{
		fa[p]=q;
		v[p]=v[b]-v[a]-w;
		return true;
	}
}
int main(){
	for(scanf("%d",&w);w;w--){
		scanf("%d%d",&n,&m);init();
		for(int x,y,z;m;m--){
			scanf("%d%d%d",&x,&y,&z);
			if(!unite(x-1,y,z)){
				puts("false");break;
			}
		}
		if(m==0)puts("true");
	}
}
