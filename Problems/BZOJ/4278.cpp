/*
[ONTAK2015]Tasowanie
��������֮ǰ��һ��Usacoһ����̰�ģ����������ͬ�ģ�������ҵ�һ����ͬ�ģ������hash+lcp�жϾ����ˣ�����д��׺���� 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=200000+5,P=13331,D=1000000007,INF=10000;
int n,m,pw[MAXN+3],a[MAXN+3],b[MAXN+3],f[MAXN+3],g[MAXN+3];
int hash0(int l,int r){return(LL)(f[r]-(LL)f[l-1]*pw[r-l+1]%D+D)%D;}
int hash1(int l,int r){return(LL)(g[r]-(LL)g[l-1]*pw[r-l+1]%D+D)%D;}
int lcp(int a,int b){
	int l=0,r=min(n-a+1,m-b+1),ans=0;//��0��ʼ 
	while(l<=r){
		int mid=(l+r)>>1;
		if(hash0(a,a+mid-1)==hash1(b,b+mid-1))ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	pw[0]=1;
	for(int i=1;i<=MAXN;i++)pw[i]=(LL)pw[i-1]*P%D;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);f[i]=((LL)f[i-1]*P+a[i])%D;}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){scanf("%d",&b[i]);g[i]=((LL)g[i-1]*P+b[i])%D;}
	a[n+1]=b[m+1]=INF;int i,j;
	for(i=j=1;i<=n&&j<=m;){
		int k=lcp(i,j);
		printf("%d ",a[i+k]<b[j+k]?a[i++]:b[j++]);
	}
	while(i<=n)printf("%d ",a[i++]);
	while(j<=m)printf("%d ",b[j++]);
  	return 0;
}
