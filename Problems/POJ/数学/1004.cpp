/*
Financial Management
*/
#include<iostream>
#include<cstdio>
using namespace std;
double ans=0,t;
int main(){
	for(int i=1;i<=12;i++){
		cin>>t;ans+=t;
	}
	printf("$%.2lf",ans/12);
	return 0;
}

