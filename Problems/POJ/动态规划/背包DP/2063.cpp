/*
Investment
���⣺������ʼ�ʽ𣬻���������Ȼ�����ÿ����Ʒ�Ĺ���۸���ÿ���õ����棬Ҫ���ڸ�������ݺ����ܵõ��������֮�͡�
��������Ϊÿ����Ʒ���Զ�ι��򣬿��Կ�������ȫ��������Ŀ������Ҫע����ǣ����ڱ�����ܻ�ܴ���������Ҫ�Ա����Ĵ�С����ѹ����ֵ��ע����ǣ���Ŀ�Ѿ�˵�˱�������Ʒ�Ĺ���۸���1000�ı������������ǿ��Խ����Ƕ�����1000������ѹ����Ȼ�����һ����ȫ����ģ�����ˡ�
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10,MAXV=100000,INF=0x3f3f3f3f;
int money,n,v[MAXN+3],w[MAXN+3],ans=0,opt[MAXV+3],T,year;
inline void input(){
	scanf("%d%d%d",&money,&year,&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&v[i],&w[i]),v[i]/=1000;
}
inline int dp(int maxv){
	memset(opt,0,sizeof(opt));
	for(int i=1;i<=n;i++)
		for(int j=v[i];j<=maxv;j++)opt[j]=max(opt[j-v[i]]+w[i],opt[j]);
	return opt[maxv];
}
inline int solve(){
	ans=money;
	while(year--)ans+=dp(ans/1000);
	return ans;
}
int main(){
	for(scanf("%d",&T);T;T--){
		input();
		printf("%d\n",solve());
	}
	return 0;
}

