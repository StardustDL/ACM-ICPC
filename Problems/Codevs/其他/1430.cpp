/*
ËØÊıÅĞ¶¨
*/
#include<iostream>
#include<cmath>
using namespace std;
int n,t;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	t=sqrt(n);
	for(int i=2;i<=t;i++){
		if(n%i==0){
			t=-1;break;
		}
	}
	if(t==-1)cout<<"\\n";
	else cout<<"\\t";
	return 0;
}
