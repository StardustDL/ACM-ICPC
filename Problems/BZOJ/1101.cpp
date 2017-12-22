/*
[POI2007]Zap
��������ϰ����д�ĵ�һ�⣬С���󲻶ϣ�
	  ��Ŀ�ȼ���x<=N/d��y<=M/d�����ʵ�x��y�Ķ�����
	  ��sigma(x<=n',y<=m',e(gcd(x,y)))
	  ��e��Ī����˹����չ����
	  e(gcd(x,y))=sigma(d|x&d|y,miu[d])
	  ת�����˳��
	  sigma(d<=n',miu[d]*(n'/d)*(m'/d))
	  ��Ϊn'�����У���n'/d��������t|n'��ע�������൱���Ǽ���d�ı�����Ԫ��(x,y)�ĸ���
	  ֻ�������ﻹ������һ�������O(n)�ģ���Ҫע�⣺ (n'/d)*(m'/d)�����O(sqrt(n)) ����
	  ǰ׺��+�ֶ�ö�� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
int mindiv[MAXN+3],primes[MAXN+3],pcnt=0,miu[MAXN+3],a,b,d,n,sum[MAXN+3];
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
	for(int i=1;i<=size;i++)sum[i]=sum[i-1]+miu[i];
}
int solve(int n,int m){
	if(n>m)swap(n,m);
	int ans=0,pos;
	for(int i=1;i<=n;i=pos+1){
		pos=min(n/(n/i),m/(m/i));//ע��������� 
		ans+=(sum[pos]-sum[i-1])*(n/i)*(m/i);
	}
	return ans;
}
int main(){
	init(50000);
	for(scanf("%d",&n);n;n--){
		scanf("%d%d%d",&a,&b,&d);
		printf("%d\n",solve(a/d,b/d));
	}
	return 0;
}

