/*
Wooden Sticks
题意：我们要处理一些木棍，第一根的时间是1分钟，另外的，在长度为l，重为w的木棍后面的那根的长度为l’, 重量w’，只要l <=l’ 并且w <= w’，就不需要时间，否则需要1分钟，求如何安排处理木棍的顺序，才能使花的时间最少。
分析：按l为第一关键字，w为第二关键字排序，然后求以每个要选位置的最长不上升子序列，类似于贪心 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=5000;
struct data{
	int l,w;
	bool operator <(const data &t)const{
		return l<t.l||l==t.l&&w<t.w;
	}
}ds[MAXN+3];
int n;
bitset<MAXN+3> used;
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&ds[i].l,&ds[i].w);
	}
	sort(ds+1,ds+n+1);
}
int solve(){
	int ans=0,curw=0;used=0;
	for(int i=1;i<=n;i++){
		if(used[i])continue;
		curw=ds[i].w;
		for(int j=i+1;j<=n;j++){
			if(curw<=ds[j].w&&!used[j]){
				used[j]=1;curw=ds[j].w;
			}
		}
		ans++;
	}
	return ans;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		input();
		printf("%d\n",solve());
	}
	return 0;
}

