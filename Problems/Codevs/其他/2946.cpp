/*
��ת��Ϸ
*/ 
#include<iostream>
using namespace std;
const int MAXN=100; 
int a[MAXN+3],s[MAXN+3],n,ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];s[i]=s[i-1]+a[i];}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans=max(ans,s[i-1]	  +(j-i+1)-(s[j]-s[i-1])+(s[n]-s[j]));
			//		ǰi-1���е�1   ��ת�����µõ���1	 ��j+1..n�е�1 
	cout<<ans;
	return 0;
}
