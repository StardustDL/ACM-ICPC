/*
[Spoj 5971] LCMSum
������sigma{lcm(i,n)}=sigma{i*n/gcd(i,n)}=n*sigma{i/gcd(i,n)}
	  ���Ը��ݷ�ĸ�������ӷ��࣬
	  ��������<=d&&gcd(i,d)==1��i�ĺͣ�
	  ����n(n>2)������<=n����n���ʵ����ĺ� s=n*phi(n)/2�� 
	  	������n�����ʵ���a����ô����֤��n-aҲ��n�����ʡ�
		Ҳ����˵�������ʵ����ܹ���ɺ�Ϊn��һ�顣
		��ôȥ����Щ���󣬻��ʵ���Ҳ�ǿ��Էֳɺ�Ϊn����ġ���ô���ʵ����ĺ;��൱��ÿ����һ�飬�õ�һ��n 
	  ������1:1,2:1
	  ��ôɸ����phi��ö��n��Լ��d������ans=n*sigma{((n/d)*phi(n/d)/2)*d/d}����ʱ�� 
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
			int k=i*primes[j];if(k>MAXN)break;//ע���г��� 
			mindiv[k]=primes[j];
			if(i%primes[j]==0){phi[k]=phi[i]*(primes[j]);break;}//ע����==0�˳� 
			else phi[k]=phi[i]*(primes[j]-1);
		}
	}
	for(int i=2;i<=MAXN;i++)phi[i]=phi[i]*i>>1;//Ԥ������phi 
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

