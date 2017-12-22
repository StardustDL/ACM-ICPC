/*
º“Õ•Œ Ã‚
*/
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,t,mx=0,mi=1<<30,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(t>mx)mx=t;
		if(t<mi)mi=t;
		s+=t;
	}
	s=round(s*1.0/n);
	cout<<mx<<endl<<mi<<endl<<s;
	return 0;
}
