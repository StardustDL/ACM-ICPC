/*
[Spoj 5971] LCMSum
分析：sigma{lcm(i,n)}=sigma{i*n/gcd(i,n)}=n*sigma{i/gcd(i,n)}
	  可以根据分母，将分子分类，
	  问题变成求<=d&&gcd(i,d)==1的i的和，
	  对于n(n>2)，满足<=n且与n互质的数的和 s=n*phi(n)/2。 
	  	考虑与n不互质的数a，那么容易证明n-a也与n不互质。
		也就是说，不互质的数能够组成和为n的一组。
		那么去除这些数后，互质的数也是可以分成和为n的组的。那么互质的数的和就相当于每两个一组，得到一个n 
	  特例：1:1,2:1
	  那么筛法求phi，枚举n的约数d，则有ans=n*sigma{((n/d)*phi(n/d)/2)*d/d}，卡时过 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=1000000,INF=0x3f3f3f3f;
int t,n;
LL phi[MAXN+3];
int mindiv[MAXN+3];
vector<int> primes;
void calc(){
	phi[1]=1;
	for(int i=2;i<=MAXN;i++){
		//cout<<i<<endl;
		if(mindiv[i]==0){phi[i]=i-1;primes.push_back(i);mindiv[i]=i;}
		for(int j=0;j<primes.size();j++){
			int k=i*primes[j];if(k>MAXN)break;//注意判超界 
			mindiv[k]=primes[j];
			if(i%primes[j]==0){phi[k]=phi[i]*(primes[j]);break;}//注意是==0退出 
			else phi[k]=phi[i]*(primes[j]-1);
		}
	}
	for(int i=2;i<=MAXN;i++)phi[i]=phi[i]*i>>1;//预处理下phi 
}
LL solve(int n){
	int up=(int)(sqrt(1.0*n));
	LL ans=0;
	for(int i=1;i<=up;i++){
		if(n%i)continue;
		ans+=phi[i];
		if(n/i!=i)ans+=(phi[n/i]);
	}
	return ans*n;
}
int main(){
	scanf("%d",&t);
	calc();
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",solve(n));
	}
	return 0;
}

