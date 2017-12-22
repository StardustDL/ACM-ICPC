/*
关押罪犯
分析：把一组敌对关系看成一条边，犯人看成两个点，仇恨值看成边的权值。
	  那么接下来就先按权值由大到小进行边排序，之后每次取边，看边的两个顶点在当前的记录下能否分到两个集合中，如果可以，则记录他们不再同一集合中，如果不行，则当前边的权值就是答案，因为如果删去当前边会使之前的某条（些）边恢复，不会比当前解更优。
	  因此我们的问题就剩下了判断两点能否分到两个集合中，以及如何记录两点不再同一集合中。
		第一个问题：初始时每个点各成一个集合，用并查集记录，如果经查询两点已经在同一集合了，说明是之前的某次操作使得他们合并在了一个集合，因此分开会使之前的某条边恢复，所以不能分开。
		第二个问题：用并查集记录在同一个集合里比较简单，而记录不再一个集合里却比较困难。那么我们不妨再增加一些”影点“，i+n为i的影点，影点与原点不在同一个集合，那么我们便可以用a与i+n在同一个集合来表示a与i不再同一个集合了。注意要对称地合并 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=20000,MAXM=5*MAXN;
struct tar{
	int a,b,c;
	bool operator < (const tar &b)const{
		return c<b.c;
	}
};
int pa[2*MAXN+3],n,m;
tar ts[MAXM+3];
int find(int x){
	return pa[x]==x?x:pa[x]=find(pa[x]);
}
void unions(int a,int b){
	a=find(a);b=find(b);
	if(a!=b)pa[a]=b;
}
bool same(int a,int b){
	return find(a)==find(b);
}
void init(){
	int a,b,c;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>ts[i].a>>ts[i].b>>ts[i].c;
	}
	sort(ts+1,ts+m+1);
	for(int i=1;i<=2*n;i++)pa[i]=i;
}
int solve(){
	for(int i=m;i>=1;i--){
		tar &t=ts[i];
		if(same(t.a,t.b)){
			return t.c;
		}
		unions(t.a,t.b+n);
		unions(t.b,t.a+n);
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	init();
	cout<<solve();
	return 0;
}
