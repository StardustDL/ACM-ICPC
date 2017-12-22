/*
ËØÊıÅĞ¶¨ 3
*/
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	int t=sqrt(n);
	for(int i=2;i<=t;i++){
		if(n%i==0){
			cout<<"composite";
			return 0;
		}
	}
	cout<<"prime";
	return 0; 
}
