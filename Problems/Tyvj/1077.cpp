/*
有理逼近
分析：枚举i，然后可以确定j的范围（在i/sqrt(p)周围），然后试一试就行了 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
const double eps=1e-7;
int n,p,x,y;
double mn=INF,k,t;
int main(){
	cin>>p>>n;
	mn=INF;k=sqrt(p);
	for(int i=n,e;i>0;i--){
		e=(int)((double)i/k);
		for(int j=e-3;j<=e+3;j++){
			if(i==j||j<=0||j>n)continue;
			t=k-(double)i/j;
			if(t>0 && t-eps<mn){
				x=i,y=j,mn=t;
			}
		}
	}
	cout<<x<<"/"<<y<<" ";
	mn=INF;
	for(int i=n,e;i>0;i--){
		e=(int)((double)i/k);
		for(int j=e-3;j<=e+3;j++){
			if(i==j||j<=0||j>n)continue;
			t=k-(double)i/j;
			if(t<0 && fabs(t)-eps<mn){
				x=i,y=j,mn=fabs(t);
			}
		}
	}
	cout<<x<<"/"<<y<<endl;
	return 0;
}

