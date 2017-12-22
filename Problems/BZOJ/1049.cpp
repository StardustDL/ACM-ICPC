/*
[HAOI2006]数字序列
分析：第一问b[i]=a[i]-i做最长不降子序列 （其实最长严格上升也是可以的，不过那样第二问就不是很好做了） 
		假设 a 是原数组，对于 i,j,i < j 使得 i,j 不被修改的必要条件是 aj-ai ≥j-i, 这样就能通过把中间 j-i-1 个数修改让他们严格递增，反之无解
	  记录第一问转移，g[i]表示最小代价
	  g[i]=min{g[j]+w(j+1,i) | f[j]+1=f[i]}
	  w(l,r)表示把b(l..r)改成单调不降的最小代价（这个等价于a严格增）
	   如果从j转移到i的话（要求j<i&&a[j]<=a[i]），那么中间一定有一个k(k>=j&&k<i)，使得j~k的高度都是b[j]，k+1~i的高度都是b[i]，且这样的花费是最优的
	   随机数据，可过 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL; 
const int MAXN=35000+5,INF=0x3f3f3f3f;
int n;
int a[MAXN+3],sta[MAXN+3],top,f[MAXN+3];
LL g[MAXN+3],s1[MAXN+3],s2[MAXN+3];
vector<int> gr[MAXN+3];//gr[i]表示f[x]=i的所有x 
void dp(){
	memset(sta,INF,sizeof(sta));
	sta[0]=-INF;
	for(int i=1;i<=n;i++){
		int t=upper_bound(sta+1,sta+top+1,a[i])-sta;
		f[i]=t;
		top=max(top,t);
		sta[t]=min(sta[t],a[i]);
	}
}
void solve(){
	for(int i=0;i<=n;i++){
		gr[f[i]].push_back(i);
		g[i]=1LL<<60;
	}
	g[0]=0;a[0]=-INF;
	for(int x=1;x<=n;x++)
		for(int i=0;i<gr[f[x]-1].size();i++){//枚举f[x]的上一个转移 
			int p=gr[f[x]-1][i];
			if(p>x)break;//这是不可行转移，注意跳出(gr[t]中是递增的) 
			if(a[p]>a[x])continue;//这是不可行转移 
			for(int j=p;j<=x;j++)
				s1[j]=abs(a[p]-a[j]),s2[j]=abs(a[x]-a[j]);
			for(int j=p+1;j<=x;j++)
				s1[j]+=s1[j-1],s2[j]+=s2[j-1];
			for(int j=p;j<x;j++)
				g[x]=min(g[x],g[p]+(s1[j]-s1[p])+(s2[x]-s2[j]));
		}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);a[i]-=i;}
	a[++n]=INF;
	dp();
	solve();
	printf("%d\n%lld\n",n-f[n],g[n]);
	return 0;
}
