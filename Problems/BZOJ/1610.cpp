/*
[Usaco2008 Feb]Line连线游戏
分析：所有点两两之间连线计算斜率，排序扫一遍。注意斜率不存在的情况
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define eps 1e-8
#define INF 1e20
using namespace std;
int n,tot,ans;
double sl[40001];
struct point{double x,y;}a[201];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	    scanf("%lf%lf",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
	   for(int j=i+1;j<=n;j++)
	      if(a[i].x!=a[j].x)sl[++tot]=(a[j].y-a[i].y)/(a[j].x-a[i].x);
	      else sl[++tot]=INF;
	sort(sl+1,sl+tot+1);
	for(int i=1;i<=tot;i++)
	   if(fabs(sl[i]-sl[i-1])>eps)ans++;
	printf("%d",ans);
	return 0;
}
