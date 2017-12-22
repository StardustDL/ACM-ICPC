/*
River Hopscotch
题意：牛要到河对岸，在与河岸垂直的一条线上，河中有N块石头，给定河岸宽度L，以及每一块石头离牛所在河岸的距离，
          现在去掉M块石头，要求去掉M块石头后，剩下的石头之间以及石头与河岸的最小距离的最大值。
分析：二分即可，当相邻的石头的距离小于等于mid，就可以去掉 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=50000;
int l,m,n,d[MAXN+3];
inline bool check(int val){
	int ans=0;
	for(int i=1,last=0;i<=n+1;i++){
		if(val>=d[i]-d[last])ans++;
		else last=i;
	}
	return ans<=m;
}
int erfen(int l,int r){
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(!check(mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main(){
	scanf("%d%d%d",&l,&n,&m);
	d[0]=0;d[n+1]=l;
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	sort(d+1,d+n+1);
	printf("%d\n",erfen(0,l));
	return 0;
}

