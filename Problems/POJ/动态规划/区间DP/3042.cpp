/*
Grazing on the Run
���⣺��n���ƺ��֪��ÿ���ƺ��λ�ã����ǿ��Կ�����x���ϵ�һ�㣩��Bessieλ��Lλ�ã���������������������ȥ�Բ�ƺ������Բ�ƺ��ʱ�䲻�ƣ�·�ϵ�ʱ����ÿ��һ����λ��ʱ��+1��ÿ���ƺ����һ��stalenessֵ�����ֵǡ�õ���Bessie�����ʱ�䣬����Ҫ�����Bessie�����в�ƺ���꣬���в�ƺ��stalenessֵ��С�Ƕ���
���������Ž�һ���������������������Ծʽ��
	  ���ԣ�
	  	��dp[i][j][0]��ʾ��i-j���䶼���꣬���ͣ����iλ�ã����в�ƺ����С��stalenessֵ
		dp[i][j][1]��ʾi-j���䶼���꣬���ͣ����jλ���ϵ���Сֵ
		��ô������״̬��ת�Ʒ��̾���
        	dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(a[i+1]-a[i])*(delay));
        	dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(a[j]-a[i])*(delay));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(a[j]-a[j-1])*(delay));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(a[j]-a[i])*(delay));
        delay��ʾ֮���ж��ٲ������ӳ�ʱ�䣬�൱����ǰ���������delay=n-(j-i+1)+1=n-j+i 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int opt[MAXN+3][MAXN+3][2],l,a[MAXN+3],n;
int dp(int start){
	memset(opt,INF,sizeof(opt));
	opt[start][start][0]=opt[start][start][1]=0;
	for(int i=start;i>=1;i--){
		for(int j=start;j<=n;j++){
			if(i==j)continue;
			int l=(j-i);
			opt[i][j][0]=min(min(opt[i+1][j][0]+(a[i+1]-a[i])*(n-l),opt[i+1][j][1]+(a[j]-a[i])*(n-l)),opt[i][j][0]);
			opt[i][j][1]=min(min(opt[i][j-1][1]+(a[j]-a[j-1])*(n-l),opt[i][j-1][0]+(a[j]-a[i])*(n-l)),opt[i][j][1]);
		}
	}
	return min(opt[1][n][0],opt[1][n][1]);
}
int main(){
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[++n]=l;
	sort(a+1,a+n+1);
	printf("%d\n",dp(lower_bound(a+1,a+n+1,l)-a)); 
	return 0;
}

