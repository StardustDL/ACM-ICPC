/*
�׳�ͳ��2
�������򵥴ֱ�����forѭ���׳ˡ������ڹ�������ʱȥĩβ0��ͬʱ����˻�����1000000000000����ȡ��1000000000000���������ټ����׳ˣ����ע��һ�����ǰ��0�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
typedef long long LL;
const LL MOD=1000000000000;//10^12 
LL ans=1;
int n,k;
void output(){
	ans%=(LL)(pow(10.0,k));
	int ws=floor(log10(ans*1.0))+1;
	if(ws<k)for(int i=ws+1;i<=k;i++)putchar('0');
	cout<<ans<<endl; 
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		ans*=i;
		while(!(ans%10))ans/=10;
		ans%=MOD;
	}
	output();
	return 0;
}

