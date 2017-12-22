/*
ÅÀÂ¥Ìİ
·ÖÎö£ºì³²¨ÄÇÆõ 
*/
#include<iostream>
using namespace std;
int n,a=1,b=1,t;
int main(){
	cin>>n;
	while(n-->1){
		t=a+b;b=a;a=t;
	}
	cout<<a;
	return 0;
}
