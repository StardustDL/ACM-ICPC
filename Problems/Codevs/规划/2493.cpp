/*
GF������
��������Ŀ���ƺܸ��ӣ�����������һ�£�
	  ���ǲ���Ҫ����ĳ�����������ĸ���ָ���µġ�
	  ������ִ�Ĵָ��L�����ִ�Ĵָ��R����ô��[L-8,L]֮��ļ����ܱ����ְ�������[R,R+8]֮��ļ����ܱ����ְ�����
	  ��������ֻ��Ҫ֪�������ִ�Ĵָ��λ�á�
	  ��Σ���Ȼ��Ŀ�и�����ָ���ܽ�������ƣ����ǿ��Է��֣���Щ���ƶ���û�õġ�
	  ��Ϊ��Ȼ����һ�ֲ�����ķ����Ƚ����Ҫ�š�
	  ��ע�⵽ÿ��ʵ����ֻ���ƶ�һֻ�֡� 
	  ����Ϊ��
	  F[i,j,k]��ʾ�����i������ʱ�����ִ�Ĵָ��jλ�ã����ִ�Ĵָ��kλ�õ���С�������ѡ�
	  ת�ƣ����ڵ�i+1�������������Ҫ����p������
	  ��ôF[i,j,k]����ת�Ƶ�F[i+1,l,k] (p<=l<=p+8)��F[i+1,j,r] (p-8<=r<=p)��
	  ��Ӧ�ļ��㻨�ѾͿ����ˣ���ע�����Ҫ�Ӿ���ֵ�� 
*/ 
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int opt[MAXN+3][52+3][52+3],l,r,n,a[MAXN+3],ml,mr; 
void input(){
	cin>>l>>r>>n;
	memset(opt,INF,sizeof(opt));
	for(int i=1;i<=n;i++)cin>>a[i];
}
int dp(){
	opt[0][l][r]=0;
	for(int i=0;i<n;i++){//iִ�е�n-1 
		for(int j=0;j<52;j++){
			for(int k=0;k<52;k++){
				for(int l=a[i+1];l<=min(a[i+1]+8,51);l++){//�ƶ����� 
					opt[i+1][l][k]=
						min(opt[i+1][l][k],
							opt[i][j][k]+(int)sqrt(abs(j-l)));
				}
				for(int r=max(a[i+1]-8,0);r<=a[i+1];r++){//�ƶ����� 
					opt[i+1][j][r]=
						min(opt[i+1][j][r],
							opt[i][j][k]+(int)sqrt(abs(r-k)));
				}
			}
		}
	}
	int ans=INF;
	for(int i=0;i<52;i++)
		for(int j=0;j<52;j++)
			ans=min(ans,opt[n][i][j]);
	return ans;
}
int main(){
	input();
	cout<<dp(); 
	return 0;
}
