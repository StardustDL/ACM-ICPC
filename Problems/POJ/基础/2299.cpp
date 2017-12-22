/*
Ultra-QuickSort
题意：给一些(n个)乱序的数，让你求冒泡排序需要交换数的次数
分析：求逆序对个数，离散化后BIT 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int INF=0x3f3f3f3f,MAXN=500000;
typedef long long LL;
int c[MAXN+3],a[MAXN+3],rank[MAXN+3],tmp[MAXN+3],n,p;
void add(int x,int ad){
	for(;x<=p;x+=lowbit(x))c[x]+=ad; 
}
int sum(int x){
	int ans=0;
	for(;x>0;x-=lowbit(x))ans+=c[x];
	return ans;
}
bool cmp(int i,int j){
	return a[i]<a[j];
}
int main(){
	while(scanf("%d",&n),n){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);rank[i]=i; 
		}
		sort(rank+1,rank+n+1,cmp);p=1;
		for(int i=1;i<=n;i++)/*tmp[rank[i]]=i;*/tmp[rank[i]]=a[rank[i]]==a[rank[i]-1]?p-1:p++;
		memset(c,0,sizeof(c));
		LL ans=0;
		for(int i=1;i<=n;i++){
			add(tmp[i],1);
			ans+=i-sum(tmp[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

