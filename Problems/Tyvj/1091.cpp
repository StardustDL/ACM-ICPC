/*
�Ȳ�����
��������f[i][j]��ʾ�Ȳ����е����������i��jʱ�ĵȲ����еĸ�������ô
		f[i][j] = ��(f[j][k]) + 1 (data[i]-data[j]=data[j]-data[k]) ��
		���㷨�ĸ��Ӷ���O(n^3).
		���ǿ���ע�⵽��ÿ�����ֶ������������ǿ�����f[i][j]��ʾ�Ȳ��������һ��Ϊi�����й���Ϊjʱ�������Ƶ�ת�Ƶõ��Ȳ����еĸ��������Ӷ���O(n^2). 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f,D=1000,MOD=9901;
int opt[MAXN+3][2*D+3],n,a[MAXN+3],ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		(ans+=i)%=MOD;
		for(int j=1,p;j<i;j++){
			p=a[i]-a[j]+D;
			(ans+=opt[j][p])%=MOD;
			(opt[i][p]+=opt[j][p]+1)%=MOD;
		}
	}
	printf("%d",ans);
	return 0;
}

