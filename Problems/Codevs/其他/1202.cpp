/*
ÇóºÍ 
*/
#include<iostream>
#include<algorithm>
using namespace std;
int n,a,sum=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	while(n-->0){
		cin>>a;
		sum+=a;
	}
	cout<<sum;
	return 0;
}
