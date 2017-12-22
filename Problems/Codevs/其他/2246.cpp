/*
ºÏ»¶Êý
*/
#include<iostream>
using namespace std;
int main(){
	int n,k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		cout<<10-(k%10)<<" ";
	}
	return 0;
}
