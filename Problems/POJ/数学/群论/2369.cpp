/*
题意：给一个1..n的排列P(i)，定义Pn(i)=P(Pn-1(i))，问最小的K使得Pk(i)=i
分析：本质上是求一置换T，T^k=e，的最小k
	  这个问题有一个定理：kmin=T的拆分的所有循环长度的最小公倍数
	  循环：将置换表示成图，i->p(i)，则图中的环即为置换中的循环
	  于是有了做法：对于每一位，算出最少的置换到自己应该的数字。每一位都有这样的数字，取最小公倍数就可以。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int n,a[MAXN+3],ans=1;
int gcd(int a,int b){
	//return a%b==0?b:gcd(b,a%b);
	return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,tmp,cnt;i<=n;i++){
		tmp=a[i];cnt=1;
		while(tmp!=i){
			tmp=a[tmp];
			cnt++;
		}
		ans=lcm(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}

