/*
数字之积
分析：
	首先对于每位数的乘积，有一个很显然的转移方程 
	d[i][j]表示i位数乘积为j的方案数，则有 
	
	d[i][j]=(1≤k≤9,k|j){d[i-1][k/j]}
	
	然而我们发现j可能很大，但经过实验发现只有5000余个，于是我们可以吧第二维下标换成在数表中的排名，单个递推就可做了； 
	对于区间[1,x)统计答案，是数位DP惯用的思路，先统计出位数比x小的答案数，再将x逐位拆分，每次统计当前位严格小于当前位上x原数字的答案，处理完后再将n除去当前位上原数字，注意如果x出现了0,则break掉，因为题目要求大于1；以上工作要求我们把d数组每一层做前缀和（注意做到n，否则有奇怪的问题）； 
	统计[L,R)容斥一下就好了 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=6000;
LL list[MAXN+3],tot;
LL cnt[19][MAXN+3],sum[19][MAXN+3];
LL l,r,n;
LL qpow(LL a,int n){
	LL ans=1;
	while(n){
		if(n&1)ans=ans*a;
		a=a*a;
		n>>=1;
	}
	return ans;
}
void pre(LL mx){
	LL x=0;
	for(int i=0;i<=3*12;++i)
    	for(int j=0;j<=2*12;++j)
    		for(int k=0;k<=12;++k)
				for(int p=0;p<=12;++p){
              		x=qpow(2,i)*qpow(3,j)*qpow(5,k)*qpow(7,p);
					if(x<=mx&&x>0)list[++tot]=x;
            	}
    sort(list+1,list+tot+1);
}
LL solve(LL x,int n) {
	int bit=0,cur,R=upper_bound(list+1,list+tot+1,n)-list-1;
	LL tx=x,ans=0;
	while(tx){bit++;tx/=10;}
	for(int i=1;i<=bit-1;i++)
		ans=ans+sum[i][R];
	for(;bit;--bit){
		LL t=qpow(10,bit-1);
		cur=x/t;x%=t;
		for(int i=1;i<cur;i++)
			if(n>=i){
				if(bit>1)ans+=sum[bit-1][upper_bound(list+1,list+tot+1,n/i)-list-1];
				else ans++;
			}
		if(cur)n/=cur;
		else break;
	}
	return ans;
}
inline void calsum(int r){
	sum[r][0]=0;
	for(int j=1;j<=tot;++j)sum[r][j]=sum[r][j-1]+cnt[r][j];
}
int main() {
	scanf("%lld%lld%lld",&n,&l,&r);
	pre(n);
	for(int i=1;i<=9;i++)cnt[1][i]=1;calsum(1);
	for(int i=2;i<=18;i++){
		int up=upper_bound(list+1,list+tot+1,qpow(10,i))-list-1;
		for(int j=1;j<=up;j++){
			for(int k=1;k<=9;k++){
				if(list[j]%k==0)
					cnt[i][j]+=cnt[i-1][lower_bound(list+1,list+tot+1,list[j]/k)-list];
			}
		}
		calsum(i);
	}
	printf("%lld\n",solve(r,n)-solve(l,n));
	return 0;
}
