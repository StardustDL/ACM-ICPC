/*
����ͳ��
������xi��ʾǰi�����У��ȵ�i����������ĸ�����
	  ��ô�������=x1+x2+x3+x4+...xn
	  ��ĿҪ���Ϊ x1+x2+x3+x4+...xn=k����x���ܵ�ȡֵ������
	  ͨ��si=xi+1������ȥ��xi=0�Ŀ��ܣ�ת�����Ļ��֣����ظ���
	  ���s1+s2+s3+s4+...+sn=k+n
	  opt[i][j]��ʾ s1+s2+s3+...+si=j�ķ����� 
*/
#include<iostream>
using namespace std;
const int MAXN=100,MAXK=(MAXN*MAXN)>>1,MOD=10000;
int opt[MAXN+3][MAXK+MAXN+3],n,k;
int dp(){
	opt[0][0]=1;
	//for(int i=0;i<=n+k;i++)opt[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k+n;j++){
			for(int l=1;l<=i;l++){
				opt[i][j]=(opt[i][j]+opt[i-1][j-l])%MOD;
			}
		}
	}
	return opt[n][n+k];
}
int main(){
	cin>>n>>k;
	cout<<dp();
	return 0;
}
