/*
Combinations, Once Again
���⣺��n��������һЩr���������n������ȡr����ȡ���Ĳ�ͬ�����ж��ٸ� 
��������ѡ�����Ŀ���ɱ����Ŀռ䣬ö�ٷ���ĳ�����ĸ������ռ�����Ϊ��ǰö�ٵĸ�����dp[j+x]+=dp[j](jΪö�ٵĵ�ǰ����������xΪö�ٵĵ�ǰĳ����ĸ���)
		���������̫��֤�� 
	  ��һ�ַ�����
	  	b[i][j]��ʾ�ӵ�i��Ԫ�ؿ�ʼ������i���г�ȡj�����Ĳ�ͬ��������
		��b[i][j]=b[i+1][j-1]+b[x][j]
		b[i+1][j-1]:������i����ȡ������ôʣ�µľ������i+1��Ԫ�ؿ�ʼȡj-1�����Ĳ�ͬ������
		b[x][j]�������i����û��ȡ����Ϊ�����������ظ����������������Ź���ģ���x������Ǵӵ�i��Ԫ��֮�󲻵��ڵ�i��Ԫ�صĵ�һ���� 
		ע����long long 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=50;
typedef long long LL; 
int c[MAXN+3],a[MAXN+3],n,r,m,u,T=0;
LL cnt[MAXN+3];
int main(){
	while(scanf("%d%d",&n,&m),n+m){
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);u=0;
		for(int i=1;i<=n;i++)if(a[i]!=a[i-1])c[++u]=1;else c[u]++;
		memset(cnt,0,sizeof(cnt));cnt[0]=1;
		for(int i=1;i<=u;i++)
			for(int j=n;j>=0;j--)
				for(int k=1;k<=c[i]&&j+k<=n;k++)cnt[j+k]+=cnt[j];
		printf("Case %d:\n",++T);
		for(int x;m;m--){
			scanf("%d",&x);
			printf("%lld\n",cnt[x]);
		}
	}
	return 0;
}

