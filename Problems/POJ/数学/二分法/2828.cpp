/*
Buy Tickets
题意：给定N(1 <= N <= 200000)个整数对(A,B)，表示在A(0<=A<i)右边的位置插入一个B，经过N次操作后问最后的B序列的排列情况。 
分析：逆向着想，先插入最后一个要插入的：在第A+1位置插入B代表在某个位置前要有A+1（因为A从0开始）个空位置，这样维护位置是否填数，树状数组维护一个点及其之前有多少个数
	  插入时：二分位置，直到找到一个位置满足他之前有A+1个空位，将B放到这个位置，同时更新树状数组
	  O(nlog^2n) 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#define lowbit(x) ((x)&(-x)) 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200000;
struct value{
	int val,pos;
}vs[MAXN+3];
int c[MAXN+3],n,ans[MAXN+3];
void add(int x,int ad){for(;x<=n;x+=lowbit(x))c[x]+=ad;}
int sum(int x){int ans=0;for(;x>0;x-=lowbit(x))ans+=c[x];return ans;} 
int ef(int l,int r,int val){
	int ans=l;
	while(l<=r){
		int mid=(l+r)>>1;
		if(mid-sum(mid)>=val)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){scanf("%d%d",&vs[i].pos,&vs[i].val);vs[i].pos++;}
		memset(c,0,sizeof(c));memset(ans,0,sizeof(ans));
		for(int i=n;i>=1;i--){
			int p=ef(1,n,vs[i].pos);
			ans[p]=vs[i].val;
			add(p,1);
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}

