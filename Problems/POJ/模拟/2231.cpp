/*
Moo Volume
���⣺����n�����֡�����������֮��Ĳ���ܺ��Ƕ��١� 
�����������ɨһ�飬���ҹ��ɣ�ע����������������Ҫ��2 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
typedef long long LL; 
int n,a[MAXN+3];
LL ans=0,t=0; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		t+=(i-1)*(LL(a[i]-a[i-1]));
		ans+=t;
	}
	printf("%lld",ans<<1); 
	return 0;
}

