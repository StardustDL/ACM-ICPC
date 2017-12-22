/*
Space Elevator
题意：有一群牛要上太空,他们计划建一个太空梯(用一些石头垒),他们有k种不同类型的石头,每一种石头的高度为h,数量为c,由于会受到太空辐射,每一种石头不能超过这种石头的最大建造高度a,求解利用这些石头所能修建的太空梯的最高的高度.
分析：先对最大高度升序排序，然后就变成多重背包可行性判断，用完全背包+计数可解 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=400,MAXH=40000,INF=0x3f3f3f3f;
struct thing{
	int n,h,mxh;
	bool operator <(const thing &t)const{
		return mxh<t.mxh;
	}
	void input(){scanf("%d%d%d",&h,&mxh,&n);}
}ds[MAXN+3];
bool can[MAXH+3];
int n,cnt[MAXH+3],ans=0; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)ds[i].input();
	sort(ds+1,ds+n+1);
	can[0]=1;
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		for(int j=ds[i].h;j<=ds[i].mxh;j++)//注意要判断!can[j]，这样保证cnt[j]最小，解更优 
			if(!can[j]&&can[j-ds[i].h]&&cnt[j-ds[i].h]<ds[i].n)can[j]=1,cnt[j]=cnt[j-ds[i].h]+1;
	} 
	for(int i=ds[n].mxh;i>=0&&ans==0;i--)if(can[i])ans=i;
	printf("%d",ans);
	return 0;
}

