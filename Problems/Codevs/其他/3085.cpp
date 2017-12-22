/*
相同的后三位
*/
#include<iostream>
using namespace std;
const int MOD=1000;
int t[1001],p,a=1,k=0;
int main(){
	cin>>p;
	t[a]=k;
	while(++k){
		a=(a*p)%MOD;
		if(t[a]){
			cout<<k<<" "<<t[a];break;
		}
		else t[a]=k;
	}
	return 0;
}
