/*
������Ϸ
�������ѻ��������ö�ٿ�ʼλ�ã�d[i][j]��ʾǰi�����ֳ�j���ֵ�����ֵ
	  ״̬ת�Ʒ��̣�
		d[i][j]=opt(d[i][j],d[k][j-1]*(((s[i]-s[k])%10+10)%10))
		s[i]��ǰi�����ĺ� 
	  �߽磺d[0][0]=1;d[i][1]=((s[i]%10+10)%10) 
*/
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,Max,Min,s[55],d[55][10],dp[55][10];
void DP(int a[])
{
	int i,j,k;
	for(i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++){
			d[i][j]=0;
			dp[i][j]=-1u>>1;
		}
	d[0][0]=dp[0][0]=1;
	for(i=1;i<=n;i++)
		d[i][1]=dp[i][1]=(s[i]%10+10)%10;
	for(j=2;j<=m;j++)
		for(i=j;i<=n;i++)
			for(k=j-1;k<i;k++){
				d[i][j]=max(d[i][j],d[k][j-1]*(((s[i]-s[k])%10+10)%10));//��k+1��������i�����ֵ���j����
				dp[i][j]=min(dp[i][j],dp[k][j-1]*(((s[i]-s[k])%10+10)%10));
			}	
	Max=max(Max,d[n][m]);
	Min=min(Min,dp[n][m]);
}
int main(){	
	while(scanf("%d%d",&n,&m)==2){
		int i,j,a[105];
		Max=0;
		Min=-1u>>1;
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			a[n+i]=a[i];
		}
		for(j=0;j<n;j++)
			DP(a+j);
		printf("%d\n%d",Min,Max);		
	}
}

