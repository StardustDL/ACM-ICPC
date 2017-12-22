/*
Dollar Dayz
题意：求将n分解为大于等于1小于等于k的数，有多少种分法。（划分数问题）
分析：可以用完全背包解，枚举体积1..k，opt[j]+=opt[j-i]
	  另一种容易想到的方法： 用a[i][j]表示考虑到用数j进行拼接时数字i的拼接方法，可以得到状态转移方程如下：
		a[i][j]=a[i][j-1]+a[i-j][j-1]+a[i-2j][j-1]+a[i-3j][j-1]…+a[0][j-1]意思很明显，就将j-1状态可以到达a[i][j]的状态的数字相加。由于得到的结果可能相当大，已经超过了long long，所以应该用大数。但是若跑完所有数据，用大数会超过一秒，我们通过大数的程序可以达到，最大的数字为33位，那么，我们可以将两个long long的数字进行拼接，组成一个超过33位的数。
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL a[1010],b[1010];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    b[0]=1;
    for(int i=1;i<=k;i++)
        for(int j=i;j<=n;j++){
            a[j]=a[j]+a[j-i]+(b[j]+b[j-i])/INF;
            b[j]=(b[j]+b[j-i])%INF;
        }
    if(a[n])printf("%lld%018lld",a[n],b[n]);
    else printf("%lld\n",b[n]);
    return 0;
}
