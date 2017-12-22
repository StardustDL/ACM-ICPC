/*
[Noi2010]能量采集
分析：注意一个结论：给定两个格点，问这两个格点连成的线段上有多少个格点，是gcd(x1-x0,y1-y0)+1 （含两端点）
	  那么这道题就是：
	  sigma{x<=n,y<=m,2*(gcd(x,y)-1)+1}
	  =sigma{x<=n,y<=m,2*gcd(x,y)-1}
	  将2和-1提出去： 
	  S=sigma{sigma(d|x&d|y,phi[d])}
	  =sigma{d<=n,phi[d]*(n/d)*(m/d)}
	  ans= 2*S-n*m 
	  注意用long long ，及时转换，防止溢出
	  O(sqrt(n)) 
	  
	  另一种方法O(n*sqrt(n))
	  设f[i]表示gcd(x,y)==i的x,y个数(x<=n&&y<=m)
	  则f[i]=(n/i) * (m/i) -f[2i]-f[3i]-f[4i] (容斥原理) 
	  i从大到小枚举，计算f[i]，ans+=f[i]*(2*(i-1)+1) 
*/
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=100000,INF=0x3f3f3f3f;
int mindiv[MAXN+3];
LL phi[MAXN+3],sum[MAXN+3];
vector<int> pris;
inline void init(int size){
	phi[1]=1;pris.clear();
	for(int i=2;i<=size;i++){
		if(mindiv[i]==0){mindiv[i]=i;phi[i]=i-1;pris.push_back(i);}
		for(int j=0,k;j<pris.size()&&(k=pris[j]*i)<=size;j++){
			mindiv[k]=pris[j];
			if(mindiv[i]==pris[j]){phi[k]=phi[i]*pris[j];break;}
			phi[k]=phi[i]*(pris[j]-1);
		}
	}
	for(int i=1;i<=size;i++)sum[i]=sum[i-1]+phi[i];
}
LL calc(int n,int m){
	if(n>m)swap(n,m);
	LL ans=0;
	for(int i=1,pos;i<=n;i=pos+1){
		pos=min(n/(n/i),m/(m/i));
		ans+=(sum[pos]-sum[i-1])*(LL)(n/i)*(LL)(m/i);
	}
	return (LL)(ans*2LL-(LL)n*m);
}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	init(max(n,m));
	printf("%lld\n",calc(n,m));
	return 0;
}
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=100000,INF=0x3f3f3f3f;
LL f[MAXN+3],ans=0;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=min(n,m);i>=1;i--){
		f[i]=(LL)(n/i)*(m/i);
		for(int j=i+i;j<=MAXN;j+=i)f[i]-=f[j];
		ans+=f[i]*(2*i-1);
	}
	printf("%lld\n",ans);
	return 0;
}
 



