/*
[CQOI2009]中位数图
分析：中位数：要求大于x的数和小于x的数个数相同，这样将所有大于的置为1，小于的置为-1，只要和为零即可，
	  又因为是连续子序列，从x的位置向左右扫，最后乘法原理统计答案。
	  注意+0=-0，这个不能统计两次，其余的都有l[i]*r[-i]+l[-i]*r[i] 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
int n,b,pos,ans=0;
int a[MAXN+3],_l[2*MAXN+3],_r[2*MAXN+3],*l=&_l[MAXN],*r=&_r[MAXN]; 
int main(){
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>b)a[i]=1;
		else if(a[i]<b)a[i]=-1;
		else a[pos=i]=0;
	}
	for(int i=pos,t=0;i>0;i--)l[t+=a[i]]++;
	for(int i=pos,t=0;i<=n;i++)r[t+=a[i]]++;
	ans=l[0]*r[0];
	for(int i=1;i<=n;i++)
		ans+=l[i]*r[-i]+r[i]*l[-i];
	printf("%d",ans);
	return 0;
}

