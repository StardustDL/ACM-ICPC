/*
GPA计算 
*/ 
#include<iostream>
#include<iomanip>
using namespace std; 
double total=0,sum=0,n,s,t;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		total+=s;
		sum+=s*t;
	}
	cout<<setprecision(2)<<setiosflags(ios::fixed)<<sum*1.0/total;//设置成两位小数 
	return 0;
} 
