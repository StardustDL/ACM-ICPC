/*
���Ļ���
��������opt[i][j]��ʾi�ֳ�j�ݵķ�����������ݷֳ�1�Ͳ��ֳ�1���࣬
	  �ӷ�ԭ���opt[i][j]=opt[i-1][j-1]+opt[i-j][j]
	  ע��߽紦��
	  �Ƶ����̣� 
	  dp[i,j]=dp[i-j,1]+dp[i-j,2]+��+dp[i-j,j];
	  dp[i-1,j-1]=dp[(i-1)-(j-1),1]+dp[(i-1)-(j-1),2]+��+dp[(i-1)-(j-1),j-1]
	  =dp[i-j,1]+dp[i-j,2]+��+dp[i-j,j-1];
	  =>
	  dp[i,j]=dp[i-j,1]+dp[i-j,2]+��+dp[i-j,j-1]+dp[i-j,j]
	  =dp[i-1,j-1]+dp[i-j,j];
*/
#include<iostream>
using namespace std;
long opt[200+3][7],n,k;
int main(){
	cin>>n>>k;
	opt[0][0]=1; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++)
			if(i>=j)opt[i][j]=opt[i-1][j-1]+opt[i-j][j];
	}
	cout<<opt[n][k];
	return 0;
}
