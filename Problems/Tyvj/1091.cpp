/*
等差数列
分析：用f[i][j]表示等差数列的最后两项是i和j时的等差数列的个数，那么
		f[i][j] = ∑(f[j][k]) + 1 (data[i]-data[j]=data[j]-data[k]) ，
		此算法的复杂度是O(n^3).
		我们可以注意到，每个数字都不大，所以我们可以用f[i][j]表示等差数列最后一项为i，数列公差为j时，用类似的转移得到等差数列的个数。复杂度是O(n^2). 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f,D=1000,MOD=9901;
int opt[MAXN+3][2*D+3],n,a[MAXN+3],ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		(ans+=i)%=MOD;
		for(int j=1,p;j<i;j++){
			p=a[i]-a[j]+D;
			(ans+=opt[j][p])%=MOD;
			(opt[i][p]+=opt[j][p]+1)%=MOD;
		}
	}
	printf("%d",ans);
	return 0;
}

