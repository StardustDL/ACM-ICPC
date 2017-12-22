/*
[HNOI2008]Խ��
������ֱ�Ӽ��㲻���㣬���в���ת��������Խ������=����-����Խ�������������������ڵķ��䲻����ͬ���ڽ̣�
	  ����=M^N,��Խ������=m*(m-1)^(n-1) 
	  ��һ���˿�������ѡ���ڽ̣������n-1����ÿ���˶�ֻ��m-1���ڽ̿���ѡ�񣨲��ܸ�����ǰ���һ���������ԣ���Խ����״̬����m*(m-1)^(n-1) 
	  ע�⸺������ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
typedef long long LL;
const LL MOD=100003;
LL m,n;
LL ksm(LL a,LL n){
	LL ans=1;
	while(n>0){
		if(n&1)(ans*=a)%=MOD;
		(a*=a)%=MOD;
		n>>=1;
	}
	return ans;
}
int main(){
	cin>>m>>n; 
	cout<<(ksm(m,n)%MOD-(m*ksm(m-1,n-1))%MOD+MOD)%MOD;
	return 0;
}

