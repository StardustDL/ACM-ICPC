/*
µ¥Êý??Ë«Êý????
*/
#include<string>
#include<iostream>
using namespace std;
string s;
int main(){
	int n,k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		k=s[s.length()-1]-'0';
		if(k%2==0)cout<<"even"<<endl;
		else cout<<"odd"<<endl;
	}
	return 0;
}
