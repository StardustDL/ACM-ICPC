/*
取出整数的一部分
*/
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int a[11],n,k,i,j=0,m,s=0;
int main(){
	cin>>n>>k;
	i=n;
	while(i!=0){
		j++;
		a[j]=i%10;
		i/=10;
	}
	m=j;
	for(int i=1;i<=m/2;i++){
		int t=a[i];
		a[i]=a[m-i+1];
		a[m-i+1]=t;
	}
	if(abs(k)>m){
		cout<<"Error";return 0;
	}
	else if(k>0){
		for(i=1;i<=k;i++)
			s=s*10+a[i];
	}
	else if(k<0){
		for(i=m+k+1;i<=m;i++)
			s=s*10+a[i];
	}
	else if(k==0)
		s=n;
	cout<<s;
	return 0;
}
