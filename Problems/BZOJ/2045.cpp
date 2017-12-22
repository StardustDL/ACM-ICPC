/*
˫����
�������������ZAP(bzoj1101)�ļ򻯰棬������������һ�����ƺ�������phi
	  �������ʱ���÷ֶ��ˣ���Ϊֻ��һ��ѯ�ʣ�ɨһ��d<=n���� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=1000000,INF=0x3f3f3f3f;
int mindiv[MAXN+3],primes[MAXN+3],pcnt=0,miu[MAXN+3],a,b,d,n;
inline void init(int size){
	miu[1]=1;
	for(int i=2;i<=size;i++){
		if(mindiv[i]==0){mindiv[i]=i;miu[i]=-1;primes[++pcnt]=i;}
		for(int j=1,k;j<=pcnt&&(k=i*primes[j])<=size;j++){
			mindiv[k]=primes[j];
			if(mindiv[i]==primes[j]){miu[k]=0;break;}
			miu[k]=-miu[i];
		}
	}
}
LL solve(int n,int m){
	if(n>m)swap(n,m);
	LL ans=0;
	for(int i=1;i<=n;i++)ans+=(LL)(miu[i]*(LL)(n/i)*(LL)(m/i)); 
	return ans;
}
int main(){
	init(MAXN);
	scanf("%d%d%d",&a,&b,&d);
	printf("%lld\n",solve(a/d,b/d));
	return 0;
}
