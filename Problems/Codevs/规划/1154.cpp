/*
��������
�������ϻ�Ϊ��������DP��ת�Ʒ��̣�
	  opt[i][j]=max{opt[i][k]+opt[k][j]+a[i]*a[k]*a[j]|i<k<j} 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100*2+3;
int n,a[MAXN],opt[MAXN][MAXN],t,ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}
	t=2*n-1;
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=t;i++){//ע��i���Ͻ� 
			int j=i+len,&m=opt[i][j];
			for(int k=i+1;k<j;k++){//ע��k��ȡֵ 
				m=max(m,opt[i][k]+opt[k][j]+a[i]*a[k]*a[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){//ö��ÿһ�ֿ��ܵĶ� 
		ans=max(ans,opt[i][i+n]);
	}
	cout<<ans;
	return 0;
}

