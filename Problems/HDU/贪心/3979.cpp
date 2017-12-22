/*
Monster
���⣺һ���ˣ�������M����N�����ˣ�ÿ������HPi,ATKi,ÿһ���˿���ѡ��һ�����˹�����ͬʱ���л��ŵĵ��˻ṥ���������������Ҫ������HP��ʹ�����������е���
������̰�ġ�����iֻ���޵ĺ�ʱΪti�����޹�����Ϊci���ⷨ�ǰ�ci/ti��ֵ�ɴ�С��˳��������ޡ�
	  ֤������������ڱ������������������ڵ������������ǵ�ci/ti��С���ڴ��ǰ�棬�򽻻�������λ�ã����ڳ�������֮����������޵Ļ���û��Ӱ�죬���������Ļ���֮�ͼ����ˣ����������Ž��ﲻ���������������
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
int n,m,ts[MAXN+3],atk[MAXN+3],r[MAXN+3];
typedef long long LL;
bool cmp(int i,int j){
	return atk[i]*ts[j]>atk[j]*ts[i];
}
void input(){
	scanf("%d%d",&n,&m);
	int t;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&t,&atk[i]);
		ts[i]=(t+m-1)/m;//���ﱣ֤�����Ͻ�һ 
		r[i]=i;
	}
}
LL solve(){
	sort(r+1,r+n+1,cmp);
	LL ans=0,tme=0;
	for(int i=1;i<=n;i++){
		tme+=ts[r[i]];//��¼ʱ�� 
		ans+=tme*atk[r[i]];
	}
	return ans;
}
int main(){
	int T;scanf("%d",&T);
	for(int i=1;i<=T;i++){
		input();
		printf("Case #%d: %lld\n",i,solve());
	}
	return 0;
}

