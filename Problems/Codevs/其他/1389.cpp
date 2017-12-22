/*
乘积平均数
分析：直接模拟，注意要不断开n次方，不能最后再开，否则得到inf
	  (a*b)^(1/n)=a^(1/n)*b^(1/n)
*/
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double ans=1;
int n,t;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t;ans*=pow(t,1.0/n);
	}
	//ans=pow(ans,1.0/n);
	printf("%.2lf",ans);
	return 0;
}
