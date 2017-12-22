/*
[POI2005]ska Piggy banks
分析：一个直接的思路是强连通缩点，统计入度为0的点，但是空间太大。
	  另一个思路：并查集：对于一个边(a,b)将b并到a，最后统计pa[i]==i的个数即是答案 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
int pa[MAXN+3],ans=0,n; 
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(find(i)!=find(x))pa[find(i)]=find(x);//注意这里pa[i]==0为终止条件，所以要加一个判断（保证不在一个集合），否则有可能会将pa[i]=0改成pa[i]=i，使得之后的find爆栈 
	}
	for(int i=1;i<=n;i++)ans+=pa[i]==0;
	printf("%d\n",ans);
	return 0;
}

