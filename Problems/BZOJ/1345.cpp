/*
[Baltic2007]��������Sequence
������ÿ����һ�������ߵĺ��ұߵĺϲ���ֻҪ���Ƚϴ���ô�ͻṱ�׸��𰸡� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
int n,a[MAXN+3];
int main(){
	scanf("%d",&n);
	a[0]=a[n+1]=INF;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	long long ans=0;
	for(int i=1;i<=n;i++)ans+=((a[i]>=a[i-1])+(a[i]>a[i+1]))*a[i];//Ϊ��ֹ�ظ������������>=���ұ���> 
	printf("%lld\n",ans);
	return 0;
}

