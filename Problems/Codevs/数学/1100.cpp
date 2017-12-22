/*
втсибДлЕ
*/
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std; 
const double eps=0.00001;
double H,s,v,l,k;
int n;
int main(){
	cin>>H>>s>>v>>l>>k>>n;
	double t1=sqrt(H/5);
	double t2;
	if(H-k<0)t2=0;
	else t2=sqrt((H-k)/5);
	double left=s-v*t1,right=s-v*t2+l;
	int ans=0;
	for(int i=0;i<n;i++)
		if((double)i>=left-eps&&(double)i<=right+eps)ans++;
	cout<<ans<<endl;
	return 0;
}
