/*
���⣺�жϵ����Ƿ���ͬ��
��������ô�ж�����һƬ��������״��ͬ�� һ�����ڸ��ʵ��㷨�ǣ���ÿһ�����Ӽ���һ��ֵ���������ֵ�Ƿ�������Ʋ������ڵ�һƬ���ӵ���״�Ƿ���ȡ������ÿ�����ӵ�ֵ�������������������������ɵ�������ȫ������Ʋ���ȼۡ�
	  ������һ��������ͳ��ʮ���ߵĲ��������÷ǳ����档��Ȼ����������ô��ѧ�����ǿ��������ݱȽ�ˮ����Ȼ��A������˼·����ͳ��ÿ���������ĸ������ߵĲ����ĺͣ��ٱȽ�������ͼ��ÿ�����Ƿ����ҵ�һ���ܲ�����ͬ�ĵ���֮ƥ�䡣 
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

