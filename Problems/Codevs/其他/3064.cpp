/*
ÇóºÍ
*/
#include<iostream>
using namespace std;
const int MAXN=5000000; 
int x,n;
double s=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>x;
	for(n=1;n<=MAXN;n++){
		s+=1.0/n;
		if(s>=x)break;
	}
	if(n>MAXN)cout<<"Error!";
	else cout<<n;
	return 0;
}
