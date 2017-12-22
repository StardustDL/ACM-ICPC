/*
糖果传递
分析：同BZOJ1045 
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=1000000,INF=0x3f3f3f3f;
int n,a[MAXN+3],c[MAXN+3],ave;
LL sum;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	ave=sum/n;
	for(int i=2;i<=n;i++)c[i]=c[i-1]+a[i]-ave;
	sort(c+1,c+n+1);
	LL ans=0;
	int mid=c[(n>>1)+1];
	for(int i=1;i<=n;i++)ans+=abs(c[i]-mid);
	printf("%lld",ans); 
	return 0;
}
