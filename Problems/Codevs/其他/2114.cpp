/*
˺��Ʊ
������������쳲��������У������������ⲻ����AC���� 
*/
#include<iostream>
using namespace std;
int n,a1=1,a2=1,t;
int main(){
	cin>>n;
	n-=2;
	while(n-->0){
		t=a1+a2;
		a2=a1;
		a1=t;
	}
	cout<<a1;
	return 0;
}
