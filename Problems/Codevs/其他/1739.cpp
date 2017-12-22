/*
GPA≈≈–Ú
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
double a[100003];
int n,k;
int main(){
	cin>>n>>k;
	double t,p;
	for(int i=1;i<=n;i++){
		cin>>t>>p;
		a[i]=t/p;
	}
	sort(a+1,a+n+1);
	printf("%.2lf",a[n-k+1]);
	return 0;
}
