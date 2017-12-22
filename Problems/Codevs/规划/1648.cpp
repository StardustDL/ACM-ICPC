/*
����
�������������Ȧ����ֱ��dp[i]=max(dp[i-1]+a[i],0) 
	  ������Ȧ����ôά��һ����ǰ��͵������еĳ���cnt��
	  cnt>=nʱ��Ҫ��ָ��ָ�����������n-i+1�������Ǹ�λ��Ҫ��ֵΪ0 
	  ע�����ֱ��ö����㣬��ô�ᳬʱ��
	  for(int i=1;i<=n;i++){
		memset(dp,0,sizeof(dp));
		for(int j=0;j<n;j++){
			dp[i+j]=max(dp[i+j-1]+a[i+j],dp[i+j]);
			ans=max(dp[i+j],ans);
		}
	} ��Ϊһ��������Ǵﲻ�����Ž�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100000;
int n,a[2*MAXN+3];
long dp[2*MAXN+3],ans=-100000000,cnt=0;
int main(){
	cin>>n;
	for(int i=1;i<=2*n;i++)dp[i]=-100000000;
	for(int i=1;i<=n;i++){
		cin>>a[i];a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;i++){
		if(a[i]>dp[i-1]+a[i]){
			cnt=1;
			dp[i]=a[i];
			ans=max(dp[i],ans);
		}
		else{
			dp[i]=dp[i-1]+a[i];
			ans=max(dp[i],ans);
			if(++cnt>=n)dp[i=i-n+1]=cnt=0;
		}
	}
	cout<<ans;
	return 0;
}
