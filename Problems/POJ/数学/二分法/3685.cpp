/*
Matrix
分析：有一个规律是看得见的，j不变i增大函数值也在增大。根据这个可以对这n列二分得到<x的值，同样所求的x也是可以二分慢慢靠近最后的结果，我处理得到最后的结果是个数为m+1的最小值，所以最后mid-1即为答案。
	  但两种二分结果不同，决定采取这种 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#define VAL(i,j) (i*i+i*100000LL+j*j-j*100000LL+i*j)
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef long long LL;
LL n,m,T;
LL getcnt(LL val){
	LL ans=0;
	for(LL i=1;i<=n;i++){
		LL l=1,r=n+1,mid=(l+r)>>1;
		while(l<r){
			if(VAL(mid,i)>=val)r=mid;
			else l=mid+1;
			mid=(l+r)>>1;
		}
		ans+=mid-1;
	}
	return ans;
}
LL ef(LL l,LL r){
	LL mid=(l+r)>>1;
	while(l<r){
		if(getcnt(mid)>=m)r=mid;
		else l=mid+1;
		mid=(l+r)>>1;
	}
	return mid-1;
}
int main(){
	for(scanf("%lld",&T);T;T--){
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",ef(-1e12,1e12));
	}
	return 0;
}
/*
这个二分错在哪：
或许这道题是找位置，而不是求可行，所以维护答案的方式并不合适 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#define VAL(i,j) (i*i+i*100000+j*j-j*100000+i*j)
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef long long LL;
LL n,m,T;
LL getcnt(LL val){
	LL ans=0;
	for(LL i=1;i<=n;i++){
		LL l=1,r=n,t=l;
		while(l<=r){
			LL mid=(l+r)>>1;
			if(VAL(mid,i)<val)l=mid+1;
			else r=mid-1,t=mid;
		}
		ans+=t-1;
	}
	return ans;
}
LL ef(LL l,LL r){
	LL ans=l,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(getcnt(mid)>=m)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main(){
	for(scanf("%lld",&T);T;T--){
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",ef(-1e12,1e12));
	}
	return 0;
} 
*/
