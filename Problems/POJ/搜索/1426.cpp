/*
Find The Multiple
���⣺����һ����n�������ҵ�һ�����ı���ֻ��1��0��ɡ� 
��������С�������ԣ�ע��ѡһ���Ͻ� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef long long LL;
bool flg;
int n; 
void dfs(LL p,int dep){
	if(dep==20||flg)return;//���Ϊ20��ֹͣ�����ƣ� 
	if(p%n==0){
		printf("%lld\n",p);
		flg=true;return;
	}
	dfs(p*10,dep+1); 
	dfs(p*10+1,dep+1);
} 
int main(){
	while(scanf("%d",&n),n){
		flg=false;
		dfs(1,1);
	}
	return 0;
}

