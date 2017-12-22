/*
isn
��������f[i]��ʾ����Ϊi�Ĳ��½������еĸ������õ�һ������Ϊi�����еķ�������f[i]*(n-i)!����ɾ��Ԫ�ص�ȫ���У� 
		�����ݳ⣬���ڳ���Ϊi�������У�����������Ϸ�����ô֮ǰһ����һ������Ϊi+1��������
		����Ans=sigma{1<=i<=n|f[i]*(n-i)!-f[i+1]*(n-(i+1))!*(i+1)[�������һλ��ɾ��λ��]} 
		ʱ�临�Ӷ�O(n^2logn)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f,MOD=1000000007;
int n,a[MAXN+3],b[MAXN+3],f[MAXN+3],bit[MAXN+3][MAXN+3];//bit[i][j]ά�������г���Ϊi�����һλΪj��������������״���� 
int fac[MAXN+3]; 
#define lowbit(x) ((x)&-(x))
void add(int l,int x,int ad){
	for(;x<=n;x+=lowbit(x))(bit[l][x]+=ad)%=MOD;//ע������ҲҪȡģ 
}
int sum(int l,int x){
	int ans=0;
	for(;x;x-=lowbit(x))(ans+=bit[l][x])%=MOD;
	return ans;
}
int main(){
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1;i<=n;i++){scanf("%d",&a[i]),b[i]=a[i];fac[i]=(1LL*fac[i-1]*i)%MOD;}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	add(0,1,1);
	for(int i=1;i<=n;i++){//ö�����һλ������a[i]��β�ĳ��ȷֱ�Ϊ[1..i]�������е����� 
		for(int j=i;j;j--){
			int t=sum(j-1,a[i]);
			f[j]=(f[j]+t)%MOD;
			add(j,a[i],t);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+1LL*f[i]*fac[n-i]%MOD)%MOD;
		if(i<n)ans=(ans-1LL*f[i+1]*fac[n-(i+1)]%MOD*(i+1)%MOD+MOD)%MOD; 
	}
	printf("%d\n",ans);
	return 0;
}

