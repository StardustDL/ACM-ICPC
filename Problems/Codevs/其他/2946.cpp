/*
翻转游戏
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
			//		前i-1个中的1   翻转部分新得到的1	 后j+1..n中的1 
	cout<<ans;
	return 0;
}
