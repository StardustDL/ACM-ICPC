/*
sumsets
����������1��û��1���ۣ����ڱ�����2���ݣ����Զ����������������opt[i]=opt[i-1](�ֳ�һ��1)
	  ����ż�����������opt[i]=opt[i/2]+opt[i-1](�ֳ�һ��1�������������2)
	  ��д��dfs����Ϊ��һ���������е�optֵ������ʵ���ڶ�Ҫ����opt[i-1]������������û���κθĽ���
	  ���һᱬջ���տ�ʼ��û��mod������ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f,MOD=1000000000;
int opt[MAXN+3],n;
int main(){
	cin>>n;
	opt[0]=1;
	for(int i=1;i<=n;i++){
		if(i&1)opt[i]=opt[i-1];
		else opt[i]=(opt[i-1]+opt[i>>1])%MOD;
	}
	cout<<opt[n]<<endl;
	return 0;
}

