/*
����
�������ܲ����״ѹDP
		���ŷ����г��ֵ�������һ����һ��ʼ���������г��ֹ�������������һ�����������Ͻ磬��һ����n+m����ȻֻҪ�ѵ�һ������n�μ������ӳ�һ������Ȼ����m�ηָ�ֳ�����2����
		����Ѿ���a�������һ�����ĺ͵���b������һ�����ĺ͵Ļ������Ȱ��������������ͬ�ģ��Ϳ������Ͻ�Ļ����ϼ������β�����Ҳ���ǽ����������ĺͺϵ��ܺ���ȥ���ʹ��ܺ���ֳ����������β���ʡȥ�ˣ�Ȼ���ٿ����������������ĺ���ȵĲ��֣�����������ӽṹ�ˣ��Ϳ�����DP���ظ㶨��
		DP[S][T]��ʾa����ѡ�еķ���ΪS,b������ѡ�з���ΪT����������ͬ�����ֵ������������ÿ����ͬ�ܼ������β�������˴𰸾���n+m-dp[(1<<(n))-1][(1<<(m))-1] 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[10+3],b[10+3],dp[1<<10+1][1<<10+1],sa[1<<10+2],sb[1<<10+2];
void init(int ind,int mxd,int st,int *a,int sum,int *out){
	if(ind==mxd+1)return;
	out[st<<(mxd-ind)]=sum;//����������ſ� 
	init(ind+1,mxd,st<<1|1,a,sum+a[ind+1],out);
	init(ind+1,mxd,st<<1,a,sum,out);
}
int solve(){
	for(int i=1;i<1<<n;i++){
		for(int j=1;j<1<<m;j++){
			int &t=dp[i][j];
			for(int k=0;k<n;k++)
				if(i&(1<<k))t=max(t,dp[i^(1<<k)][j]);
			for(int k=0;k<m;k++)
				if(j&(1<<k))t=max(t,dp[i][j^(1<<k)]);
			if(sa[i]==sb[j])t++;
		}
	}
	return dp[(1<<n)-1][(1<<m)-1];
}
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	init(0,n,0,a,0,sa);
	init(0,m,0,b,0,sb);
	printf("%d\n",n+m-2*solve());
	return 0;
}

