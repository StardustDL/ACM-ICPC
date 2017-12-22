/*
第K极值
分析：排下序就好，其实有期望O(n)的算法的（分治） 
*/ 
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long a[10002],n,min,max,k;
bool isz(long l){
	if(l<2)return false;
	for(int i=2;i<=sqrt(l);i++)if(l%i==0)return false;
	return true;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long t=a[n-k+1]-a[k];
	cout<<(isz(t)?"YES":"NO")<<endl<<t;
	return 0;
}
