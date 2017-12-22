/*
栈
分析：卡特兰数第n项，f(n)=f(n-1)*(4*n-2)/(n+1)
	  注意先乘后除，不然由于向下取整会出错 
*/
#include<iostream>
using namespace std;
long long n,ans=1;
int main(){
	cin>>n;
	for(int i=2;i<=n;i++)ans=ans*(4*i-2)/(i+1);
	cout<<ans;
	return 0; 
}
