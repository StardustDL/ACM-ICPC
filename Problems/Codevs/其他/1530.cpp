/*
大质数
分析：生成质数表，配合sqrt判断质数 
*/
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int pris[100003],l=1,n,ans=1;
bool b;
bool check(int p){
	int t=sqrt(p);
	for(int k=0;k<l&&k<=t;k++)
		if(p%pris[k]==0)return false;
	return true;
}
int main(){
	cin>>n;
	if(n==1){cout<<2;return 0;}
	pris[0]=2;
	while(l<n){
		ans+=2;
		if(check(ans))pris[l++]=ans;
	}
	cout<<ans;
	return 0;
}
