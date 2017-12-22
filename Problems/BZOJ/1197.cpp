/*
[HNOI2006]花仙子的魔法
分析：观察一维的情况：每加入一条线段最多增加两个区间（线段两边相交的区间是新的）。
		然后考虑二维的情况：已有两个相交的圆，现在加入第三个，可以发现如果把第三个圆展开成一条线段，
		其与其他两个圆相交的位置也对应到线段上，那么可以转化成一维的两条线段的情况。
		由此得出DP：记f[i][j]为最多的区间数，其中i为维数，j为施法次数。方程：f[i][j]=f[i][j-1] + f[i-1][j-1]。 
		边界f[1][i]=2*i,f[i][1]=2 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL cnt[18][103];
int n,m;
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)cnt[1][i]=i*2;
	for(int i=1;i<=n;i++)cnt[i][1]=2;
	for(int i=2;i<=n;i++)
		for(int j=2;j<=m;j++)
			cnt[i][j]=cnt[i][j-1]+cnt[i-1][j-1];
	printf("%lld\n",cnt[n][m]);
	return 0;
}

