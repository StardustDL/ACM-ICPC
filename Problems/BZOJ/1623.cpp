/*
[Usaco2008 Open]Cow Cars 奶牛飞车
分析：注意这几点：牛的速度不一定等于上限，有多条路。贪心。 
		将牛的速度从小到大排序依次考虑，每次选择一个人数最少的集合考虑加入，因为是从小到大，那么就有后面的牛一定优于当前的牛，所以一定是尝试把这头牛放进去。 
		而人数最少的集合的人数=选择的人数除以组数。 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,d,l,ans=0,s[50000+3]; 
int main(){
	scanf("%d%d%d%d",&n,&m,&d,&l);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)if(s[i]-d*(ans/m)>=l)ans++;
	printf("%d\n",ans);
	return 0;
}

