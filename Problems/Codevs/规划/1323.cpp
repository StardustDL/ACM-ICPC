/*
������̶�
������opt[i][j]��ʾ��i����Ʒ��mod f=j�ķ���������opt[i][j]=sum{opt[l][k]|1<=l<i;k+a[i] % f==j}������֪��k��Ψһ�ģ�k=(j-a[i])%f��ע��Ҫ����0
	  ����������ΪO(n*f*f)�ģ��ᳬʱ1�飬ע�⵽sum{opt[1..i-1][k]}�ǿ���������ǰ׺�͵ķ���ά���ģ��������˸Ľ����� 
*/ 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2000,MOD=100000000;
int n,f,a[MAXN+3],opt[MAXN+3][1000+3],s[1000+3];
void input(){
	cin>>n>>f;
	for(int i=1;i<=n;i++)cin>>a[i];
}
int get(int x){
	while(x<0)x+=f;
	return x%f;
}
int dp(){
	memset(opt,0,sizeof(opt));memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)opt[i][a[i]%f]=1;
	for(int i=0;i<f;i++)s[i]=opt[1][i];
	for(int i=2;i<=n;i++){
		for(int j=0;j<f;j++){
			opt[i][j]=(opt[i][j]+s[get(j-a[i])])%MOD;//�����s[k]ʵ������s[1..i-1][k] 
		}
		for(int j=0;j<f;j++)s[j]=(s[j]+opt[i][j])%MOD;//ע�⣬ֻ��������ı�s�����ŵ������ѭ���У���Ӱ������ֵ�ж� 
	}
	return s[0];
}
/*int dp(int t){
	memset(opt,0,sizeof(opt));memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)opt[i][a[i]%f]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<f;j++){
			int k=(j-a[i]);while(k<0)k+=f;k%=f;
			for(int l=1;l<i;l++){
				opt[i][j]=(opt[i][j]+opt[l][k])%MOD;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+opt[i][0])%MOD;
		//cout<<opt[i][0]<<endl;
	}
	return ans;
}*/
int main(){
	input();
	cout<<dp();
	return 0;
}
