/*
二叉树计数
分析：卡特兰数 
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
