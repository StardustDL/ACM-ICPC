/*
[Usaco2009 Nov]Ӳ����Ϸ
������һ��˼·���Ǵ���Ϸ������ʼ��ǰdp��dp�����״̬ʱ��Ȼ��֪������ܵõ�����Ǯ�ˣ����ǴӺ���ǰdp��һ�����������Ҫֱ��ǰһ���Է����˶���Ӳ�ң�����֪����ǰ���ö��٣������һά���һ��ǰһ���Է����˶��ټ��ɣ����Ǿ���f[i][j]��ʾ��ʣiöӲ��ʱǰһ����������jöӲ�ҵ�����£��Լ�����ܵõ�����Ǯ��
		״̬ת�Ʒ���Ϊf[i][j]=max{sum[i]-f[i-k][k]}(1<=k<=min{2*j,i})������sum[i]��ʾʣ�µ�iöӲ�ҵļ�ֵ�͡�
		�Ż�ת�ƣ�
			DP[c][p] = max{SUM[1][c] - DP[c-i][i]}   1 <=i<=min(2*p, c)
    		DP[c][p+1] = max{SUM[1][c] - DP[c-i][i]} 1 <=i<=min(2*(p+1), c)
               = max{DP[c][p], SUM[1][c] - DP[c-(2*p+1)][2*p+1],SUM[1][c] - DP[c-(2*p+2)][2*p+2]}
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
int n,a[MAXN+3],sum[MAXN+3],f[MAXN+3][MAXN+3]; 
int main(){
	scanf("%d",&n);
	for(int i=n;i>=1;i--)scanf("%d",&a[i]);
	sum[0]=0;for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	memset(f[0],0,sizeof(f[0]));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=f[i][j-1];
			if(i>=2*j)f[i][j]=max(f[i][j],sum[i]-f[i-2*j][2*j]);
			if(i>=2*j-1)f[i][j]=max(f[i][j],sum[i]-f[i-(2*j-1)][2*j-1]);
		}
	}
	printf("%d\n",f[n][1]);
	return 0;
}

