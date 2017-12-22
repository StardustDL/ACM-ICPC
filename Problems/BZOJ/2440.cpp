/*
[中山市选2011]完全平方数
分析：首先二分答案，接下来就转成计算小于x的非完全平方因子数的个数
	  容斥原理：
	  	对于√x以内的所有质数 x以内的无平方因子数
		  =无需是任何质数的倍数的数的数量(即x)-是至少一个质数平方倍数的数的数量+是至少两个质数平方倍数的数的数量-是至少三个质数平方倍数的数的数量...
		这个系数正好是莫比乌斯函数！
		于是我们枚举每一个数，如果这个数是奇数个不同质数的乘积，那么mu为负，偶数个则mu为正，否则mu为零
		故答案即Σx/(i*i)*mu[i] 注意平方的意义
		有人说二分是有上界的：Q(x)=6x/(pi^2) + O(sqrt(x)) Q(x)<=2x，但是不会证明 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
typedef long long LL;
const int MAXN=100000,INF=0x3f3f3f3f;
int mindiv[MAXN+3],miu[MAXN+3],K;
vector<int> pris;
inline void init(int size){
	miu[1]=1;
	for(int i=2;i<=size;i++){
		if(mindiv[i]==0){mindiv[i]=i;miu[i]=-1;pris.push_back(i);}
		for(int j=0,k;j<pris.size()&&(k=pris[j]*i)<=size;j++){
			mindiv[k]=pris[j];
			if(pris[j]==mindiv[i]){miu[k]=0;break;}
			miu[k]=-miu[i];
		}
	}
}
int calc(int x){
	int m=(int)sqrt(x),ans=0;
	for(int i=1;i<=m;i++){
		ans+=miu[i]*(x/(i*i));
	}
	return ans;
}
int bitse(int l,int r){
	int ans=l;
	while(l<=r){
		int mid=(l>>1)+(r>>1)+(l&r&1);
		if(calc(mid)>=K)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main(){
	init(MAXN);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&K);
		printf("%d\n",bitse(1,K<<1|1));
	}
	return 0;
}

