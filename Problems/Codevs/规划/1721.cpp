/*
ƽ����
�������տ�ʼ���0*0��������ʵ��DP��������opt[i][j]��ʾ��i��1..j��Щ����ƽ������ɵķ�������
	  ��ɵ�opt[i][j]=sum{opt[i-j^2][k]|0<=k<=j}opt[0][0]=1
	  ����opt[i][j]=sum{opt[i-j^2][k]|1<=k<=j}opt[i][1]=1;���ֶ���һ�� 
	  ���ս����sum{opt[n][k]|1<=k<=n(sqrt(n))} 
*/
#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=1000; 
int n,opt[MAXN+3][MAXN+3];
int dp(){
	opt[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int e=j*j;if(e>i)break;
			for(int k=0;k<=j;k++){
				opt[i][j]+=opt[i-e][k];
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=opt[n][i];
	return ans;
}
int main(){
	cin>>n;
	cout<<dp();
	return 0;
} 
