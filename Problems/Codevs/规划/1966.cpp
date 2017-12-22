/*
�˷���Ϸ
����������DP��opt[i][j]=min{opt[i][k]+opt[k][j]+a[i]*a[k]*a[j]}
	  ע��3�� opt[i][k]+opt[k][j]�ǰ���k�ģ���Ϊ�����������ûѡk��
	  a[l]*a[i]*a[r]��������a[i-1]*a[i]*a[i+1]����Ϊ�����Ѿ�ȡ��a[i-1]��a[i+1]
	  ������̳���Ϊ3 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
int n,a[MAXN+3],opt[MAXN+3][MAXN+3];
//���仯���� 
int dp(int l,int r){
	if(r-l+1==2)return 0;
	int &t=opt[l][r];
	if(t==-1){
		t=INF;
		for(int i=l+1;i<r;i++){
			t=min(dp(l,i)+dp(i,r)+a[l]*a[i]*a[r],t);
		}
	}
	return t;
}
//���� 
int dp(){
	memset(opt,INF,sizeof(opt));
	for(int i=1;i<=n;i++){
		opt[i][i]=opt[i][i+1]=0;
	}
	for(int len=3;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			for(int k=i+1;k<j;k++){
				opt[i][j]=min(opt[i][j],opt[i][k]+opt[k][j]+a[i]*a[k]*a[j]);
			}
		}
	}
	return opt[1][n];
}
int main(){
	ios::sync_with_stdio(false);
	memset(opt,-1,sizeof(opt));
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<dp();
	return 0;
}
