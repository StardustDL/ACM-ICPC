/*
[JSOI2009]Count
分析：数字范围小，开100个树状数组 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
#define lowbit(x) (x&(-x))
int cnt[103][303][303],n,m,mp[303][303];
void add(int c,int x,int y,int ad){
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=m;j+=lowbit(j))
			cnt[c][i][j]+=ad;
}
int sum(int c,int x,int y){
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			ans+=cnt[c][i][j];
	/*for(;x;x-=lowbit(x))
		for(;y;y-=lowbit(y))//不能这么写，这样y就只会循环一次 
			ans+=cnt[c][x][y];*/
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&mp[i][j]);
			add(mp[i][j],i,j,1);
		}
	}
	int q;scanf("%d",&q);
	for(int a,b,c,d,e,f;q;q--){
		scanf("%d",&a);
		if(a==1){
			scanf("%d%d%d",&b,&c,&d);
			add(mp[b][c],b,c,-1);
			mp[b][c]=d;
			add(mp[b][c],b,c,1);
		}
		else{
			scanf("%d%d%d%d%d",&b,&d,&c,&e,&f);
			printf("%d\n",sum(f,d,e)+sum(f,b-1,c-1)-sum(f,d,c-1)-sum(f,b-1,e));
		}
	}
	return 0;
}

