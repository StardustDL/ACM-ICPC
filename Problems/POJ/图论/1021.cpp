/*
题意：判断点阵是否是同构
分析：怎么判断连成一片的棋子形状相同？ 一个基于概率的算法是：给每一颗棋子计算一个值，根据这个值是否相等来推测它所在的一片棋子的形状是否相等。计算出每颗棋子的值后对其进行排序，若两副棋盘生成的序列完全相等则推测其等价。
	  网上有一个做法是统计十字走的步数，觉得非常神奇。虽然看起来不怎么科学，但是可能是数据比较水，居然能A。大致思路就是统计每个点能向四个方向走的步数的和，再比较这两个图中每个点是否都能找到一个总步数相同的点与之匹配。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXP=100,MAXN=MAXP*MAXP;
struct point{
	int x,y;
}ps[MAXN+3];
int T,n,w,h,cnt1[MAXN+3],cnt2[MAXN+3];
bool mp[MAXP+3][MAXP+3];
void solve(int *cnt){
	memset(mp,0,sizeof(mp)); 
	for(int i=1;i<=n;i++){scanf("%d%d",&ps[i].x,&ps[i].y);mp[ps[i].x][ps[i].y]=1;}
	for(int i=1;i<=n;i++){
		int xx=ps[i].x,yy=ps[i].y,x,y,s=0;
		for(x=xx,y=yy;mp[x][y]&&y<h;++y,++s);
		for(x=xx,y=yy;mp[x][y]&&x<w;++x,++s);
		for(x=xx,y=yy;mp[x][y]&&y>=0;--y,++s);
		for(x=xx,y=yy;mp[x][y]&&x>=0;--x,++s);
		cnt[i]=s;
	}
	sort(cnt+1,cnt+n+1);
}
bool check(){
	for(int i=1;i<=n;i++)if(cnt1[i]!=cnt2[i])return false;
	return true;
} 
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d%d%d",&w,&h,&n);
		solve(cnt1);
		solve(cnt2);
		if(check())puts("YES");
		else puts("NO");
	}
	return 0;
}

