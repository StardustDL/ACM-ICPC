/*
��ƻ��
��������ʵ���ǽ�M�ֳ�1�ݣ�2�ݣ�3�ݣ�...��N�ݡ������������ֻ��ֵĴ��룬���ͳ��opt[n][1..m]���ɡ� 
*/
#include<iostream>
using namespace std;
const int MAXN=10;
long long opt[MAXN+3][MAXN+3],n,k;
int dp(){
	opt[0][0]=1; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++)
			if(i>=j)opt[i][j]=opt[i-1][j-1]+opt[i-j][j];
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		ans+=opt[n][i];
	}
	return ans;
}
int main(){
	int t;cin>>t;
	while(t-->0){
		cin>>n>>k;
		cout<<dp()<<endl;
	}
	return 0;
}
