/*
Number Sequence
题意：一个数列如下：1121231234123451234561234567123456789123456789101234567891011...求此数列第n位
分析：先想的是二分k使得sigma{1..k}<=n，进而得到第n位，但是由于10，11等多位数的存在，此法无效。
	  先算出前i个数组成的序列长度，先减去一些位数，然后暴力枚举 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<bitset>
using namespace std;
#define bit(x) ((int)(log10((double)x))+1)
const int INF=0x3f3f3f3f,MAXN=50000;
/*int solve(int k){
	int l=0,r=100000000;
	while(l<r){
		int mid=(l+r)>>1;
		if((1LL+mid)*mid/2LL<k)l=mid+1;
		else r=mid;
	}
	l--;
	int n=(1+l)*l/2;
	int ans=0;
	return k-n;
}
int main(){
	int T,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&x);
		printf("%d\n",solve(x));
	}
	return 0;
}*/
int s[MAXN+3],n,t,ans;
int main(){
    s[0]=0;
    for(int i=1;i<MAXN;++i)s[i]=s[i-1]+bit(i);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int k=0,l=0;
        while(n >= s[k])n-=s[k++]; //去掉整的位
        if(!n){printf("%d\n",(k-1)%10); continue;}
        for(k=1;l<n;++k)l+=bit(k);//凑出第n位的数i是多少。
        ans=(--k)/((int)pow(double(10),l-n)); //去掉多余的位
		printf("%d\n",ans%10);
    }
    return 0;
}

