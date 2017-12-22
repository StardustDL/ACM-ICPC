/*
Drying
���⣺��һЩ�·���ÿ���·���һ��ˮ������һ����ɻ���ÿ�ο��Ժ�һ���·���ÿ���ӿ��Ժ��k��ˮ��ÿ���·�û���ӿ����Զ�������һ��ˮ���ú�ɻ����·�ʱ����������������Ҫ����ʱ���ܺ�����е��·���
���������ִ𰸣�����ÿһ���·�����С��ö�ٵĴ��������������ڣ���Ҫ�Ⱥ�ɣ���ɵ�ͬʱ������·�Ҳ�����������Ժ��ʱ����(a[i]-val)/(k-1)��ȡ�� 
	  ��ΪҪȥ��ԭ������������ע��k=1����� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
int a[MAXN+3],k,n,mx=0;
bool check(int val){
	int sum=0;
	for(int i=1;i<=n&&sum<=val;i++){
		if(a[i]<=val)continue;
		sum+=ceil((a[i]-val)*1.0/(k-1));
	}
	return sum<=val;
}
int ef(int l,int r){
	int mid,ans=l;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	return l;
}
int solve(){
	if(k==1)return mx;
	else{
		return ef(1,mx);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
	scanf("%d",&k);
	printf("%d\n",solve());
	return 0;
}

