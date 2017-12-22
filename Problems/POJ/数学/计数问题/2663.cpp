/*
Tri Tiling
题意：给定1*2的小矩形，去拼接一个3*n（n<30）的矩形，问有多少种方案。 
分析：n为奇数肯定为0，n为偶数，每次都是加两列，我们把两列看为一列，如果这一列与前面分开就只有三种方法即3*a[n-2],如果这一列不与前面的分开，那么不可分解矩形都只有两种情况所以为2*（a[n-4]+a[n-6]+……a[0])
	  化简即为a[n]=4*a[n-2]-a[n-4]
	  化简怎么化得？没有太懂 
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef long long LL; 
LL a[31],n;
int main(){
    a[0]=1;a[2]=3;
    for(int i=4;i<=30;i+=2)a[i]=4*a[i-2]-a[i-4];
    while(scanf("%lld",&n),n!=-1)printf("%lld\n",a[n]);
}


