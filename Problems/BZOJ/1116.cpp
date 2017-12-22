/*
[POI2008]CLO
分析：首先无向边不贡献入度，有向边贡献一个入度，所以只要一个联通块中含有环，就能做到，否则就会有一个点做不到
	  如何判断有环：并查集：link(a,b)若a,b属于同一个集合，则这个集合有环，若不属于，合并，新集合有环=子集合至少有一个环 
	  注意先标记，再修改树的结构 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
int pa[MAXN+3];
bool mark[MAXN+3];
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	//for(int i=1;i<=n;i++)pa[i]=i;
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);a=find(a),b=find(b);
		if(a==b)mark[a]=1;
		else{
			mark[b]|=mark[a];
			pa[a]=b;//错误写法:pa[find(a)]=find(b);mark[find(b)]|=mark[find(a)];这样第二次查找a的根，就已经是b了，这显然不是想要的 
		}
	}
	for(int i=1;i<=n;i++)if(mark[find(i)]==0){puts("NIE");return 0;}
	puts("TAK");
	return 0;
}

