/*
最近距离
分析：一定开long long 
*/
#include<iostream>
using namespace std;
const int MAXN=2000;
long long n,x[MAXN+3],y[MAXN+3],x0,y0,mn=0x3f3f3f3f,t;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			t=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			if(t<mn){
				mn=t;
				x0=i;y0=j;
			}
		}
	}
	cout<<x0<<" "<<y0;
	return 0;
} 
